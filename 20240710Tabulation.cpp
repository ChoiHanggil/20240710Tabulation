#include <iostream>
#include <vector>

std::vector<int> FibonacciT(int n)
{
	std::vector<int> v(n+1);
	v = { 0,1 };
	for (int i = 2; i < n +1; i++)
	{
		v.push_back(v[i - 1] + v[i - 2]);
	}
	return v;
}

// Time Complexity : O(n)
// Space Complexity : O(n)
int64_t Fibonacci_Tan(int n)
{
	std::vector<int> table(n + 1);
	table[0] = 0;
	table[1] = 1;
	for (int i = 2; i <= n ; i++)
	{
		table[i] = table[i - 1] + table[i - 2];
	}
	return table[n];
}
int64_t Fibonacci_Ta2(int n)
{
	std::vector<int> table(n + 1, 0);
	table[1] = 1;
	for (int i = 0; i <= n; i++)
	{
		if (i + 1 <= n)
		{
			table[i + 1] += table[i];
		}
		if (i + 2 <= n)
		{
			table[i + 2] += table[i];
		}
	}
	return table[n];
}

//길찾기
// Time Complexity : O(m*n)
// Space Complexity : O(m*n)
int64_t FindWays_Tab(const int m, const int n)
{
	std::vector<std::vector<int>> table(m + 1, std::vector<int>(n + 1, 0));

	table[1][1] = 1;

	for (int row = 1; row <= m; row++)
	{
		for (int col = 1; col <= n; col++)
		{
			if (row == 1 && col  == 1)
			{
				continue;
			}
			table[row][col] = table[row - 1][col] + table[row][col - 1];
		}
	}
	return table[m][n];
}

int64_t FindWays_Tab2(const int m, const int n)
{
	std::vector<std::vector<int>> table(m + 1, std::vector<int>(n + 1, 0));

	table[1][1] = 1;

	for (int row = 0; row <= m; row++)
	{
		for (int col = 0; col <= n; col++)
		{
			if (row+1 <= m)
			{
				table[row + 1][col] += table[row][col];
			}
			if (col+1 <= n)
			{
				table[row][col + 1] += table[row][col];
			}
		}
	}
	return table[m][n];
}

// m : sum, n : numbers 크기
// Time Complexity : O(m*n)
// Space Complexity : O(m)
bool CanAccum_Tab(const int sum, const std::vector<int>& numbers)
{
	std::vector<bool> table(sum + 1, false);
	table[0] = true;

	for (int i = 0; i <= sum; ++i)
	{
		if (table[i])
		{
			for (auto e : numbers)
			{
				if (i + e <= sum)
				{
					table[i + e] = table[i];
				}
			}
		}
	}
	return table[sum];
}

// m : sum, n : numbers 크기
// Time Complexity : O(m*m*n)
// Space Complexity : O(m*m)
std::shared_ptr<std::vector<int>> HowAccum_Tab( const int sum, const std::vector<int>&numbers )
{
	std::vector<std::shared_ptr<std::vector<int>>> table(sum + 1, nullptr);
	table[0] = std::make_shared<std::vector<int>>(0);
	for (int i = 0; i <= sum; i++)
	{
		if (table[i] != nullptr)
		{
			for (auto e : numbers)
			{
				if (i + e <= sum)
				{
					table[i + e] = std::make_shared<std::vector<int>>(*table[i]);
					table[i + e]->push_back(e);
				}
			}
		}
	}
	return table[sum];
}

//만들어 낼 수 있는 집합 중 최소 갯수
// Time Complexity : O(m*m*n)
// Space Complexity : O(m*m)
std::shared_ptr<std::vector<int>> OptimizeAccum_Tab(const int sum, const std::vector<int>& numbers)
{
	std::vector<std::shared_ptr<std::vector<int>>> table(sum + 1, nullptr);
	table[0] = std::make_shared<std::vector<int>>(0);

	for (int i = 0; i <= sum; i++)
	{
		if (table[i] != nullptr)
		{
			for (auto e : numbers)
			{
				if (i + e <= sum)
				{
					if (table[i+e] == nullptr || table[i]->size() + 1 < table[i + e]->size())
					{
						table[i + e] = std::make_shared<std::vector<int>>(*table[i]);
						table[i + e]->push_back(e);
					}
				}
			}
		}
	}
	return table[sum];
}

void Print(std::shared_ptr<std::vector<int>> result)
{
	std::cout << "{ ";
	if (result)
	{
		for (auto e : *result)
		{
			std::cout << e << " ";
		}
		std::cout << "} " << std::endl;
	}
	else
	{
		std::cout << "Nullptr" << std::endl;
	}
}

int64_t Way(int n)
{
	std::vector<int> table(n + 1);
	table[0] = 1;
	table[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		table[i] = table[i - 1] + table[i - 2];
	}
	return table[n];
}



int main()
{
	//std::cout << Fibonacci_Tan(5) << std::endl;
	//std::cout << Fibonacci_Ta2(5) << std::endl;

	//std::cout << FindWays_Tab(2, 3) << std::endl;
	//std::cout << FindWays_Tab2(2, 3) << std::endl;

	//std::cout << CanAccum_Tab(8,{2,3,5}) << std::endl;
	
	//Print(HowAccum_Tab(8, { 2,3,5 }));
	//Print(HowAccum_Tab(8, { 5,6 }));
	//Print(HowAccum_Tab(900, { 7,14 }));

	//Print(OptimizeAccum_Tab(8, { 2,3,5 }));
	//Print(OptimizeAccum_Tab(7, { 3,1,4,5 }));

	
}


//Tabulation
// 재귀할수있다
//	1. n+1개의 배열을 만듬
//	2. base case 채움
//	3. 앞에서부터 뒤로 채워나감
//
// 일반적인 접근
//	1. n+1개의 배열을 만듬
//	2. 배열에 기본값을 채움
//	3. 가장 작은 단위의 문제를 채움
//	4. 현재 값을 영향을 주는 다른 셀로 전파합니다.
// 
// TopDown
//	- 재귀 호출
//	- Memoization
// `- 숲을 보고 나무를 보는 방식
// 
// BottomUp
//	- Tabulation
//	- 나무를 보고 숲을 보는 방식
//