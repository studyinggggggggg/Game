#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

void pt_L(int* a) {
	for (int i = 0; i < 25; i++) {
		if (a[i] == INT_MAX) {
			cout << "*";
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

bool cor(int* a) {
	for (int i = 0; i < 24; i++) {
		if (a[i] == i + 1) {
		}
		else {
			return false;
		}

	}
	return true;
}

void push(char a, int* b) {
	int star, temt;
	for (int i = 0; i < 25; i++) {
		if (b[i] == INT_MAX) {
			star = i;
			break;
		}
	}

	if (a == 'a') {
		if (star % 5 == 0) {
			temt = b[star];
			b[star] = b[star + 4];
			b[star + 4] = temt;
		}
		else {
			temt = b[star];
			b[star] = b[star - 1];
			b[star - 1] = temt;
		}
	}

	else if (a == 'w') {
		if (star < 5) {
			temt = b[star];
			b[star] = b[star + 20];
			b[star + 20] = temt;
		}
		else {
			temt = b[star];
			b[star] = b[star - 5];
			b[star - 5] = temt;
		}
	}

	else if (a == 'd') {
		if (star % 5 == 4) {
			temt = b[star];
			b[star] = b[star - 4];
			b[star - 4] = temt;
		}
		else {
			temt = b[star];
			b[star] = b[star + 1];
			b[star + 1] = temt;
		}
	}

	else if (a == 's') {
		if (star >= 20) {
			temt = b[star];
			b[star] = b[star - 20];
			b[star - 20] = temt;
		}
		else {
			temt = b[star];
			b[star] = b[star + 5];
			b[star + 5] = temt;
		}
	}
}



int main() {
	srand((unsigned int)time(0));

	int L[25] = {};
	L[24] = INT_MAX;

	for (int i = 0; i < 24; i++) {
		L[i] = i + 1;
	}

	int itempt, idx1, idx2;

	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		itempt = L[idx1];
		L[idx1] = L[idx2];
		L[idx2] = itempt;
	}

	while (true) {
		pt_L(L);
		if (cor(L) == true) {
			break;
		}
		char a = _getch();
		push(a, L);
		system("cls");

	}
	cout << "³¡³µ½À´Ï´Ù.";
}
