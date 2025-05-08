#include <iostream>
using namespace std;
int takenumber()
{
	int n = 0;
	cout << "please enter year to check? ";
	cin >> n;
	return n;
}
bool isleapyr(int yr)
{
	return (yr % 4 == 0 && yr % 100 != 0) || (yr % 4 == 0);
}
int yearindays(int yr)
{
	return (isleapyr) ? 366 : 365;
}
int yearinhours(int yr)
{
	return yearindays(yr) * 24;
}
int YearInMin(int yr)
{
	return yearinhours(yr) * 60;
}
int YearInSec(int yr)
{
	return YearInMin(yr) * 60;
}
int main()
{
	int num = takenumber();

	cout << "\nNumber of Days    in Year [" << num << "] is" << yearindays(num) << endl;
	cout << "Number of Hours   in Year [" << num << "] is" << yearinhours(num) << endl;
	cout << "Number of Minutes in Year [" << num << "] is" << YearInMin(num) << endl;
	cout << "Number of Seconds in Year [" << num << "] is" << YearInSec(num) << endl;

	return 0;
}