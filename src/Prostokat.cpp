#include "Prostokat.hh"
#include "Wektor2D.hh"

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Prostokat, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
using namespace std;

Prostokat Stworz(Wektor2D wek1,Wektor2D wek2,Wektor2D wek3,Wektor2D wek4)
{

Prostokat Prosty;

	Prosty.Przypisz_wektor_prostokata(0,wek1);
	Prosty.Przypisz_wektor_prostokata(1,wek2);
	Prosty.Przypisz_wektor_prostokata(2,wek3);
	Prosty.Przypisz_wektor_prostokata(3,wek4);

return Prosty;
}


std::ostream& operator << ( std::ostream &Strm,  Prostokat    &Pr)
{
	for (int i=0;i<ILOSC;i++)
	{
		Wektor2D  tmp;
		tmp=Pr.Zwroc_wektor_prostokata(i);
		Strm<<tmp<<endl;
	}
	return Strm;

}

/////////////////////////////////////////////////////////////////////FUNKCJE JUZ NIE UZYWANE///////////////////////////////////////////////
void WyswietlWspolrzedne(Prostokat Prosty)
{
	for (int i=0;i<ILOSC;i++)
	{
		Wektor2D tmp;
		tmp=Prosty.Zwroc_wektor_prostokata(i);
		cout<<tmp<<endl;
	}	
}

