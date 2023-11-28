#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// function that starts generating the hilbert curve
void drawHilbertCurve(int level) {
  std::stringstream ss;
  appendLeftCurve(ss, level); // starts with left curve
  return ss.str(); // converts stringstream to string
}

// recursive function that appends the left part of the hilbert curve
void appendLeftCurve(std::stringstream& ss, int level) {
  if (level == 0) return; // base case, if level is zero it will return nothing

  s << "-"; // turtle turns left
  appendRightCurve(ss, level - 1); // appends the right curve of the previous level
  ss << "F+"; // turtle moves forward and turns right
  appendLeftCurve(ss, level - 1); // appends the left curve of the previous level
  ss << "F"; // turtle moves forward
  appendLeftCurve(ss, level - 1); // appends another left curve of the previous level
  ss << "+F"; // turtle turns right and moves forward
  appendRightCurve(ss, level - 1); // appends the right curve of the previous level
  
}

// recursive function that appends the right part of the hilbert curve
void appendRightCurve(std::stringstream& ss, int level) {
  if (level == 0) return; // base case

  ss << "+"; // turtle turns right
  appendLeftCurve(ss, level - 1);
  ss << "F-"; // turtle moves forward and turns left
  appendRightCurve(ss, level - 1);
  ss << "F"; // turtle moves forward
  appendRightCurve(ss, level - 1);
  ss << "-F"; // turtle turns left and moves forward
  appendLeftCurve(ss, level - 1);
  
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
