#include <iostream>
#include <ctime>
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
	Date.Day = takeday();
	Date.Month = takemonth();
	Date.Year = takeyear();

	return Date;
}
stDate GetSystemDate()
{
	stDate Date;
	time_t t = time(0);
	struct tm localTime;

	#ifdef _MSC_VER
		localtime_s(&localTime, &t); // Windows (MSVC)
	#else
		localtime_r(&t, &localTime); // Linux/macOS (GCC/Clang)
	#endif

	Date.Year = localTime.tm_year + 1900;
	Date.Month = localTime.tm_mon + 1;
	Date.Day = localTime.tm_mday;

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
stDate IncreaseDateByOneDay(stDate Date)
{
	if (LastDay(Date))
	{
		if (LastMonth(Date))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}
int GetDifferenceInDate(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Date1 = IncreaseDateByOneDay(Date1);
		Days++;
	}
	return IncludeEndDay ? ++Days : Days;
}
int main()
{
	stDate Date1, Date2;
	cout << "Enter Your Date Of Birth?" << endl;
	Date1 = ReadFullDate();
	Date2 = GetSystemDate();

	cout << "\nYour Age is : " << GetDifferenceInDate(Date1, Date2, true) << " Day(s)\n";

	return 0;
}