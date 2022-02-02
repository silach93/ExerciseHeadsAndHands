#include <algorithm>
#include <iostream>
#include <time.h>
#include <vector>

int main()
{
	std::srand(time(NULL));

	size_t N;
	std::cin >> N;
	std::vector <std::vector <int> > A(N);

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			while (A[i].size() == A[j].size() || A[i].size() == 0)
			{
				A[i].resize(std::rand() % 100 + 1);
			}
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < A[i].size(); j++)
		{
			A[i][j] = std::rand() % 50 + 1;
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		if (i % 2 == 0) std::sort(A[i].begin(), A[i].end());
		else std::sort(A[i].begin(), A[i].end(), [](int a, int b){return a > b;});
	}

	for (size_t i = 0; i < N; i++)
	{
		std::cout << "Massive №" << i <<"\n";
		for (size_t j = 0; j < A[i].size(); j++)
		{
			std::cout << A[i][j] << "\t";
		}
		std::cout << "\n";
	}
}
