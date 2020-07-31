#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

// 빙고게임의 랜덤 배열을 만들어주는 단계.
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

// 빙고게임 보여주기 창.
void show(int* a, int* b, int c) {
	cout << "==========유저==========" << endl;
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

	if(c == 0 or c == 1){ //1일 경우에는 easy모드 이므로 컴퓨터의 빙고판을 그대로 출력
		cout << "==========컴퓨터==========" << endl;
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

	else if(c == 2 ){ // 2일 경우에는 hard모드 이므로 컴퓨터의 빙고판을 별표로 가려서 표시.
		cout << "==========컴퓨터==========" << endl;
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

//몇개의 빙고가 완성되었는지 확인해주는 함수 
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

// 입력받는 숫자 빙고 체크하기.
void input_number(int a, int* b) {
	for (int i = 0; i < 25; i++) {
		if (b[i] == a) {
			b[i] = INT_MAX;
			break;
		}
	}
}

// 입력받은 값을 확인하여서 중복된 숫자인지 체크하는 함수.
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
	int mode, user_number, pc_number ,turn = 0, count = 0; // 모드 선택 , 빙고 숫자 , turn = 0 은 플레이어 턴 turn = 1은 컴퓨터 턴 , count는 save함수에서 여태까지 입력받은 숫자의 개수를 기록,.
	int save[25] = {}; // 게임간 입력받은 숫자의 값을 기록.

	int user[25] = {}; // user의 빙고 배열.
	make_bingo(user); //user 빙고 생성.

	int cpt[25] = {}; // computer의 빙고 배열.
	make_bingo(cpt); // computer의 빙고 생성.

	int star_num[12]; // 가로 5개 세로 5개 대각선 2개 총 12개에 선에서 별의 개수를 입력받는다.

	cout << "모드를 선택해 주세요. [0 : very easy /1 : easy / 2 : hard ] : " << endl; // 모드 입력받기 위해 알림말 표시.
	cin >> mode; //모드를 입력받는다.
	
	system("cls"); //화면 초기화

	while (true) {
		srand((unsigned int)time(0));

		zero(star_num);

		int bingo_num1, bingo_num2; //1은 유저 2는 피씨
		show(user, cpt, mode);
		bingo_num1 = bingo_check(user, star_num);
		bingo_num2 = bingo_check(cpt, star_num);
		if (bingo_num1 == 5 or bingo_num2 == 5) { // 상대 그리고 플레리어의 빙고 숫자를 체크하여 승패를 결정. 
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
			if (turn == 0) {				//turn = 0 일 경우에는 플레이어가 숫자를 부르는 턴.
				cout << "숫자입력 [1 ~ 25] : " << endl;
				while (true) {			// 입력받은 숫자가 중복된 숫자인지 파악하기 위한 loop구조. 중복된 값이 나오지 않을 떄 까지 반복입력.
					cin >> user_number;
					if (save_check(save, count, user_number) == 1) { 
						cout << "중복된 숫자입니다, 숫자입력 [1 ~ 25] : " << endl;
					}
					else {
						break;
					}
				}
				
				input_number(user_number, user);	// 입력받은 값을 빙고판과 비교하여 같은 숫자를 지우는 과정
				input_number(user_number, cpt);

				turn = 1;	// 본인 턴이 끝났으므로 상대방 턴으로 넘기기.
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
						pc_number = rand() % 25 + 1; // 1부터 25까지 랜덤 숫자 출력
						if (save_check(save, count, pc_number) == 1) { //중복 체크 과정. turn = 0 일경우 과정과 동일.
						}
						else {
							break;
						}
					}
				}
				
				cout << "pc는 " << pc_number << " 를 말했습니다." << endl; // 플레이어에게 피시가 어떤 숫자를 골랐는지 표시.,
				Sleep(1000); //1000 = 1초의 시간을 주어 214번 줄의 코드가 1초동안 창에 표시되게 하기 위함.
				input_number(pc_number, user);
				input_number(pc_number, cpt);

				turn = 0; 
				save[count] = user_number;
				count++;
			}
			system("cls"); // 화면 지우기/
		}
		
	}
	cout << endl << "END!"; //게임 종료
}
