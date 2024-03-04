#include <iostream>
#include <string>
#include <cmath>
#include <vector>


using namespace std;

bool is_prime(int &number)
{
	if (number <= 1)
		return false;

	int squareRoot = pow(number, 0.5);

	for(int i = 2; i <= (squareRoot + 1); i++)
		if(number % i == 0)
		{
			return false;
		}

	return true;
}

vector<vector<int>> divisor_list(int &number)
{
	vector<vector<int>> divisorList;
	vector<int> divisors;
	unsigned int i = 2;

	while (true)
	{
		if (number % i == 0)
		{
			number /= i;
			divisors.push_back(i);
			continue;
		}
		
		if (!divisors.empty()) {
			divisorList.push_back(divisors);
			divisors.clear();
		}
		
		i++;


		if (number == 1)
			return divisorList;
	}
}

void display(vector<vector<int>> divisor_list, int result)
{

	cout << "Divisors: ";

	for(unsigned int i = 0; i < divisor_list.size(); i ++)
	{

		for(unsigned int j = 0; j < divisor_list[i].size(); j++)
		{
			cout << divisor_list[i][j];
			if (! i == (divisor_list.size() - 1) )
				cout << " * ";
		}
	}
	cout << " = " << result << endl;
}

int divisors_calcul(vector<vector<int>> divisor_list){

	int result = 1;

	for (unsigned int i = 0; i < divisor_list.size(); i++)
	{

		for (unsigned int j = 0; j < divisor_list[i].size(); j++)
		{
			result *= divisor_list[i][j];
		}
	}

	return result;
	
}

int main()
{
	int number_1 = 49 * 2;
	int number_2 = 216 * 3;
	
	vector<vector<int>> divisor_list_1;
	vector<vector<int>> divisor_list_2;
	vector<vector<int>> divisor_list_3;

	// check if the number is prime
	if(!is_prime(number_1) && !is_prime(number_2))
	{

		// get the list of divisors for each number
		divisor_list_1 = divisor_list(number_1);
		divisor_list_2 = divisor_list(number_2);

		// compar the two list of divisors
		for (unsigned int i = 0; i < divisor_list_1.size(); i++)
		{
			for(unsigned int j = 0; j < divisor_list_2.size(); j++)
			{
				if(divisor_list_1[i][0] == divisor_list_2[j][0])
				{
					if (divisor_list_1[i].size() < divisor_list_2[j].size())
					{
						
						divisor_list_3.push_back(divisor_list_1[i]);
					}
					else
					{
						divisor_list_3.push_back(divisor_list_2[j]);
					}
				}
			}
		}

		// display the result
		display(divisor_list_3, divisors_calcul(divisor_list_3));
		
	} else
	{
		cout << "The number: " << number_1 << " or " << number_2 << " is a prime";
	}

	return 0;
}