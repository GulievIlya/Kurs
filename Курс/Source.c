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
		puts("�������� ��������:\n1)���� ��������:\n2)���������� ���� ��������\n3)����� ��������� �� ��������\n4)����� �� ���������");
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
	printf("1)�����:");
	scanf("%s", &(*so).login);
	printf("\n2)���� �����:");
	scanf("%d", &(*so).data_vh);
	printf("\n3)���� ������ � ������ (�. ���. ���.)");
	scanf("%d", &(*so).online[0]);
	scanf("%d", &(*so).online[1]);
	scanf("%d", &(*so).online[2]);
	printf("\n4)���� ���������� ������ (�. ���. ���.)");
	scanf("%d", &(*so).ofline[0]);
	scanf("%d", &(*so).ofline[1]);
	scanf("%d", &(*so).ofline[2]);
	printf("\n5)����������� ��:");
	scanf("%f", &(*so).dowloand);
	printf("\n6)������������ ��:");
	scanf("%f", &(*so).send);
}
void tabl(polz* so) {
	printf("\n___________________________________________");
	printf("\n|����� ������������(7���):  %s\n", (*so).login);
	printf("|���� ������ � on-line:  %d\n", (*so).data_vh);
	printf("|����� ������ ������ on-line:  %d:%d:%d\n", (*so).online[0], (*so).online[1], (*so).online[2]);
	printf("|����� ���������� ������ on-line:  %d:%d:%d\n", (*so).ofline[0], (*so).ofline[1], (*so).ofline[2]);
	printf("|���������/������������ ��:  %.2f/%.2f\t  \n", (*so).dowloand, (*so).send);
	printf("|___________________________________________\n");
}
void tlog(polz* log) {
	char c[7];
	int p, k = 0, time[3], j[3];
	puts("������� ����� ��� ������:");
	scanf("%s", &c);
	p = strlen(c);
	for (int p = strlen(c), i = 0;i <= p;i++) {
		if (c[i] == (*log).login[i])
			k++;
	}
	if (((k - 1) == p) || ((k - 1) == p - 1)) {
		puts("��������� �����");
		printf("%s", (*log).login);
	}
	else puts("�� ��������!");
	time[0] = (*log).ofline[0] - (*log).online[0];
	time[1] = (*log).ofline[1] - (*log).online[1];
	time[2] = (*log).ofline[2] - (*log).online[2];
	printf("\n������� ������������ ������ online(�)");
	scanf("%d", &j[0]);
	if (time[0] == j[0]) {
		printf("����� ������ � %d � %d ��� %d ��� �� %d � %d ��� %d ��� ", (*log).online[0], (*log).online[1], (*log).online[2], (*log).ofline[0], (*log).ofline[1], (*log).ofline[2]);
	}
	else puts("�� �������� ! ");
}
