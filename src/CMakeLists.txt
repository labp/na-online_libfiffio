cmake_minimum_required(VERSION 2.8)
project(fiffio)
SET(CMAKE_VERBOSE_MAKEFILE ON)
SET(BUILD_SHARED_LIBS ON)
ADD_DEFINITIONS(-Wall -fPIC)

SET(SOURCES
	fiffio.cpp
	LFElementHeader.cpp
	LFFileFIFF.cpp
	LFDataIO.cpp
	LFMeasurementIO.cpp
	LFMeasurementInfoIO.cpp
	LFSubjectIO.cpp
	LFProjectIO.cpp
	LFHPIMeasurementIO.cpp
	LFHPICoilIO.cpp
	LFIsotrakIO.cpp
)

SET(HEADERS
	LFTags.h
	LFBlocks.h
	LFElementHeader.h
	LFFileFIFF.h
	LFDataIO.h
	LFMeasurementIO.h
	LFMeasurementInfoIO.h
	LFSubjectIO.h
	LFProjectIO.h
	LFHPIMeasurementIO.h
	LFHPICoilIO.h
	LFIsotrakIO.h
)

SET(COMMON_HEADERS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/common/)
SET(COMMON_SOURCES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/common/)
INCLUDE(${COMMON_HEADERS_PATH}CMakeLists.txt)

#INCLUDE_DIRECTORIES(/usr/local/include/fiff/)

#find_library(liberr liberr.a /usr/local/lib/fiff/ NO_DEFAULT_PATH)
#find_library(libfiff libfiff.a /usr/local/lib/fiff/ NO_DEFAULT_PATH)
#find_library(libneurou libneurou.a /usr/local/lib/fiff/ NO_DEFAULT_PATH)
#SET(LIBS ${liberr} ${libfiff} ${libneurou})

#find_library(LIBS libfiff.a /home/evfimevskiy/libfiff_pic/ NO_DEFAULT_PATH)

#find_library(LIBS libtestlib.a /home/evfimevskiy/projects/testlib/build/ NO_DEFAULT_PATH)

OPTION(BUILD_DEBUG
	"Build the project using debugging code"
	ON)
IF(BUILD_DEBUG)
	SET(CMAKE_BUILD_TYPE Debug)
	SET_SOURCE_FILES_PROPERTIES(
		${SOURCES}
		COMPILE_FLAGS -DDEBUG)
	INCLUDE(${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt)
ENDIF(BUILD_DEBUG)

SET(EXECUTABLE_OUTPUT_PATH "../build/")

SET(LIBRARY_OUTPUT_PATH "../build/")
SET(LIBRARY_OUTPUT_DIRECTORY "../build/")

#include_directories("${CMAKE_SOURCE_DIR}")
#if(LIBS)
	INCLUDE(FindDoxygen OPTIONAL)
	IF(DEFINED DOXYGEN_EXECUTABLE)
		EXEC_PROGRAM(${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR} ARGS ${CMAKE_CURRENT_SOURCE_DIR}/doxyfile)
	ENDIF(DEFINED DOXYGEN_EXECUTABLE)
#	add_library(fiffio ${SOURCES} ${HEADERS} ${COMMON_SOURCES} ${COMMON_HEADERS})
	add_library(fiffio SHARED ${SOURCES} ${HEADERS} ${COMMON_SOURCES} ${COMMON_HEADERS})
#	TARGET_LINK_LIBRARIES(fiffio ${LIBS})
#	message("Libs found: ${LIBS}")
#else(LIBS)
#	message("Libs not found")
#endif(LIBS)

