#include "Graf.h"
#include <iostream>
#include <ctime>

using namespace std;

void TestGraph(int n, int multipl);

int main(int argc, char* argv[])
{
	/*Graf g(9,14);

	/*for (int i = 0; i < 9; i++)
		g.GenNewPint();

	g.Conect(0, 1, 4);
	g.Conect(0, 7, 8);
	g.Conect(1, 2, 8);
	g.Conect(1, 7, 11);
	g.Conect(2, 3, 7);
	g.Conect(2, 8, 2);
	g.Conect(2, 5, 4);
	g.Conect(3, 4, 9);
	g.Conect(3, 5, 14);
	g.Conect(4, 5, 10);
	g.Conect(5, 6, 2);
	g.Conect(6, 7, 1);
	g.Conect(6, 8, 6);
	g.Conect(7, 8, 7);
	
	cout << "Edges of MST are \n";
	//int mst_wt = g.Kruskal();
	int mst_wt = g.Boruvka();
	cout << "\nWeight of MST is " << mst_wt;*/
	int base = 10;
	int multipl[] = {1,2,5,10};




	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if(!(i == 0 && j == 3))
			TestGraph(base, multipl[j]);
		}

		base *= 10;
	}
}

void TestGraph(int n, int multipl)
{
	Graf g(n, n*multipl);

	if (n == 100000)
	{
		cout << "debug\n";
	}

	srand(13);
	for (int i = 0; i < n; i++)
	{
		g.GenNewPint();
	}
		
	//int* poz = new int[n,n*multipl];
	int** poz = (int**)calloc(sizeof(int*), n);

	for (int i = 0; i < n; i++)
	{
		poz[i] = (int*)calloc(sizeof(int), n);
	}


	for (int i = 0; i < n-1; i++)
	{
		g.Conect(i, i + 1, rand()%100);
		if (n == 100000)
		{
			cout << i << endl;
		}
	}
	g.Conect(n - 1, 0,rand()%100);

	for (int i = n; i < n * multipl; i++)
	{
		int a = 0, b = 0;
		while (1)
		{
			a = rand() % n;
			b = rand() % n;

			if (a != b)
			{
				if (poz[a][b] == 0)
				{
					poz[a][b] = 1;
					poz[b][a] = 1;
					g.Conect(a, b, rand() % 100);
					break;
				}
			}
		}
		
	}
	cout << "Za " << n << " cvora  a broj potega " << n * multipl << endl;
	/*if (n < 100)
	cout << "Potezi u MST-u za Kruskala su: \n";

	clock_t begin = clock();
	int mst_wt = g.Kruskal();
	clock_t end = clock();


	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "\nVreme Proslo za Kruskala je: " << elapsed_secs << endl;
	cout << "\nTezina  MST-a je: " << mst_wt;
	
	cout << endl << endl;*/


	/*if (n < 100)
		cout << "Potezi u MST-u za Borukova su: \n";

	clock_t begin = clock();
	int mst_wt = g.Boruvka();
	clock_t end = clock();

	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "\nVreme Proslo za Borukova je: " << elapsed_secs << endl;
	cout << "\nTezina  MST-a je: " << mst_wt << endl;*/


}