#include "LFIsotrakIO.h"

returncode_t LFIsotrakIO::Read( LFIsotrak& out, LFFileFIFF& file )
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
            case tag_dig_point:
            {
                int32_t buf1, buf2, np = 1;
                int32_t sz = header.GetSize();
                ret = file.Read< int32_t > ( buf1 );
                if( ret != rc_normal )
                    return ret;
                ret = file.Read< int32_t > ( buf2 );
                if( ret != rc_normal )
                    return ret;
                LFDigitisationPoint& dst = out.GetLFDigitisationPoint().AddNew();
                dst.SetKind( buf1 );
                dst.SetIdent( buf2 );
                if( sz != 20 )
                {
                    ret = file.Read< int32_t > ( np );
                    if( ret != rc_normal )
                        return ret;
                }
                LFArrayFloat3d& rr = dst.GetRr();
                rr.Allocate( np );
                ret = file.ReadArrayFloat( rr.data(), np * sizeof(float) * 3 );
                if( ret != rc_normal )
                    return ret;
                break;//tag_dig_point
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
