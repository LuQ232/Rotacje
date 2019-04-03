#include "Prostokat.hh"
#include "Macierz2x2.hh"

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Prostokat, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
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

void Prostokat::RotacjaProstokata(double kat)
{
	
Macierz2x2 Macierz;
Macierz.WypelnijTryg(kat);
  for(int i=0; i<ILOSCWIERZCHOLKOW;i++)
  {
  	wierzcholki[i]=Macierz*wierzcholki[i];
  }

}



void Prostokat::PrzesunOWektor(Wektor2D wektor)
{
	for(int i=0;i<ILOSCWIERZCHOLKOW;i++)
	{
		wierzcholki[i]=wierzcholki[i]+wektor;
	}
}

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
