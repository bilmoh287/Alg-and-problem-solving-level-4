#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
struct stDate
{
	int Day;
	int Month;
	int Year;
};
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
int takenewdays()
{
	int n = 0;
	cout << "\nHow many days to add? ";
	cin >> n;
	return n;
}

bool isleapyr(int yr)
{
	return (yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0);
}
int NumberOfDaysInMonth(int yr, int month)
{
	if (month < 1 || month > 12)
		return 0;
	int arr31days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30,  31, 30, 31 };
	return (month == 2) ? (isleapyr(yr) ? 29 : 28) : arr31days[month - 1];
}

int NumberOfDays(int year, int month, int day)
{
	int sum = 0;
	for (int i = 1; i <= month-1; i++)
	{
		sum += NumberOfDaysInMonth(year, i);
	}
	return sum + day;
}
stDate DateOfTheDay(int NumberOfDays, int addeddays, int year)
{
	stDate date;
	int remainingdays = NumberOfDays + addeddays;
	date.Year = year;
	date.Month = 1;

	while (true)
	{
		int Monthdays = NumberOfDaysInMonth(date.Year, date.Month);
		if (remainingdays > Monthdays)
		{
			remainingdays -= Monthdays;
			date.Month++;
			if (date.Month > 12)
			{
				date.Year++;
				date.Month = 1;
			}
		}
		else
		{
			date.Day = remainingdays;
			break;
		}
	}
	return date;
}
int main()
{
	int y = 0, m = 0;

	int day = takeday();
	int month = takemonth();
	int yr = takenumber();
	int additionaldays = takenewdays();
	int Numberofdays = NumberOfDays(yr, month, day);

	stDate Date;
	Date = DateOfTheDay(Numberofdays, additionaldays, yr);
	cout << "\n\nDate after adding [" << additionaldays << "] days is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	return 0;
}