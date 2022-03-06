//
// Created by Daan Trommel on 06/03/2022.
//

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

bool stringToIntegers(std::string inputString, int b,int e,int m,int p,int u,int s){
    //Use stringstream to read the numbers from the inputString
    std::stringstream iss(inputString);
    std::string numberString;
    std::vector<std::string> numbers;

    //Parse each numberString to integer and push it to the numbers vector
    while (iss >> numberString){
        numbers.push_back(numberString);
    }

    //check the number of integers in the vector
    if (numbers.size() < 5){
        std::cout << "You entered too few numbers, please enter 5 or 6" << std::endl;
        return false;
    }
    else if (numbers.size() > 6){
        std::cout << "You entered too many numbers, please enter 5 or 6" << std::endl;
        return false;
    }

    b = stoi(numbers[0]);
    e = stoi(numbers[1]);
    m = stoi(numbers[2]);
    p = stoi(numbers[3]);
    u = stoi(numbers[4]);

    //Check if number of integers in the vector is only 6 when u = 2
    if (u != 2 && numbers.size() == 6) {
        std::cout << "You entered 6 integers, that is only allowed in search mode(2)." << std::endl;
        return false;
    }
    else if (u == 2 && numbers.size() == 5) {
        std::cout << "Search mode (2) requires 6 integers, you entered 5." << std::endl;
        return false;
    }
    if (u == 2){
        s = stoi(numbers[5]);
    }
    return true;


}