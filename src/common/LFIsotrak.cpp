#include "LFIsotrak.h"

void LFIsotrak::Init()
{
    m_DigitisationPoint.Init();
}

LFDigitisationPoint& LFIsotrak::GetLFDigitisationPoint()
{
    return m_DigitisationPoint;
}
