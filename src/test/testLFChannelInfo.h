#include <cxxtest/TestSuite.h>

#include "LFChannelInfo.h"

class testLFChannelInfo: public CxxTest::TestSuite
{
public:
    void test_LFChannelInfo( void )
    {
        LFChannelInfo obj;
        TS_ASSERT_EQUALS( 1 + 1, 2 );
    }
};
