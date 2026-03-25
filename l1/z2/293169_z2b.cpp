#include <iostream>

using namespace std;

int nwd(int a, int b){
	if (a == 0 || b == 0){
		return max(a, b);
	}
	//a < b zawsze w naszym przypadku
	return nwd(b % a, a);
}

int tocjent(int n){
	int toc = 0;
	for (int i = 1; i <= n; ++i){
		if (nwd(i, n) == 1){
			++toc;
		}
	}
	return toc;
}

int Fduze(int n){
	//return n;
	int wynik = 0;
	for (int i = 1; i * i <= n; ++i){
		if (n % i == 0){
			wynik += tocjent(i);
			wynik += (i * i == n) ? 0 : tocjent(n/i);
		}
	}
	return wynik;
}

int main(){
	int n;
	cin >> n;
	cout << Fduze(n);
}
