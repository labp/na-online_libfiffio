#ifndef LFSUBJECT_H
#define LFSUBJECT_H

#include <inttypes.h>
#include<string>
using namespace std;

///Subject block (106)
class LFSubject
{
protected:
    string m_HIS_ID;///<HIS ID (410) ID used in the Hospital Information System
    string m_LastName;///<Last Name (403)
    string m_FirstName;///<First Name (401)
    string m_MiddleName;///<Middle Name (402)
    int32_t m_Birthday;///<Birthdate (404)
    //enum m_Sex (405)
    //enum m_Hand (406)
    float m_Weight;///<Body weight, kg (407)
    float m_Height;///<Body height, m (408)
    string m_Comment;///<Comment (409)
public:
    ///Constructor
    LFSubject();
    ///Sets all member variables to defaults
    void Init();
    ///Returns the HIS ID
    string& GetHIS_ID();
    ///Returns the Last Name
    string& GetLastName();
    ///Returns the First Name
    string& GetFirstName();
    ///Returns the Middle Name
    string& GetMiddleName();
    ///Returns the Birthdate
    int32_t GetBirthday();
    ///Returns the body weight
    float GetWeight();
    ///Returns the body height
    float GetHeight();
    ///Returns the comment
    string& GetComment();
    ///Sets the HIS ID
    void SetHIS_ID( const char* src );
    ///Sets the den Last Name
    void SetLastName( const char* src );
    ///Sets the First Name
    void SetFirstName( const char* src );
    ///Sets the Middle Name
    void SetMiddleName( const char* src );
    ///Sets the Birthdate
    void SetBirthday( const int32_t src );
    ///Sets the body weight
    void SetWeight( const float src );
    ///Sets the body height
    void SetHeight( const float src );
    ///Sets the Comment
    void SetComment( const char* src );
};

#endif
