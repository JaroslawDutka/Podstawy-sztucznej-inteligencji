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
	int size; //ilo�� wej��
	bool *input; //wej�cia
	double *weight; //wagi

public:
	Neuron(); //konstruktor
	~Neuron(); //destruktor

	void setSize(int s); /*ustawia ilo�� wej�� do neuronu*/
	void setInput(int i, bool value); /*ustawia warto�� wej�cia o indeksie i warto�ci� boolean*/
	void setWeight(int i, double value); /*ustawia warto�� o indeksie i wagi*/

	int getSize(); /*zwraca ilo�� wej�� do neuronu*/
	bool getInput(int i); /*zwraca warto�� boolean wej�cia o indeksie i*/
	double getWeight(int i); /*zwraca warto�� wagi o indeksie i*/

	void setNeuronInputs(bool*); /*ustawia warto�� wej�� neuronu danymi z tablicy, na kt�r� wskazuje wska�nik*/
	void teach(bool **); /*funkcja uczenia neuronu bez wsp�czynnika zapominia*/
	void forgetTeach(bool **); /*funkcja uczenia neuronu z wsp�czynnikiem zapominania*/
	double getMembraneSum(); /*oblicza sum� membranow� (suma += waga[i] * input[i])*/

	void showNeuron(); /*wy�wietlanie neuronu*/
};