#include <cstdio>
#include <cstring>
using namespace std;

int sum(int n, int m) {
	int length = n * m;
	char input[50][100];

	char passcode[57];
	int index = 0;

	printf(passcode);
	printf("\n");

	int decode[8];
	for (int i = 0, k = 0; i < 56; i+=8, k++) {
		printf("passcode = %s\n", &passcode[i]);

		for (int j = 0; j < 8; j++) {
		}
		decode[k] = 1;
		printf("decode = %d\n", decode[k]);
	}
	printf("decode end\n");

	int oddsum = 0, evensum = 0;
	for (int i = 55; i >= 0; i -= 2) {
		oddsum += passcode[i] - '0';
		evensum += passcode[i - 1] - '0';
	}

	printf("%d %d\n", oddsum, evensum);

	int validsum = evensum * 3 + oddsum;

	printf("%d\n", validsum);

	if (validsum % 10) {
		int sum = 0;
		for (int i = 0; i < 8; i+=8) {
			if (!strcmp(&passcode[i], "1001100"))
				sum += 1;
			else if (!strcmp(&passcode[i], "1100100"))
				sum += 2;
			else if (!strcmp(&passcode[i], "1011110"))
				sum += 3;
			else if (!strcmp(&passcode[i], "1100010"))
				sum += 4;
			else if (!strcmp(&passcode[i], "1000110"))
				sum += 5;
			else if (!strcmp(&passcode[i], "1111010"))
				sum += 6;
			else if (!strcmp(&passcode[i], "1101110"))
				sum += 7;
			else if (!strcmp(&passcode[i], "1110110"))
				sum += 8;
			else if (!strcmp(&passcode[i], "1101000"))
				sum += 9;
		}

		return sum;
	}
	else
		return 0;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n, m;
		scanf("%d %d", &n, &m);
		printf("#%d %d\n", t, sum(n, m));
	}
}