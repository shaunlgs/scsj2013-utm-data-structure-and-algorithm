#include <iostream>
using namespace std;

// Program 2.13
class nombor
{
    int nom1, nom2;
    public:
        nombor(int, int);
        void ubahnom(int, int);
        int get_nom1() { return nom1; }
        int get_nom2() { return nom2; }
};

nombor::nombor(int no1, int no2)
{
    nom1 = no2;
    nom2 = no1;
}

void nombor::ubahnom(int ubahno1, int ubahno2)
{
    nom1 += ubahno2;
    nom2 += ubahno1;
}

void kira(nombor& N)
{
    if((N.get_nom1() < 0) || (N.get_nom2() < 0))
    {
        N.ubahnom(5,2);
        cout << "\nNom 1 dalam fungsi = " << N.get_nom1();
        cout << "\nNom 2 dalam fungsi = " << N.get_nom2();
    }
    else
    {
        cout << "\nTiada perubahan pada Nom 1 dan Nom 2";
    }
}

int main()
{
    nombor uji(-3, 8);
    cout << "\nNilai bagi Nom 1 = " << uji.get_nom1();
    cout << "\nNilai bagi Nom 2 = " << uji.get_nom2();
    kira(uji);
    cout << "\nNilai bagi Nom 1 = " << uji.get_nom1();
    cout << "\nNilai bagi Nom 2 = " << uji.get_nom2();
}






























