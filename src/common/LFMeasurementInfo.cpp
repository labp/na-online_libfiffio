#include <float.h>
#include "LFMeasurementInfo.h"

LFMeasurementInfo::LFMeasurementInfo() :
    m_NumberOfChannels( -1 ), m_SamplingFrequency( -FLT_MAX ), m_Lowpass( -FLT_MAX ), m_Highpass( -FLT_MAX ), m_DataPack( -1 ),
                    m_LineFreq( -FLT_MAX ), m_GantryAngle( 0 )
{

}

void LFMeasurementInfo::Init()
{
    m_LFSubject.Init();
    m_LFProject.Init();
    m_LFHPIMeasurement.Init();
    m_LFSSP.Init();
    m_LFEvents.Init();
    m_LFDataAcquisitionParameters.Init();
    m_NumberOfChannels = -1;
    m_SamplingFrequency = -FLT_MAX;
    m_Lowpass = -FLT_MAX;
    m_Highpass = -FLT_MAX;
    m_DataPack = -1;
    m_LineFreq = -FLT_MAX;
    m_GantryAngle = 0;
    m_LFChannelInfo.Init();
    m_BadChannels.clear();
    m_LFHPISubsystem.Init();
}

LFSubject& LFMeasurementInfo::GetLFSubject()
{
    return m_LFSubject;
}

LFProject& LFMeasurementInfo::GetLFProject()
{
    return m_LFProject;
}

LFHPIMeasurement& LFMeasurementInfo::GetLFHPIMeasurement()
{
    return m_LFHPIMeasurement;
}

LFSSP& LFMeasurementInfo::GetLFSSP()
{
    return m_LFSSP;
}

LFEvents& LFMeasurementInfo::GetLFEvents()
{
    return m_LFEvents;
}

LFDataAcquisitionParameters& LFMeasurementInfo::GetLFDataAcquisitionParameters()
{
    return m_LFDataAcquisitionParameters;
}

int32_t LFMeasurementInfo::GetNumberOfChannels()
{
    return m_NumberOfChannels;
}

float LFMeasurementInfo::GetSamplingFrequency()
{
    return m_SamplingFrequency;
}

void LFMeasurementInfo::SetNumberOfChannels( const int32_t src )
{
    m_NumberOfChannels = src;
}

void LFMeasurementInfo::SetSamplingFrequency( const int32_t src )
{
    m_SamplingFrequency = src;
}
