#ifndef NUMBERTHEORY_HPP
#define NUMBERTHEORY_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


namespace tCryptography
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

	enum Bits {
		BITS_4 = 0xF,
		BITS_8 = 0xFF,
		BITS_16 = 0xFFFF,
		BITS_32 = 0xFFFFFFFF
	};

	class NumberTheory
	{
	public:
		NumberTheory(int number1, int number2);

		~NumberTheory();

		void setNumber1(int number_1);
		int getNumber1() const;
		void setNumber2(int number_2);
		int getNumber2() const;

		bool isPrime(int number) const;

		bool areBothNumbersPrime() const;

		/**
		 * @brief Calculate the divisors of a given number and return a list of lists containing the divisors.
		 * 
		 * @param number the number for which to find the divisors
		 * @return a list of lists containing the divisors
		 */
		vector<vector<int>> divisor_list(int number);

		/**
		 * @brief Calculate the product of all the divisors in the given list of divisors.
		 * 
		 * @param divisor_list A list of divisors, where each element is a list of integers representing divisors.
		 * @return The product of all the divisors in the list.
		 */
		int divisorsCalcul(vector<vector<int>> divisor_list);

		/**
		 * @brief compare the 2 lists and return the final list
		 *
		 * @param divisor_list_1 list of dividers of the first number
		 * @param divisor_list_2 list of dividers of the second number 
		 * @param divisor_list_3 return the final list
		 */
		void compar_lists(vector<vector<int>>& divisor_list_1, vector<vector<int>>& divisor_list_2,
		                  vector<vector<int>>& divisor_list_3);
		/**
		 * \brief Calculate the greatest common divisor (GCD) of two numbers.
		 *
		 * This function calculates the GCD of two numbers by finding the common divisors of the two numbers
		 * and then computing the product of those common divisors.
		 *
		 * @param gcd_result The struct containing the GCD and the list of divisors.
		 */
		void greatCommonDivisor(GCD_RESULT& gcd_result);

		/**
		 * \brief Calculates the greatest common divisor of two numbers and provides a list of divisors.
		 *
		 * @param number_1 The first number for which to find divisors and calculate GCD.
		 * @param number_2 The second number for which to find divisors and calculate GCD.
		 * @param gcd_result Struct containing the result of GCD calculation and the list of divisors.
		 */
		void greatCommonDivisor(int& number_1, int& number_2, GCD_RESULT& gcd_result);

		/**
		 * \brief Check if the numbers satisfy lemma 1.
		 *
		 * This function checks if the numbers are integers and satisfy the closure properties under addition, subtraction, and multiplication.
		 *
		 * @return true if the numbers satisfy the closure properties, false otherwise
		 */
		bool lemma1();

		/**
		 * \brief Implementing Lemma 4 of number theory.
		 *
		 * This function finds the smallest positive integer i such that i is coprime to both m_number1 and m_number2.
		 *
		 * @return LEMMA4_RESULT A struct containing a boolean indicating if a solution was found and the value of i.
		 */
		LEMMA4_RESULT lemma4();

		LEMMA5_RESULT lemma5(LEMMA5_RESULT& result);

		/**
		 * \brief Converts the bitwise NOT of a given number based on the specified bit size.
		 *
		 * This function calculates the bitwise NOT of a given number and applies a bit mask based on the specified bit size.
		 *
		 * @param number The number to perform bitwise NOT on.
		 * @param bit The bit size to apply as a mask.
		 * @return The result of the bitwise NOT operation with the applied bit mask.
		 */
		unsigned int convertBitwiseNot(unsigned int number, Bits bit);

	private:
		int m_number1;
		int m_number2;
	};
};

#endif // NUMBERTHEORY_HPP