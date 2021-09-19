#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>

class HTML
{
private:
    std::string code_file_path, input_file_path, output_file_path;
    std::ifstream code_file, input_file;
    std::ofstream output_file;
    std::map<std::string, std::string> code_map;

public:
    /* constructor */
    HTML(std::string code_file_path, std::string input_file_path, std::string output_file_path)
        :   code_file_path {code_file_path}, input_file_path {input_file_path}, output_file_path {output_file_path}
    {
        // open the code file
        code_file.open(code_file_path);
        if(!code_file.is_open())
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
                output_file.open("output.html");
                if(!output_file.is_open())
                {
                    std::cout << "output.txt file is missing!" << std::endl;
                }
            }
        }

        this->build_code_map();
        this->build_output();
    }

    /* builds the code map */
    void build_code_map()
    {
        std::string line;
        std::string key;
        std::string value;

        while(std::getline(this->code_file, line))
        {
            // catch the short code
            if(line[0] == ':')
            {
                if(!key.empty())
                {
                    this->code_map.insert(std::make_pair(key, value));
                    key = line;
                    value = "";
                    continue;
                }

                key = line;
            }
            else
            {
                if(line != "\n")
                {
                    value += line + '\n';
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

        while(input_file >> line)
        {
            output_file << code_map[line];
        }
    }

    /* prints the code_map */
    void display_code_map()
    {
        for(const auto &elem: this->code_map)
        {
            std::cout << elem.first << "\n" << elem.second << std::endl;
        }
    }

    /* destructor */
    ~HTML()
    {
        code_file.close();
        input_file.close();
        output_file.close();
    }
};

int main()
{
    HTML html {"code.txt", "input.txt", "output.txt"};
    html.display_code_map();

    return 0;
}