#include "LFRawDataIO.h"

returncode_t LFRawDataIO::Read( LFRawData& out, LFFileFIFF& file )
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
            case tag_first_sample:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetFirstSample( buf );
                break;//tag_first_sample
            }
            case tag_data_skip:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetDataSkip( buf );
                break;//tag_data_skip
            }
            case tag_data_skip_samp:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetDataSkipSamples( buf );
                break;//tag_data_skip_samp
            }
            case tag_data_buffer:
            {
                int32_t sz = header.GetSize();
                LFDataBuffer& dst = out.GetLFDataBuffer().AddNew();
                dst.Allocate( ( LFDataBuffer::datatype_t )header.GetType(), sz );
                switch( dst.GetDataType() )
                {
                    case LFDataBuffer::dt_int16:
                        ret = file.ReadArrayInt16( dst.GetBufferInt16()->data(), sz );
                        if( ret != rc_normal )
                            return ret;
                        break;
                    case LFDataBuffer::dt_int32:
                        ret = file.ReadArrayInt32( dst.GetBufferInt32()->data(), sz );
                        if( ret != rc_normal )
                            return ret;
                        break;
                    case LFDataBuffer::dt_float:
                        ret = file.ReadArrayFloat( dst.GetBufferFloat()->data(), sz );
                        if( ret != rc_normal )
                            return ret;
                        break;
                    default:
                        return rc_error_unknown;
                }
                break;//tag_data_buffer
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
