#include <string>
using std::string;

#include "LFSubject.h"
#include "LFMeasurementInfo.h"
#include "LFMeasurement.h"
#include "LFData.h"

LFMeasurement& LFData::GetLFMeasurement()
{
    return m_LFMeasurement;
}
