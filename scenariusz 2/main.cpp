#pragma once
#include "Perceptron.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	Perceptron nowy;
	int tab[24] = { 1,1,1,0,1,0,0,1,1,1,1,0,1,0,0,1,1,0,0,1,1,0,0,1 };
	nowy.losuj_wagi();
	nowy.ucz();
	nowy.sprawdz(tab);
	system("PAUSE");
}

