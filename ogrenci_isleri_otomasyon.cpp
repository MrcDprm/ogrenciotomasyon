/*
		2212729013
		
		Miraç DEPREM
*/

#include <iomanip> 
#include <cstring> 
#include <stdlib.h>
#include <conio.h>
#include <stdio.h> 
#include <fstream>                  
#include <iostream>
#include <locale.h>

using namespace std;

struct Ogrenci
{
	char ad[80];
	char soyad[80];
	char ogr_no[5];
	char cinsiyet;	
};

void OgrenciEkle();
void OgrenciListeleme();
void OgrenciArama();
void OgrenciSil();
void OgrenciDuzenle();

int main()
{
	setlocale(LC_ALL, "Turkish");
	char anamenu;
	do
	{	
		system("cls");
		cout << "|-------Hoþgeldiniz------|" << endl ;
		cout << "|      Seçim Yapýnýz     |" << endl ;
		cout << "|   1- Ögrenci Ekleme    |" << endl ;
		cout << "|   2- Ögrenci Listeleme |" << endl ;
		cout << "|   3- Ögrenci Arama     |"<< endl;
		cout << "|   4- Ögrenci Silme     |"<< endl;
		cout << "|   5- Ögrenci Duzenleme |"<< endl;
		cout << "|------------------------|" << endl ;
    	char secim;
		cin >> secim;
	
		switch(secim) 
		{
			case '1' : 
			{
				OgrenciEkle();
				break;	
			}
			case '2' : 
			{
		 		OgrenciListeleme();
		 		break;
			}
			case '3' : 
			{
		 		OgrenciArama();
		 		break;
			}
			case '4' : 
			{
		 		OgrenciSil();
		 		break;
			}
			case '5' : 
			{
		 		OgrenciDuzenle();
		 		break;
			}
		}
		cout << "Ana menüye dönmek için(a) çýkmak için(c) basýn: " << endl ; 
		anamenu = getche();
	
    } while(anamenu == 'a');
	return 0;
}

Ogrenci ogr;

void OgrenciEkle()
{
	setlocale(LC_ALL, "Turkish");
	ofstream yaz("ogrenci.dat",ios::binary |ios::app);
	char secim;
	int adet=0;
	
	do
	{
		cout << "Öðrenci Adýný Giriniz: ";
		cin >> ogr.ad;
		cout << endl;
		cout << "Öðrenci Soyadýný Giriniz: ";
		cin >> ogr.soyad;
		cout << endl;
		cout << "Öðrenci Numarasýný Giriniz: ";
		cin >> ogr.ogr_no;
		cout << endl;
		cout << "Öðrenci Cinsiyetini Giriniz (E/K): ";
		ogr.cinsiyet = getche();
		cout << endl;
		yaz.write((char*) & ogr, sizeof(ogr));	
		adet++;	
		cout << "Baþka kayýt eklemek ister misiniz? (E/H): ";
		secim = getche();
		cout << endl;
	} while(secim == 'e' || secim == 'E');
	cout << adet << " adet öðrenci eklendi.." << endl;	
	yaz.close();
}

void OgrenciListeleme()
{
	setlocale(LC_ALL, "Turkish");
	ifstream oku("ogrenci.dat", ios::binary | ios::app);	
	oku.seekg(0, ios::end);
	int kayits = oku.tellg() / sizeof(ogr);
	cout << "Toplam Öðrenci Kayýt Sayýsý: "<< kayits << endl;
	if(kayits > 0)
	{
		for(int i = 0; i < kayits; i++)
		{
			oku.seekg(i * sizeof(ogr));
			oku.read((char*) & ogr, sizeof(ogr));	
			cout << i + 1 << ". Öðrencinin Bilgileri"<< endl;
			cout << "Öðrencinin Adý: "<< ogr.ad << endl;
			cout << "Öðrenci Soyadý: "<< ogr.soyad << endl;
			cout << "Öðrencinin Numarasý: "<< ogr.ogr_no << endl;
			if(ogr.cinsiyet == 'e' || ogr.cinsiyet == 'E')
			{
				cout << "Öðrencinin Cinsiyeti: ERKEK " << endl;
			}
			else if(ogr.cinsiyet == 'k' || ogr.cinsiyet == 'K')
			{
				cout << "Öðrencinin Cinsiyeti: KADIN " << endl;
			}
		}		
	}
	else
	{	
		cout << "Kayýt Bulunamadý..." << endl;
	}
	oku.close();
}

