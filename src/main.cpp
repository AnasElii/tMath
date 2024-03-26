#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include "numbertheory.hpp"

using namespace std;
using namespace tCryptography;

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
	NumberTheory* numberTheory = new NumberTheory(48, 72);

	// check if the number is prime
	if (!numberTheory->areBothNumbersPrime())
	{
		GCD_RESULT gcdResult;
		LEMMA4_RESULT lemma4Result;

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

	unsigned int num = 0;
	cout << "Bitwise NOT of number 3 in BITS_4 (unsigned): " << numberTheory->convertBitwiseNot(num, Bits::BITS_4) << endl;
	cout << "Bitwise NOT of number 3 in BITS_8 (unsigned): " << numberTheory->convertBitwiseNot(num,  Bits::BITS_8) << endl;
	cout << "Bitwise NOT of number 3 in BITS_16 (unsigned): " << numberTheory->convertBitwiseNot(num, Bits::BITS_16) << endl;
	cout << "Bitwise NOT of number 3 in BITS_32 (unsigned): " << numberTheory->convertBitwiseNot(num, Bits::BITS_32) << endl;

	cout << "Binary: " << numberTheory->convertDecimalToBinary(14, Bits::BITS_8) << endl;

	//numberTheory->lemma1();

	delete numberTheory;

	unsigned int num2 = -1;
	cout << "Unsigned Number 0: " << num2 << endl;

	return 0;
}
