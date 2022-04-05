//
// Created by Daan Trommel on 06/03/2022.
//

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <thread>

bool checkIntegerParameters(int b,int e, int m, int p, int u);
int getNumberOfThreads();

/// Function that takes a string of 5 or 6 whole numbers divided by single spaces and
/// puts the integer value in one of the passed integer parameters
/// \param inputString string containing the numbers
/// \param b first integer parameter
/// \param e second integer parameter
/// \param m third integer parameter
/// \param p fourth integer parameter
/// \param u fifth integer parameter
/// \param s sixth integer parameter
/// \return returns true when string is succesfully parsed into the 6 integer parameters
bool stringToIntegers(std::string inputString, int& b,int& e,int& m,int& p,int& u,int& s){
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
    if (checkIntegerParameters(b,e,m,p,u)) return true;
    else return false;
}

/// Function checks whether the integers follow the given rules
/// \param b first integer parameter
/// \param e second integer parameter
/// \param m third integer parameter
/// \param p fourth integer parameter
/// \param u fifth integer parameter
/// \return returns true when requirements are met, otherwise returns false
bool checkIntegerParameters(int b,int e, int m, int p, int u){
    int threads = getNumberOfThreads();
    if (e <= b){
        std::cout << "second integer must be greater than first integer" << std::endl;
        return false;
    }
    else if (m < 1 || m > 256){
        std::cout << "third integer must be between 1 and 256" << std::endl;
        return false;
    }
    else if (p < 1 || p > threads){
        std::cout << "fourth integer must be between 1 and " << threads << "(threads available on machine)" << std::endl;
        return false;
    }
    else if (u < 0 || u > 2){
        std::cout << "fifth integer must be 0, 1 or 2" << std::endl;
        return false;
    }
    else return true;
}

int getNumberOfThreads(){
    unsigned int n =  std::thread::hardware_concurrency();
    return n;
}

bool mCheck(int number, int modulus){
    int currentNumber = number;
    int sum = 0;
    int times = 1;

    while (currentNumber > 0){
        sum += (currentNumber%10)*times;
        times++;
        currentNumber = currentNumber / 10;
    }

    if (sum % modulus == 0) return true;
    else return false;
}