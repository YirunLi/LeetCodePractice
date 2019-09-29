/*
	Create by xiaorun on August th, 2019.
	
*/

#include <iostream>

using namespace std;

// 思路：
// 时间复杂度分析：


// ==================== Test Code ====================

int divide(int dividend, int divisor) {
	bool isPositive = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
	long long longDividend = abs(static_cast<long long>(dividend));
	long long longDivisor = abs(static_cast<long long>(divisor));

	long long result = 0;
	long long tmpResult = 1;
	while (longDividend >= longDivisor)
	{
		if (longDividend >= tmpResult*longDivisor)
		{
			longDividend -= tmpResult * longDivisor;
			result += tmpResult;
			tmpResult *= 2;
		}
		else
			tmpResult = 1;
	}
	if (result > numeric_limits<int>::max() && isPositive)
		return numeric_limits<int>::max();
	else
		return isPositive ? result : (-1 * result);
}

int main(int argc, char* argv[])
{
	int minNum = numeric_limits<int>::min();
	int dividend = 95;
	int divisor = -3;
	//int resultStandard = dividend / divisor;
	int result = divide(dividend, divisor);

    return 0;
}