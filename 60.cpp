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
struct stPeriod
{
	stDate startDate;
	stDate EndDate;
};
int takeyear()
{
	int n = 0;
	cout << "please enter a Year? ";
	cin >> n;
	return n;
}
int takemonth()
{
	int n = 0;
	cout << "please enter a Month? ";
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
int VacationDays()
{
	int n = 0;
	cout << "\nplease enter vacation day? ";
	cin >> n;
	return n;
}
stDate ReadFullDate()
{
	stDate Date;
	Date.Day = takeday();
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
bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) : false) : false;
}
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2)) ? true : false;
}
int CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1AfterDate2(Date1, Date2))
		return 1;
	else if (IsDate1BeforeDate2(Date1, Date2))
		return -1;
	else
		return 0;
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
stPeriod ReadPeriod()
{
	stPeriod Period;
	cout << "Enter Start Date." << endl;
	Period.startDate = ReadFullDate();
	cout << "\nEnter End Date\n.";
	Period.EndDate = ReadFullDate();
	return Period;
}
bool IsOverlapPeriod(stPeriod Period1, stDate Date)
{
	return (CompareDates(Period1.EndDate, Date) == 1 || CompareDates(Period1.startDate, Date) == 1);
}
int main()
{
	stPeriod Period1;
	stDate Date;
	cout << "Enter Period 1:" << endl;
	Period1 = ReadPeriod();
	cout << "\nEnter Date to check.\n";
	Date = ReadFullDate();

	if (IsOverlapPeriod(Period1, Date))
		cout << "\nYes, Date is within Period.";
	else
		cout << "\nNo, Date is NOT within Period.";

	system("pause>0");
	return 0;
}