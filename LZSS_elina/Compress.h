#ifndef __cOMPRESS_H
#define __cOMPRESS_H
#pragma warning(disable : 4996)
//
// Compress.h
// (c)2002-2003 Jonathan Bennett (jon@hiddensoft.com)
//
// STANDALONE CLASS
//
// This is an implementation of LZSS Compression
//
// Note, this is a "as simple to follow as possible" piece of code, there are many
// more efficient and quicker (and cryptic) methods but this was done as a learning
// exercise.
//

//
// LICENSE
// This code is free to use, but please do me the decency of giving me credit :)
//

// The start of the Compression stream will contain "other" items apart from data.
//
// Algorithm ID				4 bytes
// Revision ID				1 byte
// Total UnCompressed Size	4 bytes (1 u_long)
// Compressed Data			nn bytes (16 bit aligned)
// 



#include <cstring>
#include <iostream>

#define _MAX_PATH 260




// Generic defines (same accross multiple Compressors, LZSS, LZP, etc)
#define    HS_COMP_FILE    0                        // Source/Dest is a file
#define    HS_COMP_MEM        1                        // Source/Dest is memory

#define HS_COMP_SafeFree(x) { if (x) free(x); }



// Alg ID
#define ALGID            "JB01"                // Algorithm ID (4 bytes)

// Error codes
#define    E_OK            0                    // OK
#define E_NOTJB01        1                    // Not a valid LZSS data stream
#define E_READINGSRC    2                    // Error reading source file
#define E_WRITINGDST    3                    // Error writing dest file
#define E_ABORTT        4                    // Operation was aborted
#define E_MEMALLOC        5                    // Couldn't allocate all the mem we needed


// Working block sizes (in bytes)
#define DATA_SIZE        (128*1024)            // UnCompressed buffer - must be >window+lookahead+1 and a POWER OF 2 (for ANDing)
#define DATA_MASK        (DATA_SIZE-1)    // AND mask (data size MUST be a power of 2)


// Define our hash and hash table structure
#define HHASHORDER        3                    // Order-3 hashing
#define HHASHTABLE_SIZE    65536                // Our hash function gives values 0-65535

typedef struct HHash {
    u_long nPos;                                // ABSOLUTE (non-ANDed) position in data stream
    struct HHash *lpNext;                    // Next entry in linked list or NULL
    struct HHash *lpPrev;

} _HHash;


// Define huffman and related
#define MMINMATCHLEN                3            // Minimum match length

#define    HHUFF_LITERAL_ALPHABETSIZE    (256 + 32)    // Number of characters to represent literals(256) + match lengths (32 match len codes, 0-511)
#define HHUFF_LITERAL_LENSTART        256            // Match lens are elements 256 and above in the literal alphabet
#define MMAXMATCHLEN                (511 + MMINMATCHLEN)    // Maximum match length (511 lengths over 32 codes)

#define    HHUFF_OFFSET_ALPHABETSIZE    32            // Number of characters to represent offset codes (32 codes = 0-65535)
#define MMAXWINDOWLENGTH            65535        // Sliding window size (must be <=65535)

#define HHUFF_LITERAL_INITIALDELAY    (HHUFF_LITERAL_ALPHABETSIZE / 4)    // Literal trees are initially regenerated after this many codings
#define HHUFF_LITERAL_DELAY            (HHUFF_LITERAL_ALPHABETSIZE * 12)    // Literal trees are thereafter regenerated after this many codings

#define HHUFF_OFFSET_INITIALDELAY    (HHUFF_OFFSET_ALPHABETSIZE / 4)        // Offset trees are initially regenerated after this many codings
#define HHUFF_OFFSET_DELAY            (HHUFF_OFFSET_ALPHABETSIZE * 12)    // Offset trees are thereafter regenerated after this many codings

#define    HHUFF_LITERAL_FREQMOD        1            // Frequency modifier for old values
#define    HHUFF_OFFSET_FREQMOD        1            // Frequency modifier for old values

#define HHUFF_MAXCODEBITS            16            // Maximum number of bits for a huffman code (must be <=16 for bitwriting functions)

typedef struct HHuffmanNode {
    u_long nFrequency;                            // Frequency value
    bool bSearchMe;
    uint nParent;
    uint nChildLeft;                            // Left child node or NULL
    uint nChildRight;                        // Right child node or NULL
    u_char cValue;

} _HHuffmanNode;

typedef struct HHuffmanOutput {
    uint nNumBits;                            // Code length
    u_long nCode;                                // Code (max 32bits)
} _HHuffmanOutput;


// Monitor function declaration
typedef int (*MMonitorProc)(u_long nBytesIn, u_long nBytesOut, uint nPercentComplete);


class Compress {
public:
    // Functions
    Compress() { SetDefaults(); }            // Constructor

    int CCompress();

    void SetDefaults(void);

    void SetInputType(uint nInput) { m_nInputType = nInput; }

    void SetOutputType(uint nOutput) { m_nOutputType = nOutput; }

    void SetInputFile(const char *szSrc) { strcpy(m_szSrcFile, szSrc); }

