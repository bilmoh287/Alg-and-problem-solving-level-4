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
	cout << "\nplease enter a Day? ";
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

bool LastDay(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}
bool LastMonth(stDate Date)
{
	return (Date.Month == 12);
}
stDate IncreaseDateByOneDAy(stDate& Date)
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
stDate IncreaseDateByXDay(short day, stDate Date)
{
	for (int i = 1; i <= day; i++)
	{
		IncreaseDateByOneDAy(Date);
	}
	return Date;
}
stDate IncreaseDateByOneWeek(stDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		IncreaseDateByOneDAy(Date);
	}
	return Date;
}
stDate IncreaseDateByXWeek(short weeks, stDate Date)
{
	for (int i = 1; i <= weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}
stDate IncreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	int CurrentDay = NumberOfDaysInMonth(Date.Year, Date.Month);
	if (Date.Day > CurrentDay)
		Date.Day = CurrentDay;

	return Date;
}
stDate IncreaseDateByXMonth(short Months, stDate Date)
{
	for (int i = 1; i <= Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}
stDate IncreaseDateByOneYear(stDate Date)
{
	Date.Year++;
	return Date;
}
stDate IncreaseDateByXYear(short Years, stDate Date)
{
	for (int i = 1; i <= Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}
stDate IncreaseDateByXYearFaster(short Years, stDate Date)
{
	Date.Year += Years;
	return Date;
}
stDate IncreaseDateByOneDecade(stDate Date)
{
	Date.Year += 10;
	return Date;
}
stDate IncreaseDateByXDecade(short Decades, stDate Date)
{
	for (int i = 1; i <= Decades * 10; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}
stDate IncreaseDateByXDecadeFaster(short Decades, stDate Date)
{
	Date.Year += Decades * 10;
	return Date;
}
stDate IncreaseDateByOneCentury(stDate Date)
{
	Date.Year += 100;
	return Date;
}
stDate IncreaseDateByOneMillennium(stDate Date)
{
	Date.Year += 1000;
	return Date;
}
int main()
{
	int y = 0, m = 0;

	stDate Date;
	Date = ReadFullDate();

	Date = IncreaseDateByOneDAy(Date);
	cout << "\n01-Adding One Day Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByXDay(10, Date);
	cout << "\n01-Adding 10 Day Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByOneWeek(Date);
	cout << "\n01-Adding One Week Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByXWeek(10, Date);
	cout << "\n01-Adding 10 Week Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByOneMonth(Date);
	cout << "\n01-Adding One Month Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByXMonth(5, Date);
	cout << "\n01-Adding 10 Month Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByOneYear(Date);
	cout << "\n01-Adding 1 Year Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByXYear(10,Date);
	cout << "\n01-Adding 10 Years Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByXYearFaster(10,Date);
	cout << "\n01-Adding 10 Years Is (faster) : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByOneDecade(Date);
	cout << "\n01-Adding 1 Decade Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByXDecade(10, Date);
	cout << "\n01-Adding 10 Decade Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByXDecadeFaster(10, Date);
	cout << "\n01-Adding 10 Decade Is (faster) : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByOneCentury(Date);
	cout << "\n01-Adding 1 Century Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = IncreaseDateByOneMillennium(Date);
	cout << "\n01-Adding 1 Millennium Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	return 0;
}