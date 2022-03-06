#include <iostream>
#include <vector>
#include "helperFunctions.cpp"
#include "IbanFunctions.cpp"

int main() {

    std::string inputString;

    //Input numbers
    int b; //lower limit of search range
    int e; //upper limit of search range
    int m; //modulus used by the m-check
    int p; //number of threads to be used
    int u; //search mode (0: count, 1: list, 2: search)
    int s; //optional number only used in search mode


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

    switch(u){
        case 0: CountMode(b,e,m,p); break;
        case 1: ListMode(b,e,m,p); break;
        case 2: SearchMode(b,e,m,p,s); break;
    }

    return 0;
}
