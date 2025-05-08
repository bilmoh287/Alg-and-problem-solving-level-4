#include <iostream>
using namespace std;
int takenumber()
{
	int n = 0;
	cout << "please enter year to check? ";
	cin >> n;
	return n;
}
bool checkyear(int yr)
{
	return (yr % 4 == 0 && yr % 100 != 0) || (yr % 4 == 0);
}
int main()
{
	int num = takenumber();
	if(checkyear(num))
		cout << "\nYes, year [" << num << "] is a Leap year" << endl;
	else
		cout << "\nNO, year [" << num << "] is NOT a Leap year" << endl;
	return 0;
}