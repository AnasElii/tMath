#include <iostream>
#include <string>
#include <cmath>
#include <vector>


using namespace std;

struct GCD_RESULT{
    int greate_common_divisor;
    vector<vector<int>> divisor_list;
};

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

vector<vector<int>> divisor_list(int number)
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

//bool lemma_4(int& a, int& b, int& i){
//	
//}

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

void compar_lists(vector<vector<int>>& divisor_list_1, vector<vector<int>>& divisor_list_2, vector<vector<int>>& divisor_list_3){
	
	
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
}

void greate_common_divisor(int number_1, int number_2, GCD_RESULT& gcd_result){
    
    vector<vector<int>> divisor_list_1;
    vector<vector<int>> divisor_list_2;
    vector<vector<int>> divisor_list_3;
    
    

        // get the list of divisors for each number
        divisor_list_1 = divisor_list(number_1);
        divisor_list_2 = divisor_list(number_2);

        // get the GCD
        // compar the two list of divisors
        compar_lists(divisor_list_1, divisor_list_2, divisor_list_3);
            
        gcd_result.greate_common_divisor = divisors_calcul(divisor_list_3);
        gcd_result.divisor_list = divisor_list_3;
        
    
}

int main()
{
	int number_1 = 49;
	int number_2 = 216;
	
    // check if the number is prime
    if(!is_prime(number_1) && !is_prime(number_2))
    {
    
        GCD_RESULT gcd_result;
        
        // get the greate common divisor
        greate_common_divisor(number_1, number_2, gcd_result);
        
        // display the result
        display(gcd_result.divisor_list, gcd_result.greate_common_divisor);

		if(gcd_result.greate_common_divisor == 1)
		{
			cout << "The numbers: " << number_1 << " and " << number_2 << " are coprime" << endl;

			int i = 2;

			while(true)
			{
				GCD_RESULT result;
				greate_common_divisor(number_1, i, result);
				if(result.greate_common_divisor == 1)
				{
					cout << "The numbers: " << number_1 << " and " << i << " are coprime" << endl;

					GCD_RESULT result2;
					greate_common_divisor(number_2, i, result2);

					if( result2.greate_common_divisor == 1)
					{
						cout << "The numbers: " << number_2 << " and " << i << " are coprime" << endl;

						GCD_RESULT result3;
						greate_common_divisor(number_1 * number_2, i, result2);

						if (result2.greate_common_divisor == 1)
						{
							cout << "The numbers: " << (number_1 * number_2) << " and " << i << " are coprime" << endl;

							break;
						}
					}

					
				}
				i++;
			}
		}
		else
		{
			cout << "The numbers: " << number_1 << " and " << number_2 << " are not coprime" << endl;	
		}

    } else
    {
        cout << "The number: " << number_1 << " or " << number_2 << " is a prime";
    }
        
	return 0;
}
