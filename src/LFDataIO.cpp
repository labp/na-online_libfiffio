#include "LFDataIO.h"

returncode_t LFDataIO::Read( LFData& out, LFFileFIFF& file )
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
                switch( block )
                {
                    case block_meas:
                        ret = LFMeasurementIO::Read( out.GetLFMeasurement(), file );
                        if( ret != rc_normal )
                            return ret;
                        break;//block_meas
                    default:
                        ret = file.SkipBlock();
                        if( ret != rc_normal )
                            return ret;
                        break;
                }
                break;//tag_block_start
            }
            case tag_block_end:
                return file.Skip( header.GetSize() );//The block is over
            default:
                file.Skip( header.GetSize() );
                break;
        }
        if(header.GetNext()<0)return ret;
    }
    return ret;
}

returncode_t LFDataIO::Read( LFSubject& out, LFFileFIFF& file )
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
                switch( block )
                {
                    case block_meas:
                    case block_meas_info:
                        break;//block_meas,block_meas_info
                    case block_subject:
                        ret = LFSubjectIO::Read( out, file );
                        return ret;//block_subject
                    default:
                        ret = file.SkipBlock();
                        if( ret != rc_normal )
                            return ret;
                        break;
                }
                break;//tag_block_start
            }
            case tag_block_end:
                return file.Skip( header.GetSize() );//The block is over
            default:
                file.Skip( header.GetSize() );
                break;
        }
        if(header.GetNext()<0)return ret;
    }
    return ret;
}

returncode_t LFDataIO::Read( LFRawData& out, LFFileFIFF& file )
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
                switch( block )
                {
                    case block_meas:
                        break;//block_meas
                    case block_raw_data:
                        ret = LFRawDataIO::Read( out, file );
                        return ret;//block_raw_data
                    default:
                        ret = file.SkipBlock();
                        if( ret != rc_normal )
                            return ret;
                        break;
                }
                break;//tag_block_start
            }
            case tag_block_end:
                return file.Skip( header.GetSize() );//The block is over
            default:
                file.Skip( header.GetSize() );
                break;
        }
        if(header.GetNext()<0)return ret;
    }
    return ret;
}
