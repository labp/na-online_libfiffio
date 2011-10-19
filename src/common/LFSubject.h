#ifndef LFSUBJECT_H
#define LFSUBJECT_H

///Subject block
class LFSubject
{
protected:
    string m_HIS_ID;///>HIS ID
    string m_LastName;///>Last Name
    string m_FirstName;///>First Name
    string m_MiddleName;///>Middle Name
    unsigned long m_Birthday;///>Geburtsdatum
    //enum m_Sex
    //enum m_Hand
    float m_Weight;///>Körpergewicht
    float m_Height;///>Körpergröße
    string m_Comment;///>Kommentar
public:
    ///Gibt HIS ID zurück
    const char* GetHIS_ID();
    ///Gibt HIS ID Länge zurück
    unsigned long GetHIS_IDLength();
    ///Gibt Last Name zurück
    const char* GetLastName();
    ///Gibt Last Name Länge zurück
    unsigned long GetLastNameLength();
   ///Gibt First Name zurück
    const char* GetFirstName();
    ///Gibt First Name Länge zurück
    unsigned long GetFirstNameLength();
   ///Gibt Middle Name zurück
    const char* GetMiddleName();
    ///Gibt Middle Name Länge zurück
    unsigned long GetMiddleNameLength();
    ///Gibt das Geburtsdatum zurück
    unsigned long GetBirthday();
    ///Gibt das Körpergewicht zurück
    float GetWeight();
    ///Gibt die Körpergröße zurück
    float GetHeight();
    ///Gibt den Kommentar zurück
    const char* GetComment();
    ///Gibt die Länge des Kommentars zurück
    unsigned long GetCommentLength();
  ///Setzt HIS ID
    void SetHIS_ID( const char* src );
    ///Setzt den Last Name
    void SetLastName( const char* src );
    ///Setzt den First Name
    void SetFirstName( const char* src );
    ///Setzt den Middle Name
    void SetMiddleName( const char* src );
    ///Setzt das Geburtsdatum
    void SetBirthday(unsigned long src);
    ///Setzt das Körpergewicht
    void SetWeight( float src );
    ///Setzt die Körpergröße
    void SetHeight( float src );
    ///Setzt den Kommentar
    void SetComment( const char* src );
};

#endif
