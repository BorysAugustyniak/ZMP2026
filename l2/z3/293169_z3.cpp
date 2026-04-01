#include <iostream>

using namespace std;

int main(){
    int secret[8];
    int message[8];
    for (int i = 0; i < 8; ++i){
        cin >> secret[i];
    }
    for (int i = 0; i < 8; ++i){
        cin >> message[i];
    }
    for (int i = 0; i < 8; ++i){
        cout << (secret[i] ^ message[i]);
        if (i != 7) cout << " ";
    }
}
