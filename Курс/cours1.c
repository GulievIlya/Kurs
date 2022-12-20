#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define znach 100
struct str {
	char login[8];
	int data_vh;
	int online[3];
	int ofline[3];
	float dowloand;
	float send;
};
typedef struct str polz;

int put_str(polz* zap, int chislo);
int vivod(polz* zap, int chislo);
int vivodstr(polz* zap, int *str);
int poisk1(polz* zap, int chisl,int* poisk[znach]);
int poisk2(polz* zap, int chisl);
int sorting(polz* zap, int chislo);
int readfile(polz* ptr_struct, int size,FILE *ptr_file);
void vvod(polz* ptr_struct, int size);

int main() {
	int a = 0, vvodBD = 0, j = 0, j1 = 0, poisk[znach];
	setlocale(LC_ALL, "RU");
	FILE* file_ptr;
	int n, chislo = 0;//n-действие 
	int *ptr_poisk = &poisk[chislo];
	ptr_poisk = (int*)malloc(znach);
	polz baze[znach], * ptr_zapis = &baze[chislo];
	FILE* ptr_file = fopen("BD.txt", "r");
	ptr_zapis = (struct polz*)malloc(chislo * sizeof(polz));
	while (1) {
		puts("\nВыберите действие:\n1)Ввод значений:\n2)Напечатать поля структур\n3)Поиск структур по логину\n4)Поиск структур по длительности сеанса ч.\n5)Сортировка по Объему потреблённого трафика за сеанс в Мб (принято + отправлено)\n6)Считать данные с файла\n7)Запись в файл \n8)выход из программы");
		scanf("%d", &n);
		polz log;
		switch (n) {
		case 1:
			chislo = put_str(ptr_zapis, chislo);
			break;
		case 2:
			vivod(ptr_zapis, chislo);
			break;
		case 3:
			j = poisk1(ptr_zapis, chislo,ptr_poisk);
			//printf("ptr - %d %d ", ptr_poisk[0], ptr_poisk[1]);
			break;
		case 4:
			j1 = poisk2(ptr_zapis, chislo);
			vivodstr(ptr_zapis, j1);
			break;
		case 5:
			sorting(ptr_zapis, chislo);
			break;
		case 6:
			chislo = readfile(ptr_zapis, chislo, ptr_file);
			printf("%d", chislo);
			break;
		case 7:
			vvod(ptr_zapis, chislo);
			break;
		case 8:
			return 0;
		}
	}
}
int put_str(polz* zap, int chislo) {
	if (chislo > znach) realloc(zap,znach,chislo);
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
	return 0;
}
int vivodstr(polz* zap, int* str) {
	//for (int i = 0;i < (sizeof(str) / 4);i++);
}
int poisk1(polz* zap, int chisl, int* poisk){
	char c[7];
	int p, k = 0, j,l=0,l1=-1;
	puts("Введите логин для поиска:");
	scanf("%s", &c);
	p = strlen(c);
	printf("chisl = %d", chisl);
	for (int n = 0;n < chisl;n++) {
		for (int i = 0; i < chisl;i++) {
			if (zap[n].login[i] == c[i]) {
				k++;
				printf("\n K = %d", k);
			}
			l = strlen(zap[n].login);
			printf("\nL = %d P = %d", l,p);
		}
		if (l == p) {
			if (((l == k ) || (l == k-1))) {
				puts("Найденная структура:");
				printf("\n|___________________________________________");
				printf("\n|Логин пользователя(7сим):  %s\n", zap[n].login);
				printf("|Дата выхода в on-line:  %d\n", zap[n].data_vh);
				printf("|Время начала сеанса on-line:  %d:%d:%d\n", zap[n].online[0], zap[n].online[1], zap[n].online[2]);
				printf("|Время завершения сеанса on-line:  %d:%d:%d\n", zap[n].ofline[0], zap[n].ofline[1], zap[n].ofline[2]);
				printf("|скаченные/отправленные МБ:  %.2f/%.2f\t  \n", zap[n].dowloand, zap[n].send);
				printf("|___________________________________________\n");
				//l1++;
				//poisk[l1] = n;
			}
		}
		k = 0;
	}
	printf("\n l1 = %d", l1);
	return 0;
}
int poisk2(polz* zap, int chisl) {
	int time[3], j;
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
	return 0;
}
int sorting(polz* zap, int chislo) {
	for (int i = 0;i < chislo;i++) {
		for (int j = 0; j < chislo - i - 1; j++) {
			if (zap[j].dowloand + zap[j].send > zap[j + 1].dowloand + zap[j + 1].send) {
				float tmp1 = zap[j].dowloand;
				float tmp2 = zap[j].send;
				zap[j].dowloand = zap[j + 1].dowloand;
				zap[j].send = zap[j + 1].send;
				zap[j + 1].dowloand = tmp1;
				zap[j + 1].send = tmp2;
			}
		}
	}
	return 0;
}
int readfile(polz* ptr_struct, int size, FILE* ptr_file) {
	int h = 0;
	char k[100];
	h = size - 1;
	while (!feof(ptr_file)) {
		h++;
		fscanf(ptr_file, "%s %d %d %d %d %d %d %d %f %f\n", &ptr_struct[h].login, &ptr_struct[h].data_vh, &ptr_struct[h].online[0], &ptr_struct[h].online[1], &ptr_struct[h].online[2], &ptr_struct[h].ofline[0], &ptr_struct[h].ofline[1], &ptr_struct[h].ofline[2], &ptr_struct[h].dowloand, &ptr_struct[h].send);
	}
	printf("Чтение данных с файла завершено %d\n", h);
	fclose(ptr_file);
	if (size == 0) {return (h + size + 1);}
	if (size > 0) { return (h + size); }

}
void vvod(polz* ptr_struct, int size) { //Запись последней структуры в файл 
	FILE* ptr_file = fopen("BD.txt", "a");
	int i = size - 1;
	fprintf(ptr_file, "\n%s %d %d %d %d %d %d %d %f %f", ptr_struct[i].login, ptr_struct[i].data_vh, ptr_struct[i].online[0], ptr_struct[i].online[1], ptr_struct[i].online[2], ptr_struct[i].ofline[0], ptr_struct[i].ofline[1], ptr_struct[i].ofline[2], ptr_struct[i].dowloand, ptr_struct[i].send);
	fclose(ptr_file);
}
/*
for (int chislo = 0;chislo < chisl;chislo++) {
		for (int i=0;i <= p;i++) {
			if (c[i] == zap[chislo].login[i]) {
				k++;
			}
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
				break;	
			}
		}
	}*/
//while (!feof(ptr_file)) {
//	fscanf(ptr_file, "%s %d %d %d %d %d %d %d %f %f\n", &ptr_struct[i].login, &ptr_struct[i].data_vh, &ptr_struct[i].online[0], &ptr_struct[i].online[1], &ptr_struct[i].online[2], &ptr_struct[i].ofline[0], &ptr_struct[i].ofline[1], &ptr_struct[i].ofline[2], &ptr_struct[i].dowloand, &ptr_struct[i].send);
//	h++;
//}
/*puts("Найденная структура:");
			printf("\n|___________________________________________");
			printf("\n|Логин пользователя(7сим):  %s\n", zap[n].login);
			printf("|Дата выхода в on-line:  %d\n", zap[n].data_vh);
			printf("|Время начала сеанса on-line:  %d:%d:%d\n", zap[n].online[0], zap[n].online[1], zap[n].online[2]);
			printf("|Время завершения сеанса on-line:  %d:%d:%d\n", zap[n].ofline[0], zap[n].ofline[1], zap[n].ofline[2]);
			printf("|скаченные/отправленные МБ:  %.2f/%.2f\t  \n", zap[n].dowloand, zap[n].send);
			printf("|___________________________________________\n");*/
