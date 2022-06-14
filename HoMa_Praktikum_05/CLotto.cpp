#include "CLotto.h"
#include <time.h>
#include <iostream>
#include "CZufall.h"


int CLotto::lottospielen()
{
	int winnercounter = 0;

	std::vector<int> luckynumbers = zahlenziehen();


	for (int i = 0; i < k; i++)//schleife fur tippzettel prufung
	{
		for (int j = 0; j < k; j++)//vergleichung zwischen ein element des tippzettels und alle luckynubmers
		{
			if (tippzettel[i] == luckynumbers[j])//es gibt keine doppelt Zahlen, deswegen keine Uberlappen 
			{
				winnercounter++;
			}
		}
	}
	/*
	std::cout << "Lotto gespielt winnercounter : " << winnercounter << std::endl;
	std::cout << "Lucky Numbers : ";
	for (int i = 0; i < luckynumbers.size(); i++)
	{
		std::cout << luckynumbers[i] << ", ";
	}
	std::cout << std::endl;*/
	return winnercounter;
}

std::vector<int> CLotto::zahlenziehen()//k mal zahlen ziehen
{
	
	std::vector<int> blatt;	
	CZufall random;
	int transporter = 0;
	blatt.clear();
	while (blatt.size() < k)
	{
		transporter = random.wert(0, n);//draw number

		bool init = false;
		for (int i = 0; i < blatt.size(); i++)//already drawn check loop
		{
			if (transporter == blatt[i]) //already drawn check
			{
				init = true;
			}
		}
		if (!init)//if new number save it 
			blatt.push_back(transporter);
		//wenn we go to next iteration its gona be a new transporter intilisation with different random value
	}
	return blatt;
}


CLotto::CLotto(int eingabe_n, int eingabe_k, int eingabe_s)
{
	n = eingabe_n;
	k = eingabe_k;
	if (s < 0)
		s = time(NULL);
	else
		s = eingabe_s;
	CZufall random;
	random.initialisiere(s);
	
}


void CLotto::tippzettel_setzen(std::vector<int> eingabe)
{
	if (eingabe.size() != k)
	{
		std::cout << "Falsch Tippzettel eingegeben!" << std::endl;
		system("pause");
	}
	tippzettel = eingabe;
}
