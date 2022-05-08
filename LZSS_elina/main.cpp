// Test exe file for Compression classes - very untidy code only used
// for testing Compression functions quickly
//
// CONSOLE APP
//
// (c)2002-2003 Jonathan Bennett, jon@hiddensoft.com
//

#include <cstdio>
#include <string>
#include <iostream>
#include "Compress.h"
#include "Decompress.h"
#include "Stat.h"
#include "main.h"

using namespace std;
///////////////////////////////////////////////////////////////////////////////
// CompressMonitorProc() - The callback function
///////////////////////////////////////////////////////////////////////////////
int Decomproc(Decompress &oDecompress, const string &inputf, const string &outputf, int key);

int Comproc(Compress &oCompress, const string &inputf, const string &outputf, int key);
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
        wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
        wstring wide = converter.from_bytes(szFile);
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

void readFile(string fileName) {
//    FILE *file;
    char c;
    vector<char> bytes;
    ifstream input_file(fileName);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << fileName << "'" << endl;
        return;
    }
    while (input_file.get(c)) {
        bytes.push_back(c);
    }
    for (const auto &i : bytes) {
        printbincharpad(i);
    }
    cout << endl;
    input_file.close();
}

///////////////////////////////////////////////////////////////////////////////
// main()
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
    // size_t		nCompressedSize;
    // size_t		nUnCompressedSize;
    clock_t start, end;
    int encode = 1;

    Compress oCompress;      // Our Compression class
    Decompress oDecompress;  // Our deCompression class


    string filesArray[6] = {
//            "../text/sam/sam_copy.txt",
            "../text/english/english.50MB",
//            "../text/pitches/pitches.50MB",
//            "../text/dna/dna.50MB",
//            "../text/proteins/proteins.50MB",
//            "../text/sources/sources.50MB",
//            "../text/xml/xml.50MB"
    };
    string decodedFilesArray[6] = {
//            "../text/sam/decode_output.txt",
            "../text/english/decode_output.txt",
//            "../text/pitches/decode_output.txt",
//            "../text/dna/decode_output.txt",
//            "../text/proteins/decode_output.txt",
//            "../text/sources/decode_output.txt",
//            "../text/xml/decode_output.txt"
    };
    string encodedFilesArray[6] = {
//            "../text/sam/encode_output_m",
            "../text/english/encode_output",
//            "../text/pitches/encode_output",
//            "../text/dna/encode_output",
//            "../text/proteins/encode_output",
//            "../text/sources/encode_output",
//            "../text/xml/encode_output"
    };

    for (int i = 0; i < 1; ++i) {
        string originalFile = filesArray[i];
        string encodedFile = encodedFilesArray[i];
        string decodedFile = decodedFilesArray[i];
//        if (encode) {
            start = clock();
            Comproc(oCompress, originalFile, encodedFile, INT32_MAX);
            end = clock();
            u_long originalFileSize = getSize(originalFile);
            u_long encodedFileSize = getSize(encodedFile);
            double compressionRatio = (double) encodedFileSize / (double) originalFileSize;
            printf("\033[0;32m");
            cout << originalFile.substr(8) << endl;
            printf("\033[0;37m");
            printf("Input file size: %20ld\n", originalFileSize);
            printf("compressed file size: %15ld\n", encodedFileSize);
            printf("compression ratio: %15.2lf%%\n", compressionRatio * 100);
            printf("compression time: %15.2lf sec\n", ((double) (end - start)) / CLOCKS_PER_SEC);

//        } else {
            start = clock();
            Decomproc(oDecompress, encodedFile, decodedFile, INT32_MAX);
            end = clock();
            printf("\033[0;32m");
            cout << originalFile.substr(8) << endl;
            printf("\033[0;37m");
            printf("decompression time: %15.2lf sec\n", ((double) (end - start)) / CLOCKS_PER_SEC);
//        }
        printf("\n");
    }



