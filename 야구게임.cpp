#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand((unsigned int)time(0));

	//���� 3�� ���� ����
	cout << "���� ���ڰ� ���� �Ǿ����ϴ�..." << endl << "* * *" << endl;
	int yagu[3] = {};
	
	for (int i = 0; i < 3; i++) {
		yagu[i] = (rand() % 8 + 1);
		int j = 0;
		while (j < i) {
			if (yagu[i] == yagu[j]) {
				yagu[i] = (rand() % 8 + 1);
				j = 0;
			}
			else {
				j += 1;
			}
		}
	}
	// ������ ��
	int strike = 0, count = 0;

	while (true) {
		int ball = 0, strike = 0;
		// �Է� �ޱ�
		int ipyagu[3] = {};
		count++;
		cout <<count <<"�� ° ����!!  "<< "���� 3���� �Է����ּ���. : " << endl;
		for (int i = 0; i < 3; i++) {
			cin >> ipyagu[i];
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (yagu[i] == ipyagu[j]) {
					if (i == j) {
						strike++;
						break;
					}
					else {
						ball++;
						break;
					}
				}
			}
		}
		if (strike == 0 and ball == 0) {
			cout << "OUT!!!!" << endl;
		}
		else {
			cout << "BALL : " << ball << " - " << "STRIKE : " << strike << endl;;
		}
		if (strike == 3) {
			cout << " �������ϴ�. ������ " << yagu[0] << yagu[1] << yagu[2] << " �Դϴ�.";
			return 0;
		}
	}

	

}