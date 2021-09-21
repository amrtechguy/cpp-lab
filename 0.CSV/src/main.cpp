#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

class Record
{
    
// private:
//     std::map<std::string, std::string> data;

// public:
//     Record(std::map<std::string, std::string> data)
//         : data {data}
//     {}

//     bool update(std::string value)
//     {

//         return true;
//     }

//     bool del()
//     {

//         return true;
//     }

//     ~Record()
//     {}
};

/* Class: CSV */
class CSV
{
private:
    std::string file_path;
    std::ifstream file_in;
    std::vector<std::map<std::string, std::string>> records;

public:
    CSV(std::string file_path)
        : file_path {file_path}
    {
        file_in.open(this->file_path);

        if(!file_in.is_open())
        {
            std::cout << "File [" << this->file_path << "]  is not found!" << std::endl;
        }

        this->load_data();
    }

    std::string clean_word(const std::string &word)
    {
        std::string new_word;
        for(const auto &c: word)
        {
            new_word.push_back(c);
        }
        return new_word;
    }

    void load_data()
    {
        std::string line;
        int line_num {1};
        std::vector<std::string> header_keys;

        // loop through the file
        // and get line by line
        while(std::getline(this->file_in, line))
        {            
            // get the values of the heading
            if(line_num == 1)
            {
                std::stringstream ss {line};
                std::string key;

                while(std::getline(ss, key, ','))
                {
                    key = this->clean_word(key);
                    header_keys.push_back(key);
                }
            }
            // get the values of each line (record)
            // and store it as map of key -> values
            // and push it to the back of this->records
            else
            {
                std::map<std::string, std::string> record;

                std::string value;
                std::stringstream ss {line};

                int index {0};

                while(std::getline(ss, value, ','))
                {
                    record[header_keys.at(index)] = value;

                    if(index < header_keys.size())
                    {
                        index++;
                    }
                }
                
                this->records.push_back(record);
            }

            line_num++;
        }
    }

    void add(std::string line)
    {
        // if(!this->file.is_open())
        // {
        //     std::cout << "File [" << this->file_path << "]  is not found!" << std::endl;
        // }
        // else
        // {
        //     this->file << line << std::endl;
        // }
    }

    void display_records()
    {
        std::cout << "[Records count: " << this->records.size() << "]" << std::endl;

        for(const auto &record: this->records)
        {
            std::cout << "[ ";

            for(const auto &key_value: record)
            {
                std::cout << key_value.first << ": " << key_value.second << '\t'; 
            }
            
            std::cout << "]" << std::endl;
        }
    }

    ~CSV()
    {
        this->file_in.close();
    }
};

int main()
{
    CSV csv_file {"data.csv"};
    csv_file.display_records();

    // csv_file.add("Frank,Software Engineer,USA");

    return 0;
}