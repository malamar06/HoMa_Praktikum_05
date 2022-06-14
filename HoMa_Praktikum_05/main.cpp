#include <iostream>
#include "CZufall.h"
#include "CLotto.h"
#include <iomanip>
using namespace std;

int main()
{
	vector<int> testtz = { 4,8,11,19,25,1,10,3 };
	spielerEINS(4, 8, 30, 10000,testtz);
	spielerZWEI(4, 8, 30, 10000);
	montecarlo_lotto_giveinfo(4, 8, 30);


	return 0;
}