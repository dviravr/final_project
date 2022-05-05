#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string printbincharpad(char c) {
    string byte;
    for (int i = 7; i >= 0; --i) {
        byte += (c & (1 << i)) ? '1' : '0';
    }
    return byte;
}

void readFile(string& srcFile, string &destFile) {
    char c;
    ifstream input_file(srcFile);
    ofstream output_file(destFile);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << srcFile << "'" << endl;
        return;
    }
    if (!output_file.is_open()) {
        cerr << "Could not open the file - '" << destFile << "'" << endl;
        return;
    }
    while (input_file.get(c)) {
        output_file << printbincharpad(c);
    }
    cout << endl;
    input_file.close();
    output_file.close();
}


int main() {
    string filesArray[6] = {
            "../text/encode_output_len",
//            "../text/encode_output_offset",
//            "../text/sam/sam.txt",
//            "../text/pitches/pitches.50MB",
//            "../text/dna/dna.50MB",
//            "../text/english/english.50MB",
//            "../text/proteins/proteins.50MB",
//            "../text/sources/sources.50MB",
//            "../text/xml/xml.50MB"
    };
    string decodedFilesArray[6] = {
            "../text/encode_output_len_bit.txt",
//            "../text/encode_output_offset_bit.txt",
//            "../text/sam/bits_output.txt",
//            "../text/pitches/bits_output.txt",
//            "../text/dna/bits_output.txt",
//            "../text/english/bits_output.txt",
//            "../text/proteins/bits_output.txt",
//            "../text/sources/bits_output.txt",
//            "../text/xml/bits_output.txt"
    };

    for (int i = 0; i < filesArray->length(); ++i) {
        readFile(filesArray[i], decodedFilesArray[i]);
    }
    return 0;
}