    void SetOutputFile(const char *szDst) { strcpy(m_szDstFile, szDst); }

    void SetInputBuffer(u_char *bBuf, u_long nSize) {
        m_bUserData = bBuf;
        m_nDataSize = nSize;
    }

    void SetOutputBuffer(u_char *bBuf) { m_bUserCompData = bBuf; }

    void SetCompressionLevel(uint nCompressionLevel);    // Set the hash chain limit
    void SetMonitorCallback(MMonitorProc lpfnMonitor) { m_lpfnMonitor = lpfnMonitor; }

    //u_long	GetCompressedSize(void) { return m_nUserCompPos; }

    // Monitor functions
    uint GetPercentComplete(void) { return ((uint) (((double) m_nUserDataPos / (double) m_nDataSize) * 100.0)); }

private:
    // User supplied buffers and counters
    u_char *m_bUserData;                        // When Compressing from memory this is the user input buffer
    u_char *m_bUserCompData;                    // When Compressing to memory this is the user output buffer
    u_long m_nUserDataPos;                        // Position in user unCompressed stream (also used for info)
    u_long m_nUserCompPos;                        // Position in user Compressed stream (also used for info)

    // Master variables
    u_long m_nDataSize;                        // TOTAL file unCompressed size

    uint m_nInputType, m_nOutputType;        // File or memory output and input

    FILE *m_fSrc, *m_fDst;                    // Source and destination filepointers
    char m_szSrcFile[_MAX_PATH + 1];
    char m_szDstFile[_MAX_PATH + 1];

    u_char *m_bData;
    u_long m_nDataPos;                            // Position in input stream
    u_long m_nLookAheadSize;                    // How "lookahead" data is available
    u_long m_nDataReadPos;                        // Where new data should be read into

    u_char *m_bComp;
    u_long m_nCompPos;                            // Temp position holder for internal Compressed data buffer


    // Misc
    bool m_bAbortRequested;

    // Temporary variables used for the bit operations
    u_long m_nCompressedLong;                    // Compressed stream temporary 32bit value
    u_short m_nCompressedBitsFree;                // Number of bits unused in temporary value

    // Hash table related variables
    uint m_nHashChainLimit;                    // The max length of each hash chain
    struct HHash **m_HashTable;            // Hash table
    uint *m_HashChainCounts;                    // Number of entries in each hash chain
    uint m_nHashEntriesMax;                    // Maximum number of hash entries allowed
    uint m_nHashEntriesFree;                    // Number of free hash positions we have
    void *m_HashEntryMemPool;                // Pointer to the single block of memory allocated
    struct HHash **m_HashMemAllocTable;    // Our table to keep track of memory allocated


    // Huffman variables
    struct HHuffmanNode *m_HuffmanLiteralTree;        // The huffman literal/len tree
    struct HHuffmanOutput *m_HuffmanLiteralOutput;    // Output buffer for chars
    u_long m_nHuffmanLiteralsLeft;                // Number of literals before huffman regenerated
    bool m_bHuffmanLiteralFullyActive;
    u_long m_nHuffmanLiteralIncrement;

    struct HHuffmanNode *m_HuffmanOffsetTree;        // The huffman offset tree
    struct HHuffmanOutput *m_HuffmanOffsetOutput;    // Output buffer for chars
    u_long m_nHuffmanOffsetsLeft;                // Number of literals before huffman regenerated
    bool m_bHuffmanOffsetFullyActive;
    u_long m_nHuffmanOffsetIncrement;

    // Monitor variables and related
    MMonitorProc m_lpfnMonitor;                // The monitor callback function (or NULL)


    // Functions
    u_long GetFileSize(const char *szFile);

    int AllocMem(void);

    void FreeMem(void);

    inline void WriteUserCompData(void);        // Write Compressed data to file/mem
    inline void ReadUserData(void);                // Read data from file or memory

    int CompressLoop(void);                    // The main Compression loop
    int CompressLoopDecode(void);                    // The main Compression loop
    void
    FindMatches(u_long nInitialDataPos, u_long &nOffset, uint &nLen, uint nBestLen);    // Searches for pattern matches


    // Bit operation functions
    inline void CompressedStreamWriteBits(uint nValue, uint nNumBits);

    void CompressedStreamWriteBitsFlush(void);

    inline void CompressedStreamWriteLiteral(uint nChar);

    inline void CompressedStreamWriteLen(uint nChar);

    inline void CompressedStreamWriteOffset(uint nOffset);

    // Hash table functions
    void HashTableInit(void);                // Make hash table ready for first use
    inline void HashTableAdd(uint nBytes);            // Add an entry to the table

    // Huffman functions
    void HuffmanInit(void);

    void HuffmanZero(HHuffmanNode *HuffTree, uint nAlphabetSize);    // Clears the frequencies in the huffman tree
    void HuffmanGenerate(HHuffmanNode *HuffTree, HHuffmanOutput *HuffOutput, uint nAlphabetSize, uint nFreqMod);

    // Monitor functions
    inline void MonitorCallback(void);
};


#endif
