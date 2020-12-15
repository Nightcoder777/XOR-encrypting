#include <iostream>
#include <cstring>
#include <fstream>
#include <streambuf>
#include "xor.cpp"

#define endl '\n'

int main(int argc, char* argv[]){
    std::string key;
    std::string filename;
    std::string outfile;
    bool printresult = false;
    bool binary = false;
    
    for(int i = 0; i < argc; i++)
    {
        if((std::string)argv[i] == "-k"){
            key = argv[i + 1];
        } else if ((std::string)argv[i] == "-f")
        {
            filename = argv[i + 1];
        } else if ((std::string)argv[i] == "-o")
        {
            if((std::string)argv[i + 1] != "@") outfile = argv[i + 1];
            else printresult = true;
        } else if ((std::string)argv[i] == "--binary")
        {
            binary = true;
            std::cout << "Opening file in binary mode...\n";
        }
    }
    if(!binary) std::cout << "Opening file in normal mode...\n";
    std::string str;

    if(!binary){
        std::ifstream t;
        t.open(filename);
        str = std::string((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    } else {
        std::ifstream is(filename, std::ios::binary);
        str = std::string((std::istreambuf_iterator<char>(is.rdbuf())), std::istreambuf_iterator<char>());
    }

    std::cout << "Encrypting all data...\n";
    std::string dec = decrypt(str, key);

    if(printresult != true){
        std::ofstream fout;
        if(!binary) fout.open(outfile); else fout.open(outfile, std::ios::binary);
        fout << dec;
        fout.close();
        std::cout << "File \"" << filename << "\" decrypted and saved as \"" << outfile << "\"";
    } else std::cout << dec;
    return 0;
}
