#include "Prostokat.hh"
#include "Macierz2x2.hh"

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Prostokat, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */


/*
Przesuniecie bitowe w lewo dla Prostokata (wyswietlanie) 
*/
std::ostream& operator << ( std::ostream &Strm, const  Prostokat    &Pr)
{
	for (int i=0;i<ILOSCWIERZCHOLKOW;i++)
	{
		Wektor2D  tmp;
		tmp=Pr[i];
		Strm<<tmp<<std::endl;
	}
	return Strm;
}

/*
Rotacja prostokata o dany kat
Przesylamy kat typu double 
*/
void Prostokat::RotacjaProstokata(double kat)
{
	
Macierz2x2 Macierz;
Macierz.WypelnijTryg(kat);
  for(int i=0; i<ILOSCWIERZCHOLKOW;i++)
  {
  	wierzcholki[i]=Macierz*wierzcholki[i];
  }

}


/*
Przesuniecie prostokata o dany wektor
Przesylamy wektor typu Wektor2D 
*/
void Prostokat::PrzesunOWektor(Wektor2D wektor)
{
	for(int i=0;i<ILOSCWIERZCHOLKOW;i++)
	{
		wierzcholki[i]=wierzcholki[i]+wektor;
	}
}



/*
Obliczenie, wyswietlenie dlugosci bokow danego prostokata
*/
void Prostokat::CzyRowne()
{
		if(OdlegloscPunktow(wierzcholki[0],wierzcholki[1])==OdlegloscPunktow(wierzcholki[3],wierzcholki[2]))
		{
			std::cout<<":) Jedne przeciwlegle boki sa sobie rowne."<<std::endl;
			std::cout<<"Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(16)<<OdlegloscPunktow(wierzcholki[0],wierzcholki[1])<<std::endl;
			std::cout<<"Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(16)<<OdlegloscPunktow(wierzcholki[3],wierzcholki[2])<<std::endl;
		}else
		{
			std::cout<<":0 Jedne przeciwlegle boki NIE sa sobie rowne."<<std::endl;
			std::cout<<"Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(16)<<OdlegloscPunktow(wierzcholki[0],wierzcholki[1])<<std::endl;
			std::cout<<"Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(16)<<OdlegloscPunktow(wierzcholki[3],wierzcholki[2])<<std::endl;
		}
	
	    if(OdlegloscPunktow(wierzcholki[0],wierzcholki[3])==OdlegloscPunktow(wierzcholki[1],wierzcholki[2]))
		{
			std::cout<<":) Drugie prze3ciwlegle boki sa sobie rowne."<<std::endl;
			std::cout<<"Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(16)<<OdlegloscPunktow(wierzcholki[0],wierzcholki[3])<<std::endl;
			std::cout<<"Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(16)<<OdlegloscPunktow(wierzcholki[1],wierzcholki[2])<<std::endl;
		}else
		{
			std::cout<<":0 Drugie przeciwlegle boki NIE sa sobie rowne."<<std::endl;
			std::cout<<"Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(16)<<OdlegloscPunktow(wierzcholki[0],wierzcholki[3])<<std::endl;
			std::cout<<"Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(16)<<OdlegloscPunktow(wierzcholki[1],wierzcholki[2])<<std::endl;
		}
}
