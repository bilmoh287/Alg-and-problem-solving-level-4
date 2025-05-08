#include <iostream>
using namespace std;
int takenumber()
{
	int n = 0;
	cout << "please enter year to check? ";
	cin >> n;
	return n;
}
void checkyear(int n)
{
	if (n % 400 == 0)
	{
		cout << "\nYes, year [" << n << "] is a Leap year" << endl;
	}
	else if (n % 100 != 0 && n % 4 == 0)
	{
		cout << "\nYes, year [" << n << "] is a Leap year" << endl;
	}
	else
	{
		cout << "\nNO, year [" << n << "] is NOT a Leap year" << endl;
	}
}
int main()
{
	int num = takenumber();
	checkyear(num);

	return 0;
}