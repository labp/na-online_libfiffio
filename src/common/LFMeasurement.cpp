#include "LFMeasurement.h"

LFMeasurement::LFMeasurement() :
    m_BemCoordinateFrame( c_unknown )
{

}

LFMeasurement::~LFMeasurement()
{

}

void LFMeasurement::Init()
{
    m_LFMeasurementInfo.Init();
    m_LFRawData.Init();
    m_BemCoordinateFrame = c_unknown;
    m_LFCoordTrans.Init();
    m_LFBemSurface.Init();
    m_BemSolutionMatrix.clear();
}

LFMeasurementInfo& LFMeasurement::GetLFMeasurementInfo()
{
    return m_LFMeasurementInfo;
}

LFRawData& LFMeasurement::GetLFRawData()
{
    return m_LFRawData;
}

LFMeasurement::coord_t LFMeasurement::GetBemCoordinateFrame()
{
    return m_BemCoordinateFrame;
}

LFCoordTrans& LFMeasurement::GetLFCoordTrans()
{
    return m_LFCoordTrans;
}

LFBemSurface& LFMeasurement::GetLFBemSurface()
{
    return m_LFBemSurface;
}

LFArrayFloat2d& LFMeasurement::GetBemSolutionMatrix()
{
    return m_BemSolutionMatrix;
}

void LFMeasurement::SetBemCoordinateFrame( const LFMeasurement::coord_t src )
{
    m_BemCoordinateFrame = src;
}

