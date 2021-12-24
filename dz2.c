#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

int main(void) {
	char c;
	int i, j, d;
	system("chcp 1251"); 
	system("cls");
	do {
		int m, n, t, k = 0, g[10][10], dem = 0, count = 0, har1 = 0;
		printf("\nВведите количество вершин: n= "); // количество вершин
		scanf("%d", &n);
		printf("\nВведите количество ребер: m= "); // количество ребер
		scanf("%d", &m);
		int* x = (int*)malloc(n * sizeof(int));
		int** h = (int**)malloc((n + 1) * sizeof(int));
		int har[10];
		printf("\nВводим названия вершин: ");
		for (int arr = 0; arr < n; arr++) // выделяем по одной ячейке помяти размером int в каждой строке
		{
			h[arr] = (int*)malloc(sizeof(int));
		}
		for (i = 0; i < n; i++) {
			har[i] = 0;
			printf("\nx[%d]=", i);
			x[i] = getche(); //возвращает очередной символ, считанный с консоли, и выводит этот символ на экран.
		}
		printf("\nВвод рёбер: \n");
		for (i = 0; i < m; i++)
			for (j = 0; j < 2; j++) {
				scanf("%d", &t);
				g[i][j] = t;
			}
		FILE* f;
		f = fopen("grap.dot", "w"); // открыли файл grap.dot для записи
		fprintf(f, "graph mygrap{ \n");
		for (i = 0; i < n; i++)
			fprintf(f, "%c\n", x[i]);
		for (i = 0; i < m; i++) {
			fprintf(f, "%d--%d\n", g[i][0], g[i][1]);
		}
		fprintf(f, "}");
		fclose(f);
		c = getche();
		system("dot -Tpng grap.dot -o grap.png");
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (h[i][j] == 0) har[i] = har[i] + 1;
				else dem = dem + 1;
			}
		}
		for (i = 0; i < n; i++) {
			if (h[i][i] > 0 && har[i] == n - 1 || har[i] == n) {
				printf("Graph is not connected => Graph is not tree\n");
				return 0;
			}
		}
		if (har1 != n && (dem / 2) >= n - 1) {
			printf("Graph is connected \n");
			if ((dem / 2) == (n + 1) || count != 0) printf(" but not tree ");
			else if (m == (n - 1)) printf("Graph is tree");
			else  printf(" but not tree ");
		}
		else {
			printf("Graph is not connected => Graph is not tree\n");
		}
		//Команды системы, чтобы передавать файл graph.dot в png и открывать картинку графа//
	} while ((c == 'y') || (c == 'Y'));
	getch();
	return 0;
}