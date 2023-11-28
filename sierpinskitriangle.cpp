//Start code used from Lab 6
//Sierpinski triangle is the idea of drawing smaller, equilateral triangles into one big equilateral triangle, depending on the degree given
//In this case, degree/order 0 == one triangle

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

std::string sierpinski_triangle(int order); //recursive function

int main(int argv, char* argc[]){
    std::ofstream of("l-system.txt");
    int order = std::stoi(argc[1]);
    of << sierpinski_triangle(order);
}


std::string sierpinski_triangle(int order){
    if(order == 0){
        return "FXF--FF--FF";
        //our base case is if we reach our order 0, that means that all we have to draw is one triangle, these commands will make one triangel
    }
    
    std::string commands = sierpinski_triangle(order - 1);
    // this is our recursive call, we reach it until we get to our degree one, and then we continually update it using the rules
    
    std::string newCommands = "";
    for(int i = 0; i < commands.size(); i++){
        if(commands[i] == 'F'){
            newCommands += "FF";
        }else if(commands[i] == 'X'){
            newCommands += "--FXF++FXF++FXF--";
        }else{
            newCommands += commands[i];
        }
    }

    return newCommands;
}

