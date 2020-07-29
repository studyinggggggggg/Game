#include <iostream>
#include <time.h>
using namespace std;

//Lotto Program
int main() {

	int Lotto[5] = {};
	srand((unsigned int)time(0));

	for (int i = 0; i < 5; i++) {
		Lotto[i] = (rand() % 45 + 1);
		int j = 0;
		while (j < i) {
			if (Lotto[i] == Lotto[j]) {
				Lotto[i] = (rand() % 45 + 1);
				j = 0;
			}
			else {
				j += 1;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << Lotto[i] << " ";
	}
}