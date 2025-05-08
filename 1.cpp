#include <iostream>
using namespace std;
int takenumber()
{
	int n = 0;
	cout << "please enter number? ";
	cin >> n;
	return n;
}
string numbertotext(int n)
{
	if (n == 0)
	{
		return " ";
	}
	if (n > 0 && n < 20)
	{
		string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eghit",
	"Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
		return arr[n];
	}
	if (n >= 20 && n <= 99)
	{
		string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
		return arr[n / 10] + " " + numbertotext(n % 10);
	}
	if (n >= 100 && n <= 199)
	{
		return "One Hundred " + numbertotext(n % 100);
	}
	if (n >= 200 && n <= 999)
	{
		return numbertotext(n/100) + " Hundreds " + numbertotext(n % 100);
	}
	if (n >= 1000 && n <= 1999)
	{
		return "One Thausand " + numbertotext(n % 1000);
	}
	if (n >= 2000 && n <= 999999)
	{
		return numbertotext(n / 1000) + " Thausands " + numbertotext(n % 1000);
	}
	if (n >= 1000000 && n <= 1999999)
	{
		return "One Million " + numbertotext(n % 1000000);
	}
	if (n >= 2000000 && n <= 999999999)
	{
		return numbertotext(n / 1000000) + " Millions " + numbertotext(n % 1000000);
	}
	if (n >= 1000000000 && n <= 1999999999)
	{
		return "One Billion " + numbertotext(n % 1000000000);
	}
	else
	{
		return numbertotext(n / 1000000000) + " Billions " + numbertotext(n % 1000000000);
	}
}
int main()
{
	int num = takenumber();
	cout << numbertotext(num);

	return 0;
}