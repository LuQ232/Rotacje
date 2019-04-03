#include <iostream>
#include <iomanip>
#include <fstream>

#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void PrzykladZapisuWspolrzednychDoStrumienia( ostream&     StrmWy, Prostokat Prosty)
{
  StrmWy << Prosty<<Prosty[0]<<endl;
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}



/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku,Prostokat Prosty)
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
   << ":(  nie powiodla sie." << endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy, Prosty);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

/*!
 Funkcja wyswietlajaca menu programu na standardowe wyjscie
 */
void menu()
{
cout<<endl<<endl<<endl<<endl;
cout<<"o - obrot prostokata o zadany kat"<<endl;
cout<<"p - przesuniecie prostokata o zadany wektor"<<endl;
cout<<"w - wyswietlenie wspolrzednych wierzcholkow"<<endl;
cout<<"t - sprawdzenie czy boki prostokata sa rowne"<<endl;
cout<<"m - wyswietl menu"<<endl;
cout<<"k - koniec dzialania programu"<<endl;
}





int main()
{
  
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);

  
 

//INICJACJA PROSTOKATA "NA SZTYWNO W PROGRAMIE"//
  Wektor2D wektor1;
  Wektor2D wektor2;
  Wektor2D wektor3;
  Wektor2D wektor4;
  wektor1[0]=-100;
  wektor1[1]=-100;
  wektor2[0]=100;
  wektor2[1]=-100;
  wektor3[0]=100;
  wektor3[1]=100;
  wektor4[0]=-100;
  wektor4[1]=100;
  Prostokat Prosty;
  Prosty[0]=wektor1;
  Prosty[1]=wektor2;
  Prosty[2]=wektor3;
  Prosty[3]=wektor4;
/////////////////////////////////////////////////////////////////////


//////////////////////////GLOWNA PETLA PROGRAMU////////////////////////////////////////////////////////////
	for (;;)
	{

		menu();
		char literka;
		cin>>literka;
		switch( literka )
		{
			case 'o'://OBROT PROSTOKATA
				   cout<<"podaj kat rotacji: ";
				   double kat;
				   cin>>kat;
				   cout<<"ile razy zrotowac ";
				   int ile;
				   cin>>ile;
				   for(int i=0;i<ile;i++)
					{
					   Prosty.RotacjaProstokata(kat);
					}
			    break;
			   
			case 'p'://PRZESUNIECIE PROSTOKATA O WEKTOR
			    cout<<"Wprowadz wspolrzedne wektora translacji w postaci dwoch liczb"<<endl<<"tzn. wspolrzednej x oraz wspolrzednej y."<<endl;
			    double x;
			    double y;
			    cin>>x;
			    cin>>y;
			    Wektor2D WektorPrzesuniecia;
			    WektorPrzesuniecia[0]=x;
			    WektorPrzesuniecia[1]=y;
			    Prosty.PrzesunOWektor(WektorPrzesuniecia);
			    cout<<"Prostokat zostal przesuniety"<<endl;
			    break;
			   
			    
			case 'w'://WYSWIETLENIE WSPOLRZEDNYCH I GNUPLOT
			    cout<<Prosty;
			  ////////////////////////////////////ZAPIS DO PLIKU I WYSWIETLENIE W GNUPLOCIE/////////////////////////
			  PrzykladZapisuWspolrzednychDoStrumienia(cout,Prosty);
				if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat",Prosty)) return 1;
				Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
				cout << "Naciśnij ENTER, aby kontynuowac" << endl;
				cin.ignore(100000,'\n');
				//////////////////////////////////////////////////////////////////////////////////////////////////////
			    break;

			 case 't'://SPRAWDZENIE I WYSWIETLENIE DLUGOSCI DANYCH BOKOW PROSTOKATA
			    Prosty.CzyRowne();
			    break;
			   
			case 'm'://WYSWIETLENIE MENU
			    
				break;

			case 'k'://KONIEC PROGRAMU
			    return 0;
				break;
		   
		}//KONIEC SWITCHA

	}//KONIEC NIESKONCZONEJ PETLI
}//KONIEC MAINA PROGRAMU













