#include <string>
using std::string;

#include "LFSubject.h"
#include "LFMeasurementInfo.h"
#include "LFMeasurement.h"

LFMeasurementInfo& LFMeasurement::GetLFMeasurementInfo()
{
    return m_LFMeasurementInfo;
}
