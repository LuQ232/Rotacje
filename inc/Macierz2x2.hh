#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH
#define LICZBA 2

#include <iostream>
#include "Wektor2D.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz2x2 {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
	Wektor2D wierzcholki[LICZBA];
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
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

#endif
