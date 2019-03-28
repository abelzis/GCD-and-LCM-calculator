#include "GCD.h"

//GCD Euclid algorithm
ill GCD_Euclid(ill a, ill b)
{
	if (a == b)
		return a;
	if (a > b)
	{
		while (a > 0)	//while not 0
		{
			a -= (a / b)*b;
			if (a != 0)
				std::swap(a, b);
		}
		return b;	//return last value before number hits 0
	}
	if (a < b)
	{
		while (b > 0)
		{
			b -= (b / a)*a;
			if (b != 0)
				std::swap(b, a);
		}
		return a;
	}
}

//calculate the GCD of all numbers from vector
ill GCD(vector<ill> numbers)
{
	if (numbers.size() >= 2)
	{
		for (vector<int>::size_type i = numbers.size() - 1; i > 0; i--)	//for each number
		{
			numbers[i - 1] = GCD_Euclid(numbers[i], numbers[i - 1]);	//begin from end
			numbers.pop_back();
		}
		return numbers[0];
	}
	else
		throw "Please enter more than 1 number.\n";
}