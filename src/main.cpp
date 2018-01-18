#include <iostream>
#include <fstream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;

int main(int argc, char **argv) {

    // Message if ran in windows
    #if defined(__WIN32) || defined(__WIN64)
    cout << "Windows OS is not supported." << endl;
    return 1;
    #endif

    if(argc < 2) {
        cerr << "No file specified." << endl << "\tUSAGE: tabrestore <file1> "
            << "<file2> ... <file3>" << endl;
        return 1;
    }

    for(int i = 1; i < argc; i++) {
        ifstream infile;
        infile.open(argv[i]);
        if(!infile.good()) {
            cerr << "Cannot open " << argv[i] << "." << endl;
            continue;
        }
        
        string url;
        while(infile >> url) {
            string cmd;
            #if defined(__APPLE__) || defined(__MACH__)
            cmd = "open ";
            #else
            cmd = "xdg-open ";            
            #endif

            cmd += url;
            cout << cmd << endl;
            system(cmd.c_str());
        }
    }

    return 0;
}