/////////////////LINIJKA TESTOW/////////////
//-100 -100 100 -100 100 100 -100 100

///////////////////////////STARA CZESC PROGRAMU, SLUZYLA DO TESTOW POSZCZEGOLNYCH METOD I FUNKCJI///////////////////////////////////////////
/* 
cout<<"Podaj 4 boki kwadratu:"<<endl;
  Wektor2D wektor1;
  Wektor2D wektor2;
  Wektor2D wektor3;
  Wektor2D wektor4;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  cin>>wektor1;
  cin>>wektor2;
  cin>>wektor3;
  cin>>wektor4;
  cout<<wektor1<<endl;
  cout<<wektor2<<endl;
  cout<<wektor3<<endl;
  cout<<wektor4<<endl<<endl<<endl<<endl;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  Macierz2x2 Macierz;
  Macierz=Stworz(wektor1,wektor2);
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<"MACIERZ"<<Macierz;
//////////////////////////////////////TEST ILOCZYNU MACIERZY RAZY WEKTOR////////////////////////////////////////////
  cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<"Wektor"<<wektor1;
  Wektor2D iloczyn;
  iloczyn=Macierz*wektor1;
  cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<"Iloczyn"<<iloczyn;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////TEST WYPELNIENIA MACIERZY TRYG////////////////////////////////////////////
  cout<<endl<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  Macierz.WypelnijTryg(0);
  cout<<Macierz;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////TEST PRZESUNIECIA PROSTOKATA O WEKTOR////////////////////////////////////
   Prostokat Prosty;
   cout<<endl<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
   Prosty[0]=wektor1;
   Prosty[1]=wektor2;
   Prosty[2]=wektor3;
   Prosty[3]=wektor4;
   cout<<"Prostokat przed przesunieciem: "<<endl;
   cout<<Prosty;


   PrzykladZapisuWspolrzednychDoStrumienia(cout,Prosty);
  	if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat",Prosty)) return 1;
  	Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  	cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  	cin.ignore(100000,'\n');
  	PrzykladZapisuWspolrzednychDoStrumienia(cout,Prosty);
  	if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat",Prosty)) return 1;
  	Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  	cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  	cin.ignore(100000,'\n');


   Wektor2D WektorPrzesuniecia;
   WektorPrzesuniecia[0]=101;
   WektorPrzesuniecia[1]=101;
   Prosty.PrzesunOWektor(WektorPrzesuniecia);
   cout<<"Prostokat po przesunieciu: "<<endl;
   cout<<Prosty;

   PrzykladZapisuWspolrzednychDoStrumienia(cout,Prosty);
  if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat",Prosty)) return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  cin.ignore(100000,'\n');
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   //////////////////////////////////////TEST ROTACJI PROSTOKATA //////////////////////////////////////////////
  Prostokat ProstyTestRotacji;
   ProstyTestRotacji[0]=wektor1;
   ProstyTestRotacji[1]=wektor2;
   ProstyTestRotacji[2]=wektor3;
   ProstyTestRotacji[3]=wektor4;
   cout<<"podaj kat rotacji: ";
   double kat;
   cin>>kat;
   cout<<"ile razy zrotowac ";
   int ile;
   cin>>ile;
   cout<<endl<<"Prostokat przed rotacja: "<<endl<<ProstyTestRotacji<<endl;

    PrzykladZapisuWspolrzednychDoStrumienia(cout,ProstyTestRotacji);
  if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat",ProstyTestRotacji)) return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  cin.ignore(100000,'\n');
 

   cout<<endl<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
   for(int i=0;i<ile;i++)
   {
   ProstyTestRotacji.RotacjaProstokata(kat);
   }
   cout<<"Prostokat po rotacji: "<<endl<<ProstyTestRotacji<<endl;

    PrzykladZapisuWspolrzednychDoStrumienia(cout,ProstyTestRotacji);
  if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat",ProstyTestRotacji)) return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
  cout << "Naciśnij ENTER, aby kontynuowac" << endl;
  cin.ignore(100000,'\n');
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/