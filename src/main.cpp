#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include "numbertheory.hpp"

using namespace std;
using namespace tCryptography;

void display(const vector<vector<int>>& divisor_list, const int& result)
{
	cout << "Divisors: ";

	for (unsigned int i = 0; i < divisor_list.size(); i++)
	{
		for (unsigned int j = 0; j < divisor_list[i].size(); j++)
		{
			cout << divisor_list[i][j];
			if (!i == (divisor_list.size() - 1))
				cout << " * ";
		}
	}
	cout << " = " << result << endl;
}

int main()
{
	//const auto number_theory = new NumberTheory(48, 72);
	const auto number_theory = new NumberTheory(49, 216);

	// check if the number is prime
	if (!number_theory->areBothNumbersPrime())
	{
		// get the great common divisor
		const GCD_RESULT gcd_result = number_theory->greatCommonDivisor();

		// display the result
		display(gcd_result.divisor_list, gcd_result.greatCommonDivisor);

		if (gcd_result.greatCommonDivisor == 1)
		{
			cout << "the numbers: " << number_theory->getNumber1() << " and " << number_theory->getNumber2() << " are coprime" << endl;

			const LEMMA4_RESULT lemma4Result = number_theory->lemma4();
			cout << "Lemma 4: The value of N number is: " << lemma4Result.nCoprime << endl;
		}
		else
		{
			cout << "the numbers: " << number_theory->getNumber1() << " and " << number_theory->getNumber2() << " are not coprime" << endl;
		}

		cout << "Lemma 5: The result of GCD is: " << (number_theory->lemma5() ? "true" : "false") << endl;

	}
	else
	{
		cout << "Hello Mother!" << endl;
		cout << "The number: " << number_theory->getNumber1() << " or " << number_theory->getNumber2() << " is a prime";
	}

	/*unsigned int num = 0;
	cout << "Bitwise NOT of number 3 in BITS_4 (unsigned): " << number_theory->convertBitwiseNot(num, Bits::BITS_4) << endl;
	cout << "Bitwise NOT of number 3 in BITS_8 (unsigned): " << number_theory->convertBitwiseNot(num,  Bits::BITS_8) << endl;
	cout << "Bitwise NOT of number 3 in BITS_16 (unsigned): " << number_theory->convertBitwiseNot(num, Bits::BITS_16) << endl;
	cout << "Bitwise NOT of number 3 in BITS_32 (unsigned): " << number_theory->convertBitwiseNot(num, Bits::BITS_32) << endl;

	cout << "Binary: " << number_theory->convertDecimalToBinary(14, Bits::BITS_8) << endl;*/

	//numberTheory->lemma1();

	delete number_theory;

	return 0;
}
