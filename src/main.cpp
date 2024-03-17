#include <iostream>
#include <string>
#include <cmath>
#include <vector>


using namespace std;


namespace noIdea
{
	struct GCD_RESULT
	{
		int greatCommonDivisor;
		vector<vector<int>> divisor_list;
	};

	struct LEMMA2_RESULT
	{

	};

	struct LEMMA3_RESULT
	{

	};

	struct LEMMA4_RESULT
	{
		bool isCoprime;
		int nCoprime;
	};

	struct LEMMA5_RESULT
	{
		
	};

	enum bits {
		BITS_4 = 0xF,
		BITS_8 = 0xFF,
		BITS_16 = 0xFFFF,
		BITS_32 = 0xFFFFFFFF
	};

	class NumberTheory
	{
	public:
		NumberTheory(int number1, int number2): m_number1(number1), m_number2(number2)
		{
		}

		~NumberTheory()
		{
		}

		void setNumber1(int number_1) { this->m_number1 = number_1; }
		int getNumber1() const { return m_number1; }
		void setNumber2(int number_2) { this->m_number2 = number_2; }
		int getNumber2() const { return m_number2; }

		bool isPrime(int number) const
		{
			if (number <= 1)
				return false;

			int squareRoot = pow(number, 0.5);

			for (int i = 2; i <= (squareRoot + 1); i++)
				if (number % i == 0)
				{
					return false;
				}

			return true;
		}

		bool areBothNumbersPrime() const
		{
			return isPrime(m_number1) && isPrime(m_number2);
		}

		/**
		 * Calculate the divisors of a given number and return a list of lists containing the divisors.
		 * 
		 * @param number the number for which to find the divisors
		 * @return a list of lists containing the divisors
		 */
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

				if (!divisors.empty())
				{
					divisorList.push_back(divisors);
					divisors.clear();
				}

				i++;

