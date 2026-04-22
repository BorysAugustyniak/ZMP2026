#include <iostream>

using namespace std;

int Fib(int n, int fib_n, int fib_n1){
    if (n <= 1) return fib_n;
    else return Fib(n - 1, fib_n1 + fib_n, fib_n);
}

int main(){
    int n;
    cin >> n;
    cout << Fib(n, 1, 1);
}
