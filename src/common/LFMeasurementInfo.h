#ifndef LFMEASUREMENTINFO_H
#define LFMEASUREMENTINFO_H

///Measurement-Info block
class LFMeasurementInfo
{
protected:
    LFSubject m_LFSubject;///>Subject block
public:
    LFSubject& GetLFSubject();
};

#endif
