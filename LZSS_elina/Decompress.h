#ifndef __DECOMPRESS_H
#define __DECOMPRESS_H
#pragma warning(disable : 4996)
//
// Decompress.h
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
// Total UnCompressed Size	4 bytes (1 ulong)
// Compressed Data			nn bytes (16 bit aligned)
// 



// Generic defines (same accross multiple Compressors, LZSS, LZP, etc)
#define	HS_COMP_FILE	0						// Source/Dest is a file
#define	HS_COMP_MEM		1						// Source/Dest is memory

#define HS_COMP_SafeFree(x) { if (x) free(x); }


// Alg ID
#define ALGID			"JB01"				// Algorithm ID (4 bytes)

// Error codes
#define	E_OK			0					// OK
#define E_NOTJB01		1					// Not a valid LZSS data stream
#define E_READINGSRC	2					// Error reading source file
#define E_WRITINGDST	3					// Error writing dest file
#define E_ABORTT		4					// Operation was aborted
#define E_MEMALLOC		5					// Couldn't allocate all the mem we needed


// Working block sizes
#define DATA_SIZE		(128*1024)			// UnCompressed buffer - must be >window+lookahead+1 and a POWER OF 2 (for ANDing)
#define DATA_MASK		(DATA_SIZE-1)	// AND mask (data size MUST be a power of 2)


// Define huffman and related
#define MMINMATCHLEN				3			// Minimum match length

#define	HHUFF_LITERAL_ALPHABETSIZE	(256 + 32)	// Number of characters to represent literals(256) + match lengths (32 match len codes, 0-511)
#define HHUFF_LITERAL_LENSTART		256			// Match lens are elements 256 and above in the literal alphabet

#define	HHUFF_OFFSET_ALPHABETSIZE	32			// Number of characters to represent offset codes (32 codes = 0-65535)

#define HHUFF_LITERAL_INITIALDELAY	(HHUFF_LITERAL_ALPHABETSIZE / 4)	// Literal trees are initially regenerated after this many codings
#define HHUFF_LITERAL_DELAY			(HHUFF_LITERAL_ALPHABETSIZE * 12)	// Literal trees are thereafter regenerated after this many codings

#define HHUFF_OFFSET_INITIALDELAY	(HHUFF_OFFSET_ALPHABETSIZE / 4)		// Offset trees are initially regenerated after this many codings
#define HHUFF_OFFSET_DELAY			(HHUFF_OFFSET_ALPHABETSIZE * 12)	// Offset trees are thereafter regenerated after this many codings

#define	HHUFF_LITERAL_FREQMOD		1			// Frequency modifier for old values
#define	HHUFF_OFFSET_FREQMOD		1			// Frequency modifier for old values

#define HHUFF_MAXCODEBITS			16			// Maximum number of bits for a huffman code (must be <= 16)

typedef struct HHuffmanDecompNode
{
	ulong	nFrequency;						// Frequency value
	bool	bSearchMe;
	uint	nParent;
	uint	nChildLeft;						// Left child node or NULL
	uint	nChildRight;					// Right child node or NULL
	u_char	cValue;

} _HHuffmanDecompNode;


// Monitor function declaration
typedef int (*MMonitorProc)(ulong nBytesIn, ulong nBytesOut, uint nPercentComplete);




class Decompress
{
public:
	// Functions
	Decompress() { SetDefaults(); }		// Constructor

	int		DDecompress();

	void	SetDefaults(void);
	void	SetInputType(uint nInput) { m_nInputType = nInput; }
	void	SetOutputType(uint nOutput) { m_nOutputType = nOutput; }
	void	SetInputFile(const char *szSrc) { strcpy(m_szSrcFile, szSrc); }
	void	SetOutputFile(const char *szDst) { strcpy(m_szDstFile, szDst); }
	void	SetInputBuffer(u_char *bBuf) { m_bUserCompData = bBuf; }
	void	SetOutputBuffer(u_char *bBuf) { m_bUserData = bBuf; }
	void	SetMonitorCallback(MMonitorProc lpfnMonitor) { m_lpfnMonitor = lpfnMonitor; }
	
	ulong	GetDecompressedSize(void);
	
	// Monitor functions
	uint	GetPercentComplete(void) { return ((uint)(((double)m_nUserDataPos/(double)m_nDataSize) * 100.0)); }

private:
	// User supplied buffers and counters
	u_char	*m_bUserData;						// When Compressing from memory this is the user input buffer
	u_char	*m_bUserCompData;					// When Compressing to memory this is the user output buffer
	ulong	m_nUserDataPos;						// Position in user unCompressed stream (also used for info)
	ulong	m_nUserCompPos;						// Position in user Compressed stream (also used for info)

	// Master variables
	ulong	m_nDataSize;						// TOTAL file unCompressed size

	uint	m_nInputType, m_nOutputType;		// File or memory output and input
	FILE	*m_fSrc, *m_fDst;					// Source and destination filepointers
	char	m_szSrcFile[_MAX_PATH+1];
	char	m_szDstFile[_MAX_PATH+1];

	u_char	*m_bData;
	ulong	m_nDataPos;							// Position in output stream
	ulong	m_nDataUsed;						// How much current info is in the data buff
	ulong	m_nDataWritePos;					// Where new data should be written from


	// Misc
	bool	m_bAbortRequested;

	// Temporary variables used for the bit operations
	ulong	m_nCompressedLong;					// Compressed stream temporary 32bit value
	int		m_nCompressedBitsUsed;				// Number of bits used in temporary value

	// Huffman variables
	struct	HHuffmanDecompNode *m_HuffmanLiteralTree;		// The huffman literal/len tree
	ulong	m_nHuffmanLiteralsLeft;				// Number of literals before huffman regenerated
	bool	m_bHuffmanLiteralFullyActive;
	ulong	m_nHuffmanLiteralIncrement;
		
	struct	HHuffmanDecompNode *m_HuffmanOffsetTree;		// The huffman offset tree
	ulong	m_nHuffmanOffsetsLeft;				// Number of literals before huffman regenerated
	bool	m_bHuffmanOffsetFullyActive;
	ulong	m_nHuffmanOffsetIncrement;

	// Monitor variables and related
	MMonitorProc m_lpfnMonitor;				// The monitor callback function (or NULL)


	// Functions
	int		AllocMem(void);
	void	FreeMem(void);
	int		ReadUserCompHeader(ulong &nSize);
	void	WriteUserData(void);

	int		DecompressBlock(ulong nDataSize);
	int		DecompressLoop(void);

	// Bit operation functions
	inline	uint	CompressedStreamReadBits(uint nNumBits);
	inline	uint	CompressedStreamReadLiteral(void);
	inline	uint	CompressedStreamReadLen(uint nCode);
	inline	uint	CompressedStreamReadOffset(void);
	inline	uint	CompressedStreamReadHuffman(HHuffmanDecompNode *HuffTree, uint nAlphabetSize);


	// Huffman functions
	void	HuffmanInit(void);
	void	HuffmanZero(HHuffmanDecompNode *HuffTree, uint nAlphabetSize);	// Clears the frequencies in the huffman tree
	void	HuffmanGenerate(HHuffmanDecompNode *HuffTree, uint nAlphabetSize, uint nFreqMod);

	// Monitor functions
	inline	void	MonitorCallback(void);
};


#endif
