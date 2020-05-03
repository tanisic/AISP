#include <iostream>
#include<time.h>
#include<vector>

class Stog {
public:
	int Sp;
	int N;
	std::vector<int> niz;

	Stog(int n) { //n predstavlja velicinu stoga
		Sp = 0;
		N = n;
		niz.resize(n);
	}
	int IsEmpty()
	{
		if (Sp == 0)
			return 1;
		else return 0;
	}
	void Clear()
	{
		Sp = 0;
	}
	void Push(int x)
	{
		if (Sp == N)
		{
			std::cout << "Stack Overflow" << std::endl;
			exit(-1);
		}
		Sp++;
		niz[Sp] = x;
	}
	int Pop()
	{
		if (IsEmpty())
		{
			std::cout << "Stog je prazan" << std::endl;
			exit(-1);
		}
		int x = niz[Sp];
		Sp--;
		return x;
	}
	
};