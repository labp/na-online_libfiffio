#ifndef LFMEASUREMENTINFO_H
#define LFMEASUREMENTINFO_H

#include <inttypes.h>
#include <vector>
using namespace std;

#include "LFSubject.h"
#include "LFProject.h"
#include "LFHPIMeasurement.h"
#include "LFSSP.h"
#include "LFEvents.h"
#include "LFDataAcquisitionParameters.h"
#include "LFChannelInfo.h"
#include "LFHPISubsystem.h"

///Measurement-Info block (101)
class LFMeasurementInfo
{
protected:
    LFSubject m_LFSubject;///<Subject block (106)
    LFProject m_LFProject;///<Project block (111)
    LFHPIMeasurement m_LFHPIMeasurement;///<HPI Measurement block (108)
    LFSSP m_LFSSP;///<SSP block (313)
    LFEvents m_LFEvents;///<Events block (115)
    LFDataAcquisitionParameters m_LFDataAcquisitionParameters;///<Data Acquisition Parameters block (117)
    int32_t m_NumberOfChannels;///<Number of Channels (200)
    float m_SamplingFrequency;///<Sampling Frequency, Hz (201)
    float m_Lowpass;///<Analog lowpass, Hz (219)
    float m_Highpass;///<Analog highpass, Hz (223)
    int32_t m_DataPack;///<How the raw data is packed (202)
    float m_LineFreq;///<Basic line interference frequency, Hz (235)
    int m_GantryAngle;///<Tilt angle of the dewar in degrees (282)
    LFChannelInfo m_LFChannelInfo;///<Channel descriptor (203)
    vector< int32_t > m_BadChannels;///<List of bad channels (220)
    LFHPISubsystem m_LFHPISubsystem;///<HPI Subsystem block (121)
public:
    ///Constructor
    LFMeasurementInfo();
    ///Sets all member variables to defaults
    void Init();
    ///Returns Subject block
    LFSubject& GetLFSubject();
    ///Returns Project block
    LFProject& GetLFProject();
    ///Returns HPI Measurement block
    LFHPIMeasurement& GetLFHPIMeasurement();
    ///Returns SSP block
    LFSSP& GetLFSSP();
    ///Returns Events block
    LFEvents& GetLFEvents();
    ///Returns Data Acquisition Parameters block
    LFDataAcquisitionParameters& GetLFDataAcquisitionParameters();
    ///Returns the Number of Channels
    int32_t GetNumberOfChannels();
    ///Returns the Sampling Frequency
    float GetSamplingFrequency();
    ///Sets the Number of Channels
    void SetNumberOfChannels( const int32_t src );
    ///Sets the Sampling Frequency
    void SetSamplingFrequency( const int32_t src );
};

#endif
