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
	cout << " = " << result << "\n";
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
			cout << "the numbers: " << number_theory->getNumber1() << " and " << number_theory->getNumber2() << " are coprime\n";

			const LEMMA4_RESULT lemma4Result = number_theory->lemma4();
			const LEMMA3_RESULT lemma3Result = number_theory->lemma3();

			cout << "Lemma 3: Bezout Coefficients are: x = " << lemma3Result.x << " and y = " << lemma3Result.y << "\n";
			cout << "Lemma 3: Bezout Identifier is: " << number_theory->getNumber1() << " * " << lemma3Result.x << " + " << number_theory->getNumber2() << " * " << lemma3Result.y << " = " << lemma3Result.gcd << "\n";
			cout << "Lemma 4: The value of N number is: " << lemma4Result.nCoprime << "\n";
		}
		else
		{
			cout << "the numbers: " << number_theory->getNumber1() << " and " << number_theory->getNumber2() << " are not coprime\n";
		}

		cout << "Lemma 5: The result of GCD is: " << (number_theory->lemma5() ? "true" : "false") << "\n";

	}
	else
	{
		cout << "Hello Mother!\n";
		cout << "The number: " << number_theory->getNumber1() << " or " << number_theory->getNumber2() << " is a prime\n";
	}

	/*unsigned int num = 0;
	cout << "Bitwise NOT of number 3 in BITS_4 (unsigned): " << number_theory->convertBitwiseNot(num, Bits::BITS_4) <<   "\n";
	cout << "Bitwise NOT of number 3 in BITS_8 (unsigned): " << number_theory->convertBitwiseNot(num,  Bits::BITS_8) <<  "\n";
	cout << "Bitwise NOT of number 3 in BITS_16 (unsigned): " << number_theory->convertBitwiseNot(num, Bits::BITS_16) << "\n";
	cout << "Bitwise NOT of number 3 in BITS_32 (unsigned): " << number_theory->convertBitwiseNot(num, Bits::BITS_32) << "\n";

	cout << "Binary: " << number_theory->convertDecimalToBinary(14, Bits::BITS_8) << "\n";*/

	//numberTheory->lemma1();

	delete number_theory;

	return 0;
}
