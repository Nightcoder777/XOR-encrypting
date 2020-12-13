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
        }
    }

    std::ifstream t;
    t.open(filename);
    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
 
    std::string enc = encrypt(str, key);

    if(printresult != true){
        std::ofstream fout;
        fout.open(outfile);
        fout.write(enc.c_str(), std::strlen(enc.c_str()));
        fout.close();
    } else std::cout << enc;
    return 0;
}
