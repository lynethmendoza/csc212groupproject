//Starter code used from Lab 6
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

std::string koch_snowflake(int degree);
std::string snowflake(int degree);

int main(){
    std::ofstream of("l-system.txt");

    int degree = 3;

    of << koch_snowflake(degree);
}

// *** DO NOT TOUCH! ***
std::string koch_snowflake(int degree){
    std::string commands = "";

	// This handles generating the 4 'sides' of the snowflake.
    for(int i = 0; i < 4; i++){
        commands += snowflake(degree);
        commands += "+ + ";
    }

    return commands;
}

std::string snowflake(int degree){
    if(degree == 0){
        return "F ";
    }
    std::string commands = "";

	 // Logic for generating the snowflake goes here.

    // Pattern F-F++F-F
    commands += snowflake(degree - 1);
    commands += "-"; // F-
    commands += snowflake(degree - 1); 
    commands += "+ + "; // F++
    commands += snowflake(degree - 1); 
    commands += "-"; // F-
    commands += snowflake(degree - 1); 
    commands += "-"; // F -
    commands += snowflake(degree - 1);

    return commands;
}
