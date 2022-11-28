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
void put_str(polz* so);
void tabl(polz* so);
void tlog(polz* log);
int main() {
	char c[8];
	setlocale(LC_ALL, "RU");
	int n, p = 0, k = 0, time[3], j[3];
	for (;;) {
		puts("Выберите действие:\n1)Ввод значений:\n2)Напечатать поля структур\n3)Поиск структуры по критерию\n4)Выход из программы");
		scanf("%d", &n);
		polz log;
		polz* log_p = NULL;
		switch (n) {
		case 1:
			put_str(&log);
			printf("%s", log.login);
			break;
		case 2:
			tabl(&log);
			break;
		case 3:
			tlog(&log);
		case 4:
			return 0;
		}
	}
}
void put_str(polz* so) {
	printf("1)Логин:");
	scanf("%s", &(*so).login);
	printf("\n2)Дата входа:");
	scanf("%d", &(*so).data_vh);
	printf("\n3)Дата выхода в онлайн (ч. мин. сек.)");
	scanf("%d", &(*so).online[0]);
	scanf("%d", &(*so).online[1]);
	scanf("%d", &(*so).online[2]);
	printf("\n4)Дата завершения сеанса (ч. мин. сек.)");
	scanf("%d", &(*so).ofline[0]);
	scanf("%d", &(*so).ofline[1]);
	scanf("%d", &(*so).ofline[2]);
	printf("\n5)Загруженные МБ:");
	scanf("%f", &(*so).dowloand);
	printf("\n6)Отправленные МБ:");
	scanf("%f", &(*so).send);
}
void tabl(polz* so) {
	printf("\n___________________________________________");
	printf("\n|Логин пользователя(7сим):  %s\n", (*so).login);
	printf("|Дата выхода в on-line:  %d\n", (*so).data_vh);
	printf("|Время начала сеанса on-line:  %d:%d:%d\n", (*so).online[0], (*so).online[1], (*so).online[2]);
	printf("|Время завершения сеанса on-line:  %d:%d:%d\n", (*so).ofline[0], (*so).ofline[1], (*so).ofline[2]);
	printf("|скаченные/отправленные МБ:  %.2f/%.2f\t  \n", (*so).dowloand, (*so).send);
	printf("|___________________________________________\n");
}
void tlog(polz* log) {
	char c[7];
	int p, k = 0, time[3], j[3];
	puts("Введите логин для поиска:");
	scanf("%s", &c);
	p = strlen(c);
	for (int p = strlen(c), i = 0;i <= p;i++) {
		if (c[i] == (*log).login[i])
			k++;
	}
	if (((k - 1) == p) || ((k - 1) == p - 1)) {
		puts("Найденный логин");
		printf("%s", (*log).login);
	}
	else puts("Не найденно!");
	time[0] = (*log).ofline[0] - (*log).online[0];
	time[1] = (*log).ofline[1] - (*log).online[1];
	time[2] = (*log).ofline[2] - (*log).online[2];
	printf("\nВведите длительность сеанса online(ч)");
	scanf("%d", &j[0]);
	if (time[0] == j[0]) {
		printf("Сеанс длился с %d ч %d мин %d сек до %d ч %d мин %d сек ", (*log).online[0], (*log).online[1], (*log).online[2], (*log).ofline[0], (*log).ofline[1], (*log).ofline[2]);
	}
	else puts("не найденно ! ");
}
