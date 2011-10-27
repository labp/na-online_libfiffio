#include <cxxtest/TestSuite.h>

#include "LFArrayFloat2d.h"

class testLFArrayFloat2d: public CxxTest::TestSuite
{
public:
    void test_LFArrayFloat2d( void )
    {
        LFArrayFloat2d obj;
        obj.Allocate(2);
        float* f0=obj.GetElement(0);
        float* f1=obj.GetElement(1);
        TS_ASSERT(f0!=NULL);
        TS_ASSERT(f1!=NULL);
        f0[0]=1;
        f0[1]=2;
        f0[2]=3;
        f0[3]=4;
        f0=obj.GetElement(0);
        TS_ASSERT_EQUALS( f0[0], 1 );
        TS_ASSERT_EQUALS( f0[1], 2 );
        f1=obj.GetElement(1);
        TS_ASSERT_EQUALS( f1[0], 3 );
        TS_ASSERT_EQUALS( f1[1], 4 );
    }
};

