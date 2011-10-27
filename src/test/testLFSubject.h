#include <cxxtest/TestSuite.h>

#include "LFSubject.h"

class testLFSubject: public CxxTest::TestSuite
{
public:
    void test_LFSubject( void )
    {
        LFSubject obj;
        TS_ASSERT_EQUALS( 1 + 1, 2 );
    }
};
