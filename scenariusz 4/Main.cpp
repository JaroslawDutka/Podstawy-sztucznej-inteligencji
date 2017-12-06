#include "Neuron.h"
#define numeberOfData 20
#define numberOfPixels 24

using namespace std;

void loadData(bool **tab);

int main()
{
	setlocale(LC_ALL, "");

	int epochs = 0; //licznik epok
	int userAnswer;

	bool** data = new bool*[numeberOfData];
	for (int i = 0; i < numeberOfData; i++)
	{
		data[i] = new bool[numberOfPixels];
	}
	Neuron neuron;
	bool letter[numberOfPixels] = { 0 };
	char charLetters[numeberOfData] = { 'A','a','B','b','C','c','D','d','E','e','Z','z','R','r','K','k','H','h','L','l' };

	loadData(data);

	/*cout << "Zestaw ucz¹cy: " << endl;
	for (int i = 0; i < numeberOfData; i++)
	{
		for (int j = 0; j < numberOfPixels; j++)
		{
			cout << data[i][j];
			if (j % 4 == 3 && j != 0)cout << endl;
		}
	}
	cout << endl << "Wciœnij ENTER";
	_getch();*/
	neuron.showNeuron();
	cout << endl << "Wciœnij ENTER";
	_getch();

	char znak = '0';
	while (true)
	{
		system("cls");
		cout << "Algorytm Hebba z wspó³czynnikiem zapominania wciœnij 1" << endl
			<< "Algorytm Hebba bez wspólczynnika zapominania wciœnij 2" << endl
			<< "Wyœwietl pogrupowanie wcisnij 3" << endl
			<< "Wyjscie wcisnij 0" << endl;
		cin >> znak;
		switch (znak)
		{
		case '1':
		{
			cout << "Ile epok nauczania przeprowadziæ? >> "; cin >> userAnswer;
			for (int i = 0; i < userAnswer; i++)
			{
				neuron.forgetTeach(data);
				epochs++;
			}
			neuron.showNeuron();
			cout << endl << "Wciœnij ENTER";
			_getch();
		}
		break;
		case '2':
		{
			cout << "Ile epok nauczania przeprowadziæ? >> "; cin >> userAnswer;
			for (int i = 0; i < userAnswer; i++)
			{
				neuron.teach(data);
				epochs++;
			}
			neuron.showNeuron();
			cout << endl << "Wciœnij ENTER";
			_getch();
		}
		break;
		
		case '3':
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
		cout << endl << "Wciœnij ENTER";
		_getch();
		}
		break;
		case '0':
		{
			exit(0);
		}
		break;
		default:
		{
			cout << "Wciœniêto nieprawid³owy klawisz!" << endl;
			cout << endl << "Wciœnij ENTER";
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
		<< "blad #" << plik.fail() << endl << endl;
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
