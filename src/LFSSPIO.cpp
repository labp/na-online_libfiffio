
#include "LFSSPIO.h"

returncode_t LFSSPIO::Read( LFSSP& out, LFFileFIFF& file )
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
                ret = file.Read< int32_t >( block );
                if( ret != rc_normal )
                    return ret;
                switch( block )
                {
                    case block_xfit_proj_item:
                    {
                        LFProjectionItem& dst=out.GetLFProjectionItem().AddNew();
                        ret = LFProjectionItemIO::Read( dst, file );
                        if( ret != rc_normal )
                            return ret;
                        break;//block_xfit_proj_item
                    }
                    default:
                        ret = file.SkipBlock();
                        if( ret != rc_normal )
                            return ret;
                }
                break; //tag_block_start
            }
            case tag_block_end:
                return file.Skip( header.GetSize() ); //The block is over
            case tag_nchan:
            {
                int32_t buf;
                ret = file.Read< int32_t >( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetNumberOfChannels( buf );
                break; //tag_nchan
            }
            default:
                ret = file.Skip( header.GetSize() );
                if( ret != rc_normal )
                    return ret;
                break;
        }
        if( header.GetNext() < 0 )
            return ret;
    }
    return ret;
}
