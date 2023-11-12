//Start code used from Lab 6
//Sierpinski triangle is the idea of drawing smaller, equilateral triangles into one big equilateral triangle 

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

std::string sierpinski_triangle(int degree, int len);

int main(int argv, char* argc[]){
    std::ofstream of("l-system.txt");

    int order = std::stoi(argc[1]);
    of << sierpinski_triangle(order));
}

std::string sierpinski_triangle(int order){
    if(order == 1){
    }

    std::string commands = "";

    // Logic for generating the triangles goes here.

    return commands;
}
