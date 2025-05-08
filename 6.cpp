#include <iostream>
using namespace std;
int takenumber()
{
	int n = 0;
	cout << "please enter year to check? ";
	cin >> n;
	return n;
}
int takemonth()
{
	int n = 0;
	cout << "\nplease enter month to check? ";
	cin >> n;
	return n;
}
bool isleapyr(int yr)
{
	return (yr % 4 == 0 && yr % 100 != 0) || (yr % 4 == 0);
}
int yearindays(int yr, int month)
{
	if (month < 1 || month > 12)
		return 0;
	int arr31days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30,  31, 30, 31};
	return (month == 2) ? (isleapyr(yr) ? 29 : 28) : arr31days[month -1];
}
int yearinhours(int yr, int month)
{
	return yearindays(yr, month) * 24;
}
int YearInMin(int yr, int month)
{
	return yearinhours(yr, month) * 60;
}
int YearInSec(int yr, int month)
{
	return YearInMin(yr, month) * 60;
}
int main()
{
	int num = takenumber();
	int mon = takemonth();

	cout << "\nNumber of Days    in Month [" << num << "] is " << yearindays(num,mon) << endl;
	cout << "Number of Hours   in Month [" << num << "] is " << yearinhours(num, mon) << endl;
	cout << "Number of Minutes in Month [" << num << "] is " << YearInMin(num, mon) << endl;
	cout << "Number of Seconds in Month [" << num << "] is " << YearInSec(num, mon) << endl;

	return 0;
}