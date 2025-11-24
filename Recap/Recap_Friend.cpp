#include<iostream>
using namespace std;

class Produs {
    string denumire = "Anonim";
    double pret = 0;

public:
    Produs() {};
    Produs(string _denumire, double _pret) {
        this->denumire = _denumire;
        this->pret = _pret;
    }
    Produs(Produs& prod) {
        this->denumire = prod.denumire;
        this->pret = prod.pret;
    }
    Produs& operator=(const Produs& p) {
        this->denumire = p.denumire;
        this->pret = p.pret;
    }
    void afisare() {
        cout << "\nDenumire: " << this->denumire << ", pret: " << this->pret;

    }
    friend ostream& operator<<(ostream& os, const Produs& p);
    
};
ostream& operator<<(ostream& os, const Produs& p) {
    os << "\nDenumire:" << p.denumire << "\nPret:" << p.pret;
    return os;
}

class Wishlist {
    //vector dinamic de Produs
    Produs* lista = nullptr;
    int nrProduse = 0;
    double buget = 0;
public:
    Wishlist() {}

    Wishlist(Produs* _lista, int _nrProduse, double _buget) {
        if (_nrProduse > 0 && _lista != nullptr) {
            this->nrProduse = _nrProduse;
            this->lista = new Produs[this->nrProduse]; // apel constructor fara param
            for (int i = 0; i < _nrProduse; ++i)
                this->lista[i] = _lista[i]; // operator = clasa Produse (deep copy)
        }
        this->buget = _buget;
    }

    Wishlist(const Wishlist& ws) {
        if (ws.lista != nullptr && nrProduse > 0) {
            this->nrProduse = ws.nrProduse;
            this->lista = new Produs[this->nrProduse];
            for (int i = 0; i < this->nrProduse; i++) {
                this->lista[i] = ws.lista[i];
            }
        }
        this->buget = ws.buget;
    }

    Wishlist& operator=(const Wishlist& ws) {
        if (this != &ws) {
            if (this->lista != nullptr) {
                delete[] this->lista;
                this->lista = nullptr;
            }

            if (ws.lista != nullptr && nrProduse > 0) {
                this->nrProduse = ws.nrProduse;
                this->lista = new Produs[this->nrProduse];
                for (int i = 0; i < this->nrProduse; i++) {
                    this->lista[i] = ws.lista[i];
                }
            }
            this->buget = ws.buget;
        }
        return *this;

    }
    const Produs& operator[](int idx) {
        if (idx >= 0 && idx < this->nrProduse) {
            return this->lista[idx];
        }
        else {
            throw exception("Index-ul nu e valid");
        }
    }
    void afisare() {
        cout << "\n----------------------";
        cout << "\nnr produse: " << this->nrProduse;
        for (int i = 0; i < this->nrProduse; i++) {
            cout << this->lista[i];
        }
        cout << "\nBuget: " << this->buget;
        cout << "\n----------------------";
    }

    friend ostream& operator<<(ostream& os, const Wishlist& w);

    ~Wishlist() {
        delete[] this->lista;
        this->lista = nullptr;
    }
};
ostream& operator<<(ostream& os, const Wishlist& w) {
    os << "\n----------------------";
    os << "\nnr produse: " << w.nrProduse;
    for (int i = 0; i < w.nrProduse; i++) {
        os << w.lista[i];
    }
    os << "\nBuget: " << w.buget;
    os << "\n----------------------";
    return os;
}


int main() {
    Produs p1("Sosete", 15);
    Produs p2("Calculator", 5000);
    cout << p1;
    Produs vProd[] = { p1,p2 };
    Wishlist w1(vProd, 2, 500);
    Wishlist w2 = w1;
    Wishlist w3;
    w3 = w1;
    cout << w1;
    Produs p3;
    int idx = 15; //introduc indexul intr-o var
    bool valid=false;
    while (!valid) {//while true
        try {
            p3 = w2[idx];
            valid = true;//asta se inampla doar daca linia de mai sus merge
            cout << p3;
        }
        catch (exception err) {
            cout << endl << err.what();
            cout << "Reintrodu idx:";
            cin >> idx;
        }
    }
	return 0;
}