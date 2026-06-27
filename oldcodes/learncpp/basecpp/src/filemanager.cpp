#include <fstream>
#include <string>

std::ofstream createFile(std::string file) {
  // Create and open a text file
  std::ofstream NewFile(file);

  // Write to the file
  // string data = "Hi!";
  //NewFile << data;

  // Close the file
  //NewFile.close();

  return NewFile;
}