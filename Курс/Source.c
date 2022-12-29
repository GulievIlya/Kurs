#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define const 10
#define znach 100
int delete(double *mass,int size,int k);
void insert(double* mass, int* size, int index, int k);

int main() {
	setlocale(LC_ALL, "RU");
	//zadanie2();
	int size;
	int n = 1, cc = -1, proz = 1, summ = 0, me = 0, c1 = 0,proz1=0,i=-1;
	puts("Введите размер массива");
	scanf("%d",&size);
	int* mass = (int*)malloc(n* sizeof(int));
	int* mass2 = (int*)malloc(size * sizeof(int));
	for (int i = 0;i < size;i++) {
		mass2[i] = rand() %100;
	}
	for (int i = 3;i < size;i+=4) {
		mass2[i] =0;
	}
	for (int i = 0;i < size;i++) {
		printf("\nmass[%d] = %d", i, mass2[i]);
	}
	puts("");
	while (cc < size) {
		i++;
		cc++;
		if (cc == size) break;
		while ((mass2[cc] != 0) && cc < size) {
			proz *= mass2[cc];
			cc++;
		}
		mass[i] = proz;
		//printf("\nproz = %d", proz);
		if ((mass2[size - 1] == proz) || (mass2[size - 1] == summ)) break;
		proz = 1;
		cc++;
		if (cc == size) break;
		while ((mass2[cc] != 0)&& (cc<size) ) {
			summ += mass2[cc];
			cc++;
		}
		i++;
		mass[i] = summ;
		//printf("\nsumm = %d", summ);
		if ((mass2[size - 1] == proz) || (mass2[size - 1] == summ)) break;
		summ = 0;
	}
	for (int a = 0;a <= i;a++) {
		printf("\nmass[%d] = %d", a, mass[a]);
	}
}	
int zadanie2() {
	setlocale(LC_ALL, "RU");
	int size, index1, index2, in1,in2,k=-999;
	double max, min;
	puts("Введите размер массива");
	scanf("%d", &size);
	double* mass = (double*)malloc(size * sizeof(double));
	for (int i = 0;i < size;i++) {
		mass[i] = rand() % 3 - 1 + (double)rand() / 100000;
		printf("\nmass[%d]=%lf", i, mass[i]);
	}
	max = mass[0];
	min = mass[0];
	for (int i = 0;i < size;i++) {
		if (mass[i] > max) {
			max = mass[i];
			index1 = i;
		}
		if (mass[i] < min) {
			min = mass[i];
			index2 = i;
		}
	}
	printf("\n\nmax[%d] = %lf ; min[%d] = %lf", index1, max, index2,min);
	delete(mass, size, index1);
	delete(mass, size, index2);
	puts("");
	size -= 2;
	for (int i = 0;i < size;i++) {
		printf("\nmass[%d]=%lf", i, mass[i]);
	}
	min = mass[0];
	for (int i = 0;i < size;i++) {
		if (mass[i] < min) {
			min = mass[i];
			in1 = i;
		}
	}
	//printf("\n%d ", in1);
	insert(mass, size, in1, k);
	for (int i = 0;i < size;i++) {
		printf("\nmass[%d]=%lf", i, mass[i]);
	}
}
int zadanie1() {
	setlocale(LC_ALL, "RU");
	int size;
	puts("Введите размер массива");
	scanf("%d", &size);
	int* mass = (int*)malloc(size * sizeof(int));
	int* mass2 = (int*)malloc(size * sizeof(int));
	if (mass == NULL) {
		puts("ERROR");
		return 0;
	}
	for (int i = 0;i < size;i++) {
		mass[i] = rand() % 201 - 100;
	}
	for (int i = 0;i < size;i++) {
		mass2[i] =mass[i]- const;
		printf("mass[%d]=%d\n", i, mass[i]);
	}
	puts("\n1-ый массив      2-ой массив");
	for (int i = 0;i < size;i++) {
		printf("\nmass[%d] = %d\t mass2[%d] = %d", i, mass[i], i, mass2[i]);
	}
	free(mass);
	free(mass2);
}
int delete(double* mass, int size, int k) {
	int n = size - 1;
	for (int i = k;i < (size - 1);i++) mass[i] = mass[i + 1];
	return n;
}
void insert(double* mass, int *size,int index, int k) {
	int size1 = size;
	printf("\nsize1 = %d 213", size1);
	printf("\n1");
	if (mass == NULL) return 0;
	int* ptr = (int*)malloc(size1 * sizeof(int));
	if (ptr == NULL) return 0;
	ptr = mass;
	for (int i = index-1 ; i >= 0;i--) {
		mass[i] = k;
	}
	for (int i = index + 1; i <=size;i++) {
		mass[i] = k;
	}
	size = size1;
}
