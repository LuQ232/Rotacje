#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#define ILOSC  4
#include <iostream>
#include "Wektor2D.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Prostokat {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
	Wektor2D wierzcholki[ILOSC];

  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */ 
    Wektor2D operator [] (int ind) const { return wierzcholki[ind];}
  	Wektor2D& operator [] (int ind)		 {return wierzcholki[ind];}
  /*
   void Przypisz_wektor_prostokata(unsigned int a, Wektor2D wektor)
  	{
  		wierzcholki[a]=wektor;
  	}

   Wektor2D Zwroc_wektor_prostokata(unsigned int a)
  	{
  		return wierzcholki[a];
  	}   
  	*/
};	


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream &Strm,  Prostokat    &Pr);
Prostokat Stworz(Wektor2D wek1,Wektor2D wek2,Wektor2D wek3,Wektor2D wek4);
Prostokat PrzesunOWektor(Prostokat prosty,Wektor2D wektor);
void WyswietlWspolrzedne(Prostokat Prosty);
#endif
