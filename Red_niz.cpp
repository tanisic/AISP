//Autor: Tin Anišić
#include<iostream>
#include<vector>

using namespace std;

class Red {
public:
	int izlaz;
	int ulaz;
	int velicina;
	std::vector<int> podaci;
	bool zadnji_push;

	Red(int n)
	{
		izlaz = 0;
		ulaz = 1;
		velicina = n;
		podaci.resize(velicina);
		zadnji_push = false;
	}

	 void Clear()
	 {
		 ulaz = 0;
		 izlaz = 1;
		 zadnji_push = false;
	 }

	 bool Is_empty()
	 {
		 if (ulaz == izlaz  && !zadnji_push)
			 return true;
		 else return false;
	 }

	 void Push(int x)
	 {
		 if (ulaz == izlaz  && zadnji_push)
		 {
			 std::cout << "Queue overflow. Aborting..." << std::endl;
			 exit(1);
		 }
		 zadnji_push = true;
		 ulaz = ulaz + 1;
		if (ulaz > velicina)  ulaz = 1;
		 podaci[ulaz] = x;
	 }

	 int Pop()
	 {
		 if (Is_empty())
		 {
			 std::cout << "Illegal POP. Aborting..." << std::endl;
			 exit(1);
		 }
		 zadnji_push = false;
		 izlaz = izlaz + 1;
		 if (izlaz > velicina) izlaz = 1;
		 return podaci[izlaz];

	 }
	 
	
};

int main()
{
	Red red(20);
	red.Push(29);
	red.Push(20);
	red.Push(14);
	red.Push(22);
	
	std::cout << red.Pop() << std::endl;
	std::cout << red.Pop() << std::endl;
	std::cout << red.Pop() << std::endl;



	return 0;

}