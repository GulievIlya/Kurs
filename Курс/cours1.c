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
int vivodstr(polz* zap, int i);
int poisk1(polz* zap, int chisl);
int poisk2(polz* zap, int chisl);
int sorting(polz* zap, int chislo);
int readfile(polz* ptr_struct, int size, FILE* ptr_file);
void vvod(polz* ptr_struct, int size);

int main() {
	int a = 0, vvodBD = 0, j = 0, j1 = 0, poisk[znach];
	setlocale(LC_ALL, "RU");
	FILE* file_ptr;
	int n, chislo = 0;//n-действие 
	polz *ptr_zapis ;
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
			j = poisk1(ptr_zapis, chislo);
			if (j < -900) break;
			vivodstr(ptr_zapis, j);
			break;
		case 4:
			j1 = poisk2(ptr_zapis, chislo);
			if (j1 < -200) break;
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
	if (chislo > znach) realloc(zap, znach*(chislo+1));
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
	puts("______________________________________________________________________________________________________________________");
	puts("|Номер  |Логин  |Дата выхода в on-line|Время начала сеанса on-line|Время завершения сеанса|Скачанные/отправленные М/Б|");
	for (int i = 0; i < chislo; i++) {
		printf("| %d\t| %s\t| %d\t              | %d:%d:%d\t                  | %d:%d:%d\t          | %.2f/%.2f\t             |\n",i, zap[i].login, zap[i].data_vh, zap[i].online[0], zap[i].online[1], zap[i].online[2], zap[i].ofline[0], zap[i].ofline[1], zap[i].ofline[2], zap[i].dowloand, zap[i].send);
	}
	printf("|____________________________________________________________________________________________________________________|");
	return 0;
}
int vivodstr(polz* zap, int i) {//zap[a].login
	puts("______________________________________________________________________________________________________________________");
	puts("|Номер  |Логин  |Дата выхода в on-line|Время начала сеанса on-line|Время завершения сеанса|Скачанные/отправленные М/Б|");
	printf("| %d\t| %s\t| %d\t              | %d:%d:%d\t                  | %d:%d:%d\t          | %.2f/%.2f\t             |\n", i, zap[i].login, zap[i].data_vh, zap[i].online[0], zap[i].online[1], zap[i].online[2], zap[i].ofline[0], zap[i].ofline[1], zap[i].ofline[2], zap[i].dowloand, zap[i].send);
	printf("|____________________________________________________________________________________________________________________|");
}
int poisk1(polz* zap, int chisl) {
	char c[7];
	int p, k = 0, j, l = 0, l1 = -1;
	puts("Введите логин для поиска:");
	scanf("%s", &c);
	p = strlen(c);
	for (int n = 0; n < chisl; n++) {
		for (int i = 0; i < chisl; i++) {
			if (zap[n].login[i] == c[i]) {
				k++;
			}
			l = strlen(zap[n].login);
		}
		if (l == p) {
			if (((l == k - 1))) {
				return n;

			}
			else if ((l == k)) {
				return n;
			}
			else {
				(puts("НЕ НАЙДЕНО!"));
				return -999;//проверка по поиску
			}
		}
		k = 0;
	}
}
int poisk2(polz* zap, int chisl) {
	int time[3], j;
	printf("\nВведите длительность сеанса online(ч)");
	scanf("%d", &j);
	for (int chislo = 0; chislo < chisl; chislo++) {
		time[0] = abs((zap[chislo].ofline[0] + zap[chislo].ofline[1] / 60 + zap[chislo].ofline[2] / 360) - (zap[chislo].online[0] + zap[chislo].online[1] / 60 + zap[chislo].online[2] / 360));
		//printf("\nВРЕМЯ = %d", time[0]);
		if (time[0] == j) {
			puts("Найденная структура:");
			return chislo;
		}
		else {
			puts("НЕ НАЙДЕНО! ");
			return -999;
		}
	}
}
int sorting(polz* zap, int chislo) {
	for (int i = 0; i < chislo; i++) {
		for (int j = 0; j < chislo - i - 1; j++) {
			if (zap[j].dowloand + zap[j].send > zap[j + 1].dowloand + zap[j + 1].send) {
				float n = zap[j].send+zap[j].dowloand;
				float n1 = zap[j+1].send + zap[j + 1].dowloand;
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
	printf("Чтение данных с файла завершено \n");
	fclose(ptr_file);
	if (size == 0) { return (h + size + 1); }
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
