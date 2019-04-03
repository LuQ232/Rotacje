#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH
#define ILOSCWIERZCHOLKOW 4

#include "Wektor2D.hh"

#include<iostream>
#include<iomanip>
#include<cstdlib>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Prostokat {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
	Wektor2D wierzcholki[ILOSCWIERZCHOLKOW];
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */  
   Wektor2D operator [] (int ind) const { return wierzcholki[ind];}
   Wektor2D& operator [] (int ind)		 {return wierzcholki[ind];}
   void PrzesunOWektor(Wektor2D wektor);
   void RotacjaProstokata(double kat);
   void CzyRowne(); 
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream &Strm,const Prostokat    &Pr);


#endif
