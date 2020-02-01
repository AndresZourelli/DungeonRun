/*
    input check helper function that makes sure the input is only an integer and not anything else or a combination of anything
*/

#include <string>
#include <sstream>
#include <iostream>
#include "checkInput.hpp"

//Check string to see if it is a valid input
bool checkInput(std::string input)
{
    //splits the string into a stream
    std::stringstream ss(input);
    int integer;
    //attempts to assign the part of the string that is an integer to the integer value
    if (ss >> integer)
    {
        //checks if there is anything after the integer
        char excess;
        //if there is something after the string then return a false and the user needs to reinput the value
        if (ss >> excess)
        {
            if(excess!='\n'){
                return false;
            }
        }
        //If there aren't any values after the integer then return the integer
        else
        {
                return true; 
        }
    }
    //if the string is unable to be placed into the integer value then return a false
    else
    {
        return false;
    }

    //default return
    return false;
}






//Check string to see if it is a valid input
bool checkInput(std::string input, int min, int max)
{
    //splits the string into a stream
    std::stringstream ss(input);
    int integer;
    //attempts to assign the part of the string that is an integer to the integer value
    if (ss >> integer)
    {
        //checks if there is anything after the integer
        char excess;
        //if there is something after the string then return a false and the user needs to reinput the value
        if (ss >> excess)
        {
            if(excess!='\n'){
                return false;
            }
        }
        //If there aren't any values after the integer then return the integer
        else
        {
            //convert input to int
            int valid_input = std::stoi(input);
            //check if data is in desired range
            if(valid_input<min || valid_input > max){
                //if input is not valid return false
                return false;
            }else{
                 //if input is valid return true
                return true;
            }
        }
    }
    //if the string is unable to be placed into the integer value then return a false
    else
    {
        return false;
    }

    //default return
    return false;
}