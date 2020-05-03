#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct OE_ {
	int x;
	struct OE_* sljedeci;
};
typedef struct OE_ OE;


int* generiraj_niz(int n)
{
	time_t t1, t2;
	t1 = clock();
	int* V;
	V = (int*)malloc(n * sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		V[i] = rand() % 100;
	}
	t2 = clock();
	printf("Vrijeme trajanja generiranja niza je %d ms\n", t2 - t1);
	return V;	
}

OE* kreiraj_listu(int* V,int n)
{
	time_t t1, t2;
	t1 = clock();
	OE* p = NULL;
	OE* glava = NULL;
	for (int k = 0; k < n; k++)
	{
		if (k == 0)
		{
			glava = (OE*)malloc(sizeof(OE));
			p = glava;
		}
		else
		{
			p->sljedeci= (OE*)malloc(sizeof(OE));
			p = p->sljedeci;
		}
		p->x = V[k];
	}
	p->sljedeci = NULL;
	t2 = clock();
	printf("Vrijeme trajanja generiranja povezanog popisa je %d ms\n", t2 - t1);
	return(glava);

}
void sekv_niz(int* V, int n,int trazeni)
{
	time_t t1, t2;
	t1 = clock();
	for (int i = 0; i < n; i++)
	{
		if (V[i] == trazeni) {
			t2 = clock();
			printf("Pronaden je broj na elementu %d i pretrazivanje je trajalo %d ms\n", i,t2-t1);
			break;
		}
		
	}
	t2 = clock();
	printf("Trazeni broj nije pronaden u vremenu od %d ms\n",t2-t1);
}

void sekv_lista(OE* glava, int trazeni)
{
	time_t t1, t2;
	OE* p=glava;
	t1 = clock();
	while (p != NULL)
	{
		if (p->x == trazeni)
		{
			t2 = clock();
			printf("Trazeni broj je pronaden u vremenu od %d ms\n",t2-t1);
			break;
		}
		p = p->sljedeci;
	}
	t2 = clock();
	printf("Trazeni broj nije pronaden u vremenu od %d ms\n",t2-t1);

}
void ocisti_listu(OE* glava)
{
	OE* p = glava;
	OE* brisanje = NULL;
	while (p!= NULL)
	{
		brisanje = p;
		p = p->sljedeci;
		free(brisanje);
	}
	
}

int main()
{
	int n = 10000000;
	int *V = generiraj_niz(n);
	OE* glava = kreiraj_listu(V,n);
	sekv_niz(V, n, 101);
	sekv_lista(glava, 101);
	free(V);
	ocisti_listu(glava);
	
	return 0;
}