				if (number == 1)
				{
					return divisorList;
				}
			}
		}

		/**
		 * Calculate the product of all the divisors in the given list of divisors.
		 * 
		 * @param divisor_list A list of divisors, where each element is a list of integers representing divisors.
		 * @return The product of all the divisors in the list.
		 */
		int divisorsCalcul(vector<vector<int>> divisor_list)
		{
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


		void compar_lists(vector<vector<int>>& divisor_list_1, vector<vector<int>>& divisor_list_2,
		                  vector<vector<int>>& divisor_list_3)
		{
			// compar the two list of divisors
			for (unsigned int i = 0; i < divisor_list_1.size(); i++)
			{
				for (unsigned int j = 0; j < divisor_list_2.size(); j++)
				{
					if (divisor_list_1[i][0] == divisor_list_2[j][0])
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

		void greatCommonDivisor(GCD_RESULT& gcd_result)
		{
			vector<vector<int>> divisorList1;
			vector<vector<int>> divisorList2;
			vector<vector<int>> divisorList3;


			// get the list of divisors for each number
			divisorList1 = divisor_list(m_number1);
			divisorList2 = divisor_list(m_number2);

			// get the GCD
			// compare the two list of divisors
			compar_lists(divisorList1, divisorList2, divisorList3);

			gcd_result.greatCommonDivisor = divisorsCalcul(divisorList3);
			gcd_result.divisor_list = divisorList3;
		}

		void greatCommonDivisor(int& number_1, int& number_2, GCD_RESULT& gcd_result)
		{
			vector<vector<int>> divisorList1;
			vector<vector<int>> divisorList2;
			vector<vector<int>> divisorList3;


			// get the list of divisors for each number
			divisorList1 = divisor_list(number_1);
			divisorList2 = divisor_list(number_2);

			// get the GCD
			// compar the two list of divisors
			compar_lists(divisorList1, divisorList2, divisorList3);

			gcd_result.greatCommonDivisor = divisorsCalcul(divisorList3);
			gcd_result.divisor_list = divisorList3;
		}

		bool lemma1()
		{
			 if (std::is_integral_v<decltype(m_number1)> && std::is_integral_v<decltype(m_number2)>)
			    {
			        // Check closure properties here
			        if (std::is_integral_v<decltype(m_number1 + m_number2)> &&
			            std::is_integral_v<decltype(m_number1 - m_number2)> &&
			            std::is_integral_v<decltype(m_number1 * m_number2)> && 
						std::is_integral_v<decltype(m_number1 / m_number2)>)
			        {
			            std::cout << "Lemma 1: Integers" << std::endl;
			            return true;
			        }
			    }

			return false;
		}

		LEMMA4_RESULT lemma4()
		{
			int i = 2;

			while (true)
			{
				GCD_RESULT result;
				greatCommonDivisor(m_number1, i, result);
				if (result.greatCommonDivisor == 1)
				{
					GCD_RESULT result2;
					greatCommonDivisor(m_number2, i, result2);

					if (result2.greatCommonDivisor == 1)
					{
						GCD_RESULT result3;
						int number = m_number1 * m_number2;
						greatCommonDivisor(number, i, result2);

						if (result2.greatCommonDivisor == 1)
						{
							return LEMMA4_RESULT{true, i};
						}
					}
				}

				if( i >= 100)
					return LEMMA4_RESULT{false, 0};

				i++;
			}

		}

		LEMMA5_RESULT lemma5()
		{
			
		}

		unsigned int convertBitwiseNot(unsigned int number, bits bit) {
			if (number >= 0 && number <= 32)
				return ~number & bit;

			return 0;
		}

	private:
		int m_number1;
		int m_number2;
	};
};


void display(vector<vector<int>>& divisorList, int& result)
{
	cout << "Divisors: ";

	for (unsigned int i = 0; i < divisorList.size(); i++)
	{
		for (unsigned int j = 0; j < divisorList[i].size(); j++)
		{
			cout << divisorList[i][j];
			if (!i == (divisorList.size() - 1))
				cout << " * ";
		}
	}
	cout << " = " << result << endl;
}

int main()
{
	noIdea::NumberTheory* numberTheory = new noIdea::NumberTheory(49, 216);

	// check if the number is prime
	if (!numberTheory->areBothNumbersPrime())
	{
		noIdea::GCD_RESULT gcdResult;
		noIdea::LEMMA4_RESULT lemma4Result;

		// get the greate common divisor
		numberTheory->greatCommonDivisor(gcdResult);

		// display the result
		display(gcdResult.divisor_list, gcdResult.greatCommonDivisor);

		if (gcdResult.greatCommonDivisor == 1)
		{
			cout << "the numbers: " << numberTheory->getNumber1() << " and " << numberTheory->getNumber2() << " are coprime" << endl;

			lemma4Result = numberTheory->lemma4();
			cout << "Lemma 4: The value of N number is: " << lemma4Result.nCoprime << endl;

		}
		else
		{
			cout << "the numbers: " << numberTheory->getNumber1() << " and " << numberTheory->getNumber2() << " are not coprime" << endl;
		}
	}
	else
	{
		cout << "Hello Mother!" << endl;
		cout << "The number: " << numberTheory->getNumber1() << " or " << numberTheory->getNumber2() << " is a prime";
	}

	unsigned int num = 3;
	cout << "Bitwise NOT of number 3 in BITS_4 (unsigned): " << numberTheory->convertBitwiseNot(num, noIdea::bits::BITS_4) << endl;

	cout << "Bitwise NOT of number 3 in BITS_8 (unsigned): " << numberTheory->convertBitwiseNot(num, noIdea::bits::BITS_8) << endl;
	cout << "Bitwise NOT of number 3 in BITS_16 (unsigned): " << numberTheory->convertBitwiseNot(num, noIdea::bits::BITS_16) << endl;
	cout << "Bitwise NOT of number 3 in BITS_32 (unsigned): " << numberTheory->convertBitwiseNot(num, noIdea::bits::BITS_32) << endl;

	numberTheory->lemma1();

	delete numberTheory;

	return 0;
}
