
#include <iostream>
using namespace std;

template <typename T>
bool asc(T a, T b)
{
    return a > b;
}

template <typename T>
bool desc(T a, T b)
{
    return a < b;
}

template <typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (cmp(arr[j], arr[j + 1]))
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    double niz[] = {2.4, 4, 3.3, 1, 9.2, 8};
    int n = sizeof(niz) / sizeof(niz[0]);

    my_sort(niz, n, asc);

    cout << "Uzlazno: ";
    for (int i = 0; i < n; i++)
        cout << niz[i] << " ";

    my_sort(niz, n, desc);

    cout << "\nSilazno: ";
    for (int i = 0; i < n; i++)
        cout << niz[i] << " ";
    
    int niz2[] = {2, 4, 3, 1, 9, 8};
    int n2 = sizeof(niz2) / sizeof(niz2[0]);

    my_sort(niz2, n2, asc);

    cout << "\nUzlazno: ";
    for (int i = 0; i < n; i++)
        cout << niz2[i] << " ";

    my_sort(niz2, n2, desc);

    cout << "\nSilazno: ";
    for (int i = 0; i < n; i++)
        cout << niz2[i] << " ";

    char niz3[] = {'c','a','b'};
    int n3 = sizeof(niz3) / sizeof(niz3[0]);

    my_sort(niz3, n3, asc);

    cout << "\nUzlazno: ";
    for (int i = 0; i < n; i++)
        cout << niz3[i] << " ";

    my_sort(niz3, n3, desc);

    cout << "\nSilazno: ";
    for (int i = 0; i < n; i++)
        cout << niz3[i] << " ";

    return 0;
}
