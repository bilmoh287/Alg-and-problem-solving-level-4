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

bool LastDay(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}
bool LastMonth(stDate Date)
{
	return (Date.Month == 12);
}
stDate DecreaseDateByOneDAy(stDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Year--;
			Date.Month = 12;
			Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
		}
	}

	else 
	{
		Date.Day--;
	}
	return Date;
}
stDate DecreaseDateByXDay(short day, stDate Date)
{
	for (int i = 1; i <= day; i++)
	{
		Date = DecreaseDateByOneDAy(Date);
	}
	return Date;
}
stDate DecreaseDateByOneWeek(stDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDAy(Date);
	}
	return Date;
}
stDate DecreaseDateByXWeek(short weeks, stDate Date)
{
	for (int i = 1; i <= weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}
stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	int CurrentDay = NumberOfDaysInMonth(Date.Year, Date.Month);
	if (Date.Day > CurrentDay)
		Date.Day = CurrentDay;

	return Date;
}
stDate DecreaseDateByXMonth(short Months, stDate Date)
{
	for (int i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}
stDate DecreaseDateByOneYear(stDate Date)
{
	Date.Year--;
	return Date;
}
stDate DecreaseDateByXYear(short Years, stDate Date)
{
	for (int i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}
stDate DecreaseDateByXYearFaster(short Years, stDate Date)
{
	Date.Year -= Years;
	return Date;
}
stDate DecreaseDateByOneDecade(stDate Date)
{
	Date.Year -= 10;
	return Date;
}
stDate DecreaseDateByXDecade(short Decades, stDate Date)
{
	for (int i = 1; i <= Decades * 10; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}
stDate DecreaseDateByXDecadeFaster(short Decades, stDate Date)
{
	Date.Year -= Decades * 10;
	return Date;
}
stDate DecreaseDateByOneCentury(stDate Date)
{
	Date.Year -= 100;
	return Date;
}
stDate DecreaseDateByOneMillennium(stDate Date)
{
	Date.Year -= 1000;
	return Date;
}
int main()
{
	stDate Date;
	Date = ReadFullDate();

	Date = DecreaseDateByOneDAy(Date);
	cout << "\n01-Substracting One Day Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByXDay(10, Date);
	cout << "\n01-Substracting 10 Day Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByOneWeek(Date);
	cout << "\n02-Substracting One Week Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByXWeek(10, Date);
	cout << "\n03-Substracting 10 Week Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByOneMonth(Date);
	cout << "\n04-Substracting One Month Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByXMonth(5, Date);
	cout << "\n05-Substracting 10 Month Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByOneYear(Date);
	cout << "\n06-Substracting 1 Year Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByXYear(10,Date);
	cout << "\n07-Substracting 10 Years Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByXYearFaster(10,Date);
	cout << "\n08-Substracting 10 Years Is (faster) : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByOneDecade(Date);
	cout << "\n09-Substracting 1 Decade Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByXDecade(10, Date);
	cout << "\n10-Substracting 10 Decade Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByXDecadeFaster(10, Date);
	cout << "\n11-Substracting 10 Decade Is (faster) : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByOneCentury(Date);
	cout << "\n12-Substracting 1 Century Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
	Date = DecreaseDateByOneMillennium(Date);
	cout << "\n13-Substracting 1 Millennium Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;
}