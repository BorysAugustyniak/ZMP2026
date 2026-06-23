#include <iostream>

using namespace std;

void merge(int*& tab, int*& help, int left, int middle, int right, int& inv){
    int i = left;
    int j = middle + 1;
    int k = left;

    //dwie tablice są "mergowane"
    //tablice 1 i 2 są posortowane i inwersje wśród nich są policzone
    while (i <= middle && j <= right){
        if (tab[i] <= tab[j]){
            help[k] = tab[i];
            ++i;
        }
        else{
            help[k] = tab[j];
            ++j;
            //dodajemy tyle inwersji ile pozostałych liczb w tablicy 1,
            //bo te liczby są większe od tej liczby z tablicy 2, którą właśnie dodaliśmy
            //do tablicy połączonej
            inv += middle - i + 1;
        }
        ++k;
    }
    while (i <= middle){
        help[k] = tab[i];
        ++i;
        ++k;
    }
    //nie trzeba dodawać while dla przypadku jeśli zostaną elementy z prawej listy,
    //bo one są już wtedy we właściwych miejscach

    for (int l = left; l <= right; ++l){
        tab[l] = help[l];
    }
}

void mergesort_top(int*& tab, int*& help, int left, int right, int& inv){
    if (left < right){
        int middle = (left + right) / 2;
        mergesort_top(tab, help, left, middle, inv);
        mergesort_top(tab, help, middle + 1, right, inv);
        merge(tab, help, left, middle, right, inv);
    }
}

void mergesort(int*& tab, int size, int& inv){
    int* help = new int[size];
    for (int i = 0; i < size; ++i){
        help[i] = tab[i];
    }
    mergesort_top(tab, help, 0, size - 1, inv);
    delete [] help;
}

int main(){
    int inversion = 0;
    int n;
    cin >> n;
    int* tab = new int[n];
    for (int i = 0; i < n; ++i){
        cin >> tab[i];
    }
    mergesort(tab, n, inversion);
    cout << inversion;
    delete [] tab;
}