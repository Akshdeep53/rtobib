#include"ris_bib.h"
/*
Possible changes for future update:-
    replace argument input options with getopt() function.
    error handling
    invalid input handling
    formating and cleaning code
*/

static void show_usage(std::string name);

int main(int argc, char* argv[]) 
// argc = how many cmd line arguments, argv = actual arguments
// there is always atleast one argument (argv[0]) which is name of the program (path of the program) itself which we use in terminal while executing it

{
    if (argc < 2)
    {
        show_usage(argv[0]);
        return 1;
    }
    
    std::vector <std::string> in_file;
    std::string out_file;
    ris_files();
    
    for(int i=1; i<argc; ++i){
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")){
            show_usage(argv[0]);
            return 0;
        } 
        else if((arg == "-o") || (arg == "--output_file")){
            if(i+1 < argc){
                out_file = argv[++i];
            }
            else {
                std::cerr << "ERROR: -o option requires an argument\n";
                return 1;
            }
        }
        else if((arg == "-a") || (arg == "--all")){
            in_file = names;
            if(in_file.empty()) {
                std::cerr << "ERROR: Current directory does not contain any .ris files\n";
                return 1;
            }
        }
        else if((arg == "-i") || (arg == "--input_file")){  
            if( i+1 < argc){
                int j{i};
                while(j+1 < argc) {
                    ++j;
                    if (std::string(argv[j]) != "-o" && std::string(argv[j]) != "--output_file"){ // argv is a const char* type, which is a pointer and string literals lile "-o" are also const char* type
                        in_file.push_back(argv[j]);                                               // hence if i dont convert it to string it will always be TRUE
                    } else {
                        break;}}}
            else {
                std::cerr << "ERROR: -i option requires an argument\n";
                return 1;
            }
        }
    }

    if (out_file.empty() || in_file.empty()){
        std::cerr << "ERROR: Insufficient data provided\n";
        return 1;
    }

        app_cite(in_file,out_file);
    return 0;
}

static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name << " <option(s)> SOURCES\n"
              << "Options:\n"
              << "\t-h, --help\t\tShow this help message\n"
              << "\t-o, --output_file\tSpecify the output file name\n"
              << "\t-i, --input_file\tSpecify the input file(s) name(s)\n"
              << "\t-a, --all\t\tAll the .ris files in current directory will be considered as input"
              << std::endl;
}
