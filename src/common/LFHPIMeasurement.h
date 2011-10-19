#ifndef LFHPIMEASUREMENT_H
#define LFHPIMEASUREMENT_H

///HPI Measurement block
class LFHPIMeasurement
{
protected:
    float m_SamplingFrequency;///>Sampling Frequency, Hz
    unsigned long m_NumberOfChannels;///>Number of Channels
    unsigned long m_NumberOfAverages;///>Number of Averages
    unsigned long m_NumberOfHPICoils;///>Number of HPI Coils
    unsigned long m_FirstSample;///>First Sample of Epoch
    unsigned long m_LastSample;///>Last Sample of Epoch
public:
    ///Gibt Sampling Frequency zurück
    float GetSamplingFrequency();
    ///Gibt Number of Channels zurück
    unsigned long GetNumberOfChannels();
    ///Gibt Number of Averages zurück
    unsigned long GetNumberOfAverages();
    ///Gibt Number of HPI Coils zurück
    unsigned long GetNumberOfHPICoils();
    ///Gibt First Sample zurück
    unsigned long GetFirstSample();
    ///Gibt Last Sample zurück
    unsigned long GetLastSample();
    ///Setzt Sampling Frequency
    void SetSamplingFrequency(unsigned long src);
    ///Setzt Number of Channels
    void SetNumberOfChannels(unsigned long src);
    ///Setzt Number of Averages
    void SetNumberOfAverages(unsigned long src);
    ///Setzt Number of HPI Coils
    void SetNumberOfHPICoils(unsigned long src);
    ///Setzt First Sample
    void SetFirstSample(unsigned long src);
    ///Setzt Last Sample
    void SetLastSample(unsigned long src);
};

#endif
