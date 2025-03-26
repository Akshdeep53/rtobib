#include"ris_bib.h"

std::vector<std::string> names;

void ris_files()
{
    DIR *dir = opendir(".");
    if (dir != NULL){
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL){
            std::string temp = entry->d_name;
            std::size_t found = temp.rfind(".ris");
            if(found != std::string::npos && found == (temp.length() - 4)){
                names.push_back(entry->d_name);} 
            else {
                continue;}
        }
        closedir(dir);
    }

}
