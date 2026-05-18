#include <iostream>
using namespace std;

// Abstract Base Class
class RekeningBank {
protected:
    double saldo;

    public:
    RekeningBank(double s) {
        saldo = s;
    }

    virtual void potongAdmin() = 0;

    void tampilSaldo() {
        cout << "Saldo akhir : Rp " << saldo << endl;
    }

    virtual ~RekeningBank() {}
};

// Rekening Syariah
class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        cout << "Rekening Syariah bebas biaya admin." << endl;
    }
};

// Rekening Konvensional
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 dipotong." << endl;
    }
};

// Rekening Premium
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "Saldo di atas Rp 10.000.000, bebas biaya admin." << endl;
        } else {
            saldo -= 50000;
            cout << "Biaya admin Rp 50.000 dipotong." << endl;
        }
    }
};

int main() {

    RekeningBank *r1 = new RekeningSyariah(5000000);
    RekeningBank *r2 = new RekeningKonvensional(5000000);
    RekeningBank *r3 = new RekeningPremium(8000000);
    RekeningBank *r4 = new RekeningPremium(15000000);

    cout << "\n=== Rekening Syariah ===" << endl;
    r1->potongAdmin();
    r1->tampilSaldo();

    cout << "\n=== Rekening Konvensional ===" << endl;
    r2->potongAdmin();
    r2->tampilSaldo();

    cout << "\n=== Rekening Premium 1 ===" << endl;
    r3->potongAdmin();
    r3->tampilSaldo();

    cout << "\n=== Rekening Premium 2 ===" << endl;
    r4->potongAdmin();
    r4->tampilSaldo();

    delete r1;
    delete r2;
    delete r3;
    delete r4;

    return 0;
}