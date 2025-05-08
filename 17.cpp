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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool LastDay(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}
bool LastMonth(stDate Date)
{
	return (Date.Month == 12);
}
stDate DateAfterAdding(stDate& Date)
{
	if (LastDay(Date) && LastMonth(Date))
	{
		Date.Day = 1;
		Date.Month = 1;
		Date.Year++;
		return Date;
	}
	if (LastDay(Date))
	{
		Date.Day = 1;
		Date.Month++;
		return Date;
	}
	else
	{
		Date.Day++;
		return Date;
	}
}
int GetDifferenceInDate(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		DateAfterAdding(Date1);
		Days++;
	}
	return IncludeEndDay ? ++Days : Days;
}
int main()
{
	int y = 0, m = 0;

	stDate Date1, Date2;
	Date1 = ReadFullDate();
	Date2 = ReadFullDate();


	cout << "\nDifference is : " << GetDifferenceInDate(Date1, Date2) << " Day(s)";
	cout << "\nDifference (Including LastDay is) : " << GetDifferenceInDate(Date1, Date2, true) << " Day(s)";

	return 0;
}