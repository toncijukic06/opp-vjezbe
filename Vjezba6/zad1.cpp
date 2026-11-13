#include <iostream>

class IntStack {
    int *niz;
    int n;          
    int brElemnt;

public:

    IntStack(int pocKapacitet = 2) : niz(new int[pocKapacitet]), n(pocKapacitet), brElemnt(0) {}


    ~IntStack() {
        delete[] niz;
    }

    IntStack(const IntStack &other) : niz(new int[other.n]), n(other.n), brElemnt(other.brElemnt) {
        for (int i = 0; i < brElemnt; ++i) {
            niz[i] = other.niz[i];
        }
    }

    void push(int x) {
        if (brElemnt == n) {
            n *= 2;
            int *noviNiz = new int[n];
            for (int i = 0; i < brElemnt; i++) {
                noviNiz[i] = niz[i];
            }
            delete[] niz;
            niz = noviNiz;  
        }
        niz[brElemnt++] = x;
    }

    int top(){
        if (brElemnt == 0) 
            return -1;
        
        return niz[brElemnt - 1];    
    }

    int size(){
        return brElemnt;
    }

    int capacity(){
        return n;
    }

    void pop() {
        if (brElemnt > 0) {
            brElemnt--;
        }
    }

    bool empty() {
        return brElemnt == 0;
    }
};

int main() {
    IntStack s;
    for (int i = 1; i <= 5; ++i) 
        s.push(i * 10);
    
    std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n'; 
    
    IntStack c = s;
    c.pop(); 
    c.push(99); 
    
    std::cout << s.top() << ' ' << c.top() << '\n'; 
    
    while (!s.empty()) { 
        std::cout << s.top() << ' '; 
        s.pop(); 
    } 
    std::cout << '\n';

    return 0;
}