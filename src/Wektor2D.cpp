#include "Wektor2D.hh"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor2D, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */


/*

Wektor2D  Wektor2D::operator + (Wektor2D wektor1)
{
  Wektor2D  Wynik;
  double tmp;


	for(int i=0;i<ROZMIAR;i++)
	{
	 wektor1[i]+=this->[i];
	 //tmp=wektor1[i]+wektor2[i];
	 Wynik[i]=wektor1[i];	 
	}

  return Wynik;
}
*/


Wektor2D  operator + (Wektor2D wektor1,Wektor2D wektor2)
{
  Wektor2D  Wynik;
  double tmp;

	for(int i=0;i<ROZMIAR;i++)
	{
	  tmp=wektor1[i]+wektor2[i];
	  Wynik[i]=tmp;	 
	}


  return Wynik;
}












Wektor2D  operator - (Wektor2D wektor1,Wektor2D wektor2)
{
  Wektor2D  Wynik;
  double tmp;

	for(int i=0;i<ROZMIAR;i++)
	{
	  tmp=wektor1[i]-wektor2[i];
	  Wynik[i]=tmp;	 
	}


  return Wynik;
}

//ILOCZYN SKALARNY DWOCH WEKTORÓW -> ZWRACA WEKTOR 
Wektor2D  operator * (Wektor2D wektor1,Wektor2D wektor2)
{
  Wektor2D  Wynik;
  double tmp;
	for(int i=0;i<ROZMIAR;i++)
	{
	  tmp=wektor1[i]*wektor2[i];
	  Wynik[i]=tmp;	 
	}


  return Wynik;
}

//ILOCZYN   WEKTORA I LICZBY  -> ZWRACA WEKTOR 
Wektor2D  operator * (Wektor2D wektor1,double liczba)
{
  Wektor2D  Wynik;
  double tmp;
	for(int i=0;i<ROZMIAR;i++)
	{
	  tmp=wektor1[i]*liczba;
	  Wynik[i]=tmp;	 
	}


  return Wynik;
}



//ILORAZ   WEKTORA I LICZBY  -> ZWRACA WEKTOR 
Wektor2D  operator / (Wektor2D wektor1,double liczba)
{
  Wektor2D  Wynik;
  double tmp;
	for(int i=0;i<ROZMIAR;i++)
	{
	  tmp=wektor1[i]/liczba;
	  Wynik[i]=tmp;	 
	}


  return Wynik;
}


std::ostream& operator << (std::ostream &Strm,  Wektor2D &Wek) 
{
	
	for(int i=0;i<ROZMIAR;i++)
	{
		 Strm << setw(16) << fixed << setprecision(10) << Wek[i];
	}

	cout<<endl;
	return Strm;
}

std::istream& operator >> (std::istream &Strm, Wektor2D &Wek)
{
	
	double liczba_wczytywana;	
		
	for (int i=0;i<ROZMIAR;i++)
	{
		Strm>>liczba_wczytywana;
		Wek[i]=liczba_wczytywana;
		
	}

return Strm;	
}

double dlugoscWektora (Wektor2D wektor1, Wektor2D wektor2)
{
double Wynik;
double KwadratWsporzednychX;
double KwadratWsporzednychY;

KwadratWsporzednychX=pow(wektor1[0]-wektor2[0],2);
KwadratWsporzednychY=pow(wektor1[1]-wektor2[1],2);
Wynik=sqrt(KwadratWsporzednychX+KwadratWsporzednychY);

return Wynik;
}



/////////////////////////////////////////////////////////////////////FUNKCJE JUZ NIE UZYWANE/////////////////////////////////////////////////////////////
/*
Wektor2D Dodaj_wektory(Wektor2D wektor1,Wektor2D wektor2) 
{
	Wektor2D Wynik;
	double tmp;
	tmp=wektor1.Zwroc_wartosc(0)+wektor2.Zwroc_wartosc(0);//DODAWANIE WARTOSCI X
	Wynik.Przypisz_wartosc(0,tmp);

	tmp=wektor1.Zwroc_wartosc(1)+wektor2.Zwroc_wartosc(1);//DODAWANIE WARTOSCI Y
	Wynik.Przypisz_wartosc(1,tmp);


	return Wynik;
}
void WyswietlWektor(Wektor2D wektorek)
{
	cout<<"Wspolrzedne X wektora->>"<<wektorek.Zwroc_wartosc(0)<<endl;
	cout<<"Wspolrzedne Y wektora->>"<<wektorek.Zwroc_wartosc(1)<<endl;
}
*/
