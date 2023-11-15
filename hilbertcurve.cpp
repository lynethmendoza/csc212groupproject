#include <iostream>
#include <fstream>
#include <vector>
#include <utility> // for std::pair

// defines a point as a pair of floats (x,y)
using Point = std::pair<float, float>;
// defines a curve as a vector of points
using Curve = std::vector<Point>;

// function that adds a segment to the curve
void addToCurve(Curve& curve, Point p) {
    curve.push_back(p);
}

// recursive function to draw the Hilbert Curve
void drawHilbertCurve(int level, float startX, float startY, float xIncrement, float stepX, float yIncrement, float stepY, Curve& curve) {
    if (level == 0) {
        // base case: adds a single point to the curve
        addToCurve(curve, {startX + (xIncrement + yIncrement)/2, startY + (stepX + stepY)/2});
    } else {
        // recursive case: divides the problem and draws each part of the curve
        level--;
        // bottom-left segment
        drawHilbertCurve(level, startX, startY, yIncrement / 2, stepY / 2, xIncrement / 2, yIncrement / 2, curve);
        // bottom-right segment
        drawHilbertCurve(level, startX + xIncrement / 2, startY + stepX / 2, xIncrement / 2, stepX / 2, yIncrement / 2, stepY / 2, curve);
        // top-right segment
        drawHilbertCurve(level, startX + xIncrement/2 + yIncrement/2, startY + stepX/2 + stepY/2, xIncrement/2, stepX/2, yIncrement/2, stepY/2, curve);
        // top-left segment, with direction reversed
        drawHilbertCurve(level, startX + xIncrement/2 + yIncrement, startY + stepX/2 + stepY, -yIncrement/2, -stepY/2, -xIncrement/2, -stepX/2, curve);
    }
}

// function that draws the start of the Hilbert Curve
void drawHilbert(int level, Curve& curve) {
    drawHilbertCurve(level, 0, 0, 1, 0, 0, 1, curve);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <level> <output_curve_filename> <output_image_filename>\n";
        return 1;
    }

    int level = std::stoi(argv[1]); // gets the recursion level from the command line
    std::string outputCurveFilename = argv[2]; // gets the curve output filename from the command line
    std::string outputImageFilename = argv[3]; // gets the image output filename from the command line

    Curve curve; // declares the curve variable

    // generates the Hilbert Curve data
    drawHilbert(level, curve);

    // writes the data to a file specified by the command line argument
    std::ofstream file(outputCurveFilename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file " << outputCurveFilename << " for writing.\n";
        return 1;
    }

    // write the points of the curve to the file
    for (const auto& point : curve) {
        file << point.first << " " << point.second << "\n";
    }
    file.close();

    // defines the degree for turns, for Hilbert Curve it is set to '90'
    int angle = 90;

    // build the command string using the specified output filenames and the angle
    std::string command = "python3 l-system-plotter.py " + outputCurveFilename + " " + outputImageFilename + " " + std::to_string(angle);
    std::system(command.c_str()); // executes the command

    return 0;
}
