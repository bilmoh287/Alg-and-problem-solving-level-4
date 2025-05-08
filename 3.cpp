#include <iostream>
using namespace std;
int takenumber()
{
	int n = 0;
	cout << "please enter year to check? ";
	cin >> n;
	return n;
}
bool checkyear(int n)
{
	return (n % 400 == 0) ? true : ((n % 100 != 0 && n % 4 == 0)? true : false);
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