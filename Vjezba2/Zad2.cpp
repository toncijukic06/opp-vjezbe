
#include <iostream>
using namespace std;

inline bool asc(int a, int b)
{
    return a > b;
}

inline bool desc(int a, int b)
{
    return a < b;
}

void my_sort(int arr[], int n, bool (*cmp)(int, int))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (cmp(arr[j], arr[j + 1]))
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int niz[] = {2, 4, 3, 1, 9, 8};
    int n = sizeof(niz) / sizeof(niz[0]);

    my_sort(niz, n, asc);

    cout << "Uzlazno: ";
    for (int i = 0; i < n; i++)
        cout << niz[i] << " ";

    my_sort(niz, n, desc);

    cout << "\nSilazno: ";
    for (int i = 0; i < n; i++)
        cout << niz[i] << " ";

    return 0;
}
