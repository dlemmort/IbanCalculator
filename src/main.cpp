#include <iostream>
#include <vector>
#include "helperFunctions.cpp"

int main() {

    std::string inputString;

    //Input numbers
    int b;
    int e;
    int m;
    int p;
    int u;
    int s;


    std::cout << "Welcome to Iban Calculator" << std::endl;
    std::cout << "Please enter 5 or 6 integers divided by a single space" << std::endl;



    //Get seperate integers from inputString
    bool correctNumberString = false;
    do {
        //Get string input from user
        getline(std::cin,inputString);
        correctNumberString = stringToIntegers(inputString,b,e,m,p,u,s);
    }
    while (correctNumberString == false);

    std::cout << b << " " << e << " " << m << " " << p << " " << u << " " << s << std::endl;

    return 0;
}
