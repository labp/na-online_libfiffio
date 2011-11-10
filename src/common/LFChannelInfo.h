#ifndef LFCHANNELINFO_H
#define LFCHANNELINFO_H

#include <inttypes.h>
using namespace std;

/**
 * ch_info_t structure, contains information about one channel
 */
class LFChannelInfo
{
protected:
    int32_t m_ScanNo;///<Position of this channel in scanning order, default == -1
    int32_t m_LogNo;///<Logical channel number. These must be unique within channels of the same kind, default ==-1
    int32_t m_Kind;///<Kind of the channel described (MEG, EEG, EOG, etc.), default == -1
    float m_Range;///<The raw data values must be multiplied by this to get into volts at the electronics output, default == -FLT_MAX
public:
    /**
     * Constructor
     */
    LFChannelInfo();
    /**
     * Sets all member variables to defaults
     */
    void Init();
    /**
     * Returns position of this channel in scanning order
     */
    int32_t GetScanNo();
    /**
     * Returns logical channel number
     */
    int32_t GetLogNo();
    /**
     * Returns kind of the channel described (MEG, EEG, EOG, etc.)
     */
    int32_t GetKind();
    /**
     * Returns the multiplication coefficient
     */
    float GetRange();
    /**
     * Sets position of this channel in scanning order
     */
    void SetScanNo( const int32_t src );
    /**
     * Sets logical channel number
     */
    void SetLogNo( const int32_t src );
    /**
     * Sets kind of the channel described (MEG, EEG, EOG, etc.)
     */
    void SetKind( const int32_t src );
    /**
     * Sets the multiplication coefficient
     */
    void SetRange( const float src );
};
#endif
