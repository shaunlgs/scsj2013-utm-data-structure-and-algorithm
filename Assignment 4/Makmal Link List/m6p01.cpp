//Aturcara makmal 6 p02
//Aturcara Senarai berpaut menggunakan penuding

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef char ELEM;

class nod{
public:
   ELEM Name[25];
   ELEM NoKP[15];
   ELEM NoMetrik[9];
   ELEM Kursus[5];
   ELEM Kedudukan[3];
   nod *paut;
   nod(const ELEM Nama[25],const ELEM nokp[15],const ELEM nomat[9],const ELEM kursus[5],const ELEM kedudukan[3]);
   ~nod();
};

class SenaraiPaut
{
private:
   nod* kepala;
   nod* sblm;
   nod* semasa;
   int bil;
public:
   SenaraiPaut();
   ~SenaraiPaut();
   void setPos (const ELEM[]);
   void input (const ELEM Nama[],const ELEM nokp[],const ELEM nomat[],const ELEM kursus[],const ELEM kedudukan[]);
   void papar();
   void hapus (const ELEM[]);
   int length() const;
	bool kosong() const;
   bool cari (const ELEM[]);
};

nod::nod(const ELEM Nama[25],const ELEM nokp[15],const ELEM nomat[9],const ELEM kursus[5],const ELEM kedudukan[3])
{
   strcpy(Name,Nama);
   strcpy(NoKP,nokp);
   strcpy(NoMetrik,nomat);
   strcpy(Kursus,kursus);
   strcpy(Kedudukan,kedudukan);
}

nod::~nod()
{
  if(paut!=NULL)	paut = NULL;
}

SenaraiPaut::SenaraiPaut()
{
   semasa=NULL;
   kepala=NULL;
   bil=0;
}

SenaraiPaut::~SenaraiPaut()
{
   delete kepala;
   delete semasa;
   delete sblm;
}

void SenaraiPaut::setPos(const ELEM Nama[])
{
   sblm=NULL;
   semasa=kepala;
   while ((semasa!=NULL) && (strcmp(semasa->Name,Nama)<0))
   {
   	sblm=semasa;
	semasa=semasa->paut;
   }
}

void SenaraiPaut::input(const ELEM Nama[],const ELEM nokp[],const ELEM nomat[],
const ELEM kursus[],const ELEM kedudukan[])
{
nod *n=new nod(Nama,nokp,nomat,kursus,kedudukan);
setPos(Nama);

   if (sblm==NULL)
   {	n->paut=NULL;
   	kepala=n;
   }
   if ((sblm==NULL) && (kepala !=NULL))
   	{	n->paut=semasa;
      	kepala=n;
      }
      else
      {
      n->paut=semasa;
      sblm->paut=n;
      }
      bil++;
   }


void SenaraiPaut::hapus(const ELEM Nama[])
{
  ELEM ThisNama[25];
  setPos(Nama);
  if(semasa !=NULL && strcmp(semasa->Name,Nama)==0)

    {	strcpy(ThisNama,Nama);
        if (sblm==NULL)
                kepala=semasa->paut;
            else
                sblm->paut=semasa->paut;

        semasa->paut=NULL;
        delete semasa;
        semasa=NULL;
        bil--;
     }

  else

    {	cout<<"Tiada dalam senarai!"<<"\n";
        strcpy(ThisNama,"Tiada");
     }
}

void SenaraiPaut::papar()
{

nod *n;
  n=kepala;
  while (n!=NULL)

    {	cout<<n->Name<<"\t"<<n->NoKP<<"\t"<<n->
     NoMetrik<<"\t"<<n->Kursus<<"\t"<<n->Kedudukan<<"\n";
        n=n->paut;
     }
}

bool SenaraiPaut::kosong() const

{
return kepala==NULL;
}

int SenaraiPaut::length() const
{
return bil;
}

bool SenaraiPaut::cari(const ELEM Nama[])
{

nod *n;
  n=kepala;
  bool jumpa=false;
  while (n!=NULL)
{
if (strcmp(n->Name,Nama)==0)
    jumpa=true;
  n=n->paut;
}
  return jumpa;
}


int main()
{
    SenaraiPaut L;
    FILE *MyFile;
    char Nama[25];
    char noic[15];
    char NoMetrik[9];
    char kursus[4];
    char kedudukan[3];

    L.input("Rosli Bin Abd Rahman", "720506-01-3365", "AC345298", "4SCK", "KB");
    L.input("Rokiah Bt Seh       ", "730304-02-3324", "AC786509", "4SKK", "KB");
    L.input("Rosmalawate Bt Rosli", "730109-10-5432", "AC234193", "4SKE", "KS");
    L.input("Saruddin Bin Rosli  ", "721010-08-4321", "AC871290", "2SKJ", "KS");

    cout<<"Latihan Makmal Senarai Berpaut Penuding\n";
    cout<<"\n";
    cout<<"Nod yang ada dalam senarai:"<<"\n";
    L.papar();
    cout<<"\n";
    cout<<"Bilangan Nod Dalam Senarai:"<<"\n";
    cout<<L.length();

    L.hapus("Rosmalawate Bt Rosli");
    cout<<"\n";
    cout<<"\n";
    cout<<"Nod selepas penghapusan dilakukan:"<<"\n";
    L.papar();
    cout<<"\n";
    cout<<"Bilangan nod selepas penghapusan dilakukan:"<<"\n";
    cout<<L.length();

    cout<<"\n";
    cout<<"TAMAT"<<"\n";
    cout<<"\n";

    return 0;
}
/* output
Latihan Makmal Senarai Berpaut Penuding

Nod yang ada dalam senarai:
Rokiah Bt Seh           730304-02-3324  AC786509        4SKK    KB
Rosli Bin Abd Rahman    720506-01-3365  AC345298        4SCK    KB
Rosmalawate Bt Rosli    730109-10-5432  AC234193        4SKE    KS
Saruddin Bin Rosli      721010-08-4321  AC871290        2SKJ    KS

Bilangan Nod Dalam Senarai:
4

Nod selepas penghapusan dilakukan:
Rokiah Bt Seh           730304-02-3324  AC786509        4SKK    KB
Rosli Bin Abd Rahman    720506-01-3365  AC345298        4SCK    KB
Saruddin Bin Rosli      721010-08-4321  AC871290        2SKJ    KS

Bilangan nod selepas penghapusan dilakukan:
3
TAMAT
*/
