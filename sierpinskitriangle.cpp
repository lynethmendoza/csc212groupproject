#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

std::string koch_snowflake(int degree);
std::string snowflake(int degree);
std::string sierpinski_triangle(int degree, int len);

int main(){
    std::ofstream of("l-system.txt");

    int degree = 3;
    of << sierpinski_triangle(degree, std::pow(2, degree - 1));
}

std::string sierpinski_triangle(int degree, int len){
    if(degree == 0){
        return "";
    }

    std::string commands = "";

    // Logic for generating the triangles goes here.

    return commands;
}
