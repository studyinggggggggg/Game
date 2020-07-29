#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

void show(int* a) {
	for (int i = 0; i < 25; i++) {
		if (a[i] == INT_MAX) {
			cout << '*';
		}
		else {
			cout << a[i];
		}
		if (i % 5 == 4) {
			cout << '\n';
		}
		else {
			cout << '\t';
		}
	}
}

void checking(int a, int* b) {
	for (int i = 0; i < 25; i++) {
		if (b[i] == a) {
			b[i] = INT_MAX;
			break;
		}
	}
}

int bingo_check(int* a) {
	int bingo_number = 0;
	for (int i = 0; i < 5; i++) {
		int check = 0;
		for (int j = 0; j < 5; j++) {
			if (a[i * 5] == INT_MAX and a[i * 5 + j] == INT_MAX) {
				check++;
			}
			else {
				break;
			}
		}
		if (check == 5) {
			bingo_number++;
		}
	}

	for (int i = 0; i < 5; i++) {
		int check = 0;
		for (int j = 0; j < 5; j++) {
			if (a[i] == INT_MAX and a[j * 5 + i] == INT_MAX) {
				check++;
			}
			else {
				break;
			}
		}
		if (check == 5) {
			bingo_number++;
		}
	}
	int check = 0;
	for (int i = 0; i < 5; i++) {
		if (a[i*6] == INT_MAX) {
			check++;
		}
	}
	if (check == 5) {
		bingo_number++;
	}

	check = 0;
	for (int i = 1; i <= 5; i++) {
		if (a[i * 4] == INT_MAX) {
			check++;
		}
	}
	if (check == 5) {
		bingo_number++;
	}

	return bingo_number;
}

int main() {
	srand((unsigned int)time(0));

	int bingo[25] = {};

	for (int i = 0; i < 25; i++) {
		bingo[i] = i + 1;
	}

	int tempt, idx1, idx2;

	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		tempt = bingo[idx1];
		bingo[idx1] = bingo[idx2];
		bingo[idx2] = tempt;
	}

	show(bingo);

	while (true) {
		int bin = bingo_check(bingo);
		cout << '\n' << bin << "빙고!";
		if (bin == 5) {
			break;
		}
		else {
			int a;
			cout << '\n' << "숫자를 입력해주세요 : ";

			cin >> a;

			checking(a,bingo);
			system("cls"); 
			show(bingo);
		}
	}
	cout << '\n' << "END";
}
