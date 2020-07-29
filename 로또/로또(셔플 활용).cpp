#include <iostream>
#include <time.h>
using namespace std;

//Lotto Program
int main() {

	int Lotto[45] = {};
	srand((unsigned int)time(0));

	for (int i = 0; i < 45; i++) {
		Lotto[i] = i + 1;
	}

	int itempt, idx1, idx2;

	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 45 + 1;
		idx2 = rand() % 45 + 1;

		itempt = Lotto[idx1];
		Lotto[idx1] = Lotto[idx2];
		Lotto[idx2] = itempt;
	}

	for (int i = 0; i < 5; i++) {
		cout << Lotto[i] << " ";
	}
}
