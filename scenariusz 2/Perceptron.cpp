#include "Perceptron.h"

Perceptron::Perceptron()
{
	ilosc_wejsc = 20;
	ilosc_wejsc;
	wspolczynnik_nauki = 0.1;

	wczytanie_danych();
}

void Perceptron::wczytanie_danych()
{
	ifstream plik;
	plik.open("test1.txt");
	if (!plik.good()) //jesli nie mozna otworzyc pliku to wypisz blad
	{
		cerr << "Nie mo¿na otworzyæ pliku Ÿród³owego!" << endl
			<< "blad #" << plik.fail() << endl << endl;
		system("PAUSE");
		exit(1);
	}
	while (!plik.eof()) // dopoki sa dane w pliku, wczytuj dane
	{
		for (int i = 0; i < ilosc_wejsc; i++)
		{
			for (int j = 0; j < 24; j++)
			{
				plik >> this->tab_wej[i][j]; //wczytaj dane do tablicy z wejsciami
			}
			plik >> this->tab_wyn_ocz[i]; //wczytaj wynik oczekiwany
		}
	}
	plik.close(); // zamknij plik
} 

void Perceptron::losuj_wagi()
{
	for (int i = 0; i < 24; i++)
	{
		this->tab_wag[i] = (float)rand() / (float)RAND_MAX;
	}
}

float Perceptron::licz_wyjscia(int i)
{
	float suma = 0;	
		for (int j = 0; j < 24; j++)
		{
			suma += this->tab_wej[i][j] * this->tab_wag[j];
		}
	return suma;
}

void Perceptron::ucz()
{
	float blad_lokalny;
	float blad_globalny = 0;
	int epoka = 0;
	int przypadek;
	float wynik_tmp;

	do 
	{
		blad_globalny = 0;
		for (przypadek = 0; przypadek < 20; przypadek++) 
		{
			/*OBLICZANIE WYNIKU W ITERACJI*/
			wynik_tmp = licz_wyjscia(przypadek);
			blad_lokalny = this->tab_wyn_ocz[przypadek] - wynik_tmp;
			
			/*AKTALIZACJA WAG*/
			
			for (int i = 0; i < this->ilosc_wejsc; i++)
			{
				this->tab_wag[i] += this->wspolczynnik_nauki * blad_lokalny * this->tab_wej[przypadek][i];
			}
			
			blad_globalny += (blad_lokalny*blad_lokalny);
		}
		epoka++;
	} while (blad_globalny > 2.66299); //threashold
	cout << "Liczba wykonanych epok = " << epoka << endl;
}

void Perceptron::sprawdz(int tab[])
{
	float suma = 0, blad_lokalny = 0, blad_globalny = 0;
	for (int i = 0; i < 24; i++)
	{
		suma += tab[i] * this->tab_wag[i];
	}
	blad_lokalny = 1 - suma;
	blad_globalny = pow(2, blad_lokalny);
	
	if (blad_globalny < 1.5)
		this->wynik = true;	
	else	
		this->wynik = false;
		
	wypisz();
}

void Perceptron::wypisz()
{
	if (this->wynik == true)
		cout << "Podana jest ma³a litera!" << endl << endl;
	else
		cout << "Podana jest du¿a litera!" << endl << endl;
}

