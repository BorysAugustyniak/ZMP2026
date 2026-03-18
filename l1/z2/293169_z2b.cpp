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
	for (int i = 1; i < n; ++i){
		if (nwd(i, n) == 1){
			++toc;
		}
	}
	return toc;
}

int Fduze(int n){
    return n;
}

int main(){
	int n;
	cin >> n;
	cout << Fduze(n);
}
