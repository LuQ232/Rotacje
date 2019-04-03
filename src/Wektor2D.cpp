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


Wektor2D  Wektor2D::operator + (Wektor2D  wektor1)
{
  

	for(int i=0;i<ROZMIARWEKTORA;i++)
	{
	  wektor1[i] = wektor1[i] + tablica[i];
	}


  return wektor1;
}

Wektor2D  Wektor2D::operator - (Wektor2D  wektor1)
{
  

	for(int i=0;i<ROZMIARWEKTORA;i++)
	{
	  wektor1[i] = wektor1[i] - tablica[i];
	}


  return wektor1;
}

//ILOCZYN SKALARNY DWOCH WEKTORÓW -> ZWRACA WEKTOR 
Wektor2D  Wektor2D::operator * (Wektor2D  wektor1)
{
  Wektor2D  Wynik;
  double tmp;
	for(int i=0;i<ROZMIARWEKTORA;i++)
	{
	  tmp=tablica[i]*wektor1[i];
	  Wynik[i]=tmp;	 
	}


  return Wynik;
}

//ILOCZYN   WEKTORA I LICZBY  -> ZWRACA WEKTOR 
Wektor2D  Wektor2D::operator * (double liczba)
{
  Wektor2D  Wynik;
  double tmp;
	for(int i=0;i<ROZMIARWEKTORA;i++)
	{
	  tmp=tablica[i]*liczba;
	  Wynik[i]=tmp;	 
	}


  return Wynik;
}

//ILORAZ   WEKTORA I LICZBY  -> ZWRACA WEKTOR 
Wektor2D Wektor2D::operator / (double liczba)
{
  Wektor2D  Wynik;
  double tmp;
	for(int i=0;i<ROZMIARWEKTORA;i++)
	{
	  tmp=tablica[i]/liczba;
	  Wynik[i]=tmp;	 
	}


  return Wynik;
}


std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek) 
{
	
	for(int i=0;i<ROZMIARWEKTORA;i++)
	{
		 Strm << setw(16) << fixed << setprecision(10) << Wek[i];
	}

	std::cout<<std::endl;
	return Strm;
}

std::istream& operator >> (std::istream &Strm, Wektor2D &Wek)
{

	for (int i=0;i<ROZMIARWEKTORA;i++)
	{
		Strm>>Wek[i];
		
		
	}

return Strm;	
}


double OdlegloscPunktow (Wektor2D wektor1, Wektor2D wektor2)
{
	double odleglosc;
	double RoznicaX;
	double RoznicaY;
	RoznicaX=wektor2[0]-wektor1[0];
	RoznicaY=wektor2[1]-wektor1[1];
	
	odleglosc=sqrt(pow(RoznicaX,2)+pow(RoznicaY,2));
return odleglosc;
}