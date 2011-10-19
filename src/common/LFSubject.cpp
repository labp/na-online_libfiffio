#include <string>
using std::string;

#include "LFSubject.h"

const char* LFSubject::GetHIS_ID()
{
    return m_HIS_ID;
}

unsigned long LFSubject::GetHIS_IDLength()
{
    return m_HIS_ID.length();
}

const char* LFSubject::GetLastName()
{
    return m_LastName;
}

unsigned long LFSubject::GetLastNameLength()
{
    return m_LastName.length();
}

const char* LFSubject::GetFirstName()
{
    return m_FirstName;
}

unsigned long LFSubject::GetFirstNameLength()
{
    return m_FirstName.length();
}

const char* LFSubject::GetMiddleName()
{
    return m_MiddleName;
}

unsigned long LFSubject::GetMiddleNameLength()
{
    return m_MiddleName.length();
}

unsigned long LFSubject::GetBirthday()
{
    return m_Birthday;
}

float LFSubject::GetWeight()
{
    return m_Weight;
}

float LFSubject::GetHeight()
{
    return m_Height;
}

const char* LFSubject::GetComment()
{
    return m_Comment;
}

void LFSubject::SetHIS_ID( const char* src )
{
    m_HIS_ID = src;
}

void LFSubject::SetLastName( const char* src )
{
    m_LastName = src;
}

void LFSubject::SetFirstName( const char* src )
{
    m_FirstName = src;
}

void LFSubject::SetMiddleName( const char* src )
{
    m_MiddleName = src;
}

void LFSubject::SetBirthday( unsigned long src )
{
    m_Birthday = src;
}

unsigned long LFSubject::GetCommentLength()
{
    return m_Comment.length();
}

void LFSubject::SetWeight( float src )
{
    m_Weight = src;
}

void LFSubject::SetHeight( float src )
{
    m_Height = src;
}

void LFSubject::SetComment( const char* src )
{
    m_Comment = src;
}

