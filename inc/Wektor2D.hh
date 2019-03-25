#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#define ROZMIAR 2

#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor2D {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */

		double tablica[ROZMIAR];

  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
  	double Zwroc_wartosc(int a)
  	{
  		return tablica[a];
  	}

  	void Przypisz_wartosc(int a, double b)
  	{
  		tablica[a]=b;
  	}

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm,  Wektor2D &Wek) ;

 
Wektor2D  operator + (Wektor2D wektor1,Wektor2D wektor2);
Wektor2D  operator - (Wektor2D wektor1,Wektor2D wektor2);
Wektor2D  operator * (Wektor2D wektor1,Wektor2D wektor2);
//Wektor2D  operator * (Wektor2D wektor1,Macierz2x2 macierz);
Wektor2D  operator * (Wektor2D wektor1,double liczba);
Wektor2D  operator / (Wektor2D wektor1,double liczba);
void WyswietlWektor(Wektor2D wektorek);

Wektor2D Dodaj_wektory(Wektor2D wektor1,Wektor2D wektor2);
#endif
