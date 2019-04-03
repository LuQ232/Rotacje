#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH
#define LICZBAMACIERZY 2

#include <iostream>
#include <cmath>
#include "Wektor2D.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz2x2 {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
	Wektor2D tablica[LICZBAMACIERZY];
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */   
   Wektor2D operator () (int Wektor) const {return tablica[Wektor];}
   Wektor2D& operator () (int Wektor)  {return tablica[Wektor];} 
   Wektor2D operator * (Wektor2D wektor);
   void WypelnijTryg(double kat);
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 *
 * Przeciążenie to może być użyteczne w trakcie debugowania programu.
 */
std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);
Macierz2x2 Stworz(Wektor2D wek1,Wektor2D wek2);

#endif
