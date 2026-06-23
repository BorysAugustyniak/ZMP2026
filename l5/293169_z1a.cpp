#include <iostream>

using namespace std;

int inversion(int* tab, int size){
    int answer = 0;
    for (int i = 0; i < size; ++i){
        for (int j = i; j < size; ++j){
            if (tab[i] > tab[j]){
                ++answer;
            }
        }
    }
    return answer;
}

int main(){
    int n;
    cin >> n;
    int* tab = new int[n];
    for (int i = 0; i < n; ++i){
        cin >> tab[i];
    }
    cout << inversion(tab, n);
    delete [] tab;
}