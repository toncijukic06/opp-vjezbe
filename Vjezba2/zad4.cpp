#include <iostream>

void my_transform(int arr[], int n, int (*f)(int))
{

    for (int i = 0; i < n; i++)
    {
        arr[i] = f(arr[i]);
    }
}

int twice(int broj)
{

    return broj * 2;
}

int main()
{

    int niz[] = {2, 6, 3, 4};
    int n = sizeof(niz) / sizeof(niz[0]);
    my_transform(niz, n, twice);

    std::cout << "Prva transfomacija: ";

    for (int i = 0; i < n; i++)
    {
        std::cout << niz[i] << " ";
    }
    std::cout << "\nDruga transfomacija: ";
    auto parnost = [](int x)
    {
        return (x % 2 == 0) ? x / 2 : x * 2;
    };

    my_transform(niz, n, parnost);
    for (int i = 0; i < n; i++)
    {
        std::cout << niz[i] << " ";
    }

    int suma=0;
    int produkt=1;

    auto lambda1 = [&](int x) {
        suma += x;
        produkt *= x;
    };

    for (int i = 0; i < n; i++) {
        lambda1(niz[i]);
    }

    std::cout<<"\nSuma: "<<suma;
    std::cout<<"\nProdukt: "<<produkt;

    int prag = 4;
    suma = 0;

    
    auto lambda2 = [prag, &suma](int x) {
        if (x > prag) {
            suma += x;
        }
    };

    for (int i = 0; i < n; i++) {
        lambda2(niz[i]);
    }

    std::cout << "\nSuma vecih od praga: " << suma;
}