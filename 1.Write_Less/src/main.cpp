#include <iostream>
#include <fstream>
#include <map>
#include <string>

class WriteLess
{
private:
    std::string dictionary_file_path, input_file_path, output_file_path;
    std::ifstream dictionary_file, input_file;
    std::ofstream output_file;
    std::map<std::string, std::string> dic_map;

public:
    /* constructor */
    WriteLess(std::string dictionary_file_path, std::string input_file_path, std::string output_file_path)
        :   dictionary_file_path {dictionary_file_path}, input_file_path {input_file_path}, output_file_path {output_file_path}
    {
        // open the code file
        dictionary_file.open(dictionary_file_path);
        if(!dictionary_file.is_open())
        {
            std::cout << "code.txt file is missing!" << std::endl;
        }
        else
        {
            // open the input file
            input_file.open(input_file_path);
            if(!input_file.is_open())
            {
                std::cout << "input.txt file is missing!" << std::endl;
            }
            else
            {
                // open or create the output file
                output_file.open(output_file_path);
                if(!output_file.is_open())
                {
                    std::cout << "output.txt file is missing!" << std::endl;
                }
            }
        }

        this->build_dic_map();
        this->build_output();
    }

    /* builds the dic map */
    void build_dic_map()
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
    void build_output()
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
    void display_dic_map()
    {
        for(const auto &elem: this->dic_map)
        {
            std::cout << elem.first << "\n" << elem.second << std::endl;
        }
    }

    /* destructor */
    ~WriteLess()
    {
        dictionary_file.close();
        input_file.close();
        output_file.close();
    }
};

int main()
{
    WriteLess app {"dictionary.txt", "input.txt", "output.html"};

    return 0;
}
