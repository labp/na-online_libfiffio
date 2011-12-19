
#include "LFHPICoilIO.h"
#include "LFHPISubsystemIO.h"

returncode_t LFHPISubsystemIO::Read( LFHPISubsystem& out, LFFileFIFF& file )
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
//                    case block_hpi_coil:
//                    {
//                        LFHPICoil& dst=out.GetLFHPICoil().AddNew();
//                        ret = LFHPICoilIO::Read( dst, file );
//                        if( ret != rc_normal )
//                            return ret;
//                        break;//block_hpi_coil
//                    }
                    default:
                        ret = file.SkipBlock();
                        if( ret != rc_normal )
                            return ret;
                }
                break; //tag_block_start
            }
            case tag_block_end:
                return file.Skip( header.GetSize() ); //The block is over
            case tag_hpi_ncoil:
            {
                int32_t buf;
                ret = file.Read< int32_t >( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetNumberOfHPICoils( buf );
                break; //tag_hpi_ncoil
            }
            case tag_event_channel:
            {
                int32_t sz = header.GetSize();
                string& dst = out.GetEventChannel();
                dst.resize( sz );
                ret = file.ReadString( ( char* )dst.data(), sz );
                if( ret != rc_normal )
                    return ret;
                break; //tag_event_channel
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
