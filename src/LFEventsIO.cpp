
#include "LFEventsIO.h"

returncode_t LFEventsIO::Read( LFEvents& out, LFFileFIFF& file )
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
            case tag_event_channels:
            {
                int32_t sz = header.GetSize();
                vector< int32_t >& dst = out.GetEventChannels();
                dst.resize( sz / sizeof(float) );
                ret = file.ReadArrayInt32( ( int32_t* )dst.data(), sz );
                if( ret != rc_normal )
                    return ret;
                break;//tag_event_channels
            }
            case tag_event_list:
            {
                int32_t sz = header.GetSize();
                out.AllocateEventListBytes(sz);
                ret = file.ReadArrayInt32( out.GetEventListElement(), sz );
                if( ret != rc_normal )
                    return ret;
                break;//tag_event_list
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
