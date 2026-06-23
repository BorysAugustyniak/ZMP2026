#include <iostream>

using namespace std;

void merge(int*& tab, int*& help, int left, int middle, int right, int& diff){
    int i = left;
    int j = middle + 1;
    int k = left;

    //dwie tablice są "mergowane"
    //tablice 1 i 2 są posortowane i maksymalna różnica wśród tych tablic jest uwzględniona w wyniku

    //zanim posortujemy tablice to musimy odnaleźć maksymalną różnicę wsród tych elementów
    //
    //rozpatrzyliśmy już różnice między elementami z tablicy 1 i analogicznie z tablicy 2,
    //więc zostały tylko różnice między pewnym elementem z tablicy 1 i elementem z tablicy 2
    //
    //natomiast tablice 1 i 2 są posortowane, więc wystarczy rozpatrzyć różnicę z elementem
    //najbardziej po prawo z tablicy 2 (największym w tej tablicy), a elementem najbardziej
    //po lewo z tablicy 1 (najmniejszym w tej tablicy), bo wszystkie inne różnice będe mniejsze
    //bądź równe do różnicy tab[right]- tab[left]
    diff = max(diff, tab[right] - tab[left]);

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

void mergesort_bottom(int*& tab, int*& help, int size, int& diff){
    for (int set_size = 1; set_size < size; set_size *= 2){
        for (int left = 0; left < size; left += 2 * set_size){
            int middle = min(size - 1, left + set_size - 1);
            int right = min(size - 1, left + 2 * set_size - 1);
            merge(tab, help, left, middle, right, diff);
        }
    }
}

void mergesort(int*& tab, int size, int& diff){
    int* help = new int[size];
    for (int i = 0; i < size; ++i){
        help[i] = tab[i];
    }
    mergesort_bottom(tab, help, size, diff);
    delete [] help;
}

int main(){
    int difference = 0;
    int n;
    cin >> n;
    int* tab = new int[n];
    for (int i = 0; i < n; ++i){
        cin >> tab[i];
    }
    mergesort(tab, n, difference);
    cout << difference;
    delete [] tab;
}