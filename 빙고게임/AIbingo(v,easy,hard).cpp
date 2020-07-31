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

	if(c == 0 or c == 1){ //1�� ��쿡�� easy��� �̹Ƿ� ��ǻ���� �������� �״�� ���
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

	else if(c == 2 ){ // 2�� ��쿡�� hard��� �̹Ƿ� ��ǻ���� �������� ��ǥ�� ������ ǥ��.
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
int bingo_check(int* a, int*b){
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
			if (a[5 * i + j] == INT_MAX) {
				b[i]++;
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
			if (a[j * 5 + i] == INT_MAX) {
				b[i + 5]++;
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
			b[10]++;
		}
	}
	if (check == 5) {
		bingo_number++;
	}

	check = 0;
	for (int i = 1; i <= 5; i++) {
		if (a[i * 4] == INT_MAX) {
			check++;
			b[11]++;
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

// �Է¹��� ���� Ȯ���Ͽ��� �ߺ��� �������� üũ�ϴ� �Լ�.
int save_check(int *a, int b, int c) {
	for (int i = 0; i < b; i++) {
		if (a[i] == c) {
			return 1;
		}
	}
	return 2;
}

int index_return(int* a, int b) {
	if (b < 5 and b >= 0) {
		for (int j = 0; j < 5; j++) {
			if (a[5 * b + j] != INT_MAX) {
				return a[5 * b + j];
			}
		}
	}
	else if (b >= 5 and b < 10) {
		for (int j = 0; j < 5; j++) {
			if (a[5 * j + b] != INT_MAX) {
				return a[5 * j + b];
			}
		}
	}
	else if (b == 11) {
		for (int i = 0; i < 5; i++) {
			if (a[i * 6] != INT_MAX) {
				return a[i * 6];
			}
		}
	}
	else {
		for (int i = 1; i <= 5; i++) {
			if (a[i * 4] != INT_MAX) {
				return a[i * 4];
			}
		}
	}
}

void zero(int* a) {
	for (int i = 0; i < 12; i++) {
		a[i] = 0;
	}
}

int main() {
	int mode, user_number, pc_number ,turn = 0, count = 0; // ��� ���� , ���� ���� , turn = 0 �� �÷��̾� �� turn = 1�� ��ǻ�� �� , count�� save�Լ����� ���±��� �Է¹��� ������ ������ ���,.
	int save[25] = {}; // ���Ӱ� �Է¹��� ������ ���� ���.

	int user[25] = {}; // user�� ���� �迭.
	make_bingo(user); //user ���� ����.

	int cpt[25] = {}; // computer�� ���� �迭.
	make_bingo(cpt); // computer�� ���� ����.

	int star_num[12]; // ���� 5�� ���� 5�� �밢�� 2�� �� 12���� ������ ���� ������ �Է¹޴´�.

	cout << "��带 ������ �ּ���. [0 : very easy /1 : easy / 2 : hard ] : " << endl; // ��� �Է¹ޱ� ���� �˸��� ǥ��.
	cin >> mode; //��带 �Է¹޴´�.
	
	system("cls"); //ȭ�� �ʱ�ȭ

	while (true) {
		srand((unsigned int)time(0));

		zero(star_num);

		int bingo_num1, bingo_num2; //1�� ���� 2�� �Ǿ�
		show(user, cpt, mode);
		bingo_num1 = bingo_check(user, star_num);
		bingo_num2 = bingo_check(cpt, star_num);
		if (bingo_num1 == 5 or bingo_num2 == 5) { // ��� �׸��� �÷������� ���� ���ڸ� üũ�Ͽ� ���и� ����. 
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
			if (turn == 0) {				//turn = 0 �� ��쿡�� �÷��̾ ���ڸ� �θ��� ��.
				cout << "�����Է� [1 ~ 25] : " << endl;
				while (true) {			// �Է¹��� ���ڰ� �ߺ��� �������� �ľ��ϱ� ���� loop����. �ߺ��� ���� ������ ���� �� ���� �ݺ��Է�.
					cin >> user_number;
					if (save_check(save, count, user_number) == 1) { 
						cout << "�ߺ��� �����Դϴ�, �����Է� [1 ~ 25] : " << endl;
					}
					else {
						break;
					}
				}
				
				input_number(user_number, user);	// �Է¹��� ���� �����ǰ� ���Ͽ� ���� ���ڸ� ����� ����
				input_number(user_number, cpt);

				turn = 1;	// ���� ���� �������Ƿ� ���� ������ �ѱ��.
				save[count] = user_number; 
				count++;
			}
			else if (turn == 1) {
				if (mode == 2 or mode == 1) {
					zero(star_num);
					bingo_check(cpt, star_num);
					int idx ,max = 0;
					for (int i = 0; i < 12; i++) {
						//cout << star_num[i] << "\t";
						if (star_num[i] > max and star_num[i] < 5) {
							max = star_num[i];
							idx = i;
						}
					}
					pc_number = index_return(cpt, idx);

				}
				else {
					while (true) {
						pc_number = rand() % 25 + 1; // 1���� 25���� ���� ���� ���
						if (save_check(save, count, pc_number) == 1) { //�ߺ� üũ ����. turn = 0 �ϰ�� ������ ����.
						}
						else {
							break;
						}
					}
				}
				
				cout << "pc�� " << pc_number << " �� ���߽��ϴ�." << endl; // �÷��̾�� �ǽð� � ���ڸ� ������� ǥ��.,
				Sleep(1000); //1000 = 1���� �ð��� �־� 214�� ���� �ڵ尡 1�ʵ��� â�� ǥ�õǰ� �ϱ� ����.
				input_number(pc_number, user);
				input_number(pc_number, cpt);

				turn = 0; 
				save[count] = user_number;
				count++;
			}
			system("cls"); // ȭ�� �����/
		}
		
	}
	cout << endl << "END!"; //���� ����
}
