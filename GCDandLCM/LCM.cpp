#include "LCM.h"

//LCM algorithm
ill LCM_Formula(ill a, ill b)
{
	return (a*b) / GCD_Euclid(a, b);
}

//returns vector of all LCMs between numbers
ill LCM(vector<ill> numbers)
{
	if (numbers.size() >= 2)
	{
		for (vector<int>::size_type i = numbers.size() - 1; i > 0; i--)
		{
			numbers[i - 1] = LCM_Formula(numbers[i], numbers[i - 1]);
			numbers.pop_back();
		}
		return numbers[0];
	}
	else
		throw "Please enter more than 1 number.\n";
}