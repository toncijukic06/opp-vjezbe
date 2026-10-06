#include <iostream>

int& find_max(int arr[], int n) {
    int max = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[max]) {
            max= i;
        }
    }
    return arr[max];
}

int main(){

    int numbers[] = {4, -7, 12, 0, 9, -3};
    int n = sizeof(numbers) / sizeof(numbers[0]);

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
    std::cout<<x<<" ";

    std::cout << "\n";

    find_max(numbers, n) = 0;

    std::cout << "Niz nakon izmjene: ";
    for (auto x : numbers)
    std::cout<<x<<" ";
    std::cout << "\n";

}
