// Program 6.1
#include <iostream>
using namespace std;

int CarianJujukan(int [], int, int);

int main()
{
    int nom[100];
    int k, target, j;
    char ans = 'y';

    cout << "Masukkan saiz tatasusunan:";
    cin >> k;
    for(int i=0; i<k; i++)
    {
        cout << "nom[" << i << "]=";
        cin >> nom[i];
    }
    do
    {
        cout << "\nMasukkan nombor yang ingin dicari :";
        cin >> target;
        j = CarianJujukan(nom, k, target);
        if(j==-1)
            cout << "gagal" << endl;
        else
                cout << "berjaya iaitu unsur nom[ " << j << "]\n";
        cout << "Cari nombor yang lain?:";
        cin >> ans;
    }
    while(ans=='y');

    return 0;
}
int CarianJujukan(int a[], int n, int target)
{
    int i;
    for(i=0; i<n; i++)
        if(a[i] == target)
            return i;
        return -1;
}

/*output
Masukkan saiz tatasusunan:10
nom[0]=8
nom[1]=4
nom[2]=10
nom[3]=5
nom[4]=20
nom[5]=4
nom[6]=15
nom[7]=23
nom[8]=12
nom[9]=11

Masukkan nombor yang ingin dicari :5
berjaya iaitu unsur nom[ 3]
Cari nombor yang lain?:y

Masukkan nombor yang ingin dicari :4
berjaya iaitu unsur nom[ 1]
Cari nombor yang lain?:y

Masukkan nombor yang ingin dicari :25
gagal
Cari nombor yang lain?:n
*/
