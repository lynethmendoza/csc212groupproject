#include <iostream>
#include <fstream>
#include <string>

void drawHilbertCurve(int level, std::string& commands) {

  // implement recursive function

}

void outputCurve(int level, const std::string& filename) { 

  // 


int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <level> <output_filename>\n";
    return 1;
  }

  int level = std::stoi(argv[1]);
  std::string outputFilename = argv[2];

  outputCurve(level, outputFilename)

  return 0;
}
