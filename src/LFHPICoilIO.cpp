
#include <memory.h>
#include "LFHPICoilIO.h"

//bool LFHPICoilIO::Read( LFArrayPtr<LFHPICoil>& out, fiffDirNode parentdirnode, fiffFile& file )
//{
//    for(int i=0; i<parentdirnode->nchild; i++)
//    {
//        fiffDirNode dirnode=parentdirnode->children[i];
//        if(dirnode->type==FIFFB_HPI_COIL){
//            LFHPICoil& obj=out.AddNew();
//            Read(obj,dirnode,file);
//        }
//    }
//    return true;
//}

returncode_t LFHPICoilIO::Read( LFHPICoil& out, LFFileFIFF& file )
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

            case tag_hpi_coil_no:
            {
                int32_t buf;
                ret = file.Read< int32_t > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetCoilNumber( buf );
                 break;//tag_hpi_coil_no
            }
            case tag_epoch:
            {
                int32_t sz=header.GetSize();
                char* buf=new char[sz];
                ret=file.ReadString(buf,sz);
                if( ret != rc_normal ){
                    delete[] buf;
                    return ret;
                }
                LFArrayFloat2d & dst=out.GetEpoch();
                dst.AllocateBytes(sz);
                memcpy(dst.GetElement(),buf,sz);
                delete[] buf;
                break;//tag_epoch
            }
            case tag_hpi_slopes:
            {
                int32_t sz=header.GetSize();
                char* buf=new char[sz];
                ret=file.ReadString(buf,sz);
                if( ret != rc_normal ){
                    delete[] buf;
                    return ret;
                }
                vector< float >& dst=out.GetSlopes();
                sz=sz/sizeof(float);
                dst.resize(sz);
                for(int32_t i=0; i<sz; i++)LFFileFIFF::swab(( ( const float* )buf )[i]);
                for(int32_t i=0; i<sz; i++)dst[i]=( ( const float* )buf )[i];
                break;//tag_hpi_slopes
            }
//            case tag_hpi_corr_coeff:
//            {
//                vector< float >& dst=out.GetCorrelationCoefficient();
//                size_t sz=tag.size/sizeof(float);
//                dst.resize(sz);
//                for(size_t i=0; i<sz; i++)dst[i]=*( ( const float* )tag.data );
//            }
//            break;//tag_hpi_corr_coeff
            case tag_hpi_coil_freq:
            {
                float buf;
                ret = file.Read< float > ( buf );
                if( ret != rc_normal )
                    return ret;
                out.SetCoilFrequency( buf );
                 break;//tag_hpi_coil_freq
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
