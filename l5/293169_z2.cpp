#include <iostream>

using namespace std;

void merge(int*& tab, int*& help, int left, int middle, int right){
    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right){
        if (tab[i] <= tab[j]){
            help[k] = tab[i];
            ++i;
        }
        else{
            help[k] = tab[j];
            ++j;
        }
        ++k;
    }
    while (i <= middle){
        help[k] = tab[i];
        ++i;
        ++k;
    }

    for (int l = left; l <= right; ++l){
        tab[l] = help[l];
    }
}

void mergesort_bottom(int*& tab, int*& help, int size){
    for (int set_size = 1; set_size < size; set_size *= 2){
        for (int left = 0; left < size; left += 2 * set_size){
            int middle = min(size - 1, left + set_size - 1);
            int right = min(size - 1, left + 2 * set_size - 1);
            merge(tab, help, left, middle, right);
        }
    }
}

void mergesort(int*& tab, int size){
    int* help = new int[size];
    for (int i = 0; i < size; ++i){
        help[i] = tab[i];
    }
    mergesort_bottom(tab, help, size);
    delete [] help;
}

int main(){
    int n;
    cin >> n;
    int* tab = new int[n];
    for (int i = 0; i < n; ++i){
        cin >> tab[i];
    }
    mergesort(tab, n);
    for (int i = 0; i < n; ++i){
        cout << tab[i] << " ";
    }
    cout << endl;
    delete [] tab;
}