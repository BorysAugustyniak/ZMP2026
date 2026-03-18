#include <iostream>

using namespace std;

int collatz(int n);

int collatz(int n){
	if (n % 2 == 0){
		return n / 2;
	}
	else {
		return (3 * n + 1);
	}
}

int main(){
	int wynik = 0;
	int n;
	cin >> n;
	while (true){
		cout << n;
		wynik++;
		if (n == 1){
			break;
		}
		n = collatz(n);
		cout << " ";
	}
	cout << ", " << wynik;
}
