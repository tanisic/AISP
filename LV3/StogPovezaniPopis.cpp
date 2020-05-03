#include <iostream>
#include<time.h>
#include<vector>
struct oe { //osnovni element povezanog popisa
	int x;
	oe* next;
};
class StogPP {
public:
	int Sp;
	oe* head;
	oe* last;

	StogPP()
	{
		 Sp = 0;
		 head = NULL;
		 last = NULL;
	};

	int IsEmpty() {
		if (last == NULL)
		{
			return 1;
		}
		else return 0;
	}
	void Push(int x) {
		oe* novi = new oe;
		novi->x = x;
		novi->next = last;
		last = novi;
	}
	int Pop()
	{
		if (IsEmpty())
		{
			std::cout << "Stog je prazan!" <<std::endl;
			return -1;
		}
		int x = last->x;
		oe* temp = new oe;
		temp = last;
		last = last->next;
		delete temp;
		return x;
	}
	void Clear()
	{
		while (IsEmpty() == 0)
		{
			Pop();
		}
	}

};


	