//    string ccc = "-c";
//    // Compress file to file function
//    if ((argc == 4) && !ccc.compare(argv[1])) {
//        const string inputf = argv[2];
//        const string outputf = argv[3];
//        return Comproc(oCompress, inputf, outputf);
//    }
//
//    // UnCompress file to file function
//    string ddd = "-d";
//    if ((argc == 4) && !ddd.compare(argv[1])) {
//        const string inputf = argv[2];
//        const string outputf = argv[3];
//
//        return Decomproc(oDecompress, inputf, outputf);
//    }
//
//    string ttt = "-t";
//    if ((argc == 3) && !ttt.compare(argv[1])) {
//        string inputf = argv[2];
//        string outputf = inputf + ".out";
//        Comproc(oCompress, inputf, outputf);
//        inputf = outputf;
//        outputf = string(argv[2]) + "re.txt";
//        return Decomproc(oDecompress, inputf, outputf);
//    }

//    readFile("../text/sam/encode_output");

    // If we got here, invalid parameters
//    printf("Usage: %s <-c | -d> <infile> <outfile>\n", argv[0]);
//    printf("  -c performs file to file Compression\n");
//    printf("  -d performs file to file deCompression\n");

    return 0;
}

int Comproc(Compress &oCompress, const string &inputf, const string &outputf, const int key) {
    // How big is the source file?
//    auto nUnCompressedSize = getSize(inputf);
//    cout << inputf << "\t";  // " Input file size      :  " << nUnCompressedSize << endl;
    // Do the Compression
    oCompress.SetDefaults();
    oCompress.SetInputType(HS_COMP_FILE);
    oCompress.SetOutputType(HS_COMP_FILE);
    oCompress.SetInputFile(inputf.c_str());
    oCompress.SetOutputFile(outputf.c_str());
    // oCompress.SetMonitorCallback(&CompressMonitorProc);
    oCompress.SetCompressionLevel(3);
//    if (key != INT32_MAX)
//        oCompress.SetKey(key);
    Timer tmer;
    auto nRes = oCompress.CCompress();
//    auto scnds = tmer.elapsed();
//    auto nComprSize = getSize(outputf);
    // printf("\rCompressed           : %d%% (%d%%)  ", oCompress.GetPercentComplete(),
    //	(uint)(100 - ((nComprSize / (float)nUnCompressedSize) * 100.0)));
//    printf("\nCtime     : %.fms \t", scnds);

    if (nRes != E_OK) {
        printf("Error Compressing.\n");
        return 0;
    }

    // Print the output size
    // printf("Output file size     : %d\n", nComprSize );
//    printf("Ratio    : %.3f%%\t", ((nComprSize / (float) nUnCompressedSize) * 100.0));
    //	printf("Compression ratio    : %.3f bpb\n", (nComprSize * 8.0) / (float)nUnCompressedSize);

    return 0;
}

int Decomproc(Decompress &oDecompress, const string &inputf, const string &outputf, const int key) {
    // Do the unCompression
    oDecompress.SetDefaults();
//    auto nCompressedSize = getSize(inputf);
    // cout << "Input file size      : " << nCompressedSize << endl;
    oDecompress.SetInputType(HS_COMP_FILE);
    oDecompress.SetOutputType(HS_COMP_FILE);
    oDecompress.SetInputFile(inputf.c_str());
    oDecompress.SetOutputFile(outputf.c_str());
//    if (key != INT32_MAX)
//        oDecompress.SetKey(key);
    // oDecompress.SetMonitorCallback(&DecompressMonitorProc);
//    Timer tmer;
    auto nRes = oDecompress.DDecompress();
//    auto mscnd = tmer.elapsed();
    // printf("\rDecompressed         : %d%%  ", oDecompress.GetPercentComplete());
//    printf("\tDtime     : %.fms \n", mscnd);
    if (nRes != E_OK) {
        cout << "Error unCompressing.\n";
        return 0;
    }
    // Print filesize
    // cout << "Output file size     : " << getSize(outputf) << endl;

    return 0;
}
