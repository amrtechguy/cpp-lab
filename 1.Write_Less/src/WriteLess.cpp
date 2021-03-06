#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "..\include\WriteLess.h"

/* constructor */
WriteLess::WriteLess(std::string dictionary_file_path, std::string input_file_path, std::string output_file_path)
    :   dictionary_file_path {dictionary_file_path}, input_file_path {input_file_path}, output_file_path {output_file_path}
{
    // open the code file
    dictionary_file.open(dictionary_file_path);
    if(!dictionary_file.is_open())
    {
        std::cout << "File: ["<< this->dictionary_file_path << "] is missing!" << std::endl;
    }
    else
    {
        // open the input file
        input_file.open(input_file_path);
        if(!input_file.is_open())
        {
            std::cout << "File: ["<< this->input_file_path << "] is missing!" << std::endl;
        }
        else
        {
            // open or create the output file
            output_file.open(output_file_path);
            if(!output_file.is_open())
            {
                std::cout << "File: ["<< this->output_file_path << "] is missing!" << std::endl;
            }
        }
    }

    this->build_dic_map();
    this->build_output();
}

/* builds the dic map */
void WriteLess::build_dic_map()
{
    std::string line;
    std::string key;
    std::string value;

    while(std::getline(this->dictionary_file, line))
    {
        // check if the line is a shortcode
        if(line[0] == ':')
        {
            // check if there's a key->value pair
            // needs to be added to the dictionary map
            // before storing a new pair
            if(!key.empty())
            {
                this->dic_map.insert(std::make_pair(key, value));
                key = line;
                value = "";
                continue;
            }

            key = line;
        }
        // check if the line is a comment or a new line
        else if(line[0] == '/' && line[1] == '/')
        {
            continue;
        }
        // add the line to the value
        else
        {
            value += (line + '\n');

            // check if it's the last line (end of file)
            if(this->dictionary_file.eof())
            {
                this->dic_map.insert(std::make_pair(key, value));
            }
        }
    }
}

/* parse the input.txt and build the output.txt */
void WriteLess::build_output()
{
    // loop through input.txt
    std::string line;
    std::string key;
    std::string value;

    while(std::getline(this->input_file, line))
    {
        if(line[0] = ':')
        {
            this->output_file << dic_map[line];
        }  
    }
}

/* prints the dictionary map sorted alphabetically as pairs of key -> value */
void WriteLess::display_dic_map() const
{
    for(const auto &elem: this->dic_map)
    {
        std::cout << elem.first << "\n" << elem.second << std::endl;
    }
}

