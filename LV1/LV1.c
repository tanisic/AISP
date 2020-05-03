#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void swap_(float* x, float* y)
{
	float temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void gen_arr(float V[], int n, float dg, float gg)
{
	srand((unsigned int)time(NULL));
	float gen;
	int i;
	for (i = 0; i < n; i++)
	{
		 gen = (float)rand() / RAND_MAX; //Daje broj u rasponu [0,1.0]
		V[i] = dg + gen * (gg - dg);  //Daje broj u rasponu [dg,gg]
	}
}
int sekv_pret(float V[], int n, float x)
{
	time_t t = clock();
	for (int i = 0; i < n; i++) {
		if (V[i] == x) {
			t = clock() - t;
			printf("Vrijeme trajanja sekvencijalnog pretrazivanja iznosi %f ms.\n", t);
			return i;
		}
	}
	t = clock() - t;
	printf("Vrijeme trajanja sekvencijalnog pretrazivanja iznosi %f ms.\n", t);
	return -1;
}
void sort(float V[], int n)
{
	int i, j;
	time_t t = clock();
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; i < n - i - 1; j++)
		{
			if (V[j] > V[j + 1])
				swap_(V + j, V + j + 1);
		}
	}
	t = clock() - t;
	printf("Vrijeme trajanja selection sorta iznosi %f ms.\n", t);
}
int bin_pret(float V[], int n, float x)
{
	int dg = 0;
	int gg = n-1;
	int sredina=(dg + gg) / 2;
	int i = 0;
	time_t t = clock();
	while (dg <= gg)
	{
		i++;
		
		if (V[sredina] < x){
			dg = sredina + 1;
		}
		else if (V[sredina] == x) { 
			t = clock() - t;
			printf("Vrijeme trajanja binarnog pretrazivanja iznosi %f ms.\n", t);
			return i; 
		}
		else {
			gg = sredina - 1;
			sredina = (gg + dg) / 2;

		}
		if (dg > gg) return -1;
	}
	t = clock() - t;
	printf("Vrijeme trajanja binarnog pretrazivanja iznosi %f ms.\n", t);
}
void ispisNiza(float V[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%f \n", V[i]);
	}
}

void main()
{
	int n=10000;
	float* V = NULL;
	printf("Unesite broj elemenata:\n");
	scanf("%d", &n);
	V = (float*)malloc(n * sizeof(float));
	gen_arr(V, n, 0, 100);
	
	printf("\nSEKVENCIJALNO PRETRAZIVANJE:\n");
	sekv_pret(V, n, 300);
	printf("\nSORTIRANJE:\n");
	sort(V, n);
	printf("\nBINARNO PRETRAZIVANJE\n");
	bin_pret(V, n, 120);
	

}