#include <iostream>
#include <string>

using namespace std;

class Pojazd{
    protected:
        string marka;
        string model;
        int rok_produkcji;
    public:
        Pojazd (string mark, string mode, int rok){
            marka = mark;
            model = mode;
            rok_produkcji = rok;
        }
        virtual void wyswietl(){};
};

class Samochod : public Pojazd{
    private:
        int liczba_drzwi;
    public:
        Samochod (string mark, string mode, int rok, int drzwi) : Pojazd (mark, mode, rok){
            liczba_drzwi = drzwi;
        }
        void wyswietl() override{
            cout << "Ten samochód to " << marka << ", model " << model << ", stworzony w " << rok_produkcji << " o liczbie drzwi: " << liczba_drzwi << "\n";
        };
};

class Rower: public Pojazd{
    private:
        int liczba_przerzutek;
    public:
        Rower (string mark, string mode, int rok, int prze) : Pojazd (mark, mode, rok){
            liczba_przerzutek = prze;
        }
        void wyswietl() override{
            cout << "Ten rower to " << marka << ", model " << model << ", stworzony w " << rok_produkcji << " o liczbie przerzutek: " << liczba_przerzutek << "\n";
        };
};

int main(){
    string marka_sam, model_sam, marka_row, model_row;
    int rok_sam, drzwi_sam, rok_row, prze_row;
    cin >> marka_sam >> model_sam >> rok_sam >> drzwi_sam;
    cin >> marka_row >> model_row >> rok_row >> prze_row;
    Samochod s(marka_sam, model_sam, rok_sam, drzwi_sam);
    Rower r(marka_row, model_row, rok_row, prze_row);
    s.wyswietl();
    r.wyswietl();
}
