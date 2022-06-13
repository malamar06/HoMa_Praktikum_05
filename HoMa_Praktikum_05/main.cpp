#include <iostream>
#include "CZufall.h"
#include "CLotto.h"
#include <iomanip>
using namespace std;

void spielerEINS(int r, int k, int n, int N)
{
	double wincount = 0;
	//tippzettel 4 8 15 16 23 42
	vector<int> tippzettelnumm = { 4,8,11,19,25,1 };
	CLotto Lotto(n, k, -1);
	Lotto.tippzettel_setzen(tippzettelnumm);
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
	for (int i = 0; i < tippzettelnumm.size(); i++)
	{
		cout << tippzettelnumm[i] << ", ";
	}
	cout << ") simuliert.\n";
	cout << "Warhscheinlichkeit Wert in Prozent : " << setprecision(5) << winprozent << endl;
}


int main()
{
	spielerEINS(2, 6, 49, 100);
	


	return 0;
}