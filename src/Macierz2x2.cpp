#include "Macierz2x2.hh"

using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz2x2, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

 
std::ostream& operator << (std::ostream &Strm,  Macierz2x2 &Mac)
{

	for (int i=0;i<LICZBA;i++)
	{
		Wektor2D  tmp;
		tmp=Mac.Zwroc_wektor_macierzy(i);
		Strm<<tmp<<endl;
	}
	return Strm;

}


Macierz2x2 Stworz(Wektor2D wek1,Wektor2D wek2)
{

Macierz2x2 Macierz;

	Macierz.Przypisz_wektor_macierzy(0,wek1);
	Macierz.Przypisz_wektor_macierzy(1,wek2);
	
return Macierz;
}

/*
//ILOCZYN  WEKTORA I MACIERZY -> ZWRACA WEKTOR 
Wektor2D  operator * (Wektor2D wektor1,Macierz2x2 macierz)
{
	Wektor2D Wynik;

  return Wynik;
}
*/