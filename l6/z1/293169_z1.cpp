#include <iostream>

using namespace std;

struct OjciecMateusz{
    int size = 0;
    int capacity = 1;
    int* tab = nullptr;
    void reduce_cap(){
        capacity /= 2;
        int* placeholder = new int[capacity];
        for (int i = 0; i < size; ++i){
            placeholder[i] = tab[i];
        }
        delete [] tab;
        tab = placeholder;
    }
    void increase_cap(){
        capacity *= 2;
        int* placeholder = new int[capacity];
        for (int i = 0; i < size; ++i){
            placeholder[i] = tab[i];
        }
        delete [] tab;
        tab = placeholder;
    }
    void push(int x){
        if (size == capacity){
            increase_cap();
        }
        tab[size] = x;
        ++size;
    }
    void pop(){
        if (size != 0){
            tab[size - 1] = 0;
            --size;    
            if (2 * size <= capacity){
                reduce_cap();
            }
        }
    }
    int get_size() {return size;}
    int get_capacity() {return capacity;}
    int get_item(int n) {
        if (n >= 0 && (n + 1) <= size) {return tab[n];}
    }
    void merge(int*& help, int left, int middle, int right){
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
    void mergesort_copy(int*& help, int left, int right){
        if (left < right){
            int middle = (left + right) / 2;
            mergesort_copy(help, left, middle);
            mergesort_copy(help, middle + 1, right);
            merge(help, left, middle, right);
        }
    }
    void mergesort(){
        int* help = new int[size];
        for (int i = 0; i < size; ++i){
            help[i] = tab[i];
        }
        mergesort_copy(help, 0, size - 1);
        delete [] help;
    }
};

int main(){
    int n;
    cin >> n;
    OjciecMateusz mietek{.size = n, .capacity = n};
    mietek.tab = new int[mietek.capacity];
    for (int i = 0; i < n; ++i){
        cin >> mietek.tab[i];
    }
    mietek.mergesort();
    for (int i = 0; i < n; ++i){
        cout << mietek.tab[i] << " ";
    }
    delete [] mietek.tab;
}
