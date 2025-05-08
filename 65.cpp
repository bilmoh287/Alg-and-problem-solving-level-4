#include <iostream>
#include <vector>
#include <string>
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
stPeriod ReadPeriod()
{
	stPeriod Period;
	cout << "Enter Start Date." << endl;
	Period.startDate = ReadFullDate();
	cout << "\nEnter End Date\n.";
	Period.EndDate = ReadFullDate();
	return Period;
}
bool IsOverlapPeriod(stPeriod Period1, stPeriod Period2)
{
	if (CompareDates(Period2.EndDate, Period1.startDate) == -1 || CompareDates(Period2.startDate, Period1.EndDate) == 1)
		return false;
	else
		return true;
}
int CalculateOverlapDays(stPeriod Period1, stPeriod Period2)
{
	if (!IsOverlapPeriod(Period1, Period2))
		return 0;

	// Find the actual overlap start and end
	stDate OverlapStart, OverlapEnd;

	// The latest start date
	OverlapStart = (IsDate1BeforeDate2(Period1.startDate, Period2.startDate)) ? Period2.startDate : Period1.startDate;

	// The earliest end date
	OverlapEnd = (IsDate1BeforeDate2(Period1.EndDate, Period2.EndDate)) ? Period1.EndDate : Period2.EndDate;

	int counter = 0;
	while (IsDate1BeforeDate2(OverlapStart, OverlapEnd) || IsDate1EqualDate2(OverlapStart, OverlapEnd))
	{
		counter++;
		OverlapStart = IncreaseDateByOneDAy(OverlapStart);
	}
	return counter;
}

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}

stDate StringToStuctDate(string line, string delim = "/")
{
	stDate Date;
	vector<string> vclientdata;

	vclientdata = SplitString(line, delim);

	Date.Day = stoi(vclientdata[0]);
	Date.Month = stoi(vclientdata[1]);
	Date.Year = stoi(vclientdata[2]);


	return Date;
}
string DateToString(stDate Date, int format, string delim = "/")
{
	string line = "";
	switch (format)
	{
	case 1:
		line += to_string(Date.Day) + delim;
		line += to_string(Date.Month) + delim;
		line += to_string(Date.Year);
		break;
	case 2:
		line += to_string(Date.Year) + delim;
		line += to_string(Date.Day) + delim;
		line += to_string(Date.Month);
		break;
	case 3:
		line += to_string(Date.Month) + delim;
		line += to_string(Date.Day) + delim;
		line += to_string(Date.Year);
		break;
	case 4:
		line += to_string(Date.Month) + "-";
		line += to_string(Date.Day) + "-";
		line += to_string(Date.Year);
		break;
	case 5:
		line += to_string(Date.Day) + "-";
		line += to_string(Date.Month) + "-";
		line += to_string(Date.Year);
		break;
	case 6:
		cout << "\n\nDay:" << Date.Day << ", Month:" << Date.Month << ", Year:" << Date.Year;
		break;
	}

	return line;
}
string ReadStringDate()
{
	string date = "";
	cout << "Please enter Date dd/mm/yyyy? ";
	cin >> date;
	return date;
}
void PrintStructDate(stDate Date)
{
	cout << "\nDay : " << Date.Day << endl;
	cout << "Month : " << Date.Month << endl;
	cout << "Year : " << Date.Year << endl;
}
void PrintStringDate(string Date)
{
	cout << "\nYou Entered : " + Date;
}

int main()
{
	string Date = ReadStringDate();
	stDate Date2 = StringToStuctDate(Date);

	cout << "\n" << DateToString(Date2, 1);
	cout << "\n\n" << DateToString(Date2, 2);
	cout << "\n\n" << DateToString(Date2, 3);
	cout << "\n\n" << DateToString(Date2, 4);
	cout << "\n\n" << DateToString(Date2, 5);
	cout << "\n\n" << DateToString(Date2, 6);

	system("pause>0");
	return 0;
}