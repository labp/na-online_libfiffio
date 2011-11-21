#include "LFElementHeader.h"

LFElementHeader::LFElementHeader() :
    m_tag( -1 ), m_type( -1 ), m_size( -1 ), m_next( -1 )
{

}

void LFElementHeader::Init()
{
    m_tag = -1;
    m_type = -1;
    m_size = -1;
    m_next = -1;
}

int32_t LFElementHeader::GetTag()
{
    return m_tag;
}

int32_t LFElementHeader::GetType()
{
    return m_type;
}

int32_t LFElementHeader::GetSize()
{
    return m_size;
}

int32_t LFElementHeader::GetNext()
{
    return m_next;
}

