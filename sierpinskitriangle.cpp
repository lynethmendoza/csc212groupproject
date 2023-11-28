//Start code used from Lab 6
//Sierpinski triangle is the idea of drawing smaller, equilateral triangles into one big equilateral triangle, depending on the degree given
//In this case, degree/order 0 == no triangle
//This code uses L System commands in order to visually represent the output

#include <string>
#include <iostream>
#include <fstream>

std::string sierpinski_triangle(int order); //recursive function

int main(int argv, char* argc[]){
    std::ofstream of("l-system.txt");
    int order = std::stoi(argc[1]);
    of << sierpinski_triangle(order);
    of.close();
    std::cout << "Sierpinski Triangle commands written to 'l-system.txt'\n";
}


std::string sierpinski_triangle(int order){
    if(order == 0){
        return "";
        //our base case is if we reach our order 0, that means that we don't draw anything
    }

    if(order == 1){
        return "FXF--FF--FF";
        //our second base case is that when we reach order 1, we just draw 1 triangle
    }
    
    std::string commands = sierpinski_triangle(order - 1); //recursive call, this reaches all the way to the base case, then we edit until we reach the order we need

    std::string newCommands = ""; //we use this to use the rules in order to create the fractal
    //rule 1: whenever there is an F, make it an FF
    //rule 2: whenever there is an X, make it a --FXF++FXF++FXF--, which makes an upside triangle

    //this loop iterates throught the command string to look at each character to check whether there is an F or X in the current commands
    for(int i = 0; i < commands.size(); i++){
        if(commands[i] == 'F'){
            newCommands += "FF"; //rule 1
        }else if(commands[i] == 'X'){
            newCommands += "--FXF++FXF++FXF--"; //rule 2
        }else{
            newCommands += commands[i];
            //if there is neither, you don't change the command, you keep it there
        }
    }

    return newCommands;
}


