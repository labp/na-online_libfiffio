#ifndef LFELEMENTHEADER_H
#define LFELEMENTHEADER_H

#include <inttypes.h>
#include <stdio.h>

#include "LFReturnCodes.h"
#include "LFTags.h"
#include "LFBlocks.h"
/**
 * FIFF - Element header
 */
class LFElementHeader
{
    friend class LFFileFIFF;
protected:
    int32_t m_tag;/**< The kind of data stored, default is -1 */
    int32_t m_type;/**< The data type of the contents, default is -1 */
    int32_t m_size;/**< Number of bytes in the data member, default is -1 */
    /**
     * Location of the next tag in the file.
     * If this value is 0 , the next tag follows sequentially.
     * If the value is -1 the list of tags ends here (default).
     * Otherwise next indicates the byte position of the next tag in the file.
     */
    int32_t m_next;
public:
    /**
     * Constructor
     */
    LFElementHeader();
    /**
     * Sets all member variables to default
     */
    void Init();
    /**
     * Returns the tag number, default is -1
     */
    int32_t GetTag();
    /**
     * Returns the data type of the contents, default is -1
     */
    int32_t GetType();
    /**
     * Returns the number of bytes in the data member, default is -1
     */
    int32_t GetSize();
    /**
     * Returns the location of the next tag in the file, default is -1
     */
    int32_t GetNext();
};

#endif //LFELEMENTHEADER_H
