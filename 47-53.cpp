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
int DayOrer(stDate Date)
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
int DaysUntillEndOfMonth(stDate Date)
{
	stDate EndMonth;
	EndMonth.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
	EndMonth.Month = Date.Month;
	EndMonth.Year = Date.Year;

	return GetDifferenceInDate(Date, EndMonth, true);
}
int DaysUntillEndOfYear(stDate Date)
{
	stDate EndYear;
	EndYear.Day = 31;
	EndYear.Month = 12;
	EndYear.Year = Date.Year;

	return GetDifferenceInDate(Date, EndYear, true);
}
int main()
{
	stDate Date;
	Date = ReadFullDate();
	string weekname = Dayname(DayOrer(Date));
	cout << "\nToday is " << weekname << ", " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	cout << "\n\nIs it End of the Week?";
	if (weekname == "Sun")
		cout << "\nYes, It is End of the Week.";
	else
		cout << "\nNo, It is NOT End of the Week.";

	cout << "\n\nIs it a Weekend?";
	if (weekname == "Sat" || weekname == "Sun")
		cout << "\nYes, It is a Weekend.";
	else
		cout << "\nNo, It is NOT a Weekend.";

	cout << "\n\nIs it a Bussiness day?";
	if (weekname != "Sat" && weekname != "Sun")
		cout << "\nYes, It is a Bussiness day.";
	else
		cout << "\nNo, It is NOT a Bussiness day.";

	cout << "\n\nDays untill End of the week : " << 6 - DayOrer(Date)  << " Day(s)";
	cout << "\nDays untill End of the week : " << DaysUntillEndOfMonth(Date) << " Day(s)";
	cout << "\nDays untill End of the week : " << DaysUntillEndOfYear(Date) << " Day(s)";

	system("pause>0");
	return 0;
}