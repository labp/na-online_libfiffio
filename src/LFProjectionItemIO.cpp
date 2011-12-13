
#include "LFProjectionItemIO.h"

returncode_t LFProjectionItemIO::Read( LFProjectionItem& out, LFFileFIFF& file )
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
                    default:
                        ret = file.SkipBlock();
                        if( ret != rc_normal )
                            return ret;
                }
                break; //tag_block_start
            }
            case tag_block_end:
                return file.Skip( header.GetSize() ); //The block is over
            case tag_description:
            {
                int32_t sz = header.GetSize();
                string& dst = out.GetDescription();
                dst.resize( sz );
                ret = file.ReadString( ( char* )dst.data(), sz );
                if( ret != rc_normal )
                    return ret;
                break; //tag_description
            }
            case tag_proj_item_kind:
            {
                int32_t buf;
                ret = file.Read< int32_t >( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetKind( ( LFProjectionItem::proj_item_t )buf );
                break; //tag_proj_item_kind
            }
            case tag_nchan:
            {
                int32_t buf;
                ret = file.Read< int32_t >( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetNumberOfChannels( buf );
                break; //tag_nchan
            }
            case tag_proj_item_ch_name_list:
            {
                int32_t sz = header.GetSize();
                string& dst = out.GetChannelNameList();
                dst.resize( sz );
                ret = file.ReadString( ( char* )dst.data(), sz );
                if( ret != rc_normal )
                    return ret;
                break; //tag_proj_item_ch_name_list
            }
            case tag_proj_item_time:
            {
                float buf;
                ret = file.Read< float >( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetTime( buf );
                break; //tag_proj_item_time
            }
            case tag_proj_item_vectors:
            {
                int32_t sz=header.GetSize();
                LFArrayFloat2d & dst=out.GetProjectionVectors();
                dst.AllocateBytes(sz);
                ret = file.ReadArrayFloat( ( float* )dst.data(), sz );
                if( ret != rc_normal )
                    return ret;
                break;//tag_proj_item_vectors
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
