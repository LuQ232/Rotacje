#include "Wektor2D.hh"

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor2D, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

void WyswietlWektor(Wektor2D wektorek)
{
	cout<<"Wspolrzedne X wektora->>"<<wektorek.Zwroc_wartosc(0)<<endl;
	cout<<"Wspolrzedne Y wektora->>"<<wektorek.Zwroc_wartosc(1)<<endl;
}

/*
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek)
{
Strm << setw(16) << fixed << setprecision(10) << Wek.Zwroc_wartosc(0);<< setw(16) << fixed << setprecision(10) << Wek.Zwroc_wartosc(1); << endl;
return Strm;
}
*/


Wektor2D  operator + (Wektor2D wektor1,Wektor2D wektor2)
{
  Wektor2D  Wynik;
  double tmp;

/*
  tmp=wektor1.Zwroc_wartosc(0)+wektor2.Zwroc_wartosc(0);//DODAWANIE WARTOSCI X
  Wynik.Przypisz_wartosc(0,tmp);
  tmp=wektor1.Zwroc_wartosc(1)+wektor2.Zwroc_wartosc(1);//DODAWANIE WARTOSCI Y
  Wynik.Przypisz_wartosc(1,tmp);
*/
	for(int i=0;i<ROZMIAR;i++)
	{
	  tmp=wektor1.Zwroc_wartosc(i)+wektor2.Zwroc_wartosc(i);
	  Wynik.Przypisz_wartosc(i,tmp);	 
	}

  return Wynik;
}

Wektor2D  operator - (Wektor2D wektor1,Wektor2D wektor2)
{
  Wektor2D  Wynik;
  double tmp;

  /*tmp=wektor1.Zwroc_wartosc(0)-wektor2.Zwroc_wartosc(0);//DODAWANIE WARTOSCI X
  Wynik.Przypisz_wartosc(0,tmp);
  tmp=wektor1.Zwroc_wartosc(1)-wektor2.Zwroc_wartosc(1);//DODAWANIE WARTOSCI Y
  Wynik.Przypisz_wartosc(1,tmp);
  */

	for(int i=0;i<ROZMIAR;i++)
	{
	  tmp=wektor1.Zwroc_wartosc(i)-wektor2.Zwroc_wartosc(i);
	  Wynik.Przypisz_wartosc(i,tmp);	 
	}


  return Wynik;
}



std::ostream& operator << (std::ostream &Strm,  Wektor2D &Wek) 
{
	
	for(int i=0;i<ROZMIAR;i++)
	{
		 Strm << setw(16) << fixed << setprecision(10) << Wek.Zwroc_wartosc(i);
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
		Wek.Przypisz_wartosc(i,liczba_wczytywana);
		
	}

return Strm;	
}



/////////////////////////////////////////////////////////////////////FUNKCJE JUZ NIE UZYWANE/////////////////////////////////////////////////////////////
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