#include <iostream>
using namespace std;

#define BOOK_SIZE 32
#define B_R_SIZE 32
struct _book_rental {
	char b_name[BOOK_SIZE];
	int b_price;
	int b_number;
	bool b_state;
};

enum MENU {
	BOOK_NONE,
	BOOK_ENROLL,
	BOOK_RENT,
	BOOK_RETURN,
	BOOK_LIST,
	END
};

int main() {
	_book_rental rentsys[B_R_SIZE] = {};
	int booknumber = 0;
	int BOOKNUM = 1;
	int enrollll = 0;
	char b_name[BOOK_SIZE];
	while (true) {
		system("cls");
		cout << "=============== ���� �뿩 ���α׷� ==============" << endl;
		cout << "1. å ��� " << endl;
		cout << "2. å �뿩 " << endl;
		cout << "3. å �ݳ� " << endl;
		cout << "4. å ��� " << endl;
		cout << "5. ���� " << endl;
		
		int iMenu;
		cin >> iMenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		switch (iMenu)
		{
		case(BOOK_ENROLL):
				system("cls");
				cout << "========== ���� ��� =========="<< endl;
				cout << "å �̸� : ";
				cin.ignore(1024, '\n');
				cin.getline(rentsys[booknumber].b_name,BOOK_SIZE);
				cout << "å �뿩 �ݾ� : ";
				cin >> rentsys[booknumber].b_price;
				rentsys[booknumber].b_number = BOOKNUM;
				rentsys[booknumber].b_state = false;
				BOOKNUM++;
				booknumber++;

				while (true) {
					int er_ctin;
					cout << "��� ����Ͻðڽ��ϱ�? Y = (1) / N = (2)";
					cin >> er_ctin;
					if (er_ctin == 1) {
						system("cls");
						cout << "========== ���� ��� ==========" << endl;;
						cout << "å �̸� : ";
						cin.ignore(1024, '\n');
						cin.getline(rentsys[booknumber].b_name, BOOK_SIZE);
						cout << "å �뿩 �ݾ� : ";
						cin >> rentsys[booknumber].b_price;
						rentsys[booknumber].b_number = BOOKNUM;
						rentsys[booknumber].b_state = false;
						BOOKNUM++;
						booknumber++;
					}
					else {
						break;
					}
				}
				break;
		case(BOOK_RENT):
			system("cls");
			cout << "========== ���� �뿩 =========" << endl;
			cout << "�뿩�� å �̸��� �Է����ּ���. : " << endl;
			cin.ignore(1024, '\n');
			cin.getline(b_name,BOOK_SIZE);
			for (int i = 0; i < booknumber; i++) {

				if (strcmp(b_name, rentsys[i].b_name) == 0) {
					if (rentsys[i].b_state) {
						cout << "�̹� �뿩���Դϴ�." << endl;
					}
					else {
						cout << "�뿩 �ݾ��� " << rentsys[i].b_price << "�� �Դϴ�." << endl;
						enrollll = 0;
						cout << "�뿩 �Ͻðڽ��ϱ�? Y = (1) / N = (2)";
						cin >> enrollll;
						if (enrollll == 1) {
							cout << "�뿩 �Ϸ�Ǿ����ϴ�. ";
							rentsys[i].b_state = true;
						}
						else {
							break;
						}
					}
				}
			}
			if (enrollll ==  0) {
				cout << "�������� �ʴ� ���� �Դϴ� ." << endl;
			}
			break;

		case(BOOK_RETURN):
			system("cls");
			cout << "========== ���� �ݳ� =========" << endl;
			cout << "�ݳ��� å �̸��� �Է����ּ���. : " << endl;
			cin.ignore(1024, '\n');
			cin.getline(b_name, BOOK_SIZE);
			for (int i = 0; i < booknumber; i++) {

				if (strcmp(b_name, rentsys[i].b_name) == 0) {
					rentsys[i].b_state = false;
					cout << "�ݳ� �Ϸ�Ǿ����ϴ�. ";
					enrollll = 1;
				}

			}
			if (enrollll == 0) {
				cout << "�������� �ʴ� ���� �Դϴ� ." << endl;
			}
			break;

		case(BOOK_LIST):
			system("cls");
			cout << "========== ���� ��� =========" << endl;
			for (int i = 0; i < booknumber; i++) {
				cout << "====================================================" << endl;
				cout << "å �̸�  : " << rentsys[i].b_name << endl;
				cout << "�뿩 �ݾ�  : " << rentsys[i].b_price << endl;
				cout << "å ��ȣ  : " << rentsys[i].b_number << endl;
				if (rentsys[i].b_state) {
					cout << "å �뿩 ����  : ������ " << endl;
				}
				else {
					cout << "å �뿩 ����  : �뿩���� " << endl;
				}
			}
			break;

		case(END):
			return 0;

		default: 
			cout << "�޴��� �߸� �����߽��ϴ�." << endl;
			break;
		}
		system("pause");
	}

	
}