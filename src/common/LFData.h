#ifndef LFFIFFDATA_H
#define LFFIFFDATA_H

///FIFF - Daten
class LFData
{
protected:
    LFMeasurement m_LFMeasurement;///>Measurement block
public:
    ///Gibt Measurement Block zurück
    LFMeasurement& GetLFMeasurement();
};

#endif
