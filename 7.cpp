#include <iostream>
#include <cmath>
using namespace std;
int takenumber()
{
	int n = 0;
	cout << "please enter a Year? ";
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
int DayOrder(int yr, int month, int day)
{
	int a = (14 - month) / 12;
	int y = yr - a;
	int m = month + (12 * a) - 2;

	int d = 0;
	return  (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12) ) % 7;
}
string Dayname(int d)
{
	string days[7] = { "Sun", "Mon", "Tue", "Wend", "Thur", "Fri", "Sat" };
	return days[d];
}
int main()
{
	int y = 0, m = 0, a = 0;

	int yr = takenumber();
	int mon = takemonth();
	int day = takeday();

	cout << "\nDate      : " << day << "/" << mon << "/" << yr << endl;
	cout << "Day Order : " << DayOrder(yr, mon, day) << endl;
	cout << "Day Name  : " << Dayname(DayOrder(yr, mon, day));

	return 0;
}