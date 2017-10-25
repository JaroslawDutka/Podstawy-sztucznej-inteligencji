/*#include <cstdio>
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
	friend float licz_wyjscia(float[], float);

	int ilosc = 208; //wartoœæ domyœlna
	//float *x0 = new float[ilosc];
	//float *x1 = new float[ilosc];
	int wejscia[20][24];
	//float wagi[3];
	float wagi[25];
	int wynik;
	//int *wynikOczekiwany = new int[ilosc];
	int wynik_oczekiwany[25];	
	int ilosc_elementow;

public:

	float losuj_wagi()
	{
		return (float)rand() / (float)RAND_MAX;
	}

	/*void ucz()
	{

		int iteracja = 0;
		float blad_lokalny;
		float blad_globalny = 0;
		float sredni_blad;
		do {
			blad_globalny = 0;
			iteracja++;

			for (int p = 0; p < this->ilosc_elementow; p++) {
				this->wynik = licz_wyjscia(this->wagi, this->x0[p], this->x1[p]);

				blad_lokalny = this->wynikOczekiwany[p] - this->wynik;
				this->wagi[0] += WSPOLCZYNNIK_NAUKI * blad_lokalny * this->x0[p];
				this->wagi[1] += WSPOLCZYNNIK_NAUKI * blad_lokalny * this->x1[p];
				this->wagi[2] += WSPOLCZYNNIK_NAUKI * blad_lokalny;

				blad_globalny += (blad_lokalny*blad_lokalny);
			}
			sredni_blad = sqrt(blad_globalny / this->ilosc_elementow);
			cout << "Iteracja #" << iteracja << " |Œredni b³¹d kwadratowy: " << sredni_blad << fixed << endl;
		} while (blad_globalny != 0 && iteracja <= MAX_ITERACJE);
		//cout << endl << "Równanie graniczne: " << this->wagi[0] << "*x + " << this->wagi[1] << "*y + " << this->wagi[2] << endl;
		cout << endl << "Równanie graniczne: " << "y = " << this->wagi[0] / this->wagi[1] << "*x + " << this->wagi[2] / this->wagi[1] << endl;
	}

	Perceptron()
	{
		//cout << "Podaj iloœæ danych ucz¹cych (max 208) >> "; cin >> ilosc;
		//oczytanie danych wejsciowych z pliku
		ifstream plik;
		plik.open("test1.txt");
		if (!plik.good())
		{
			cerr << "Nie mo¿na otworzyæ pliku Ÿród³owego!" << endl
				<< "blad #" << plik.fail() << endl << endl;
			return;
		}

		int i = 0;

		while (!plik.eof() && i < ilosc - 1) {
			for (int i = 0; i < 20; i++) 
			{
				for (int j = 0; j < 24; j++)
				{
					plik >> wejscia[i][j];
				}
				plik >> wynik_oczekiwany[j];
				if (wynik_oczekiwany[j] == 0)
					wynik_oczekiwany[j] = -1;
			}
			//plik >> x0[i] >> x1[i] >> wynikOczekiwany[i];
			/*if (wynikOczekiwany[i] == 0) {
				wynikOczekiwany[i] = -1;
			}
			i++;
		}
		ilosc_elementow = i;
		plik.close();

		//losowanie wag;
		/*wagi[0] = losuj_wagi();
		wagi[1] = losuj_wagi();
		wagi[2] = losuj_wagi();*/
		/*wagi[0] = 0;
		wagi[1] = 0;
		wagi[2] = 0;

		for (int i = 0; i < 25; i++)
		{
			wagi[i] = losuj_wagi();
		}
	}

	/*void sprawdz(float y, float x)
	{
		if (y > (this->wagi[0] / this->wagi[1]) * x + (this->wagi[2] / this->wagi[1]))
			cout << "Punkt le¿y nad prost¹!" << endl;
		else if ((y < (this->wagi[0] / this->wagi[1]) * x + (this->wagi[2] / this->wagi[1])))
			cout << "Punkt le¿y pod prost¹!" << endl;
		else if ((y = (this->wagi[0] / this->wagi[1]) * x + (this->wagi[2] / this->wagi[1])))
			cout << "Punkt le¿y na prost¹!" << endl;
	}*/
/*
	~Perceptron() {	}
};

float licz_wyjscia(float wagi[], float x[])
{
	/*float sum = x0 * wagi[0] + x1 * wagi[1] + wagi[2];
	return (sum >= 0) ? 1 : -1;*/
	/*float suma = 0;
	for (int i = 0; i < 24; i++)
	{
		suma += x[i] * wagi[i];
	}
	suma += wagi[24];
}

void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	float y, x;
	Perceptron p;
	p.ucz();

	cout << "Podaj y = "; cin >> y;
	cout << "Podaj x ="; cin >> x;
	p.sprawdz(y, x);

	system("PAUSE");
}*/