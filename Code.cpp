#include <stdio.h>
#include <windows.h>
#include <ctime>
#include <math.h>
#include <conio.h>
int main() {
	srand(time(NULL));
	double k;
	COORD pos;
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int a[51][50], i, j, n, m, b, min, max, lmin, lmax, l = 0, l1, k1 = 0;
	printf("input number (n,m<10) ");
	scanf_s("%d %d", &n, &m);
	k = 12e7 / sqrt(n * m);
	for (i = 1; i < n + 1; i++) {
		for (j = 0; j < m; j++) {
			a[i][j] = rand();
		}
	}
	max = a[1][0];
	for (i = 1; i < n + 1; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j] > max)
				max = a[i][j];
		}
	}
	min = a[1][0];
	for (i = 1; i < n + 1; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j] < min)
				min = a[i][j];
		}
	}
	for (lmax = 1; lmax < 12; lmax++) {
		l1 = pow(10, lmax);
		if (max < l1)
			break;
	}
	for (lmin = 1; lmin < 12; lmin++) {
		l1 = -1 * pow(10, lmin);
		if (min > l1)
			break;
	}
	lmin += 1;
	l = lmin;
	if (lmax > lmin)
		l = lmax;
	printf("\n");
	for (i = 1; i < n + 1; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	pos.X = m + 30;
	pos.Y = n + 6;
	for (i = 1; i < n + 1; i++) {
		for (j = 0; j < m; j++) {
			SetConsoleCursorPosition(hconsole, pos);
			printf("%d", a[i][j]);
			pos.X += 2 * (l + 1);
			SetConsoleCursorPosition(hconsole, pos);
			for (b = 1; b < k; b++);
		}
		pos.X = m + 30;
		pos.Y += 2;
	}
	printf("\n");
	printf("Press any key to stop");
	while (1) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				a[i][j] = a[i + 1][j];
				pos.X = m + 30 + (l + 1) * j * 2;
				pos.Y = n + 6 + 2 * i;
				for (k1 = 0; k1 < 2; k1++) {
					SetConsoleCursorPosition(hconsole, pos);
					for (l1 = 0; l1 < l; l1++)
						printf(" ");
					for (b = 1; b < k; b++);
					pos.Y -= 1;
					SetConsoleCursorPosition(hconsole, pos);
					printf("%d", a[i][j]);
					for (b = 1; b < k; b++);
				}
				pos.Y += 2;
			}
			pos.X = m + 30;
		}
		for (j = 0; j < m; j++) {
			a[n][j] = a[0][j];
			pos.X = m + 30 + (l + 1) * j * 2;
			pos.Y = n + 4;
			SetConsoleCursorPosition(hconsole, pos);
			for (l1 = 0; l1 < l; l1++)
				printf(" ");
			pos.X += l + 1;
			for (b = 1; b < k; b++);
			while (pos.Y < n + 5 + 2 * n) {
				SetConsoleCursorPosition(hconsole, pos);
				printf("%d", a[n][j]);
				for (b = 1; b < k; b++);
				SetConsoleCursorPosition(hconsole, pos);
				for (l1 = 0; l1 < l; l1++)
					printf(" ");
				pos.Y += 1;
			}
			pos.Y -= 1;
			pos.X -= l + 1;
			SetConsoleCursorPosition(hconsole, pos);
			printf("%d", a[n][j]);
		}
		if (_kbhit() != 0)
			break;
	}
	pos.X = 0;
	pos.Y += 3;
	SetConsoleCursorPosition(hconsole, pos);
	for (i = 1; i < n + 1; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}