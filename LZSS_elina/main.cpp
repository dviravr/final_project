// Test exe file for Compression classes - very untidy code only used
// for testing Compression functions quickly
//
// CONSOLE APP
//
// (c)2002-2003 Jonathan Bennett, jon@hiddensoft.com
//

#include <stdio.h>
// #include <conio.h>
// #include <windows.h>
// #include <mmsystem.h>
#include <codecvt>
#include <string>
#include <iostream>
#include "Compress.h"
#include "Decompress.h"
#include "Stat.h"
#include "main.h"
///////////////////////////////////////////////////////////////////////////////
// CompressMonitorProc() - The callback function
///////////////////////////////////////////////////////////////////////////////
int Decomproc(Decompress& oDecompress, const std::string& inputf, const std::string& outputf);

int Comproc(Compress& oCompress, const std::string& inputf, const std::string& outputf);
/*
int CompressMonitorProc(u_long nBytesIn, u_long nBytesOut, uint nPercentComplete)
{
        static	uint	nDelay = 0;
        static	uint	nRot = 0;
        char	szGfx[]= "-\\|/";
        u_char	ch;

//	if (nDelay > 16)
//	{
                nDelay = 0;
                nRot = (nRot+1) & 0x3;
                printf("\rCompressing %c        : %d%% (%d%%)  ", szGfx[nRot], nPercentComplete, 100-((100*nBytesOut) / nBytesIn));

//	}
//	else
//		nDelay++;

        // Check if ESC was pressed and if so request stopping
        if (kbhit())
        {
                ch = getch();
                if (ch == 0)
                        ch = getch();
                if (ch == 27)
                        return 0;
        }

        return 1;

} // CompressProc()
*/

///////////////////////////////////////////////////////////////////////////////
// DeompressMonitorProc() - The callback function
///////////////////////////////////////////////////////////////////////////////

int DecompressMonitorProc(u_long nBytesIn, u_long nBytesOut, uint nPercentComplete) {
    static uint nDelay = 0;
    static uint nRot = 0;
    char szGfx[] = "-\\|/";
    u_char ch;

    //	if (nDelay > 16)
    //	{
    nDelay = 0;
    nRot = (nRot + 1) & 0x3;
    printf("\rDecompressing %c      : %d%%  ", szGfx[nRot], nPercentComplete);
    //	}
    //	else
    //		nDelay++;

    // // Check if ESC was pressed and if so request stopping
    // if (kbhit())
    // {
    // 	ch = getch();
    // 	if (ch == 0)
    // 		ch = getch();
    // 	if (ch == 27)
    // 		return 0;
    // }

    return 1;

}  // DecompressMonitorProc()

///////////////////////////////////////////////////////////////////////////////
// mainGetFileSize()
//
// Uses Win32 functions to quickly get the size of a file (rather than using
// fseek/ftell which is slow on large files
//
// Use BEFORE opening a file! :)
//
///////////////////////////////////////////////////////////////////////////////
/*
u_long mainGetFileSize(const char *szFile)
{
        HANDLE	hFile;
        u_long	nSize;
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring wide = converter.from_bytes(szFile);
        LPCWSTR f = wide.c_str();

        hFile = CreateFile(f, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        if (hFile == INVALID_HANDLE_VALUE)
                return 0;

        nSize = GetFileSize(hFile, NULL);

        CloseHandle(hFile);

        return nSize;

} // mainGetFileSize()
*/


void printbincharpad(char c) {
    for (int i = 7; i >= 0; --i) {
        putchar((c & (1 << i)) ? '1' : '0');
    }
//    putchar(' ');
}

void readFile(char *fileName) {
    FILE *file;
    char c;
    file = fopen(fileName, "rb");
    while ((c = fgetc(file)) != EOF) {
        printbincharpad(c);
    }
//    printbincharpad(c);
//    while ((c = fgetc(file)) != EOF) {
//        printbincharpad(c);
//    }
}

