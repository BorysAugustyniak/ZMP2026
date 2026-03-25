#include <iostream>

using namespace std;

int main(){
	int x, n, ind = -1;
	cin >> x >> n;
	int* tab = new int[n];
	for (int i = 0; i < n; ++i){
		cin >> tab[i];
	}
	for (int i = 0; i < n; ++i){
		if (x == tab[i]){
			ind = i;
			break;
		}
	}
	if (ind != -1){
		cout << "tak " << ind;
	}
	else{
		cout << "nie";
	}
	delete [] tab;
}
