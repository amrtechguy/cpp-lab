#ifndef __WRITELESS_H__
#define __WRITELESS_H__

class WriteLess
{
private:
    std::string dictionary_file_path, input_file_path, output_file_path;
    std::ifstream dictionary_file, input_file;
    std::ofstream output_file;
    std::map<std::string, std::string> dic_map;

public:
    /* constructor */
    WriteLess(std::string dictionary_file_path, std::string input_file_path, std::string output_file_path);

    /* builds the dic map */
    void build_dic_map();

    /* builds the output */
    void build_output();

    /* prints the dictionary map sorted alphabetically as pairs of key -> value */
    void display_dic_map() const;

    /* destructor */
    ~WriteLess()
    {
        dictionary_file.close();
        input_file.close();
        output_file.close();
    }
};

#endif