///////////////////////////////////////////////////////////////////////////////
// main()
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
    // size_t		nCompressedSize;
    // size_t		nUnCompressedSize;

    Compress oCompress;      // Our Compression class
    Decompress oDecompress;  // Our deCompression class
	std::string ccc = "-c";
    // Compress file to file function
    if ((argc == 4) && !ccc.compare(argv[1])) {
        const std::string inputf = argv[2];
        const std::string outputf = argv[3];
        return Comproc(oCompress, inputf, outputf);
    }

    // UnCompress file to file function
	std::string ddd = "-d";
    if ((argc == 4) && !ddd.compare(argv[1])) {
        const std::string inputf = argv[2];
        const std::string outputf = argv[3];

        return Decomproc(oDecompress, inputf, outputf);
    }

	std::string ttt = "-t";
    if ((argc == 3) && !ttt.compare(argv[1])) {
        std::string inputf = argv[2];
        std::string outputf = inputf + ".out";
        Comproc(oCompress, inputf, outputf);
        inputf = outputf;
        outputf = std::string(argv[2]) + "re.txt";
        return Decomproc(oDecompress, inputf, outputf);
    }

    readFile("../text/sam/encoded");

    // If we got here, invalid parameters
    printf("Usage: %s <-c | -d> <infile> <outfile>\n", argv[0]);
    printf("  -c performs file to file Compression\n");
    printf("  -d performs file to file deCompression\n");

    return 0;
}

int Comproc(Compress& oCompress, const std::string& inputf, const std::string& outputf) {
    // How big is the source file?
    auto nUnCompressedSize = getSize(inputf);
    std::cout << inputf << "\t";  // " Input file size      :  " << nUnCompressedSize << std::endl;
    // Do the Compression
    oCompress.SetDefaults();
    oCompress.SetInputType(HS_COMP_FILE);
    oCompress.SetOutputType(HS_COMP_FILE);
    oCompress.SetInputFile(inputf.c_str());
    oCompress.SetOutputFile(outputf.c_str());
    // oCompress.SetMonitorCallback(&CompressMonitorProc);
    oCompress.SetCompressionLevel(3);
    Timer tmer;
    auto nRes = oCompress.CCompress();
    auto scnds = tmer.elapsed();
    auto nComprSize = getSize(outputf);
    // printf("\rCompressed           : %d%% (%d%%)  ", oCompress.GetPercentComplete(),
    //	(uint)(100 - ((nComprSize / (float)nUnCompressedSize) * 100.0)));
    printf("\nCtime     : %.fms \t", scnds);

    if (nRes != E_OK) {
        printf("Error Compressing.\n");
        return 0;
    }

    // Print the output size
    // printf("Output file size     : %d\n", nComprSize );
    printf("Ratio    : %.3f%%\t", ((nComprSize / (float)nUnCompressedSize) * 100.0));
    //	printf("Compression ratio    : %.3f bpb\n", (nComprSize * 8.0) / (float)nUnCompressedSize);

    return 0;
}

int Decomproc(Decompress& oDecompress, const std::string& inputf, const std::string& outputf) {
    // Do the unCompression
    oDecompress.SetDefaults();
    auto nCompressedSize = getSize(inputf);
    // std::cout << "Input file size      : " << nCompressedSize << std::endl;
    oDecompress.SetInputType(HS_COMP_FILE);
    oDecompress.SetOutputType(HS_COMP_FILE);
    oDecompress.SetInputFile(inputf.c_str());
    oDecompress.SetOutputFile(outputf.c_str());
    // oDecompress.SetMonitorCallback(&DecompressMonitorProc);
    Timer tmer;
    auto nRes = oDecompress.DDecompress();
    auto mscnd = tmer.elapsed();
    // printf("\rDecompressed         : %d%%  ", oDecompress.GetPercentComplete());
    printf("\tDtime     : %.fms \n", mscnd);
    if (nRes != E_OK) {
        std::cout << "Error unCompressing.\n";
        return 0;
    }
    // Print filesize
    // std::cout << "Output file size     : " << getSize(outputf) << std::endl;

    return 0;
}
