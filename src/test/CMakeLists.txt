INCLUDE(Dart)
OPTION(BUILD_TESTING "Build the project using CTest" ON)
IF(BUILD_TESTING)
	MESSAGE("Build testing")
	find_package(CxxTest)
	if(CXXTEST_FOUND)
		include_directories(${CXXTEST_INCLUDE_DIR})
		enable_testing()
		FIND_PROGRAM(CXXTEST_PERL_TESTGEN_EXECUTABLE cxxtestgen.pl PATHS /usr/local/cxxtest)
		CXXTEST_ADD_TEST(testLFMeasurement testLFMeasurement.cc
			${CMAKE_CURRENT_SOURCE_DIR}/test/testLFMeasurement.h)
		CXXTEST_ADD_TEST(testLFSubject testLFSubject.cc
			${CMAKE_CURRENT_SOURCE_DIR}/test/testLFSubject.h)
		target_link_libraries(testLFSubject ${CMAKE_CURRENT_SOURCE_DIR}/common/LFSubject.cpp ${CMAKE_CURRENT_SOURCE_DIR}/common/LFSubject.h)
		CXXTEST_ADD_TEST(testLFArrayFloat2d testLFArrayFloat2d.cc
			${CMAKE_CURRENT_SOURCE_DIR}/test/testLFArrayFloat2d.h)
		target_link_libraries(testLFArrayFloat2d ${CMAKE_CURRENT_SOURCE_DIR}/common/LFArrayFloat2d.cpp ${CMAKE_CURRENT_SOURCE_DIR}/common/LFArrayFloat2d.h)
		CXXTEST_ADD_TEST(testLFArrayFloat3d testLFArrayFloat3d.cc
			${CMAKE_CURRENT_SOURCE_DIR}/test/testLFArrayFloat3d.h)
		target_link_libraries(testLFArrayFloat3d ${CMAKE_CURRENT_SOURCE_DIR}/common/LFArrayFloat3d.cpp ${CMAKE_CURRENT_SOURCE_DIR}/common/LFArrayFloat3d.h)
		CXXTEST_ADD_TEST(testLFBemSurface testLFBemSurface.cc
			${CMAKE_CURRENT_SOURCE_DIR}/test/testLFBemSurface.h)
		target_link_libraries(testLFBemSurface ${CMAKE_CURRENT_SOURCE_DIR}/common/LFBemSurface.cpp ${CMAKE_CURRENT_SOURCE_DIR}/common/LFBemSurface.h)
		CXXTEST_ADD_TEST(testLFChannelInfo testLFChannelInfo.cc
			${CMAKE_CURRENT_SOURCE_DIR}/test/testLFChannelInfo.h)
		target_link_libraries(testLFChannelInfo ${CMAKE_CURRENT_SOURCE_DIR}/common/LFChannelInfo.cpp ${CMAKE_CURRENT_SOURCE_DIR}/common/LFChannelInfo.h)
		CXXTEST_ADD_TEST(testLFCoordTrans testLFCoordTrans.cc
			${CMAKE_CURRENT_SOURCE_DIR}/test/testLFCoordTrans.h)
		target_link_libraries(testLFCoordTrans ${CMAKE_CURRENT_SOURCE_DIR}/common/LFCoordTrans.cpp ${CMAKE_CURRENT_SOURCE_DIR}/common/LFCoordTrans.h)
#		CXXTEST_ADD_TEST(test* test*.cc
#			${CMAKE_CURRENT_SOURCE_DIR}/test/test*.h)
#		target_link_libraries(test* ${CMAKE_CURRENT_SOURCE_DIR}/common/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/common/*.h)
		#message(: ${})
	endif(CXXTEST_FOUND)
#	INCLUDE(CTest)
#	ENABLE_TESTING()
#	ADD_TEST(NAME testLFMeasurement COMMAND testLFMeasurement.h)
ENDIF(BUILD_TESTING)

