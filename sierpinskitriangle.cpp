//Start code used from Lab 6

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

std::string sierpinski_triangle(int degree, int len);

int main(int argv, char* argc[]){
    std::ofstream of("l-system.txt");

    int size = std::stoi(argc[1]);
    of << sierpinski_triangle(degree, std::pow(2, degree - 1));
}

std::string sierpinski_triangle(int degree, int len){
    if(){
        

    std::string commands = "";

    // Logic for generating the triangles goes here.

    return commands;
}
