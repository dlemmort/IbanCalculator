//
// Created by Daan Trommel on 06/03/2022.
//
#include <thread>
#include <mutex>
#include <future>

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
    //Time was 5.46338 without concurrent optimization Macbook M1 Pro
    //Time was 1.37416 with 8 threads enabled Macbook M1 Pro
    //Time was 1.25386 with 16 threads enabled Macbook M1 Pro
    //Time was 1.25151 with 32 threads enabled Macbook M1 Pro
    //Time was 1.2441 with 64 threads enabled Macbook M1 Pro

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

static int indexNumber = 0;
/// Functie om gevonden getallen naar de console te schrijven
/// \param b Begin van het bereik (inclusief)
/// \param e Eind van het bereik (exclusief)
/// \param m Modulus
void List(int b, int e, int m){
    for (int i = b;i < e;i++){
        if(mCheck(i,m)){
            mutex.lock();
            std::cout<< indexNumber << ": " << i << std::endl;
            indexNumber++;
            mutex.unlock();
        }
    }
}

void ListMode(int b, int e, int m, int p){
    int startNumber = b;
    int threadNumber = p;
    int numberPerThread = (e-startNumber)/threadNumber;
    int remaining = (e - startNumber)%threadNumber;

    std::cout << "ListMode activated" << std::endl;
    std::vector<std::thread> threads;

    //Create threads to execute functions
    for (int i = 0; i < threadNumber; i++)
    {
        if (remaining != 0){
            int endNumber = startNumber+numberPerThread+1;
            threads.push_back(std::thread(List, startNumber, endNumber,m));
            remaining--;
            startNumber = endNumber;

        }
        else{
            int endNumber = startNumber+numberPerThread;
            threads.push_back(std::thread(List,startNumber,endNumber,m));
            startNumber = endNumber;
        }
    }

    //Join threads
    for (int i = 0; i < threads.size(); i++)
    {
        threads.at(i).join();
    }
}
static int searchNumber = 0;

int Search(int b, int e, int m, int s){
    for (int i = b;i < e;i++){
        if(mCheck(i,m)){
            if (i==s) return i;
        }
    }
}

void SearchMode(int b, int e, int m, int p, int s){
    if (!mCheck(s,m)){
        std::cout<<"Number to search does not meet "<<m<< " check."<<std::endl;
        return;
    }
    int startNumber = b;
    int threadNumber = p;
    int numberPerThread = (e-startNumber)/threadNumber;
    int remaining = (e - startNumber)%threadNumber;

    std::cout << "ListMode activated" << std::endl;
    std::vector<std::thread> threads;

    std::future<int> result;
    //Create threads to execute functions
    for (int i = 0; i < threadNumber; i++)
    {
        if (remaining != 0){
            int endNumber = startNumber+numberPerThread+1;
            result = std::async(std::launch::async, Search,startNumber,endNumber,m,s);
            remaining--;
            startNumber = endNumber;

        }
        else{
            int endNumber = startNumber+numberPerThread;
            result = std::async(std::launch::async, Search,startNumber,endNumber,m,s);
            startNumber = endNumber;
        }
    }
    std::cout<<result.get()<<std::endl;
}



