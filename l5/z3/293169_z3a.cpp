#include <iostream>

using namespace std;

int difference(int* tab, int size){
    //0 bo T[j] - T[j] = 0
    int answer = 0;
    for (int i = 0; i < size; ++i){
        for (int j = i; j < size; ++j){
            answer = max(answer, tab[j] - tab[i]);
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
    cout << difference(tab, n);
    delete [] tab;
}