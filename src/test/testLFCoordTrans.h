#include <cxxtest/TestSuite.h>
#include <memory.h>
#include <stdio.h>
#include "LFCoordTrans.h"

class testLFCoordTrans: public CxxTest::TestSuite
{
public:
    void test_LFCoordTrans( void )
    {
        LFCoordTrans obj;
        float array1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
        float array2[3][3]={{0,0,0},{0,0,0},{0,0,0}};
        obj.SetRot(array1);
        memcpy(array2,obj.GetRot(),sizeof(array2));
        for(int i=0;i<3;i++){
            for(int j=0; j<3;j++){
                TS_TRACE("\n");
                TS_TRACE(array1[i][j]);
                TS_TRACE("==");
                TS_TRACE(array2[i][j]);
            }
        }
        TS_ASSERT_SAME_DATA( array1, array2, sizeof(array1));
    }
};
