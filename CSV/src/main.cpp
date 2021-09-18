#include <iostream>
#include <fstream>
#include <string>

class CSV
{
private:
    std::string file_path;
    std::ofstream file;

public:
    CSV(std::string file_path)
        : file_path {file_path}
    {
        file.open(this->file_path, std::ios::app);
        
        if(!file.is_open())
        {
            std::cout << "File [" << this->file_path << "]  is not found!" << std::endl;
        }
    }

    void write(std::string line)
    {
        if(!this->file.is_open())
        {
            std::cout << "File [" << this->file_path << "]  is not found!" << std::endl;
        }
        else
        {
            this->file << line << std::endl;
        }
    }

    ~CSV()
    {
        this->file.close();
    }
};

int main()
{
    CSV csv_file {"data.csv"};
    
    csv_file.write("Amr Hassan,Software Engineer,Egypt");

    return 0;
}