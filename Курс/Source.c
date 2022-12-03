#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
struct str {
	char login[8];
	int data_vh;
	int online[3];
	int ofline[3];
	float dowloand;
	float send;
};
typedef struct str polz;
int put_str(polz *zap, int chislo);
int vivod(polz *zap, int chislo);
int poisk(polz *zap, int chislo);

int main() {
	setlocale(LC_ALL, "RU");
	int n,chislo=0;//n-действие 
	polz baze[100], * ptr_zapis = &baze[chislo];
	while(1) {
	puts("\nВыберите действие:\n1)Ввод значений:\n2)Напечатать поля структур\n3)Поиск структуры по критерию\n4)Выход из программы");
	scanf("%d", &n);
	polz log;
		switch (n) {
		case 1:
			chislo = put_str(ptr_zapis,chislo);
			break;
		case 2:
				vivod(ptr_zapis, chislo);
			break;
		case 3:
			poisk(ptr_zapis, chislo);
			break;
		case 4:
			return 0;
		}
	}
}
int put_str(polz *zap,int chislo) {
	printf("\n1)Логин:");
	scanf("%s", &zap[chislo].login);
	printf("\n2)Дата входа:");
	scanf("%d", &zap[chislo].data_vh);
	printf("\n3)Дата выхода в онлайн (ч. мин. сек.)");
	scanf("%d", &zap[chislo].online[0]);
	scanf("%d", &zap[chislo].online[1]);
	scanf("%d", &zap[chislo].online[2]);
	printf("\n4)Дата завершения сеанса (ч. мин. сек.)");
	scanf("%d", &zap[chislo].ofline[0]);
	scanf("%d", &zap[chislo].ofline[1]);
	scanf("%d", &zap[chislo].ofline[2]);
	printf("\n5)Загруженные МБ:");
	scanf("%f", &zap[chislo].dowloand);
	printf("\n6)Отправленные МБ:");
	scanf("%f", &zap[chislo].send);
	chislo++;
	return chislo;
}
int vivod(polz* zap, int chislo) {
	for (int i = 0;i < chislo;i++) {
		printf("\n___________________________________________");
		printf("\n|Логин пользователя(7сим):  %s\n", zap[i].login);
		printf("|Дата выхода в on-line:  %d\n", zap[i].data_vh);
		printf("|Время начала сеанса on-line:  %d:%d:%d\n", zap[i].online[0], zap[i].online[1], zap[i].online[2]);
		printf("|Время завершения сеанса on-line:  %d:%d:%d\n", zap[i].ofline[0], zap[i].ofline[1], zap[i].ofline[2]);
		printf("|скаченные/отправленные МБ:  %.2f/%.2f\t  \n", zap[i].dowloand, zap[i].send);
		printf("|___________________________________________\n");
	}
}
int poisk(polz* zap, int chisl) {
	char c[7];
	int p, k = 0, time[3], j;
	puts("Введите логин для поиска:");
	scanf("%s", &c);
	p = strlen(c);
	for (int chislo = 0;chislo < 3;chislo++) {
		for (int i=0;i <= p;i++) {
			if (c[i] == zap[chislo].login[i])
				k++;
		}
		for (int zaps = 0; zaps < chisl;zaps++) {
			if (((k - 1) == p) || ((k - 1) == p - 1)) {
				puts("Найденная структура:");
				printf("\n|___________________________________________");
				printf("\n|Логин пользователя(7сим):  %s\n", zap[zaps].login);
				printf("|Дата выхода в on-line:  %d\n", zap[zaps].data_vh);
				printf("|Время начала сеанса on-line:  %d:%d:%d\n", zap[zaps].online[0], zap[zaps].online[1], zap[zaps].online[2]);
				printf("|Время завершения сеанса on-line:  %d:%d:%d\n", zap[zaps].ofline[0], zap[zaps].ofline[1], zap[zaps].ofline[2]);
				printf("|скаченные/отправленные МБ:  %.2f/%.2f\t  \n", zap[zaps].dowloand, zap[zaps].send);
				printf("|___________________________________________\n");
			}
		}
	}
	printf("\nВведите длительность сеанса online(ч)");
	scanf("%d", &j);
	for (int chislo = 0;chislo < chisl;chislo++) {
		time[0] = zap[chislo].ofline[0] - zap[chislo].online[0];
		if (time[0] == j) {
			puts("Найденная структура:");
			printf("\n|___________________________________________");
			printf("\n|Логин пользователя(7сим):  %s\n", zap[chislo].login);
			printf("|Дата выхода в on-line:  %d\n", zap[chislo].data_vh);
			printf("|Время начала сеанса on-line:  %d:%d:%d\n", zap[chislo].online[0], zap[chislo].online[1], zap[chislo].online[2]);
			printf("|Время завершения сеанса on-line:  %d:%d:%d\n", zap[chislo].ofline[0], zap[chislo].ofline[1], zap[chislo].ofline[2]);
			printf("|скаченные/отправленные МБ:  %.2f/%.2f\t  \n", zap[chislo].dowloand, zap[chislo].send);
			printf("|___________________________________________\n");
			//printf("%d)Сеанс длился с %d ч %d мин %d сек до %d ч %d мин %d сек ",chislo, zap[chislo].online[0], zap[chislo].online[1], zap[chislo].online[2], zap[chislo].ofline[0], zap[chislo].ofline[1], zap[chislo].ofline[2]);
		}
	}
}
