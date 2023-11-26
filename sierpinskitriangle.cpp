//Start code used from Lab 6
//Sierpinski triangle is the idea of drawing smaller, equilateral triangles into one big equilateral triangle 

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

std::string triangle(int length) //helper function 
std::string sierpinski_triangle(int order, int length); //recursive function

int main(int argv, char* argc[]){
    std::ofstream of("l-system.txt");

    int order = std::stoi(argc[1]);
    of << sierpinski_triangle(order));
}

std::string triangle(int length){
    for(int i = 0; i < 3; i++){
        //make a command to draw the side
        //change the angle?
    }
}

std::string sierpinski_triangle(int order, int length){
    std::string commands = "";
    if(order == 1){
        return = triangle(length);
        //our base case is if we reach our order 1, that means that all we have to draw is one triangle
    }

    std::string commands = sierpinski_traingle(order -1, length/2) + sierpinski_traingle(order - 1, length/2) + sierpinski_traingle(order -1, length/2)
    
    return commands;
}
