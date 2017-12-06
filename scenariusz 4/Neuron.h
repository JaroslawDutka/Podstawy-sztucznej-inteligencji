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
	Neuron(); //konstruktor
	~Neuron(); //destruktor

	void setSize(int s); /*ustawia iloœæ wejœæ do neuronu*/
	void setInput(int i, bool value); /*ustawia wartoœæ wejœcia o indeksie i wartoœci¹ boolean*/
	void setWeight(int i, double value); /*ustawia wartoœæ o indeksie i wagi*/

	int getSize(); /*zwraca iloœæ wejœæ do neuronu*/
	bool getInput(int i); /*zwraca wartoœæ boolean wejœcia o indeksie i*/
	double getWeight(int i); /*zwraca wartoœæ wagi o indeksie i*/

	void setNeuronInputs(bool*); /*ustawia wartoœæ wejœæ neuronu danymi z tablicy, na któr¹ wskazuje wskaŸnik*/
	void teach(bool **); /*funkcja uczenia neuronu bez wspó³czynnika zapominia*/
	void forgetTeach(bool **); /*funkcja uczenia neuronu z wspó³czynnikiem zapominania*/
	double getMembraneSum(); /*oblicza sumê membranow¹ (suma += waga[i] * input[i])*/

	void showNeuron(); /*wyœwietlanie neuronu*/
};