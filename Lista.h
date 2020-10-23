#pragma once
class Lista
{
private:
	vector<string> vec;
	void wypelnienieLiczbami(const int &ile);
public:
	Lista();     // konstruktor
	Lista(int ile); // jeszcze jeden konstruktor (przeci¹¿enie)
	Lista(TRodzajWypelnieniaWektora wersja);
	~Lista();  // destruktor
	void wypisanie();
private:
	virtual string formatuj(const string &txt_p);
};

