#ifndef LFPROJECT_H
#define LFPROJECT_H

///Project block
class LFProject
{
protected:
    LFHPIMeasurement m_LFHPIMeasurement;///>///HPI Measurement block
public:
    ///Gibt HPI Measurement block zurück
    LFHPIMeasurement& GetLFHPIMeasurement();
};
#endif
