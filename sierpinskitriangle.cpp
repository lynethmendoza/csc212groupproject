//Start code used from Lab 6
//Sierpinski triangle is the idea of drawing smaller, equilateral triangles into one big equilateral triangle, depending on the degree given
//In this case, degree/order 0 == one triangle

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

std::string sierpinski_triangle(int order, int length); //recursive function

int main(int argv, char* argc[]){
    std::ofstream of("l-system.txt");

    int order = std::stoi(argc[1]);
    int length = std::pow(2, order - 1); //we need the lenght to be 2^n-1, n ebing the degrees 
    of << sierpinski_triangle(order, length);
}


std::string sierpinski_triangle(int order, int length){
    if(order == 1){
        return "F+F+F+";
        //our base case is if we reach our order 0, that means that all we have to draw is one triangle
    }
    
    std::string commands = sierpinski_triangle(order - 1, length/2)+ "- " + sierpinski_triangle(order - 1, length/2) + "- " + sierpinski_triangle(order -1, length/2) + "+ + " + sierpinski_triangle(order - 1, length/2);
    // this is our recursive call, it calls the function 4 times, because you are trying to make 4 smaller equal triangles in one triangle
    
    return commands;
}
