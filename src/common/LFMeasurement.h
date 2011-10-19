#ifndef LFMEASUREMENT_H
#define LFMEASUREMENT_H

///Measurement block
class LFMeasurement
{
protected:
    LFMeasurementInfo m_LFMeasurementInfo;///>Measurement-Info block
public:
    LFMeasurementInfo& GetLFMeasurementInfo();
};

#endif