void OgrenciArama()
{
	setlocale(LC_ALL, "Turkish");
	ifstream oku("ogrenci.dat", ios::binary |ios::app);
	oku.seekg(0, ios::end);
	int kayits = oku.tellg() / sizeof(ogr);
	cout << "Aranan öðrencinin numarasýný giriniz: " << endl;
	char ogr_no[80];
	cin >> ogr_no;
	if(kayits > 0)
	{
		for(int i = 0; i < kayits; i++)
		{
			oku.seekg(i * sizeof(ogr));
			oku.read((char*) & ogr, sizeof(ogr));		
			if(strcmp(ogr.ogr_no, ogr_no) == 0)
			{
				cout << "Bulunan Öðrencinin Bilgileri" << endl;
				cout << "Öðrencinin Adý: " << ogr.ad << endl ;
				cout << "Öðrencinin Soyadý: "<< ogr.soyad <<endl ;
				cout << "Öðrencinin Numarasý: "<< ogr.ogr_no <<endl ;
				if(ogr.cinsiyet == 'e' || ogr.cinsiyet=='E')
				{
					cout << "Öðrencinin Cinsiyeti: ERKEK " << endl ;
				}
				else if(ogr.cinsiyet=='k' || ogr.cinsiyet=='K')
				{
					cout << "Öðrencinin Cinsiyeti: KADIN " << endl ;
				}
		    }
		}
	}
	else
	{
		cout << "Kayýt Bulunamadý..." << endl;
	}
	oku.close();
}

void OgrenciSil()
{
	setlocale(LC_ALL, "Turkish");
	char ogrno[80];
    char secim = ' ';
    bool var = false;
    ifstream oku("ogrenci.dat", ios::binary |ios::app);
	oku.seekg(0, ios::end);
	int kayitsayisi = oku.tellg() / sizeof(ogr);
    cout<<"Kaydýný silmek istediðiniz öðrencinin numarasýný giriniz: ";
    cin >> ogrno;
    for(int i = 0; i < kayitsayisi; i++)
    {
        oku.seekg(i * sizeof(ogr));
		oku.read((char*)&ogr, sizeof(ogr));	
    	if(strcmp(ogr.ogr_no, ogrno) == 0)
    	{
            cout << endl;
            cout << "Öðrencinin";
            cout << "\nAdý: "<<ogr.ad;
            cout << "\nSoyadý: "<<ogr.soyad;
            cout << "\nNumarasý: "<<ogr.ogr_no;
            cout << "\nCinsiyeti: ";
            if(ogr.cinsiyet == 'e'|| ogr.cinsiyet == 'E')
            {
            	cout << "Erkek";
			}
            if(ogr.cinsiyet == 'k'|| ogr.cinsiyet == 'K')
            {
            	cout << "Kadýn";			  
        	}
			cout << "\n\nSilmek Ýstediðiniz Kayýt Bu Mu? [E/H]: ";
            secim = getche();
            if(secim == 'H' || secim == 'h')
            {      
				Ogrenci y_ogr;
                ofstream y_dosya("Yedek.dat", ios::app|ios::binary);
                strcpy(y_ogr.ad, ogr.ad);
                strcpy(y_ogr.soyad, ogr.soyad);
                strcpy(y_ogr.ogr_no, ogr.ogr_no);
                ogr.cinsiyet = y_ogr.cinsiyet;        
                y_dosya.write((char*) & ogr, sizeof(ogr));
                y_dosya.close();
            }
            if(secim == 'e'||secim == 'E')
            {
   				var=true;
  		 	}
        }
            else
            {
            	Ogrenci y_ogr;
            	ofstream y_dosya("Yedek.dat", ios::app|ios::binary);
            	strcpy(y_ogr.ad, ogr.ad);
            	strcpy(y_ogr.soyad, ogr.soyad);
              	strcpy(y_ogr.ogr_no, ogr.ogr_no);
              	ogr.cinsiyet = y_ogr.cinsiyet;       
              	y_dosya.write((char*) & ogr, sizeof(ogr));
              	y_dosya.close();
            }
    }
    oku.close();
    if(var)
    {
        remove("ogrenci.dat");
        rename("Yedek.dat", "ogrenci.dat");
        cout << "\n Kayýt Silindi" << endl;
    }
    else
    {
        remove("Yedek.dat");
        cout << "\n Kayýr Bulunamadý" << endl;                  
    }
}

