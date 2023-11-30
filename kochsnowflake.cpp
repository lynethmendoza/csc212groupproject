// Header inclusions
#include <iostream>
#include <string>
#include <fstream>

// Function declarations
std::string Koch_snowflake(int degree);
std::string Snowflake(int degree);

int main(){

    // Ofstream to output the restlt of the koch function
    std::ofstream of("l-system.txt");

    int degree = 3;

    of << Koch_snowflake(degree);
}

// Generates 4 'sides' of the snowflake
std::string Koch_snowflake(int degree){
    std::string commands = "";

    for(int i = 0; i < 4; i++){
        commands += Snowflake(degree);
        commands += "+ + ";
    }

    return commands;
}

// Recursive function for generating the snowflake
std::string Snowflake(int degree){
    if(degree == 0){
        return "F ";
    }
    std::string commands = "";

    // Logic for generating the snowflake
    // Pattern F-F++F-F
    commands += Snowflake(degree - 1);
    commands += "-"; // F-
    commands += Snowflake(degree - 1);
    commands += "+ + "; // F++
    commands += Snowflake(degree - 1);
    commands += "-"; // F-
    commands += Snowflake(degree - 1);
    commands += "-"; // F -
    commands += Snowflake(degree - 1);

    return commands;
}
