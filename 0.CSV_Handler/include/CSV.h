#ifndef __CSV_H__
#define __CSV_H__

class CSV
{
private:
    std::string file_path;
    std::ifstream file_in;
    std::ofstream file_out;

public:
    CSV(std::string file_path);

    ~CSV()
    {
        this->file_in.close();
        this->file_out.close();
    }
};

#endif