//
// Created by Daan Trommel on 06/03/2022.
//

void CountMode(int b, int e, int m, int p){
    std::cout << "CountMode activated" << std::endl;
    int number = 0;
    for (int i = b;i < e;i++){
        if(mCheck(i,m)) number++;
    }
    std::cout << number << std::endl;
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

