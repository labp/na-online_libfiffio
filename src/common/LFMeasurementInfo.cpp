#include <string>
using std::string;

#include "LFSubject.h"
#include "LFMeasurementInfo.h"

LFSubject& LFMeasurementInfo::GetLFSubject()
{
    return m_LFSubject;
}
