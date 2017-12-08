#include "Neuron.h"
#define numeberOfData 20
#define numberOfPixels 24

using namespace std;

void loadData(bool **tab); /*wczytanie danych ucz¹cych*/

void assign(bool* letter, bool **tab, Neuron *ptr);

int main()
{
	setlocale(LC_ALL, "");

	int epochs = 0; //licznik epok
	int userAnswer; /*iloœæ epok jak¹ chce przeprowadziæ u¿ytkownik*/

	/*Tworzenie dynamicznej tablicy dwuwymiarowej do przechowania danych ucz¹cych*/
	bool** data = new bool*[numeberOfData];
	for (int i = 0; i < numeberOfData; i++)
	{
		data[i] = new bool[numberOfPixels];
	}
	/*******************************************************************************/
	Neuron neuron; /*stworzenie domyœlnego neuronu*/
	Neuron *ptr = &neuron;
	bool letter[numberOfPixels] = { 0 }; /*tablica do przechowywania wyników dla poszczególnych liter*/
	char charLetters[numeberOfData] = { 'A','a','B','b','C','c','D','d','E','e','Z','z','R','r','K','k','H','h','L','l' };/*litery do wydruku*/

	loadData(data); /*³adowanie danych ucz¹cych do tablicy data*/
	
	neuron.showNeuron();
	cout << endl << "Wciœnij dowolny klawisz...";
	_getch();

	char znak = '0'; /*zmienna char do obs³ugi menu*/
	while (true)
	{
		system("cls");
		cout <<"_______________________________________________________" << endl;
		cout <<"|________________________MENU_________________________|" << endl;
		cout <<"| 1 | Algorytm Hebba z wspó³czynnikiem zapominania    |" << endl
			<< "| 2 | Algorytm Hebba bez wspólczynnika zapominania    |" << endl
			<< "| 3 | Wyœwietl pogrupowanie                           |" << endl
			<< "| 4 | Reset danych                                    |" << endl
			<< "| 5 | Wyjœcie                                         |" << endl
			<< "|___|_________________________________________________|"<<endl;
		cout<<endl << "Twój wybór >> "; cin >> znak;
		switch (znak)
		{
		case '1': /*uczenie z wspó³czynnikiem zapominania*/
		{
			assign(letter, data, ptr);
			cout << "Ile epok nauczania przeprowadziæ? >> "; cin >> userAnswer;
			for (int i = 0; i < userAnswer; i++)
			{
				neuron.forgetTeach(data);
				epochs++;
			}
			neuron.showNeuron();
			cout << endl << "Wciœnij dowolny klawisz...";
			_getch();
		}
		break;

		case '2': /*uczenie bez wspó³czynnika nauczania*/
		{
			assign(letter, data, ptr);
			cout << "Ile epok nauczania przeprowadziæ? >> "; cin >> userAnswer;
			for (int i = 0; i < userAnswer; i++)
			{
				neuron.teach(data);
				epochs++;
			}
			neuron.showNeuron();
			cout << endl << "Wciœnij dowolny klawisz...";
			_getch();
		}
		break;
		
		case '3': /*wyœwietl wyniki po uczeniu*/
		{
			cout << endl << "Wyniki po " << epochs << " epokach:" << endl;
		for (int i = 0; i < numeberOfData; i++)
		{
			for (int j = 0; j < numberOfPixels; j++)
			{
				letter[j] = data[i][j];
			}
			neuron.setNeuronInputs(letter);
			cout << charLetters[i] << " - " << neuron.getMembraneSum() << setprecision(4) << endl;
		}
		cout << endl << "Wciœnij dowolny klawisz...";
		_getch();
		}
		break;

		case '4': /*zresetuj program*/
		{
			system("cls");
			for (int i = 0; i < numeberOfData; i++)
			{
				letter[i] = 0;
			}
			neuron = Neuron();
			epochs = 0;
			loadData(data);
			cout << "Resetowanie ustawieñ i losowanie wag..." << endl;
			Sleep(1000);
			system("cls");
			cout << "Resetowanie ustawieñ zakoñczone sukcesem!" << endl;
			Sleep(1000);
		}
		break;

		case '0':/*wykjscie z programu*/
		{
			system("cls");
			cout << "Wyjœcie z programu...";
			Sleep(1500);
			exit(0);
		}
		break;

		default: /*nepoprawny klawisz*/
		{
			cout << "Wciœniêto nieprawid³owy klawisz!" << endl;
			cout << endl << "Wciœnij dowolny klawisz...";
			_getch();
		}

		}
	}
	
	
	//Dealokacja pamiêci
	for (int i = 0; i < numeberOfData; i++)
	{
		delete[] data[i];
	}
	delete[] data;
	data = NULL;
	neuron.~Neuron();
	return 0;
}


void loadData(bool **tab)
{
	double a = 0.0;
	ifstream plik;
	plik.open("dane.txt");
	string line;
	int numberLine = 1;
	int i = 0;
	int j = 0;

	if (!plik.good()) //jesli nie mozna otworzyc pliku to wypisz blad
	{
		cerr << "Nie mo¿na otworzyæ pliku Ÿród³owego!" << endl
		<< "Error #" << plik.fail() << endl << endl;
		system("PAUSE");
		exit(1);	//jesli nie udalo sie otworzyc pliku to zakoncza dzialanie calego programu
	}
	while (getline(plik, line, ';'))
	{
		a = atoi(line.c_str());
		numberLine++;
		tab[i][j] = a;
		j++;
		if (j % 24 == 0 && j != 0)
		{
			i++;
			j = 0;
		}
	}
	plik.close();
}

void assign(bool *letter, bool** tab, Neuron *ptr)
{
	for (int i = 0; i < numeberOfData; i++)
	{
		for (int j = 0; j < numberOfPixels; j++)
		{
			letter[j] = tab[i][j]; /*dla ustawienia wejsc neuronu robie to przypisanie*/
		}
	}
	ptr->setNeuronInputs(letter);
}