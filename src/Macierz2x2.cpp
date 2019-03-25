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
		for (int j=0; j<LICZBA;j++)
		{
			double  tmp;
			tmp=Mac(i,j);
			Strm<<tmp<<"  ";
		}
		Strm<<endl;
	}
	return Strm;

}


//Wektor2D operator * (Wektor2D wektor)
Wektor2D operator * (Wektor2D wektor, Macierz2x2 macierz)
{

Wektor2D Wynik;
Wynik[0]=0;
Wynik[1]=0;
 

    for (int i=0; i<=LICZBA;i++)
 	{
		
	    for (int j=0; j<=LICZBA;j++)
	 	{
			 	Wynik[i]+=macierz(i,j)*wektor[j];

	 	}		 		

 	}

return Wynik;
}




Macierz2x2 Stworz(Wektor2D wek1,Wektor2D wek2)
{

Macierz2x2 Macierz;

	Macierz(0,0)=wek1[0];
	Macierz(0,1)=wek1[1];
	Macierz(1,0)=wek2[0];
	Macierz(1,1)=wek2[1];
//	Macierz[1]=wek2;
	
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