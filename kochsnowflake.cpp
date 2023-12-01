// Header inclusions
#include <iostream>
#include <string>
#include <fstream>

// Function declarations
std::string Koch_snowflake(int degree);

int main(){

    // Ofstream to output the restlt of the koch function
    std::ofstream of("l-system.txt");

    int degree = 6;

    of << Koch_snowflake(degree);
}
// Recursive function for generating the snowflake
std::string Koch_snowflake(int degree){
    if(degree == 0){
        return "";
    }
// Set Axiom for the snowflake which is F--F--F
    if(degree == 1){
        return "F--F--F";
    }
    std::string commands = Koch_snowflake(degree-1);

    std::string newCommands = "";

    for(int i =0; i < commands.size(); i++){
        if(commands[i] == 'F'){
            // Snowflake recursive pattern F+F--F+F
            newCommands += "F+F--F+F";
        }else{
            newCommands += commands[i];
        }
    }

    return newCommands;
}
