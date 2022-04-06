//
// Created by Daan Trommel on 06/03/2022.
//
#include <thread>
#include <mutex>

using namespace std::chrono;
std::mutex mutex;
static int count = 0;

/// Functie om aantal getallen weer te geven die voldoen aan de M proef in een bepaald bereik
/// \param b Begin van het bereik (inclusief)
/// \param e Eind van het bereik (exclusief)
/// \param m Modulus
void Count (int b, int e, int m){
    int sum = 0;    //Temporary variable for saving thread sum
    for (int i = b;i < e;i++){
        if(mCheck(i,m)){
            sum++;  //Add 1 to sum when mCheck is true;
        }
    }
    //Lock global variable for saving total sum
    mutex.lock();
    count += sum;
    mutex.unlock();
}


void CountMode(int b, int e, int m, int p){
    //Time was 5.46338 without concurrent optimization
    //Time was 1.37416 with 8 threads enabled
    //Time was 1.25386 with 16 threads enabled
    //Time was 1.25151 with 32 threads enabled
    //Time was 1.2441 with 64 threads enabled

    //Starting clock for performance purposes
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    //Declare variables for dividing numbers evenly over threads
    int startNumber = b;
    int threadNumber = p;
    int numberPerThread = (e-startNumber)/threadNumber;
    int remaining = (e - startNumber)%threadNumber;

    std::cout << "CountMode activated" << std::endl;
    std::vector<std::thread> threads;

    //Create threads
    for (int i = 0; i < threadNumber; i++)
    {
        if (remaining != 0){
            int endNumber = startNumber+numberPerThread+1;
            threads.push_back(std::thread(Count, startNumber, endNumber,m));
            remaining--;
            startNumber = endNumber;

        }
        else{
            int endNumber = startNumber+numberPerThread;
            threads.push_back(std::thread(Count,startNumber,endNumber,m));
            startNumber = endNumber;
        }
    }

    //Join threads
    for (int i = 0; i < threads.size(); i++)
    {
        threads.at(i).join();
    }

    //Calculate time
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    //Print result
    std::cout << count << " in " << time_span.count() << std::endl;

}

void ListMode(int b, int e, int m, int p){
    std::cout << "ListMode activated" << std::endl;
    int number = 1;
    for (int i = b;i<e;i++){
        if (mCheck(i,m)) {
            std::cout << number << " " << i << std::endl;
            number++;
        }
    }
}

void SearchMode(int b, int e, int m, int p, int s){
    std::cout << "SearchMode activated" << std::endl;
    if (s < b || s >= e) {
        std::cout << "-1" << std::endl;
        return;
    }
    else if (!mCheck(s,m)){
        std::cout<< "-1" << std::endl;
    }
    else {
        for (int i =b;i<e;i++){
            if (i == s){
                std::cout<<i<<std::endl;
                return;
            }
        }
    }
    std::cout << "-1" << std::endl;
    return;

}



