#include <iostream>

using namespace std;

int nwd(int a, int b){
	if (a == 0 || b == 0){
		return max(a, b);
	}
	//a < b zawsze w naszym przypadku
	return nwd(b % a, a);
}

int main(){
	int n , NWD;
	cin >> n;
	int* tab = new int[n];
	for (int i = 0; i < n; ++i){
		cin >> tab[i];
	}
	NWD = tab[0];
	for (int i = 1; i < n; ++i){
		NWD = nwd(NWD, tab[i]);
	}
	cout << NWD;
	delete [] tab;
}
