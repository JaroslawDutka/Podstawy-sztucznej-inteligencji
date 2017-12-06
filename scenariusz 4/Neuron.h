#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

class Neuron
{
private:
	int size; //iloœæ wejœæ
	bool *input; //wejœcia
	double *weight; //wagi

public:
	Neuron();
	~Neuron();

	void setSize(int s);
	void setInput(int i, bool value);
	void setWeight(int i, double value);

	int getSize();
	bool getInput(int i);
	double getWeight(int i);

	void setNeuronInputs(bool*);
	void teach(bool **);
	void forgetTeach(bool **);
	double getMembraneSum();
	double activationFunction();

	void showNeuron();
};