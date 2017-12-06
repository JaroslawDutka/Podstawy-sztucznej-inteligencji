#include "Neuron.h"

#define learningRate  0.05
#define forgetRate  0.005
#define numberOfData  20

using namespace std;

#pragma region Constructors&Destructors
Neuron::Neuron()
{
	size = 20;
	input = new bool[size];
	weight = new double[size];
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		input[i] = 0;
		weight[i] = (rand() % 100) / 200.0; //losowanie od 0 do 1
	}
}

Neuron::~Neuron()
{
	delete[] input;
	delete[] weight;
}
#pragma endregion

#pragma region Setters
void Neuron::setSize(int s)
{
	size = s;
}

void Neuron::setInput(int i, bool value)
{
	input[i] = value;
}

void Neuron::setWeight(int i, double value)
{
	weight[i] = value;
}
#pragma endregion

#pragma region Getters
int Neuron::getSize()
{
	return size;
}

bool Neuron::getInput(int i)
{
	return input[i];
}

double Neuron::getWeight(int i)
{
	return weight[i];
}
#pragma endregion

#pragma region Functions
void Neuron::setNeuronInputs(bool * tab)
{
	for (int i = 0; i < size; i++)
	{
		input[i] = tab[i];
	}
}

void Neuron::teach(bool ** tab)
{
	double answer = 0.0;

	for (int i = 0; i < numberOfData; i++)
	{
		for (int j = 0; j < size; j++)
		{
			input[j] = tab[(size*i) + j];
		}
		for (int j = 0; j < size; j++)
		{
			answer = getMembraneSum();
			weight[j] = weight[j] /** (1 - forgetRate)*/ + (learningRate * input[j] * answer);
		}
	}
}

void Neuron::forgetTeach(bool ** tab)
{
	double answer = 0.0;

	for (int i = 0; i < numberOfData; i++)
	{
		for (int j = 0; j < size; j++)
		{
			input[j] = tab[(size*i) + j];
		}
		for (int j = 0; j < size; j++)
		{
			answer = getMembraneSum();
			weight[j] = weight[j] * (1 - forgetRate) + (learningRate * input[j] * answer);
		}
	}
}


double Neuron::getMembraneSum()
{
	if (size == 0)
		return -1;
	else
	{
		double sum = 0.0;

		for (int i = 0; i < size; i++)		
			sum += input[i] * weight[i];
		
		return sum;
	}
}

double Neuron::activationFunction()
{
	double x = getMembraneSum();
	if (x >= 4.5)
		return 1.0;
	return 0.0;
}

void Neuron::showNeuron()
{
	{
		//std::cout << "_____MÓJ NEURON_____" << std::endl;
		for (int i = 0; i < size; i++)
		{
			cout << i << "  INPUT: " << input[i] << "  WEIGHT: " << weight[i] << endl;
		}
		//std::cout << "_________________________" << std::endl;
		cout << "| SUMA:     |   " << getMembraneSum() << endl<<endl;
		//std::cout << "_________________________" << std::endl;
	}
}
#pragma endregion

