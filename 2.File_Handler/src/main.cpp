#include <iostream>
#include <fstream>
#include <string>

int main()
{
  std::fstream myFile;
  /*
    [This comment was copied from Saldina @ CodeBeauty] (^_^)

    ios::in - opens the file to read(default for ifstream)
    ios::out - opens the file to write(default for ofstream)
    ios::binary - opens the file in binary mode
    ios::app- opens the file to append new info at the end
    ios::ate - opens and moves the control to the end of the file
    ios::trunc - removes the data in the existing file
    ios::nocreate - opens the file only if it already exists
    ios::noreplace - opens the file only if it doesn't already exist

    We can also combine different modes using symbol |
    For example:
    myFile.open(“saldinaFile.txt”, ios::out | ios::in);
    In this example, we are opening saldinaFile.txt for both writing and reading.
  */ 
  myFile.open("file.txt", std::ios::in | std::ios::out | std::ios::app);

  std::string line;

  if(myFile.is_open())
  {
    // reading from the file
    std::getline(myFile, line);
    std::cout << line << std::endl;

    // writing to the file
    myFile << "I'm a Software Engineer (^_^)\n";

    // closing the file
    myFile.close();
  }

  return 0;
}
