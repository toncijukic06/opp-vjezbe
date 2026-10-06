#include <iostream>

int main(){

    int numbers[] = {4, -7, 12, 0, 9, -3};

    for (auto x : numbers)
    std::cout<<x<<' ';
    std::cout<<'\n';
    
    for (auto &x : numbers){
        if (x<0)
        {
            x*=-1;
        }
        
    }
    for (auto x : numbers)
    std::cout<<x<<' ';

}
