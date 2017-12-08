#include "Neuron.h"
#define numeberOfData 20
#define numberOfPixels 24

using namespace std;

void loadData(bool **tab); /*wczytanie danych ucz�cych*/

void assign(bool* letter, bool **tab, Neuron *ptr);

int main()
{
	setlocale(LC_ALL, "");

	int epochs = 0; //licznik epok
	int userAnswer; /*ilo�� epok jak� chce przeprowadzi� u�ytkownik*/

	/*Tworzenie dynamicznej tablicy dwuwymiarowej do przechowania danych ucz�cych*/
	bool** data = new bool*[numeberOfData];
	for (int i = 0; i < numeberOfData; i++)
	{
		data[i] = new bool[numberOfPixels];
	}
	/*******************************************************************************/
	Neuron neuron; /*stworzenie domy�lnego neuronu*/
	Neuron *ptr = &neuron;
	bool letter[numberOfPixels] = { 0 }; /*tablica do przechowywania wynik�w dla poszczeg�lnych liter*/
	char charLetters[numeberOfData] = { 'A','a','B','b','C','c','D','d','E','e','Z','z','R','r','K','k','H','h','L','l' };/*litery do wydruku*/

	loadData(data); /*�adowanie danych ucz�cych do tablicy data*/
	
	neuron.showNeuron();
	cout << endl << "Wci�nij dowolny klawisz...";
	_getch();

	char znak = '0'; /*zmienna char do obs�ugi menu*/
	while (true)
	{
		system("cls");
		cout <<"_______________________________________________________" << endl;
		cout <<"|________________________MENU_________________________|" << endl;
		cout <<"| 1 | Algorytm Hebba z wsp�czynnikiem zapominania    |" << endl
			<< "| 2 | Algorytm Hebba bez wsp�lczynnika zapominania    |" << endl
			<< "| 3 | Wy�wietl pogrupowanie                           |" << endl
			<< "| 4 | Reset danych                                    |" << endl
			<< "| 5 | Wyj�cie                                         |" << endl
			<< "|___|_________________________________________________|"<<endl;
		cout<<endl << "Tw�j wyb�r >> "; cin >> znak;
		switch (znak)
		{
		case '1': /*uczenie z wsp�czynnikiem zapominania*/
		{
			assign(letter, data, ptr);
			cout << "Ile epok nauczania przeprowadzi�? >> "; cin >> userAnswer;
			for (int i = 0; i < userAnswer; i++)
			{
				neuron.forgetTeach(data);
				epochs++;
			}
			neuron.showNeuron();
			cout << endl << "Wci�nij dowolny klawisz...";
			_getch();
		}
		break;

		case '2': /*uczenie bez wsp�czynnika nauczania*/
		{
			assign(letter, data, ptr);
			cout << "Ile epok nauczania przeprowadzi�? >> "; cin >> userAnswer;
			for (int i = 0; i < userAnswer; i++)
			{
				neuron.teach(data);
				epochs++;
			}
			neuron.showNeuron();
			cout << endl << "Wci�nij dowolny klawisz...";
			_getch();
		}
		break;
		
		case '3': /*wy�wietl wyniki po uczeniu*/
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
		cout << endl << "Wci�nij dowolny klawisz...";
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
			cout << "Resetowanie ustawie� i losowanie wag..." << endl;
			Sleep(1000);
			system("cls");
			cout << "Resetowanie ustawie� zako�czone sukcesem!" << endl;
			Sleep(1000);
		}
		break;

		case '0':/*wykjscie z programu*/
		{
			system("cls");
			cout << "Wyj�cie z programu...";
			Sleep(1500);
			exit(0);
		}
		break;

		default: /*nepoprawny klawisz*/
		{
			cout << "Wci�ni�to nieprawid�owy klawisz!" << endl;
			cout << endl << "Wci�nij dowolny klawisz...";
			_getch();
		}

		}
	}
	
	
	//Dealokacja pami�ci
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
		cerr << "Nie mo�na otworzy� pliku �r�d�owego!" << endl
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