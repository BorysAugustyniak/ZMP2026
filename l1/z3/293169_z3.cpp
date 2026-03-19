#include <iostream>

using namespace std;

int main(){
	//wzor legendre'a
	int n;
	cin >> n;
	//vp2, vp5 - wykladniki p-adyczne n!
	int vp2 = 0, vp5 = 0;
	//zmienna do zapisania 2 ^ k lub 5 ^ k
	int poteg = 2;

	while (poteg <= n){
		vp2 += (n / poteg);
		poteg *= 2;
	}
	poteg = 5;
	while (poteg <= n){
		vp5 += (n / poteg);
		poteg *= 5;
	}

	//tyle razy 10 dzieli n!
	cout << min(vp2, vp5);
}
