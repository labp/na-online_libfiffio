#include "LFHPIMeasurement.h"

float LFHPIMeasurement::GetSamplingFrequency()
{
    return m_SamplingFrequency;
}

unsigned long LFHPIMeasurement::GetNumberOfChannels()
{
    return m_NumberOfChannels;
}

unsigned long LFHPIMeasurement::GetNumberOfAverages()
{
    return m_NumberOfAverages;
}

unsigned long LFHPIMeasurement::GetNumberOfHPICoils()
{
    return m_NumberOfHPICoils;
}

unsigned long LFHPIMeasurement::GetFirstSample()
{
    return m_FirstSample;
}

unsigned long LFHPIMeasurement::GetLastSample()
{
    return m_LastSample;
}

void LFHPIMeasurement::SetSamplingFrequency(unsigned long src)
{
    m_SamplingFrequency=src;
}

void LFHPIMeasurement::SetNumberOfChannels(unsigned long src)
{
    m_NumberOfChannels=src;
}
void LFHPIMeasurement::SetNumberOfAverages(unsigned long src)
{
    m_NumberOfAverages=src;
}

void LFHPIMeasurement::SetNumberOfHPICoils(unsigned long src)
{
    m_NumberOfHPICoils=src;
}

void LFHPIMeasurement::SetFirstSample(unsigned long src)
{
    m_FirstSample=src;
}

void LFHPIMeasurement::SetLastSample(unsigned long src)
{
    m_LastSample=src;
}
