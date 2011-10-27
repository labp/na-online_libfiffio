#include<float.h>
#include "LFChannelInfo.h"

LFChannelInfo::LFChannelInfo() :
    m_ScanNo( -1 ), m_LogNo( -1 ), m_Kind( -1 ), m_Range( -FLT_MAX )
{

}

void LFChannelInfo::Init()
{
    m_ScanNo = -1;
    m_LogNo = -1;
    m_Kind = -1;
    m_Range = -FLT_MAX;
}

int32_t LFChannelInfo::GetScanNo()
{
    return m_ScanNo;
}

int32_t LFChannelInfo::GetLogNo()
{
    return m_LogNo;
}

int32_t LFChannelInfo::GetKind()
{
    return m_Kind;
}

float LFChannelInfo::GetRange()
{
    return m_Range;
}

void LFChannelInfo::SetScanNo( const int32_t src )
{
    m_ScanNo = src;
}

void LFChannelInfo::SetLogNo( const int32_t src )
{
    m_LogNo = src;
}

void LFChannelInfo::SetKind( const int32_t src )
{
    m_Kind = src;
}

void LFChannelInfo::SetRange( const float src )
{
    m_Range = src;
}

