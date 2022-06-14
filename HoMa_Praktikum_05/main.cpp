#include <iostream>
#include "CZufall.h"
#include "CLotto.h"
#include <iomanip>
using namespace std;

void spielerZWEI(int r, int k, int n, int N)
{
	double wincount = 0;
	CZufall random;
	CLotto Lotto(n, k, -1);

	for (int x = 0; x < N; x++)
	{
		Lotto.tippzettel_setzen(Lotto.zahlenziehen());

		if (Lotto.lottospielen() == r)
		{
			wincount++;
		}
	}

	//infostelle
	cout << "**************************************" << endl;
	cout << "Simulation type : SPIELER 2\n";
	cout << "Win Count : " << wincount << endl;
	cout << N << " mal simuliert.\n";
	cout << "Warhscheinlichkeit Wert in Prozent : " << wincount / N * 100 << endl;
}

void spielerEINS(int r, int k, int n, int N,vector<int> tippzettel)
{
	double wincount = 0;
	//tippzettel 4 8 15 16 23 42
	CLotto Lotto(n, k, -1);
	Lotto.tippzettel_setzen(tippzettel);
	for (int i = 0; i < N; i++)
	{
		if (Lotto.lottospielen() == r)
		{
			wincount++;
		}
	}
	double winprozent = wincount / N * 100;

	//infostelle
	cout << "**************************************" << endl;
	cout << "Simulation type : SPIELER 1\n";
	cout << "Win Count : " << wincount << endl;
	
	cout << N << " mal mit Tippzettel ( ";
	for (int i = 0; i < tippzettel.size(); i++)
	{
		cout << tippzettel[i] << ", ";
	}
	cout << ") simuliert.\n";
	cout << "Warhscheinlichkeit Wert in Prozent : " << setprecision(7) << winprozent << endl;
}


int main()
{
	vector<int> testtz = { 4,8,11,19,25,1,10,3 };
	spielerEINS(2, 8, 30, 10000,testtz);
	spielerZWEI(2, 8, 30, 10000);
	//CZufall random;
	//random.test(0, 30, 10000, 1);

	return 0;
}