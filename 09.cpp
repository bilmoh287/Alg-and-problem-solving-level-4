#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int takenumber()
{
	int n = 0;
	cout << "please enter a Year? ";
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

int DayOrder(int yr, int month, int day)
{
	int a = (14 - month) / 12;
	int y = yr - a;
	int m = month + (12 * a) - 2;

	int d = 0;
	return  (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string Dayname(int d)
{
	string days[7] = { "Sun", "Mon", "Tue", "Wend", "Thur", "Fri", "Sat" };
	return days[d];
}
string MonthName(int m)
{
	string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
						  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return months[m - 1];
}
void PrintMonthCalander(int Month, int Year)
{
	int NumberOfDays;

	// Index of the day from 0 to 6
	int current = DayOrder(Year, Month, 1);
	NumberOfDays = NumberDays(Year, Month);

	// Print the current month name
	printf("\n ________________%s_______________\n\n", MonthName(Month).c_str());

	// Print the columns (weekdays)
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	// Print appropriate spaces before the first day
	int i;
	for (i = 0; i < current; i++)
		printf("     ");  // Five spaces for alignment

	// Print all days of the month
	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j); // Print the day with width 5
		if (++i == 7) // New row after Saturday
		{
			i = 0;
			printf("\n");
		}
	}

	// Print closing line
	printf("\n __________________________________\n");
}
void PrintYearCalander(int yr)
{
	printf(" __________________________________\n");
	printf("\n         Calander :- %d", yr);
	printf("\n __________________________________\n");

	for (int i = 1; i <= 12; i++)
	{
		PrintMonthCalander(i, yr);
	}
}
int main()
{
	int y = 0, m = 0;

	int yr = takenumber();
	PrintYearCalander(yr);






	return 0;
}