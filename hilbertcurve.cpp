#include <iostream>
#include <fstream>
#include <string>

void drawHilbertCurve(int level, std::string& commands) {

  // implement recursive function

}

// recursive function that appends the left part of the hilbert curve
void appendLeftCurve(std::stringstream& ss, int n) {
  
}

// recursive function that appends the right part of the hilbert curve
void appendRightCurve(std::stringstream& ss, int n) {
  
}

// handles cla and writes the curve data to a file
int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <level> <output_filename>\n";
    return 1;
  }

  int level = std::stoi(argv[1]); // first argument is level of curve
  std::string outputFilename = argv[2]; // second argument is output file name

  std::string hilberCurve = drawHilbertCurve(level); // generates the hilbert curve
  
  std::ofstream outFile(outputFilename); // file opens for writing
  if (!outFile.is_open()) {
    std::cerr << "Error: Unable to open file '" << outputFilename << "' for writing.\n";
    return 1;
  }

  outFile << hilbertCurve;
  outFile.close();
  std::cout << "Hilbert curve commands written to '" << outputFilename << "'\n";
  
  return 0;
}
