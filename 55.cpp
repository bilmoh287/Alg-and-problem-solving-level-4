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
	cout << "please enter a Day? ";
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

int DayOrder(int yr, int month, int day)
{
	int a = (14 - month) / 12;
	int y = yr - a;
	int m = month + (12 * a) - 2;

	int d = 0;
	return  (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
int DayOrder(stDate Date)
{
	return DayOrder(Date.Year, Date.Month, Date.Day);
}
string Dayname(int d)
{
	string days[7] = { "Sun", "Mon", "Tue", "Wend", "Thur", "Fri", "Sat" };
	return days[d];
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
bool IsBussinessDays(stDate Date)
{
	//for Araba's (5 & 6) and form Ethiopia (6 & 0) or Sat & San
	return (DayOrder(Date) == 5 || DayOrder(Date) == 6) ? true : false;
}
bool IsWeekend(stDate Date)
{
	//weekend is Fri & Sat
	return (DayOrder(Date) == 5 || DayOrder(Date) == 6) ? true : false;
}
int ActualVacationDays(int Diff, stDate Date1, stDate Date2)
{
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		if (IsBussinessDays(Date1))
		{
			Diff--;
		}
		Date1 = DateAfterAdding(Date1);
	}

	return Diff;
}
stDate VacationReturnDate(int days, stDate Date1)
{
	for (int i = 0; i < days; i++)
	{
		if (IsWeekend(Date1))
		{
			i--;
		}
		Date1 = DateAfterAdding(Date1);
	}
	while (IsWeekend(Date1))
	{
		Date1 = DateAfterAdding(Date1);
	}
	return Date1;
}
int main()
{
	stDate Date1;
	cout << "Vacation Starts.\n";
	Date1 = ReadFullDate();
	int Vdays = VacationDays();
	Date1 = VacationReturnDate(Vdays, Date1);
	string StartingWeekName = Dayname(DayOrder(Date1));


	cout << "\nReturn Date : " << StartingWeekName << ", " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	system("pause>0");
	return 0;
}