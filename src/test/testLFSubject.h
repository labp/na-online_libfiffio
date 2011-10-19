#include <cxxtest/TestSuite.h>

#include <string>
using std::string;

#include "LFSubject.h"

class testLFSubject: public CxxTest::TestSuite
{
public:
    void test_LFSubject( void )
    {
        LFSubject obj;
        TS_ASSERT( !obj.GetHIS_IDLength() );
        TS_ASSERT( !obj.GetLastNameLength() );
        TS_ASSERT_EQUALS( 1 + 1, 2 );
    }
};
