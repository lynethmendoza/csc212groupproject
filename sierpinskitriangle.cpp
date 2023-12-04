//Start code used from Lab 6
//Sierpinski triangle is the idea of drawing smaller, equilateral triangles into one big equilateral triangle, depending on the degree given
//In this case, degree/order 0 == no triangle
//This code uses L System commands to visually represent the output of the fractal

#include <string>
#include <iostream>
#include <fstream>

std::string sierpinski_triangle(int order); //recursive function

int main(int argc, char* argv[]){
    if(argc != 3) {
        std::cerr <<"Usage: " << argv[0] << " <filename> <order>\n";
        return 1;
    }
    std::string filename = argv[1]; //input file that will be used to put the commands
    std::ofstream of(filename);

    if(!of.is_open()){
        std::cerr << "Error: Unable to open file '" << filename << "' for writing.\n";
        return 1;
    }
    int order = std::stoi(argv[2]); //order of fractal that we want
    of << sierpinski_triangle(order);
    of.close();
    std::cout << "Sierpinski Triangle commands written to '" << filename << "' \n";

    return 0;
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
    
    std::string commands = sierpinski_triangle(order - 1); //recursive call, this will be called until it reaches the base cases, then we edit until we reach the order we need

    std::string newCommands = ""; //we use this to use the rules to create the fractal
    //rule 1: whenever there is an F, make it an FF
    //rule 2: whenever there is an X, make it a --FXF++FXF++FXF--, which makes an upside-down triangle

    //this loop iterates through the current command string to look at each character to check whether there is an F or X in the current commands
    for(int i = 0; i < commands.size(); i++){
        if(commands[i] == 'F'){
            newCommands += "FF";
            //rule 1
        }else if(commands[i] == 'X'){
            newCommands += "--FXF++FXF++FXF--";
            //rule 2
        }else{
            newCommands += commands[i];
            //if there is neither, you don't change the command, you keep it there
        }
    }

    return newCommands;
}
