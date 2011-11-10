#ifndef LFHPISUBSYSTEM_H
#define LFHPISUBSYSTEM_H

#include <string>
#include <inttypes.h>
using namespace std;

/**
 * Data about HPI state
 */
class LFHPISubsystem
{
protected:
    int32_t m_NumberOfHPICoils;///<Number of HPI Coils, default == -1 (216)
    string m_EventChannel;///<Event channel name (602)
    //HPI Coil (110)
public:
    /**
     * Constructor
     */
    LFHPISubsystem();
    /**
     * Sets all member variables to defaults
     */
    void Init();
    /**
     * Returns the Number of HPI Coils
     */
    int32_t GetNumberOfHPICoils();
    /**
     * Returns Event channel name
     */
    string& GetEventChannel();
    /**
     * Sets the Number of HPI Coils
     */
    void SetNumberOfHPICoils( const int32_t src );
};

#endif
