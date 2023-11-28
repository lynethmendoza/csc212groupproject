#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// forward declarations
void appendLeftCurve(std::stringstream& ss, int level);
void appendRightCurve(std::stringstream& ss, int level);

// function that starts generating the hilbert curve
std::string drawHilbertCurve(int level) {
  std::stringstream ss;
  appendLeftCurve(ss, level); // starts with left curve
  return ss.str(); // converts stringstream to string
}

// recursive function that appends the left part of the hilbert curve
void appendLeftCurve(std::stringstream& ss, int level) {
  if (level == 0) return; // base case, if level is zero it will return nothing

  ss << "-"; // turtle turns left
  appendRightCurve(ss, level - 1); // appends the right curve of the previous level
  ss << "F+"; // turtle moves forward and turns right
  appendLeftCurve(ss, level - 1); // appends the left curve of the previous level
  ss << "F"; // turtle moves forward
  appendLeftCurve(ss, level - 1); // appends another left curve of the previous level
  ss << "+F"; // turtle turns right and moves forward
  appendRightCurve(ss, level - 1); // appends the right curve of the previous level
  ss << "-"; // turtle turns left
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
  ss << "+"; // turtle turns right
}

// handles cla and writes the curve data to a file
int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <level>\n";
    return 1;
  }

  int level = std::stoi(argv[1]); // first argument is level of curve
  std::ofstream of("l-system.txt"); // opens file stream

  if(!of.is_open()) { 
    std::cerr << "Error: Unable to open file 'l-system.txt' for writing.\n";
  }

  std::string hilbertCurve = drawHilbertCurve(level); // generates the hilbert curve
  of << hilbertCurve; // writes curve to file
  of.close();
  std::cout << "Hilbert curve commands written to 'l-system.txt'\n";
  
  return 0;
}
