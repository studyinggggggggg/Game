#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

// ��������� ���� �迭�� ������ִ� �ܰ�.
void make_bingo(int* bingo) {
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
}

// ������� �����ֱ� â.
void show(int* a, int* b, int c) {
	cout << "==========����==========" << endl;
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

	if(c == 1){
		cout << "==========��ǻ��==========" << endl;
		for (int i = 0; i < 25; i++) {
			if (b[i] == INT_MAX) {
				cout << '*';
			}
			else {
				cout << b[i];
			}
			if (i % 5 == 4) {
				cout << '\n';
			}
			else {
				cout << '\t';
			}
		}
	}

	else if(c == 2){
		cout << "==========��ǻ��==========" << endl;
		for (int i = 0; i < 25; i++) {
			cout << "*";
			if (i % 5 == 4) {
				cout << '\n';
			}
			else {
				cout << '\t';
			}
		}
	}
}

//��� ���� �ϼ��Ǿ����� Ȯ�����ִ� �Լ� 
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
		if (a[i * 6] == INT_MAX) {
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

// �Է¹޴� ���� ���� üũ�ϱ�.
void input_number(int a, int* b) {
	for (int i = 0; i < 25; i++) {
		if (b[i] == a) {
			b[i] = INT_MAX;
			break;
		}
	}
}

int save_check(int *a, int b, int c) {
	for (int i = 0; i < b; i++) {
		if (a[i] == c) {
			return 1;
		}
	}
	return 2;
}

int main() {
	int mode, user_number, pc_number ,turn = 0, count = 0; // ��� ���� , ���� ���� 
	int save[25] = {};

	int user[25] = {}; // user�� ���� �迭.
	make_bingo(user); //user ���� ����.

	int cpt[25] = {}; // computer�� ���� �迭.
	make_bingo(cpt); // computer�� ���� ����.

	cout << "��带 ������ �ּ���. [1 : easy / 2 : hard ] : " << endl; // ��� �Է¹ޱ� ���� �˸��� ǥ��.
	cin >> mode; //��带 �Է¹޴´�.
	
	system("cls"); //ȭ�� �ʱ�ȭ

	while (true) {
		srand((unsigned int)time(0));

		int bingo_num1, bingo_num2; //1�� ���� 2�� �Ǿ�
		show(user, cpt, mode);
		bingo_num1 = bingo_check(user);
		bingo_num2 = bingo_check(cpt);
		if (bingo_num1 == 5 or bingo_num2 == 5) {
			if (bingo_num1 == 5) {
				cout << "you win!!";
				break;
			}
			else if (bingo_num1 == 5 and bingo_num2 == 5) {
				cout << " draw~";
				break;
			}
			else {
				cout << "you lose~~";
				break;
			}
		}
		else {
			if (turn == 0) {
				cout << "�����Է� [1 ~ 25] : " << endl;
				while (true) {
					cin >> user_number;
					if (save_check(save, count, user_number) == 1) {
						cout << "�ߺ��� �����Դϴ�, �����Է� [1 ~ 25] : " << endl;
					}
					else {
						break;
					}
				}
				
				input_number(user_number, user);
				input_number(user_number, cpt);

				turn = 1;
				save[count] = user_number;
				count++;
			}
			else if (turn == 1) {
				while (true) {
					pc_number = rand() % 25 + 1;
					if (save_check(save, count, pc_number) == 1) {
					}
					else {
						break;
					}
				}
				
				cout << "pc�� " << pc_number << " �� ���߽��ϴ�." << endl;
				Sleep(1000);
				input_number(pc_number, user);
				input_number(pc_number, cpt);

				turn = 0;
				save[count] = user_number;
				count++;
			}
			system("cls");
		}
		
	}
	cout << endl << "END!";
}
