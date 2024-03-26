#include "numbertheory.hpp"


using namespace::tCryptography;

NumberTheory::NumberTheory(int number1, int number2): m_number1(number1), m_number2(number2)
{
}

NumberTheory::~NumberTheory()
{
}

void NumberTheory::setNumber1(int number_1)
{
	this->m_number1 = number_1;
}

int NumberTheory::getNumber1() const
{
	return m_number1;
}

void NumberTheory::setNumber2(int number_2)
{
	this->m_number2 = number_2;
}

int NumberTheory::getNumber2() const
{
	return m_number2;
}

bool NumberTheory::isPrime(int number) const
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

bool NumberTheory::areBothNumbersPrime() const
{
	return isPrime(m_number1) && isPrime(m_number2);
}

bool NumberTheory::isDivisible(int &number1, int &number2) const
{
	if(number1 % number2 == 0)
		return true;

	return false;
}

vector<vector<int>> NumberTheory::divisor_list(int number)
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

int NumberTheory::divisorsCalcul(vector<vector<int>> divisor_list)
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


void NumberTheory::compar_lists(vector<vector<int>>& divisor_list_1, vector<vector<int>>& divisor_list_2,
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

void NumberTheory::greatCommonDivisor(GCD_RESULT& gcd_result)
{
    // Initialize lists to store divisors
    vector<vector<int>> divisorList1;
    vector<vector<int>> divisorList2;
    vector<vector<int>> divisorList3;

    // Get the list of divisors for each number
    divisorList1 = divisor_list(m_number1);
    divisorList2 = divisor_list(m_number2);

    // Compare the two lists of divisors to find common divisors
    compar_lists(divisorList1, divisorList2, divisorList3);

    // Calculate the GCD by finding the product of common divisors
    gcd_result.greatCommonDivisor = divisorsCalcul(divisorList3);
    gcd_result.divisor_list = divisorList3;
}

void NumberTheory::greatCommonDivisor(int& number_1, int& number_2, GCD_RESULT& gcd_result)
{
    // Initialize lists to store divisors
    vector<vector<int>> divisorList1;
    vector<vector<int>> divisorList2;
    vector<vector<int>> divisorList3;

    // Get the list of divisors for each number
    divisorList1 = divisor_list(number_1);
    divisorList2 = divisor_list(number_2);

    // Compare the two lists of divisors
    compar_lists(divisorList1, divisorList2, divisorList3);

    // Calculate the GCD and update the result struct
    gcd_result.greatCommonDivisor = divisorsCalcul(divisorList3);
    gcd_result.divisor_list = divisorList3;
}

bool NumberTheory::lemma1()
{
	if (std::is_integral_v<decltype(m_number1)> && std::is_integral_v<decltype(m_number2)>)
	{
		// Check closure properties here
		if (std::is_integral_v<decltype(m_number1 + m_number2)> &&
			std::is_integral_v<decltype(m_number1 - m_number2)> &&
			std::is_integral_v<decltype(m_number1 * m_number2)>)
		{
			std::cout << "Lemma 1: Integers" << std::endl;
			return true;
		}
	}

	return false;
}

LEMMA4_RESULT NumberTheory::lemma4()
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
					return LEMMA4_RESULT{ true, i };
				}
			}
		}

		if (i >= 100)
			return LEMMA4_RESULT{ false, 0 };

		i++;
	}
}

LEMMA5_RESULT NumberTheory::lemma5(LEMMA5_RESULT& result)
{
	return LEMMA5_RESULT{};
}

//std::string NumberTheory::convertDecimalToBinary(unsigned int number, Bits bit)
//{
//	std::string binary;
//
//	while (number > 0) {
//		binary = std::to_string(number % 2) + binary;  // Append remainder as binary digit
//		number /= 2;                                   // Divide by 2 for next iteration
//	}
//
//	// Handle zero case separately
//	if (binary.empty()) {
//		binary = "0";
//	}
//
//	return binary;
//}

std::string NumberTheory::convertDecimalToBinary(unsigned int number, Bits bit)
{
	std::string strBinary;

	if (number == 0)
		return 0; // Base case: Decimal 0 is binary 0

	unsigned int binaryResult = 0;
	unsigned int powerOfTwo = 1; // Represents 2^0 initially

	while (number > 0) {
		// Extract the rightmost bit of the decimal number
		unsigned int bitValue = number % 2;
		cout << "bit value: " << bitValue << endl;
		strBinary += std::to_string(bitValue);

		// Set the corresponding bit in the binary result
		binaryResult += bitValue * powerOfTwo;
		cout << "binary result: " << binaryResult << endl;

		// Move to the next bit
		powerOfTwo *= 2;
		number /= 2;
	}

	// Apply the bit mask (e.g., BITS_8) if needed
	binaryResult &= bit;


	//strBinary = std::to_string(binaryResult);
	return strBinary;
}

unsigned int NumberTheory::convertBitwiseNot(unsigned int number, Bits bit)
{
	if (number >= 0 && number <= 32)
		return ~number & bit;

	return 0;
}




