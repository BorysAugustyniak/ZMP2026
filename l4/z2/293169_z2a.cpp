#include <iostream>

using namespace std;

/*void arrcout(int* tab, int len){
    for (int i = 0; i < len; ++i){
        cout << tab[i] << " ";
    }
}*/

void subsets(int* tab, int len){
    int check;
    int power2;
    int sublen = (1 << len);
    for (int i = 0; i < sublen; ++i){
        power2 = 1;
        if (i == 0) cout << "empty";
        else
        {
            for (int j = 0; j < len; ++j){
                check = i & power2;
                power2 *= 2;
                if (check != 0){
                    cout << tab[j] << " ";
                }
            }
        }
        cout << "\n";
    }
}

int main(){
    int n;
    cin >> n;
    int* tab = new int[n];
    for (int i = 0; i < n; ++i){
        cin >> tab[i];
    }
    subsets(tab, n);
    delete [] tab;
}
