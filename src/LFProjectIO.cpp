
#include "LFProjectIO.h"

returncode_t LFProjectIO::Read( LFProject& out, LFFileFIFF& file )
{
    LFElementHeader header;
    returncode_t ret = rc_error_unknown;
    while( ( ret = file.ReadElementHeader( header ) ) == rc_normal )
    {
        switch( header.GetTag() )
        {
            case tag_block_start:
            {
                int32_t block;
                ret = file.Read< int32_t > ( block );
                if( ret != rc_normal )
                    return ret;
                switch( block )
                {
                    default:
                        ret = file.SkipBlock();
                        if( ret != rc_normal )
                            return ret;
                }
                break;//tag_block_start
            }
            case tag_block_end:
                return file.Skip( header.GetSize() );//The block is over
            case tag_proj_id:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetId( buf );
                break;//tag_proj_id
            }
            case tag_proj_name:
            {
                int32_t sz=header.GetSize()+1;
                char* buf=new char[sz];
                memset(buf,0,sz);
                ret=file.ReadString(buf,sz-1);
                if( ret != rc_normal ){
                    delete[] buf;
                    return ret;
                }
                out.GetName() = buf;
                delete[] buf;
                break;
            }
            case tag_proj_comment:
            {
                int32_t sz=header.GetSize()+1;
                char* buf=new char[sz];
                memset(buf,0,sz);
                ret=file.ReadString(buf,sz-1);
                if( ret != rc_normal ){
                    delete[] buf;
                    return ret;
                }
                out.GetComment()= buf;
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
