#include "LFSubjectIO.h"

returncode_t LFSubjectIO::Read( LFSubject& out, LFFileFIFF& file )
{
    LFElementHeader header;
    returncode_t ret = rc_error_unknown;
    while( ( ret = file.ReadElementHeader( header ) ) == rc_normal )
    {
        switch( header.GetTag() )
        {
            case tag_block_start:
            {
//                int32_t block;
//                ret = file.Read< int32_t > ( block );
//                if( ret != rc_normal )
//                    return ret;
//                switch( block )
//                {
//                   default:
                ret = file.SkipBlock();
                if( ret != rc_normal )
                    return ret;
//                }
                break;//tag_block_start
            }
            case tag_block_end:
                return file.Skip( header.GetSize() );//The block is over

            case tag_subj_his_id:
            {
                int32_t sz=header.GetSize()+1;
                char* buf=new char[sz];
                memset(buf,0,sz);
                ret=file.ReadString(buf,sz-1);
                if( ret != rc_normal ){
                    delete[] buf;
                    return ret;
                }
                out.SetHIS_ID( buf );
                delete[] buf;
                break;
            }
            case tag_subj_first_name:
            {
                int32_t sz=header.GetSize()+1;
                char* buf=new char[sz];
                memset(buf,0,sz);
                ret=file.ReadString(buf,sz-1);
                if( ret != rc_normal ){
                    delete[] buf;
                    return ret;
                }
               out.SetFirstName( buf );
                delete[] buf;
                break;
            }
            case tag_subj_middle_name:
            {
                int32_t sz=header.GetSize()+1;
                char* buf=new char[sz];
                memset(buf,0,sz);
                ret=file.ReadString(buf,sz-1);
                if( ret != rc_normal ){
                    delete[] buf;
                    return ret;
                }
                out.SetMiddleName( buf );
                delete[] buf;
                break;
            }
            case tag_subj_last_name:
            {
                int32_t sz=header.GetSize()+1;
                char* buf=new char[sz];
                memset(buf,0,sz);
                ret=file.ReadString(buf,sz-1);
                if( ret != rc_normal ){
                    delete[] buf;
                    return ret;
                }
                out.SetLastName( buf );
                delete[] buf;
                break;
            }
            case tag_subj_birth_day:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetBirthday( buf );
                break;//tag_subj_birth_day
            }
            case tag_subj_sex:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetSex( ( LFSubject::sex_t )buf );
                break;//tag_subj_sex
            }
            case tag_subj_hand:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetHand( ( LFSubject::hand_t )buf );
                break;//tag_subj_hand
            }
            case tag_subj_weight:
            {
                float buf;
                ret = file.Read< float > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetWeight( buf );
                break;//tag_subj_weight
            }
            case tag_subj_height:
            {
                float buf;
                ret = file.Read< float > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetHeight( buf );
                break;//tag_subj_height
            }
            case tag_subj_comment:
            {
                int32_t sz=header.GetSize()+1;
                char* buf=new char[sz];
                memset(buf,0,sz);
                ret=file.ReadString(buf,sz-1);
                if( ret != rc_normal ){
                    delete[] buf;
                    return ret;
                }
                out.SetComment( buf );
                delete[] buf;
                break;
            }
            default:
                ret=file.Skip( header.GetSize() );
                if( ret != rc_normal )
                    return ret;
                break;
        }
        if(header.GetNext()<0)return ret;
    }
    return ret;
}
