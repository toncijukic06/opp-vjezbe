#include <iostream>
using std::cout;
using std::cin;

inline double add(double a, double b) {
    return a + b;
}

inline double subtract(double a, double b) {
    return a - b;
}

inline double multiply(double a, double b) {
    return a * b;
}

inline double divide(double a, double b) {
    return a / b;
}

int main() {
    double a, b;
    int operacija;

    double (*funkcije[4])(double, double) = {
        add, subtract, multiply, divide
    };

    cout << "Unesi dva broja: ";
    cin >> a >> b;

    cout << "Odaberi operaciju (0-zbrajanje, 1-oduzimanje, 2-mnozenje, 3-dijeljenje): ";
    cin >> operacija;

    if (operacija < 0 || operacija > 3) {
        cout << "Nepostojeca operacija";
        return 1;
    }

    if (operacija == 3 && b == 0) {
        cout << "Dijeljenje s nulom nije dozvoljeno";
    }
    else {
        cout << "Rezultat: " << funkcije[operacija](a, b);
    }

    return 0;
}