// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "Lista.h"
#include "ListaFormatowana.h"

void podkreslenie() {
	cout << "-----------------------------------\n";
}
//zadanie: utworzyć tutaj klasę Zadania
//i wypełnić ją metodami statycznymi zadaniaZObiektow oraz zadaniaZeWskaznikow()
class Zadania {
public:
	static void zadaniaZObiektow() {
		//std::cout << "Hello World!\n"; 
		Lista li(10);
		li.wypisanie();
		podkreslenie();
		//Ćw : napisać to samo co wyżej ale używając new (podobnie jak w C#)
		Lista *li2 = new Lista(5); //gwiazdka oznacza że li2 jest ,,wskaźnikiem'' (=pointerem).
		li2->wypisanie(); // operator -> to operator 
		delete li2;
		/*przypomnijmy że w C# powyższa sekwencja kodu by wyglądała tak:
		  Lista li2 = new Lista(5);
		  li2.wypisanie();
		*/
		/*string txt;
		cin >> txt;*/
		podkreslenie();
		// a teraz użyjemy klasy potomnej ListaSformatowana
		ListaFormatowana *lf = new ListaFormatowana(5);
		lf->wypisanie();
		delete lf;
	
	}
	static void zadaniaZeWskaznikow() {
		cout << "TODO: zadanie ze wskaznikow\n";
		//napisać ilustrację działania wskaźnika na int,
		//tzn zaalokować wskaźnik, nadać mu wartość a potem zwolnić wskaźnik:
		int *wskI = new(int);
		*wskI = 7;
		assert(*wskI == 7);
		delete wskI;
	}
	static void przykladWirtualnosciMetody() {
		class K1 {
		public:
			virtual int f(int p) {
				return p;
			};
			void oblicz() {
				for (int i : {1, 2, 3, 4, 5}) {
					cout << f(i) << "\t";
				}
				cout << endl;
			}
		};
		class K2 : public K1 {
		public:
			int f(int p) {
				return p * p;
			};
		};
		cout << "Z powodu wirtualności metody ukazuje się lista kwadratów liczb:\n";
		K2* o2 = new K2();
		//((K1*)o2)->oblicz();
		o2->oblicz();
		delete o2;
	}
};


int main()
{//zadanie : dorobić proste menu:
	for(;;) {
		cout << "1. Zadania z obiektow\n";
		cout << "2. Zadania ze wskaźników\n";
		cout << "3. Przykład wirtualności metody w klasie\n";
		cout << "4. Test kontruktorów z parametrem enum klasy Lista\n";
		cout << "0. Wyjście\n";
		string opcja;
		cin >> opcja;
		if (opcja.empty() || opcja[0] == '0') break;
		switch (opcja[0]) {
		case '1':
			Zadania::zadaniaZObiektow();
			break;
		case '2':
			Zadania::zadaniaZeWskaznikow();
			break;
		case '3':
			Zadania::przykladWirtualnosciMetody();
			break;
		case '4': {
			TRodzajWypelnieniaWektora wersja = TRodzajWypelnieniaWektora::liczby;
			Lista* li = new Lista(wersja);
			li->wypisanie();
			delete li;

			wersja = TRodzajWypelnieniaWektora::dniTygodnia;
			li = new Lista(wersja);
			li->wypisanie();
			delete li;
			break;
		}
		default:
			break;
		}
	};
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
