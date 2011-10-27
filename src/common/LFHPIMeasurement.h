#ifndef LFHPIMEASUREMENT_H
#define LFHPIMEASUREMENT_H

#include <inttypes.h>

#include "LFHPICoil.h"
#include "LFIsotrak.h"

///HPI Measurement block (108)
class LFHPIMeasurement
{
protected:
    float m_SamplingFrequency;///<Sampling Frequency, Hz (201)
    int32_t m_NumberOfChannels;///<Number of Channels (200)
    int32_t m_NumberOfAverages;///<Number of Averages (207)
    int32_t m_NumberOfHPICoils;///<Number of HPI Coils (216)
    int32_t m_FirstSample;///<First Sample of Epoch (208)
    int32_t m_LastSample;///<Last Sample of Epoch (209)
    LFHPICoil m_LFHPICoil;///<HPI Coil block (110)
    LFIsotrak m_LFIsotrak;///<Isotrak block (107)
public:
    ///Constructor
    LFHPIMeasurement();
    ///Sets all member variables to defaults
    void Init();
    ///Returns the Sampling Frequency
    float GetSamplingFrequency();
    ///Returns the Number of Channels
    int32_t GetNumberOfChannels();
    ///Returns the Number of Averages
    int32_t GetNumberOfAverages();
    ///Returns the Number of HPI Coils
    int32_t GetNumberOfHPICoils();
    ///Returns the First Sample
    int32_t GetFirstSample();
    ///Returns the Last Sample
    int32_t GetLastSample();
    ///Returns the HPI Coil block
    LFHPICoil& GetLFHPICoil();
    ///Returns the Isotrak block
    LFIsotrak& GetLFIsotrak();
    ///Sets the Sampling Frequency
    void SetSamplingFrequency( const int32_t src );
    ///Sets the Number of Channels
    void SetNumberOfChannels( const int32_t src );
    ///Sets the Number of Averages
    void SetNumberOfAverages( const int32_t src );
    ///Sets the Number of HPI Coils
    void SetNumberOfHPICoils( const int32_t src );
    ///Sets the First Sample
    void SetFirstSample( const int32_t src );
    ///Sets the Last Sample
    void SetLastSample( const int32_t src );
};

#endif
