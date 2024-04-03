#include "numbertheory.hpp"

using namespace::tmath::cryptography;

NumberTheory::NumberTheory(int number1, int number2): m_number1(number1), m_number2(number2)
{
}

NumberTheory::~NumberTheory()
{
}

void NumberTheory::set_number1(int number_1)
{
	this->m_number1 = number_1;
}

int NumberTheory::get_number1() const
{
	return m_number1;
}

void NumberTheory::set_number2(int number_2)
{
	this->m_number2 = number_2;
}

int NumberTheory::get_number2() const
{
	return m_number2;
}

bool NumberTheory::is_prime(int number) const
{
	if (number <= 1)
		return false;

	int squareRoot = sqrt(number);

	for (int i = 2; i <= (squareRoot + 1); i++)
		if (number % i == 0)
		{
			return false;
		}

	return true;
}

bool NumberTheory::are_bothNumbers_prime() const
{
	return is_prime(m_number1) && is_prime(m_number2);
}

bool NumberTheory::is_divisible() const
{
	if(m_number1 % m_number2 == 0)
		return true;

	return false;
}


bool NumberTheory::is_divisible(const int& number1, const int& number2) const
{
	if (number1 % number2 == 0)
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

void NumberTheory::divisor_calcul(int a, int b)
{
	if (a == 0 || b == 0)
		return;

	if (b % a == 0)
		return;

	if (a == b)
		return;

	m_divisor_list.push_back({ {"dividend", b}, {"divisor", a},{"quotient", (int)b / a},  {"rest", b % a} });
	divisor_calcul(b % a, a);
}

int NumberTheory::gcd_calcule(vector<vector<int>> finalList)
{
	int result = 1;

	for (unsigned int i = 0; i < finalList.size(); i++)
	{
		for (unsigned int j = 0; j < finalList[i].size(); j++)
		{
			result *= finalList[i][j];
		}
	}

	return result;
}

void NumberTheory::compar_lists(const vector<vector<int>>& divisorList_1, const vector<vector<int>>& divisorList_2,
	vector<vector<int>>& finaLlist) const
{
	// compare the two list of divisors
	for (unsigned int i = 0; i < divisorList_1.size(); i++)
	{
		for (unsigned int j = 0; j < divisorList_2.size(); j++)
		{
			if (divisorList_1[i][0] == divisorList_2[j][0])
			{
				if (divisorList_1[i].size() < divisorList_2[j].size())
				{
					finaLlist.push_back(divisorList_1[i]);
				}
				else
				{
					finaLlist.push_back(divisorList_2[j]);
				}
			}
		}
	}
}

GCD_RESULT NumberTheory::great_common_Divisor()
{
    // Initialize lists to store divisors
    const vector<vector<int>> divisor_list1 = divisor_list(m_number1);
    const vector<vector<int>> divisor_list2 = divisor_list(m_number2);
    vector<vector<int>> finalList;

    // Compare the two lists of divisors to find common divisors
	compar_lists(divisor_list1, divisor_list2, finalList);

    // Calculate the GCD by finding the product of common divisors
	m_gcd = gcd_calcule(finalList);

	return { m_gcd, finalList };
}

void NumberTheory::great_common_divisor(int& number_1, int& number_2, GCD_RESULT& gcd_result)
{
    // Initialize lists to store divisors
	vector<vector<int>> divisor_list1 = divisor_list(number_1);
	vector<vector<int>> divisor_list2 = divisor_list(number_2);
	vector<vector<int>> finalList;

    // Compare the two lists of divisors
    compar_lists(divisor_list1, divisor_list2, finalList);

    // Calculate the GCD and update the result struct
    gcd_result.great_common_divisor = gcd_calcule(finalList);
    gcd_result.divisor_list = finalList;
}

int NumberTheory::great_common_divisor(int& number_1, int& number_2)
{
	// Initialize lists to store divisors
	const vector<vector<int>> divisorList1 = divisor_list(number_1);
	const vector<vector<int>> divisorList2 = divisor_list(number_2);
	vector<vector<int>> finalList;

	// Compare the two lists of divisors
	compar_lists(divisorList1, divisorList2, finalList);

	// Calculate the GCD and update the result struct
	return  gcd_calcule(finalList);
	
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

LEMMA3_RESULT NumberTheory::lemma3()
{
	divisor_calcul(m_number1, m_number2);

	int x = 0;
	int y = 1;

	int index = m_divisor_list.size() - 1;
	while (true)
	{
		int quotient = m_divisor_list[index]["quotient"];

		int temp_x = x;
		x = y;
		y = temp_x - quotient * y;


		if (index == 0)
		{
			temp_x = x;
			x = y;
			y = temp_x;
			break;
		}
		index--;
	}

	return { x, y, m_gcd };
}

LEMMA4_RESULT NumberTheory::lemma4()
{
	int product = m_number1 * m_number2;
	int n = 2;

	while(n <= SOME_UPPER_LIMIT)
	{
		if(great_common_divisor(m_number1, n) == 1 && great_common_divisor(m_number2, n ) == 1 && great_common_divisor(product, n) == 1)
		{
			return LEMMA4_RESULT{ true, n };
		}

		n++;
	}

	return LEMMA4_RESULT{ false, 0 };
}

bool NumberTheory::lemma5()
{
	int num1 = m_number1 / m_gcd;
	int num2 = m_number2 / m_gcd;
	const int gcd_result = great_common_divisor(num1, num2);

	if(gcd_result == 1)
		return true;

	return false;
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

std::string NumberTheory::convert_decimal_to_Binary(unsigned int number, Bits bit)
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

unsigned int NumberTheory::convert_bitwise_not(unsigned int number, Bits bit)
{
	if (number >= 0 && number <= 32)
		return ~number & bit;

	return 0;
}