// Test exe file for Compression classes - very untidy code only used
// for testing Compression functions quickly
//
// CONSOLE APP
//
// (c)2002-2003 Jonathan Bennett, jon@hiddensoft.com
//

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Compress.h"
#include "Decompress.h"
#include "Stat.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// CompressMonitorProc() - The callback function
///////////////////////////////////////////////////////////////////////////////
int Decomproc(Decompress &oDecompress, const string &inputf, const string &outputf, uint key);

int Comproc(Compress &oCompress, const string &inputf, const string &outputf, uint key);

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

bool isNumber(char str[]) {
    for (int i = 0; i < strlen(str); ++i) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////
// main()
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
    Compress oCompress;      // Our Compression class
    Decompress oDecompress;  // Our deCompression class

    string compressFlag = "-c";
    string decompressFlag = "-d";
    string bothFlag = "-t";
    string keyFlag = "-k";
    uint key = UINT32_MAX;

    // Compress file to file function
    if ((argc >= 4) && compressFlag == argv[1]) {
        if (argc == 6) {
            if (keyFlag == argv[4] && isNumber(argv[5])) {
                key = (uint) stoi(argv[5]);
            } else {
                cout << "Usage of key: -k <key>. key must be numeric" << endl;
                return 0;
            }
        }
        const string inputf = argv[2];
        const string outputf = argv[3];
        return Comproc(oCompress, inputf, outputf, key);
    }

    // UnCompress file to file function
    if ((argc >= 4) && decompressFlag == argv[1]) {
        if (argc == 6) {
            if (keyFlag == argv[4] && isNumber(argv[5])) {
                key = (uint) stoi(argv[5]);
            } else {
                cout << "Usage of key: -k <key>. key must be numeric" << endl;
                return 0;
            }
        }
        const string inputf = argv[2];
        const string outputf = argv[3];

        return Decomproc(oDecompress, inputf, outputf, key);
    }


    if ((argc >= 3) && bothFlag == argv[1]) {
        if (argc == 5) {
            if (keyFlag == argv[3] && isNumber(argv[4])) {
                key = (uint) stoi(argv[4]);
            } else {
                cout << "Usage of key: -k <key>. key must be numeric" << endl;
                return 0;
            }
        }
        string inputf = argv[2];
        string outputf = inputf + ".out";
        Comproc(oCompress, inputf, outputf, key);
        inputf = outputf;
        outputf = string(argv[2]) + "re.txt";
        return Decomproc(oDecompress, inputf, outputf, key);
    }

    // If we got here, invalid parameters
    cout << "Usage: " << argv[0] << " <-c | -d> <infile> <outfile>" << endl;
    cout << "  -c performs Compression to infile" << endl;
    cout << "  -d performs deCompression to infile" << endl;
    cout << "Or: " << argv[0] << " <-t> <infile>" << endl;
    cout << "  -t performs Compression and deCompression to infile" << endl;
    cout << "Optional: -k <key>" << endl;
    cout << "  -k perform encoded/decoded to the Compression/deCompression file with the specific key (numeric)"
         << endl;

    return 0;
}

int Comproc(Compress &oCompress, const string &inputf, const string &outputf, uint key) {
    // How big is the source file?
    auto nUnCompressedSize = getSize(inputf);
    cout << inputf << "\t" << " Input file size      :  " << nUnCompressedSize << endl;
    // Do the Compression
    oCompress.SetDefaults();
    oCompress.SetInputType(HS_COMP_FILE);
    oCompress.SetOutputType(HS_COMP_FILE);
    oCompress.SetInputFile(inputf.c_str());
    oCompress.SetOutputFile(outputf.c_str());
    oCompress.SetCompressionLevel(3);
    if (key != UINT32_MAX)
        oCompress.SetKey(key);
    Timer tmer;
    auto nRes = oCompress.CCompress();
    auto scnds = tmer.elapsed();
    auto nComprSize = getSize(outputf);
    printf("\rCompressed           : %d%% (%d%%)  ", oCompress.GetPercentComplete(),
           (uint) (100 - (((float) nComprSize / (float) nUnCompressedSize) * 100.0)));
    printf("\nCtime     : %.fms \t", scnds);

    if (nRes != E_OK) {
        printf("Error Compressing.\n");
        return 0;
    }

    // Print the output size
    printf("Output file size     : %lu\n", nComprSize);
    printf("Ratio    : %.3f%%\t", (((float) nComprSize / (float) nUnCompressedSize) * 100.0));
    printf("Compression ratio    : %.3f bpb\n", ((float) nComprSize * 8.0) / (float) nUnCompressedSize);

    return 0;
}

int Decomproc(Decompress &oDecompress, const string &inputf, const string &outputf, uint key) {
    oDecompress.SetDefaults();
    auto nCompressedSize = getSize(inputf);
    cout << "Input file size      : " << nCompressedSize << endl;
    oDecompress.SetInputType(HS_COMP_FILE);
    oDecompress.SetOutputType(HS_COMP_FILE);
    oDecompress.SetInputFile(inputf.c_str());
    oDecompress.SetOutputFile(outputf.c_str());
    if (key != -1)
        oDecompress.SetKey(key);
    oDecompress.SetMonitorCallback(&DecompressMonitorProc);
    Timer tmer;
    auto nRes = oDecompress.DDecompress();
    auto mscnd = tmer.elapsed();
    printf("\rDecompressed         : %d%%  ", oDecompress.GetPercentComplete());
    printf("\tDtime     : %.fms \n", mscnd);
    if (nRes != E_OK) {
        cout << "Error unCompressing.\n";
        return 0;
    }
//    Print filesize
    cout << "Output file size     : " << getSize(outputf) << endl;

    return 0;
}
