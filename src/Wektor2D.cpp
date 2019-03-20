#include "Wektor2D.hh"

using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor2D, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

void WyswietlWektor(Wektor2D wektorek)
{
	cout<<"Wspolrzedne X wektora->>"<<wektorek.Zwroc_wartosc(0)<<endl;
	cout<<"Wspolrzedne Y wektora->>"<<wektorek.Zwroc_wartosc(1)<<endl;
}