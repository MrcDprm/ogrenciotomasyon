/*
		2212729013
		
		Mira� DEPREM
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
		cout << "|-------Ho�geldiniz------|" << endl ;
		cout << "|      Se�im Yap�n�z     |" << endl ;
		cout << "|   1- �grenci Ekleme    |" << endl ;
		cout << "|   2- �grenci Listeleme |" << endl ;
		cout << "|   3- �grenci Arama     |"<< endl;
		cout << "|   4- �grenci Silme     |"<< endl;
		cout << "|   5- �grenci Duzenleme |"<< endl;
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
		cout << "Ana men�ye d�nmek i�in(a) ��kmak i�in(c) bas�n: " << endl ; 
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
		cout << "��renci Ad�n� Giriniz: ";
		cin >> ogr.ad;
		cout << endl;
		cout << "��renci Soyad�n� Giriniz: ";
		cin >> ogr.soyad;
		cout << endl;
		cout << "��renci Numaras�n� Giriniz: ";
		cin >> ogr.ogr_no;
		cout << endl;
		cout << "��renci Cinsiyetini Giriniz (E/K): ";
		ogr.cinsiyet = getche();
		cout << endl;
		yaz.write((char*) & ogr, sizeof(ogr));	
		adet++;	
		cout << "Ba�ka kay�t eklemek ister misiniz? (E/H): ";
		secim = getche();
		cout << endl;
	} while(secim == 'e' || secim == 'E');
	cout << adet << " adet ��renci eklendi.." << endl;	
	yaz.close();
}

void OgrenciListeleme()
{
	setlocale(LC_ALL, "Turkish");
	ifstream oku("ogrenci.dat", ios::binary | ios::app);	
	oku.seekg(0, ios::end);
	int kayits = oku.tellg() / sizeof(ogr);
	cout << "Toplam ��renci Kay�t Say�s�: "<< kayits << endl;
	if(kayits > 0)
	{
		for(int i = 0; i < kayits; i++)
		{
			oku.seekg(i * sizeof(ogr));
			oku.read((char*) & ogr, sizeof(ogr));	
			cout << i + 1 << ". ��rencinin Bilgileri"<< endl;
			cout << "��rencinin Ad�: "<< ogr.ad << endl;
			cout << "��renci Soyad�: "<< ogr.soyad << endl;
			cout << "��rencinin Numaras�: "<< ogr.ogr_no << endl;
			if(ogr.cinsiyet == 'e' || ogr.cinsiyet == 'E')
			{
				cout << "��rencinin Cinsiyeti: ERKEK " << endl;
			}
			else if(ogr.cinsiyet == 'k' || ogr.cinsiyet == 'K')
			{
				cout << "��rencinin Cinsiyeti: KADIN " << endl;
			}
		}		
	}
	else
	{	
		cout << "Kay�t Bulunamad�..." << endl;
	}
	oku.close();
}

void OgrenciArama()
{
	setlocale(LC_ALL, "Turkish");
	ifstream oku("ogrenci.dat", ios::binary |ios::app);
	oku.seekg(0, ios::end);
	int kayits = oku.tellg() / sizeof(ogr);
	cout << "Aranan ��rencinin numaras�n� giriniz: " << endl;
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
				cout << "Bulunan ��rencinin Bilgileri" << endl;
				cout << "��rencinin Ad�: " << ogr.ad << endl ;
				cout << "��rencinin Soyad�: "<< ogr.soyad <<endl ;
				cout << "��rencinin Numaras�: "<< ogr.ogr_no <<endl ;
				if(ogr.cinsiyet == 'e' || ogr.cinsiyet=='E')
				{
					cout << "��rencinin Cinsiyeti: ERKEK " << endl ;
				}
				else if(ogr.cinsiyet=='k' || ogr.cinsiyet=='K')
				{
					cout << "��rencinin Cinsiyeti: KADIN " << endl ;
				}
		    }
		}
	}
	else
	{
		cout << "Kay�t Bulunamad�..." << endl;
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
    cout<<"Kayd�n� silmek istedi�iniz ��rencinin numaras�n� giriniz: ";
    cin >> ogrno;
    for(int i = 0; i < kayitsayisi; i++)
    {
        oku.seekg(i * sizeof(ogr));
		oku.read((char*)&ogr, sizeof(ogr));	
    	if(strcmp(ogr.ogr_no, ogrno) == 0)
    	{
            cout << endl;
            cout << "��rencinin";
            cout << "\nAd�: "<<ogr.ad;
            cout << "\nSoyad�: "<<ogr.soyad;
            cout << "\nNumaras�: "<<ogr.ogr_no;
            cout << "\nCinsiyeti: ";
            if(ogr.cinsiyet == 'e'|| ogr.cinsiyet == 'E')
            {
            	cout << "Erkek";
			}
            if(ogr.cinsiyet == 'k'|| ogr.cinsiyet == 'K')
            {
            	cout << "Kad�n";			  
        	}
			cout << "\n\nSilmek �stedi�iniz Kay�t Bu Mu? [E/H]: ";
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
        cout << "\n Kay�t Silindi" << endl;
    }
    else
    {
        remove("Yedek.dat");
        cout << "\n Kay�r Bulunamad�" << endl;                  
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
    cout << "Kayd�n� d�zeltmek istedi�iniz ��rencinin numaras�n� giriniz: ";
    cin >> ogrno;
    cout << endl;
    for(int i=0;i<kayitsayisi;i++)
    {
    	oku.seekg(i * sizeof(ogr));
		oku.read((char*) & ogr, sizeof(ogr));
     	if(strcmp(ogr.ogr_no, ogrno) == 0)
     	{  	
        	cout << endl;
            cout << "��rencinin";
            cout << "\nAd�: " << ogr.ad;
            cout << "\nSoyad�: " << ogr.soyad<<endl;
            cout << "\nNumaras�: "<<ogr.ogr_no;
            cout << "\nCinsiyeti: ";
            if(ogr.cinsiyet == 'e'||ogr.cinsiyet == 'E')
            {
                cout << "Erkek";
            }
            if(ogr.cinsiyet == 'k'||ogr.cinsiyet == 'K')
            {
                cout << "Kad�n";
            }
            cout << "\n\nD�zeltmek �stedi�iniz Kay�t Bu Mu? [E/H]: ";
            secim = getche();
            if(secim == 'E' || secim == 'e')
            {
                var = true;
                ofstream dosya("Yedek.dat", ios::app|ios::binary);
                cout << "\n��rencinin Ad�n� Giriniz: ";
				cin >> ogr.ad;
				cout << endl;
				cout << "��rencinin Soyad�n� Giriniz: ";
				cin >> ogr.soyad;
				cout << endl;
				cout << "��rencinin Numaras�n� Giriniz: ";
				cin>> ogr.ogr_no;
				cout << endl;
				cout << "��rencinin Cinsiyetini Giriniz (E/K): ";
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
        cout << "\Kay�t D�zenlendi." << endl;
    }
    else
    {
        remove("Yedek.dat");
    	cout << "\nKayit Bulunamad�..." << endl;                  
    }
}
