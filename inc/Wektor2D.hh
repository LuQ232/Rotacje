#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#define ROZMIARWEKTORA 2

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor2D {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */

   double tablica[ROZMIARWEKTORA]; 
 
	
	
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */   
    double operator [] (int Ind) const { return tablica[Ind];}
    double& operator [] (int Ind) {return tablica[Ind];}
    Wektor2D  operator + (Wektor2D wektor1);
    Wektor2D  operator - (Wektor2D wektor1);
    Wektor2D  operator * (Wektor2D wektor1);
    Wektor2D  operator * (double liczba);
    Wektor2D  operator / ( double liczba);

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
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);
double OdlegloscPunktow (Wektor2D wektor1, Wektor2D wektor2);
#endif
