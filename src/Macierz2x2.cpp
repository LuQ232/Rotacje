#include "Macierz2x2.hh"
#include "Wektor2D.hh"

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz2x2, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */


/*
 Przesuniecie bitowe w lewo dla Macierzy2x2 (wyswietlanie)
 */
std::ostream& operator << (std::ostream &Strm, const  Macierz2x2 &Mac)
{

	for (int i=0;i<LICZBAMACIERZY;i++)
	{
			Strm<<Mac(i)<<"  "<<std::endl;
	}
	return Strm;

}

/*
 Opracja mnozenia Macierzy razy wektor
 Przesylamy Wektor
 Zwracamy Wynik mnozenia -> Wektor
 */
Wektor2D Macierz2x2::operator * (Wektor2D wektor)
{

Wektor2D Wynik;
Wynik[0]=0;
Wynik[1]=0;
 

    for (int i=0; i<LICZBAMACIERZY;i++)
 	{
	    for (int j=0; j<ROZMIARWEKTORA;j++)
	 	{
			 	Wynik[i]+=tablica[i][j]*wektor[j];

	 	}		 		
 	}

return Wynik;
}

/*
 Funkcja wypelnienia macierzy funkcjami trygonometrycznymi dla zadanego kata
 Funkcja potrzebna do Rotacji prostokata
 Przesylamy kat jako double
 */
void Macierz2x2::WypelnijTryg(double kat)
{

	tablica[0][0]=cos(kat*M_PI/180);	
	tablica[0][1]=(-1)*sin(kat*M_PI/180);	
	tablica[1][0]=sin(kat*M_PI/180);	
	tablica[1][1]=cos(kat*M_PI/180);	
}





//////////////////////FUNKCJE NIEUZYWANE//////////////////////////////////////////////////

/*
 Funkcja wypelniajaca macierz zadanymi wektorami
 Przesylamy dwie zmienne typu Wektor2D
 Zwracamy wypelniona macierz (typ Macierz2x2)
 */

/*
Macierz2x2 Stworz(Wektor2D wek1,Wektor2D wek2)
{
Macierz2x2 Macierz;
	Macierz(0)=wek1;
	Macierz(1)=wek2;
return Macierz;
}

*/