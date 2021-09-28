#include <iostream>
#include <fstream>
#include <string>

#include "../include/CSV.h"

CSV::CSV(std::string file_path)
    : file_path {file_path}
{
    // open the file for writing or create it if it's missing
    file_out.open(this->file_path, std::ios::app);

    // open the file for reading
    file_in.open(this->file_path);

    // check if the file is found and open
    if(!file_in.is_open() || !file_out.is_open())
    {
        std::cout << "File: [" << this->file_path << "] is missing." << std::endl;
    }
}