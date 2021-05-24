#include <iostream>
#include <math.h>
#include <string>
#include <limits>

using namespace std;

long long int LOOP_SIZE;

int factorial(int n) { return (n == 0) || (n == 1) ? 1 : n * factorial(n - 1); }

bool isFactorion(long long int num)
{
	long long int factorion = 0;
	string digits = to_string(num);

	for (int j = 0; j < digits.length(); j++)
		factorion += factorial(digits[j] - '0');

	return factorion == num;
}

int main()
{
	cout << "Options :" << endl;
	cout << "1 - Search for all factorions up to a limit" << endl;
	cout << "2 - Check if a single number is a factorion" << endl;
	int option;
	
	cin >> option;
	while (option <= 0 || option > 2 || cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Incorrect input, please try again :" << endl;
		cin >> option;
	}

	if (option == 1)
	{
		cout << "Enter number limit to search for factorions : " << endl;
		cin >> LOOP_SIZE;
		while (LOOP_SIZE <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Incorrect input, please try again :" << endl;
			cin >> LOOP_SIZE;
		}

		for (long long int i = 1; i <= LOOP_SIZE; i++)
		{
			if (isFactorion(i))
				cout << "Factorion found : " << i << endl;
		}

		cout << "Loop completed ! " << endl;
	}
	else
	{
		cout << "Enter number to check : " << endl;
		long long int num;
		cin >> num;
		while (num <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Incorrect input, please try again :" << endl;
			cin >> num;
		}

		if (isFactorion(num))
			cout << num << " is a factorion!" << endl;
		else
			cout << num << " is not a factorion." << endl;
	}

	cout << "Hit enter to exit" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}