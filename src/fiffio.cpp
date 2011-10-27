//#include <fiff.h>
//#include <err.h>
//#include <raw_info.h>
//#include "libfiffio.h"
//#include </usr/include/c++/4.4/string>

#include "LFInterface.h"
//int testlibfunction( const char* a );

int readStaticData( const char* path )
{
//    rawInfo info;
//    if( ( info = fiff_load_raw_info( path ) ) == NULL )
//    {
//        return 100;
//    }
//    return testlibfunction("aaa");
    return 0;
}

int LFInterface::fiffRead(LFData& output, const char* path)
{
    return 0;
}
