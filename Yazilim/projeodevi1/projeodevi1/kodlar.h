#include<iostream>
using namespace std;
#include <fstream>
	


#ifndef proje
#define proje

struct Tarih
{

	int Gun;
	int Ay;
	int Yil;

};

struct PersonelBilgi
{
	int No;
	char Adi[30];
	char Soyadi[30];
	char Cinsiyet;
	int yas;
	int izinliGun;
	int isGunu;
	float Maas;
	float maasKatsayisi;
	Tarih DogumTarihi;
	Tarih iseGirisTarihi;

};
struct Baglilar
{
	int BagliOlduguPersonelNo;
	char Adi[30];
	char Soyadi[30];
	char Cinsiyet;
	int yas;
	Tarih DogumTarihi;
};

int NumaraBul()
{
		ifstream DO;	
		PersonelBilgi PB;
		int No=1001;
			DO.open("Personel.Bin");	
			while(!DO.eof())			
			{
				DO >> PB.No >> PB.Adi >> PB.Soyadi >> PB.Cinsiyet >> PB.yas>>PB.izinliGun>>PB.isGunu>>PB.Maas>>PB.maasKatsayisi>>PB.DogumTarihi.Gun>>PB.DogumTarihi.Ay>>PB.DogumTarihi.Yil>>PB.iseGirisTarihi.Gun>>PB.iseGirisTarihi.Ay>>PB.iseGirisTarihi.Yil;		
				No=PB.No+1;
			}
	

			DO.close();		
        return No;
}

void BaglilarVeriGir(int No)
{
	Baglilar Bg;
	Bg.BagliOlduguPersonelNo=No;
	cout<<"Adi";
	cin>>Bg.Adi;

	cout<<"Soyadi";
	cin>>Bg.Soyadi;

	cout<<"Cinsiyet";
	cin>>Bg.Cinsiyet;

	cout<<"Yas";
	cin>>Bg.yas;

	cout<<"Dogum Tarihi gun ay yil";
	cin>>Bg.DogumTarihi.Gun>>Bg.DogumTarihi.Ay>>Bg.DogumTarihi.Yil;
	
	ofstream Cikis;
	Cikis.open("Baglilar.Bin",ios::out|ios::binary);

Cikis.write((char*)&Bg,sizeof(Bg));
cout<<"Yeni Bir Bagli Eklendi"<<endl;
	


	Cikis.close();
	system("pause");

}
PersonelBilgi PersonelVeriGir()
{
			PersonelBilgi PrsB;
			
			PrsB.No=NumaraBul();
			cout<<"Adi:";
			cin>>PrsB.Adi;
			cout<<"Soyadi:";
			cin>>PrsB.Soyadi;
			cout<<"Cinsiyet:";
			cin>>PrsB.Cinsiyet;
			cout<<"Yas:";
			cin>>PrsB.yas;

			cout<<"Dogum Tarihi gun ay yil :";
			cin>>PrsB.DogumTarihi.Gun>>PrsB.DogumTarihi.Ay>>PrsB.DogumTarihi.Yil;
		    cout<<"ise giris Tarihi gun ay yil :";
			cin>>PrsB.iseGirisTarihi.Gun>>PrsB.iseGirisTarihi.Ay>>PrsB.iseGirisTarihi.Yil;

			cout<<"Oldugumuz Ayin Gun Sayisi:";
			int AyinGunSayisi;
			cin>>AyinGunSayisi;
			cout<<"izinli gün sayisi:";
			cin>>PrsB.izinliGun;
			cout<<"Maas Katsayisi:";
			cin>>PrsB.maasKatsayisi;

			PrsB.isGunu=AyinGunSayisi-PrsB.izinliGun;
			PrsB.Maas=PrsB.isGunu*PrsB.maasKatsayisi;



			int BagliAdet;
			cout<<"Personel Baglilar Adedi Giriniz:";
			cin>>BagliAdet;
				
			for(int i=0;i<BagliAdet;i++)
				{
				BaglilarVeriGir(PrsB.No);
		
				}
		return PrsB;
}




void Menu(int &secim)
{
	
		cout<<"0. Yeni Kayit Girisi"<<endl;
		cout<<"1. Kayit Düzeltme ve izin Girisi (Personel No ya Gore)"<<endl;
		cout<<"2. Kayit Silme (Personel No ya Gore)"<<endl;
		cout<<"3. Kayit Arama ve goruntuleme (Alt Menu)"<<endl;
		cout<<"4. Kayit Listeleme (Alt Menu)"<<endl;
		cout<<"5. Personel Maas Hesaplama"<<endl;
		cout<<"6. Cikis"<<endl;
		cout<<"Bir Secim Yapiniz:";
		cin>>secim;
		
		
		switch(secim)
		{

		case 0:
			cout<<"::Personel Yeni Kayit Girisi::"<<endl;
				PersonelBilgi Personel1;
				Personel1=PersonelVeriGir();
	
				ofstream Cikis;
				Cikis.open("Personel.Bin",ios::out|ios::binary);

			Cikis.write((char*)&Personel1,sizeof(Personel1));
				Cikis.close();
				cout<<"Yeni Personel Kaydi Yapildi"<<endl;
				break;
	
		}

}

#endif