#include"ris_bib.h"
std::string trim(const std::string& line)
{
    const char* WhiteSpace = " \t\v\r\n";
    std::size_t start = line.find_first_not_of(WhiteSpace);
    std::size_t end = line.find_last_not_of(WhiteSpace);
    if(start == std::string::npos){
        return "";}
    return line.substr(start, end - start + 1);
}

void app_cite(std::vector<std::string> in_file, std::string out_file)
{

    std::string line,
                file_name,
                author,
                title,
                journal,
                edition,
                year,
                month,
                day,
                publisher,
                volume,
                number,
                start_page,
                end_page,
                pages,
                doi,
                url,
                address,
                note;

    std::ofstream output(out_file, std::ios::out | std::ios::app);
    //std::ifstream input {in_file[0]};
    // ,ios::ate will set the initial position at the end of the file
    // ios::app , all output operations are performed at the end of the file, appending the content to the current content of the file

    for (std::string i : in_file){
        line.clear(),
        file_name.clear(),
        author.clear(),
        title.clear(),
        journal.clear(),
        edition.clear(),
        year.clear(),
        month.clear(),
        day.clear(),
        publisher.clear(),
        volume.clear(),
        number.clear(),
        start_page.clear(),
        end_page.clear(),
        pages.clear(),
        doi.clear(),
        url.clear(),
        address.clear(),
        note.clear();

        std::ifstream input {i.c_str()};
        if (input.is_open()){
            while(getline(input,line)){
                auto pos = line.find_first_of('-');
                //std::cout << trim(line.substr(0,pos)) << "\n";
                //std::cout << trim(line.substr(pos+1)) << "\n";
                std::string key = trim(line.substr(0,pos));
                std::string value = trim(line.substr(pos+1));
                if( key == "AU"
                    || key == "A1"
                    || key == "A2"
                    || key == "A3"
                    || key == "A4"
                    || key == "ED") {
                    if (author.empty()){
                        author.append(value);}
                    else{ 
                        author.append("\n");
                        author.append("and "+value);}}

                else if(key == "TI"
                    || key == "T1"){
                    if (title.empty()){
                        title.append(value); }
                    else {
                        title.append("\n");
                        title.append("and "+value+"\n");}}
                        
                else if(key == "T2"
                    || key == "JA"
                    || key == "JF"
                    || key == "JO"){
                    if (journal.empty()){
                        journal.append(value); }}

                else if(key == "ET"){
                    edition.append(value); }

                else if(key == "AD"){
                    address.append(value); }

                else if(key == "PB"){
                    if (publisher.empty()){
                        publisher.append(value); }
                    else {
                        publisher.append("and "+value+"\n");}}

                else if(key == "M3"
                    || key == "DI"
                    || key == "DO"
                    || key == "DOI"
                    || key == "L3"){
                    if (doi.empty()){
                        doi.append(value); }}
                    //else{ 
                     //   doi.append("\n");
                      //  doi.append("and "+trim(line.substr(pos+1))+"\n");}

                else if(key == "L1"
                    || key == "L2"
                    || key == "UR"){
                    if (url.empty()){
                        url.append(value); }
                    else {
                        url.append("and "+value+"\n");}}

                else if(key == "Y1"
                    || key == "DA"){
                    if (year.empty() || month.empty() || day.empty()){
                        year.append(trim(line.substr(pos+1)).substr(0,4));
                        month.append(trim(line.substr(pos+1)).substr(5,2));
                        day.append(trim(line.substr(pos+1)).substr(8,2));}}

                else if(key == "PY"){
                    if (year.empty()){
                        year.append(value);}}
                
                else if(key == "VL"){
                        volume.append(value);}

                else if(key == "IS"){
                    if (number.empty()){
                        number.append(value);}}

                else if(key == "SP"){
                    if (start_page.empty()){
                        start_page.append(value);}}

                else if(key == "EP"){
                    if (end_page.empty()){
                        end_page.append(value);}}
                
                else if(!start_page.empty() && !end_page.empty()){
                    if (pages.empty()){
                        pages.append(start_page + "-" + end_page); }}
                
                else if(key == "N1"
                       || key == "NO"
                       || key == "RN"){
                    if (note.empty()){
                        note.append(value);}}

            }
            auto pos_name = author.find_first_of(',');
            std::string val_name = author.substr(0,pos_name);
            std::string::iterator end_pos = std::remove(val_name.begin(),val_name.end(),' ');
            val_name.erase(end_pos,val_name.end());
            if (file_name.empty()) {
                if(!year.empty()){
                    file_name.append(val_name+year);}
                else{
                    file_name.append(trim(author.substr(0,pos_name)));}}
        } else std::cerr << "ERROR: File " << i << " cannot be opened\n";
        input.close();

        if(output.is_open()){
            output << "@article{" << file_name << ",\n"
                    << "author={" << author << "},\n"
                    << "title={" << title << "},\n"
                    << "journal={" << journal << "},\n"
                    << "year={" << year << "},\n"
                    << "month={" << month << "},\n"
                    << "day={" << day << "},\n"
                    << "publisher={" << publisher << "},\n"
                    << "volume={" << volume << "},\n"
                    << "number={" << number << "},\n"
                    << "pages={" << pages << "},\n"
                    << "doi={" << doi << "},\n"
                    << "url={" << url << "},\n"
                    << "address={" << address << "}}\n\n";
//                    << "note={" << note << "}}\n";
        } else std::cout << "ERROR\n";
    }

        output.close();
}

 

