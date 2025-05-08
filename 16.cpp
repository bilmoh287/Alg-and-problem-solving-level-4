#include <iostream>
using namespace std;
struct stDate
{
	int Day;
	int Month;
	int Year;
};
int takeyear()
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
stDate ReadFullDate()
{
	stDate Date;
	Date.Day = takenewdays();
	Date.Month = takemonth();
	Date.Year = takeyear();

	return Date;
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

bool LastDay(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}
bool LastMonth(stDate Date)
{
	return (Date.Month == 12);
}
bool DateAfterAdding(stDate &Date)
{
	if (LastDay(Date) && LastMonth(Date))
	{
		Date.Day = 1;
		Date.Month = 1;
		Date.Year++;
		return true;
	}
	if (LastDay(Date))
	{
		Date.Day = 1;
		Date.Month++;
		return true;
	}
	else
	{
		Date.Day++;
		return true;
	}
}

int main()
{
	int y = 0, m = 0;

	stDate Date;
	Date = ReadFullDate();

	DateAfterAdding(Date);

	cout << "\n\nDate after adding One days is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	return 0;
}