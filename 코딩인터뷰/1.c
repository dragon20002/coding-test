#include <stdio.h>
#include <stdlib.h>

int solution1() {
	char s[1000];
	char ascii[129] = { 0, };
	char* c;

	scanf("%s", s);

	for (c = s; *c != '\0'; c++) {
		if (ascii[*c])
			return 1;
		ascii[*c] = 1;
	}
	return 0;
}

int solution2() {
	char s1[1000], s2[1000];
	char ascii[129] = { 0, };
	char* c;
	int i;

	scanf("%s %s", s1, s2);

//	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
//		ascii[s1[i]]++;
//		ascii[s2[i]]--;
//	}
	for (c = s1; *c != '\0'; c++)
		ascii[*c]++;

	for (c = s2; *c != '\0'; c++)
		ascii[*c]--;

	for (i = 0; i < 129; i++)
		if (ascii[i])
			return 0;

	return 1;
}

char* solution3(char* str, int size) {
	char* s = (char*)malloc(size * 2);
	int i = 0;
	char* c;

	for (c = str; *c != '\0'; c++) {
		if (*c == ' ') {
			s[i++] = '%';
			s[i++] = '2';
			s[i++] = '0';
		}
		else
			s[i++] = *c;
	}
	s[i] = '\0';

	return s;
}

#define SWAP(x, y) { int t=x; x=y; y=t; }

void solution4(int img[][2], int n) {
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n / 2; j++) {
			SWAP(img[i][j], img[i][n - j - 1]);
		}
	}

	for (i = 0; i < n / 2; i++) {
		for (j = 0; j < n / 2; j++) {
			SWAP(img[i][j], img[n - i - 1][n - j - 1]);
		}
	}
}

int main() {
	//printf("%d\n", solution1());

	//printf("%d\n", solution2());

	//printf("%s\n", solution3("Mr John Smith", 13));

	int img[][2] = { {1, 2}, {3, 4} };
	int i, j;

	solution4(img, 2);

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("%d ", img[i][j]);
		}
		printf("\n");
	}

	getch();

	return 0;
}