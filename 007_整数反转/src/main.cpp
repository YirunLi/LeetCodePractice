/*
	Create by xiaorun on August th, 2019.
	
*/

#include <iostream>

using namespace std;

// Ë¼Â·£º

int reverse(int x) {
	long long resultNum = 0;
	bool smallThanZero = x < 0 ? true : false;

	long long x2 = x;
	x2 = std::abs(x2);
	while (x2)
	{
		resultNum = resultNum * 10 + x2 % 10;
		x2 = x2 / 10;
	}

	if (smallThanZero)
	{
		resultNum *= -1;
		if (resultNum < numeric_limits<int>::min())
			return 0;
	}
	else
	{
		if (resultNum > numeric_limits<int>::max())
			return 0;
	}

	return (int)resultNum;
}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	int result1 = reverse(123);
	int result2 = reverse(-321);
	int result3 = reverse(numeric_limits<int>::max());
	int result4 = reverse(numeric_limits<int>::min());

    return 0;
}