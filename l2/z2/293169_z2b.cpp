#include <iostream>

using namespace std;

int binsea(int* &tab, int siz, int x){
	int l = 0, r = siz - 1;
	int s = (l + r) / 2;
	while (l <= r){
		if (tab[s] < x){
			l = s + 1;
			s = (l + r) / 2;	
		}
		else if (tab[s] > x){
			r = s - 1;
			s = (l + r) / 2;
		}
		else{
			return s;
		}
	}
	return -1;
}

int main(){
	int x, n, ind = -1;
	cin >> x >> n;
	int* tab = new int[n];
	for (int i = 0; i < n; ++i){
		cin >> tab[i];
	}
	ind = binsea(tab, n, x);
	if (ind != -1){
		cout << "tak " << ind;
	}
	else{
		cout << "nie";
	}
	delete [] tab;
}
