#include <iostream>
#include "fstream"
using namespace std;

struct Tarih
{
	int Gün;
	int Ay;
	int Yil;

};

struct Personel_Bilgi
{
	Tarih Ptarih;
	char Ad[30];
	char Soyad[50];
	int No;
	int Is_günü;
	int Izin_Sayisi;
	int Maas;

};

Personel_Bilgi Veri()
{
	Personel_Bilgi PBilgi;
    cout<<"Personel Adi:" ;
    cin>>PBilgi.Ad;
	cout<<"Personel Soyadi:" ;
    cin>>PBilgi.Soyad;
	cout<<"Personel No:" ;
    cin>>PBilgi.No;
	cout<<"Personelin Kullandigi Izin Sayisi:" ;
    cin>>PBilgi.Izin_Sayisi;
return PBilgi;
}
void VeriYaz(Personel_Bilgi Prs)
{
	ofstream VeriY;
	VeriY.open("Personel.Bin");
	VeriY << Prs.Ad << Prs.Soyad << Prs.No << Prs.Izin_Sayisi; 
	VeriY.close();
}
void main()
{
Personel_Bilgi PrsBlg;

PrsBlg=Veri();
VeriYaz(PrsBlg);
system("pause");

}


