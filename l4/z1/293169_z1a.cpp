#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a = 1, b = 1;
	for (int i = 1; i < n; ++i){
		b = a + b;
		a = b - a;
	}
	cout << b;
}
