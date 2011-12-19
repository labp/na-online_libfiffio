
#include "LFBemIO.h"

returncode_t LFBemIO::Read( LFBem& out, LFFileFIFF& file )
{
    LFElementHeader header;
    returncode_t ret = rc_error_unknown;
    while( ( ret = file.ReadElementHeader( header ) ) == rc_normal )
    {
        switch( header.GetTag() )
        {
            case tag_block_start:
            {
                ret = file.SkipBlock();
                if( ret != rc_normal )
                    return ret;
                break;//tag_block_start
            }
            case tag_block_end:
                return file.Skip( header.GetSize() );//The block is over
            case tag_bem_coord_frame:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetBemCoordinateFrame( ( LFBem::coord_t )buf );
                break;
            }
            case tag_coord_trans:
            {
                int32_t sz = header.GetSize();
                LFCoordTrans& dst=out.GetLFCoordTrans();
                                                unsigned char* p=new unsigned char[sz];//dbg
                                                file.ReadString((char*)p,sz);//dbg
                                                for(int32_t i=0; i<sz; i++)printf("%x ",p[i]);//dbg
                                                printf("\n");//dbg
                                                delete [] p;
                break; //tag_coord_trans
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
