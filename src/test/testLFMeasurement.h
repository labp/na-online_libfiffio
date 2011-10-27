
// MyTestSuite.h
#include <cxxtest/TestSuite.h>

#include "LFMeasurement.h"

class testLFMeasurement: public CxxTest::TestSuite
{
public:
    void test_LFMeasurement( void )
    {
        LFMeasurement obj();
        TS_ASSERT( 1 + 1 > 1 );
        TS_ASSERT_EQUALS( 1 + 1, 2 );
    }
};