void OgrenciDuzenle()
{
	setlocale(LC_ALL, "Turkish");
	char ogrno[80];
    char secim = ' ';
    bool var = false;
    ifstream oku("ogrenci.dat",ios::binary |ios::app);
	oku.seekg(0,ios::end);
	int kayitsayisi = oku.tellg() / sizeof(ogr);
    cout << "Kaydýný düzeltmek istediðiniz öðrencinin numarasýný giriniz: ";
    cin >> ogrno;
    cout << endl;
    for(int i=0;i<kayitsayisi;i++)
    {
    	oku.seekg(i * sizeof(ogr));
		oku.read((char*) & ogr, sizeof(ogr));
     	if(strcmp(ogr.ogr_no, ogrno) == 0)
     	{  	
        	cout << endl;
            cout << "Öðrencinin";
            cout << "\nAdý: " << ogr.ad;
            cout << "\nSoyadý: " << ogr.soyad<<endl;
            cout << "\nNumarasý: "<<ogr.ogr_no;
            cout << "\nCinsiyeti: ";
            if(ogr.cinsiyet == 'e'||ogr.cinsiyet == 'E')
            {
                cout << "Erkek";
            }
            if(ogr.cinsiyet == 'k'||ogr.cinsiyet == 'K')
            {
                cout << "Kadýn";
            }
            cout << "\n\nDüzeltmek Ýstediðiniz Kayýt Bu Mu? [E/H]: ";
            secim = getche();
            if(secim == 'E' || secim == 'e')
            {
                var = true;
                ofstream dosya("Yedek.dat", ios::app|ios::binary);
                cout << "\nÖðrencinin Adýný Giriniz: ";
				cin >> ogr.ad;
				cout << endl;
				cout << "Öðrencinin Soyadýný Giriniz: ";
				cin >> ogr.soyad;
				cout << endl;
				cout << "Öðrencinin Numarasýný Giriniz: ";
				cin>> ogr.ogr_no;
				cout << endl;
				cout << "Öðrencinin Cinsiyetini Giriniz (E/K): ";
				ogr.cinsiyet = getche();
				cout << endl;
                dosya.write((char*) & ogr, sizeof(ogr));
                dosya.close();
            }
            else
            {
                Ogrenci y_ogr;
                ofstream y_dosya;
                y_dosya.open("Yedek.dat", ios::app|ios::binary);
                strcpy(y_ogr.ad, ogr.ad);
            	strcpy(y_ogr.soyad, ogr.soyad);
            	strcpy(y_ogr.ogr_no, ogr.ogr_no);
             	y_ogr.cinsiyet = ogr.cinsiyet;
             	y_dosya.write((char*) & y_ogr, sizeof(y_ogr));
                y_dosya.close();
            }
    	}
	}
    oku.close();
    if(var)
    {
        remove("ogrenci.dat");
        rename("Yedek.dat", "ogrenci.dat");
        cout << "\Kayýt Düzenlendi." << endl;
    }
    else
    {
        remove("Yedek.dat");
    	cout << "\nKayit Bulunamadý..." << endl;                  
    }
}
