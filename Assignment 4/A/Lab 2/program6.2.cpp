// Program 6.1
#include <iostream>
using namespace std;

int CarianPduaan(int [], int, int);

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
        j = CarianPduaan(nom, k, target);
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
int CarianPduaan(int a[], int n, int target)
{
    int first = 0;
    int last = n - 1;
    int mid;
    while(first <= last)
    {
        mid = (first + last) / 2;
        if(target == a[mid])
            return mid;
        else if (target < a[mid])
        {
            last = mid - 1;
            cout << "nilai tengah:" << mid << "\tmula:" << first << "\takhir:" << last << endl;
        }
        else
        {
                first = mid + 1;
        cout << "nilai tengah:" << mid << "\tmula:" << first << "\takhir:" << last << endl;
        }
    }
    return -1;
}

/*output
Masukkan saiz tatasusunan:10
nom[0]=2
nom[1]=5
nom[2]=6
nom[3]=8
nom[4]=10
nom[5]=12
nom[6]=15
nom[7]=16
nom[8]=20
nom[9]=21

Masukkan nombor yang ingin dicari :5
nilai tengah:4  mula:0  akhir:3
berjaya iaitu unsur nom[ 1]
Cari nombor yang lain?:y

Masukkan nombor yang ingin dicari :20
nilai tengah:4  mula:5  akhir:9
nilai tengah:7  mula:8  akhir:9
berjaya iaitu unsur nom[ 8]
Cari nombor yang lain?:y

Masukkan nombor yang ingin dicari :25
nilai tengah:4  mula:5  akhir:9
nilai tengah:7  mula:8  akhir:9
nilai tengah:8  mula:9  akhir:9
nilai tengah:9  mula:10 akhir:9
gagal
Cari nombor yang lain?:n
*/
