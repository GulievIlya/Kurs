#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define znach 2//кол-во структур в массиве
struct str {
	char login[8];
	int data_vh;
	int online[3];
	int ofline[3];
	float dowloand;
	float send;
};
typedef struct str polz;

int put_str(polz* zap, int chislo); //ввод структуры с клавиатуры
void vivod(polz* zap, int chislo); //вывод всех структур
void vivodstr(polz* zap, int i); //вывод какого-то индекса
int poisk1(polz* zap, int chisl); //1-ый поиск по логину
int poisk2(polz* zap, int chisl,int* mass); //2-ой поиск по длительности сеанса 
int sorting(polz* zap, int chislo); //сортировка по отправленным + скаченным МБ
int readfile(int size, polz** l, char *name); //считывание структур с файла
void vvod(polz* ptr_struct, int size, char name); //запись в файл

int main() {
	int j = 0, j1 = 0,n, chislo = 0;//n-действие , chislo- кол-во записей ; j и j1 проверка для сортировки если ничего нет. 
	setlocale(LC_ALL, "RU");
	char file[100] = "BD.txt";
	polz* ptr_zapis; //массив записей
	int* mass = (int*)malloc(100); //массив для поиска
	ptr_zapis = (struct polz*)malloc(znach* sizeof(polz));//выделение памяти для массива структур
	while (1) {
		puts("\nВыберите действие:\n1)Ввод значений:\n2)Напечатать поля структур\n3)Поиск структур по логину\n4)Поиск структур по длительности сеанса ч.\n5)Сортировка по Объему потреблённого трафика за сеанс в Мб (принято + отправлено)\n6)Считать данные с файла\n7)Запись в файл \n8)выход из программы");
		scanf("%d", &n);
		switch (n) {
		case 1:			
			chislo = put_str(ptr_zapis, chislo);
			ptr_zapis = realloc(ptr_zapis, sizeof(polz)*(chislo+1));
			break;
		case 2:
			vivod(ptr_zapis, chislo);
			break;
		case 3:
			puts("Введите логин для поиска:");
			j = poisk1(ptr_zapis, chislo);
			if (j < -900) { break; }
			else vivodstr(ptr_zapis, j);
			break;
		case 4:
			printf("\nВведите длительность сеанса online(ч)");
			j1 = poisk2(ptr_zapis, chislo,mass);
			if (j1 < -900) break;
			puts("НАЙДЕННЫЕ СТРУКТУРЫ:");
			for (int l = 0;l <= j1;l++) {
				int p = mass[l];
				vivodstr(ptr_zapis, p);
			}
			break;
		case 5:
			sorting(ptr_zapis, chislo,mass,file);
			break;
		case 6:
			chislo = readfile(chislo, &ptr_zapis,file);
			printf("Чтение данных с файла завершено \n");
			break;
		case 7:
			vvod(ptr_zapis, chislo,file);
			break;
		case 8:
			return 0;
			break;
		}
	}
}
int put_str(polz * zap, int chislo) {
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
void vivod(polz* zap, int chislo) {
	puts("______________________________________________________________________________________________________________________");
	puts("|Номер  |Логин  |Дата выхода в on-line|Время начала сеанса on-line|Время завершения сеанса|Скачанные/отправленные М/Б|");
	for (int i = 0; i < chislo; i++) {
		printf("|   %3d |%7s|         %3d         | %2d:%2d:%2d                  | %2d:%2d:%2d              | %.2f/%.2f       \t     |\n", i+1, zap[i].login, zap[i].data_vh, zap[i].online[0], zap[i].online[1], zap[i].online[2], zap[i].ofline[0], zap[i].ofline[1], zap[i].ofline[2], zap[i].dowloand, zap[i].send);
	}
	printf("|____________________________________________________________________________________________________________________|");
}
void vivodstr(polz* zap, int i) {//zap[a].login
	puts("______________________________________________________________________________________________________________________");
	puts("|Номер  |Логин  |Дата выхода в on-line|Время начала сеанса on-line|Время завершения сеанса|Скачанные/отправленные М/Б|");
	printf("|   %3d |%7s|         %3d         | %2d:%2d:%2d                  | %2d:%2d:%2d              | %4.2f/%4.2f             |\n", i+1, zap[i].login, zap[i].data_vh, zap[i].online[0], zap[i].online[1], zap[i].online[2], zap[i].ofline[0], zap[i].ofline[1], zap[i].ofline[2], zap[i].dowloand, zap[i].send);
	printf("|____________________________________________________________________________________________________________________|");
}
int poisk1(polz* zap, int chisl) {
	char c[7];
	int p, k = 0, l = 0;
	scanf("%s", &c);
	p = strlen(c);//считываем длинну ввёденого логина
	for (int n = 0; n < chisl; n++) {
		for (int i = 0; i < chisl; i++) {
			if (zap[n].login[i] == c[i]) {
				k++; //кол-во сходств в введёном слове и в структуре
			}
			l = strlen(zap[n].login); 
		}
		if (l == p) { //сравнивнение сходств и длины слова , если равны то выводим логин ( допуск 1 ошибка в логине)
			if (((l == k - 1))) {
				return n;
			}
			else if ((l == k)) {
				return n;
			}
		}
		k = 0;
	}
	(puts("НЕ НАЙДЕНО!"));
	return -999;//проверка по поиску
}
int poisk2(polz* zap, int chisl,int *mass)	 {
	int time[3], j, sum = -1;
	scanf("%d", &j);
	for (int chislo = 0; chislo < chisl; chislo++) {
		time[0] = ((zap[chislo].ofline[0] + zap[chislo].ofline[1] / 60 + zap[chislo].ofline[2] / 360) - (zap[chislo].online[0] + zap[chislo].online[1] / 60 + zap[chislo].online[2] / 360));
		if (time[0] == j) {
			sum++;
			mass[sum] = chislo;
		}
	}
	if (sum == -1) return -999;
	else return sum;
}
int sorting(polz* zap, int chislo) { //сортировка вставками
	int location = 0;
	for (int i = 1;i < chislo;i++) {
		for (int j = i; j > 0 && zap[j - 1].dowloand + zap[j - 1].send > zap[j].dowloand+ zap[j].send; j--) {
			location++;
			polz tmp = zap[j - 1];
			zap[j - 1] = zap[j];
			zap[j] = tmp;
		}
	}
}
int readfile(int size,polz **l, char *name) {
	int h = 0;
	h = size - 1;
	FILE* ptr_file = fopen(name, "r");
	while (!feof(ptr_file)) {
		h++;
		*l = (polz*)realloc(*l,(h+1)*sizeof(polz));
		fscanf(ptr_file, "%s %d %d %d %d %d %d %d %f %f\n", &(*l)[h].login, &(*l)[h].data_vh, &(*l)[h].online[0], &(*l)[h].online[1], &(*l)[h].online[2], &(*l)[h].ofline[0], &(*l)[h].ofline[1], &(*l)[h].ofline[2], &(*l)[h].dowloand, &(*l)[h].send);
	}
	fclose(ptr_file);
	return h;
}
void vvod(polz* ptr_struct, int size, char name) {
	FILE* ptr_file = fopen(name, "w");
	for (int i = 0;i < size;i++) {
		fprintf(ptr_file, "%s %d %d %d %d %d %d %d %f %f\n", ptr_struct[i].login, ptr_struct[i].data_vh, ptr_struct[i].online[0], ptr_struct[i].online[1], ptr_struct[i].online[2], ptr_struct[i].ofline[0], ptr_struct[i].ofline[1], ptr_struct[i].ofline[2], ptr_struct[i].dowloand, ptr_struct[i].send);
	}
	puts("Запись заврешена!");
	fclose(ptr_file);
}
