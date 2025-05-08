#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int takenumber()
{
	int n = 0;
	cout << "\nplease enter a Year? ";
	cin >> n;
	return n;
}
int takemonth()
{
	int n = 0;
	cout << "\nplease enter a Month? ";
	cin >> n;
	return n;
}
int takeday()
{
	int n = 0;
	cout << "\nplease enter a Day? ";
	cin >> n;
	return n;
}

bool isleapyr(int yr)
{
	return (yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0);
}
int NumberDays(int yr, int month)
{
	if (month < 1 || month > 12)
		return 0;
	int arr31days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30,  31, 30, 31 };
	return (month == 2) ? (isleapyr(yr) ? 29 : 28) : arr31days[month - 1];
}

int NumberOfDays(int year, int month, int day)
{
	int sum = 0;
	for (int i = 1; i < month; i++)
	{
		sum += NumberDays(year, i);
	}
	return sum + day;
}

int main()
{
	int y = 0, m = 0;

	int day = takeday();
	int month = takemonth();
	int yr = takenumber();

	cout << "\nThe number of Days from the begining of the year is : " << NumberOfDays(yr, month, day);

	return 0;
}