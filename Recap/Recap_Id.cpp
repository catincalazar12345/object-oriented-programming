#include<iostream>
using namespace std;
//const declared inside the class, default values inside the class, id generators
class Abonat {
    const int id; // se genereaza, nu se primeste ca param
    string detinator = "Anonim";
    int nrContacte = 0;
    string* contacte = nullptr;
    static int generatorID;

public:
    Abonat() : id(++Abonat::generatorID) {}
    Abonat(const string& _detinator, int _nrContacte, string* _contacte)
        :detinator(_detinator), id(++Abonat::generatorID) {
        if (_nrContacte > 0) {
            this->nrContacte = _nrContacte;
            this->contacte = new string[this->nrContacte];
            for (int i = 0; i < this->nrContacte; ++i) {
                this->contacte[i] = _contacte[i];
            }
        }
    }
    Abonat(const Abonat& ab) :id(++Abonat::generatorID), detinator(ab.detinator) { //acelasi detinator, ID diferit
        if (ab.nrContacte > 0 && ab.contacte != nullptr) {
            this->nrContacte = ab.nrContacte;
            this->contacte = new string[this->nrContacte];
            for (int i = 0; i < this->nrContacte; ++i) {
                this->contacte[i] = ab.contacte[i];
            }
        }
    }
    Abonat& operator=(const Abonat& ab) {
        if (this != &ab) {
            delete[] this->contacte;
            this->contacte = nullptr;
            if (ab.nrContacte > 0 && ab.contacte != nullptr) {
                for (int i = 0; i < this->nrContacte; ++i) {
                    this->contacte[i] = ab.contacte[i];
                }
            }
            else {
                this->nrContacte = 0;
                this->contacte = nullptr;
            }
        }
        return *this;

    }
    void afisare() const {
        cout << "\n=====================\n";
        cout << "ID: " << this->id << endl;
        cout << "Detinator: " << this->detinator << endl;
        cout << "Nr Contacte: " << this->nrContacte << endl;
        cout << "Numele contactelor: " << endl;
        for (int i = 0; i < nrContacte; ++i) {
            cout << contacte[i] << " ; ";
        }
        cout << "\n=====================\n";
    }
    ~Abonat() {
        delete[] this->contacte;
        this->contacte = nullptr;
    }
};


int Abonat::generatorID = 100;

int main() {
    Abonat ab1;
    ab1.afisare();
    string agenda[] = { "Popescu Ionel", "Ariana Grande", "Ionescu Ionela" };
    Abonat a2("Lazar Catinca", 3, agenda);
    a2.afisare();
	return 0;
}