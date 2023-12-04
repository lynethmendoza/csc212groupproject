// Header inclusions
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

// Function declarations
std::string Koch_snowflake(int degree);

int main(int argc, char *argv[]){

    if(argc != 3){
        std::cerr << "Usage: " << argv[0] << " <filename> <degree>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::ofstream of(filename); // Ofstream to output the restlt of the koch function
    int degree = std::atoi(argv[2]);

    // Call recursive function
    of << Koch_snowflake(degree);
    of.close();
    std::cout << "Snowflake commands written to '" << filename << "'\n";

    return 0;
}
// Recursive function for generating the snowflake
std::string Koch_snowflake(int degree){
// If the degree is 0 there should be no shape to return    
    if(degree == 0){
        return "";
    }
// Set axiom (base case) for the snowflake which is F--F--F or a triangle 
    if(degree == 1){
        return "F--F--F";
    }
    std::string commands = Koch_snowflake(degree-1);

    std::string newCommands = "";

    // Recursive structure
    for(int i = 0; i < commands.size(); i++){
        if(commands[i] == 'F'){
            // Koch snowflake recursive pattern F+F--F+F
            newCommands += "F+F--F+F";
        }else{
            newCommands += commands[i];
        }
    }
    return newCommands;
}
