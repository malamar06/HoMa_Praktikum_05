#include "CZufall.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>

int CZufall::wert(int a, int b)
{
	return rand() % (b - a + 1) + a;
}

void CZufall::initialisiere(int s)
{
	srand(s);
}

void CZufall::test(int a, int b, int N, bool print)
{
	std::vector<int> rErgebnis;
	rErgebnis.resize(N);
	int counter = 0;
	int counter_indexcheck = 0;

	for (int i = 0; i < N; i++)//Ziehung Schleife
	{
		rErgebnis[i] = wert(a, b);//Aktuel Ziehung 

		if (rErgebnis[i] <= b && rErgebnis[i] >= a)//Fakt Check hier
			counter++;
		else//assertion
		{
		std::cout << "Error : Ergebnis ist aus dem Bereich." << std::endl;//assert
		system("pause");
		}
	}
	if (print)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << j << " =>  " << rErgebnis[j] << std::endl;
		}
	}

	//Zufaelligkeit Uberprufung
	for (int i = a; i <= b; i++)
	{
		int hoeversZahl = 0;
		for (int k = 0; k < N; k++)
		{
			if (i == rErgebnis[k])
			{
				hoeversZahl++;
			}
		}
		std::cout << i << " Zufaelligkeitswert = " << hoeversZahl << std::endl;
	}

	//infostelle
	std::cout << "**************************************" << std::endl;
	std::cout << "TEST :\n";
	std::cout << N << " Zufall nummern ausgezieht.\n";
	std::cout << counter << " Nummern von " << N << " sind im bereich: " << a << " - " << b << std::endl;

}

void CZufall::test_falsch(int a, int b, int N)
{
	std::vector<int> rErgebnis;
	rErgebnis.resize(N);
	int counter = 0;

	for (int i = 0; i < N; i++)
	{
		initialisiere(time(NULL));
		rErgebnis[i] = wert(a, b);
		if (rErgebnis[i] < b && rErgebnis[i] > a)
			counter++;

	}
	std::cout << "**************************************" << std::endl;
	std::cout << "TEST FALSCH : \n";
	std::cout << N << " Zufall nummern ausgezieht.\n";
	std::cout << counter << " Nummern von " << N << " sind im bereich: " << a << " - " << b << std::endl;
}