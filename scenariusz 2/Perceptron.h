#pragma once
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>

#define WSPOLCZYNNIK_NAUKI  0.1
#define MAX_ITERACJE 20

using namespace std;

class Perceptron
{
	int tab_wej[20][24];
	float tab_wag[24];
	int tab_wyn_ocz[20];
	int ilosc_wejsc;
	bool wynik;
	float wspolczynnik_nauki;

	

public:
	Perceptron();
	void wczytanie_danych();
	void losuj_wagi();
	float licz_wyjscia(int i);
	void ucz();
	void sprawdz(int tab[]);
	void wypisz();
};
