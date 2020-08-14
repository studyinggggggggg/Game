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
		cout << "=============== 도서 대여 프로그램 ==============" << endl;
		cout << "1. 책 등록 " << endl;
		cout << "2. 책 대여 " << endl;
		cout << "3. 책 반납 " << endl;
		cout << "4. 책 목록 " << endl;
		cout << "5. 종료 " << endl;
		
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
				cout << "========== 도서 등록 =========="<< endl;
				cout << "책 이름 : ";
				cin.ignore(1024, '\n');
				cin.getline(rentsys[booknumber].b_name,BOOK_SIZE);
				cout << "책 대여 금액 : ";
				cin >> rentsys[booknumber].b_price;
				rentsys[booknumber].b_number = BOOKNUM;
				rentsys[booknumber].b_state = false;
				BOOKNUM++;
				booknumber++;

				while (true) {
					int er_ctin;
					cout << "계속 등록하시겠습니까? Y = (1) / N = (2)";
					cin >> er_ctin;
					if (er_ctin == 1) {
						system("cls");
						cout << "========== 도서 등록 ==========" << endl;;
						cout << "책 이름 : ";
						cin.ignore(1024, '\n');
						cin.getline(rentsys[booknumber].b_name, BOOK_SIZE);
						cout << "책 대여 금액 : ";
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
			cout << "========== 도서 대여 =========" << endl;
			cout << "대여할 책 이름을 입력해주세요. : " << endl;
			cin.ignore(1024, '\n');
			cin.getline(b_name,BOOK_SIZE);
			for (int i = 0; i < booknumber; i++) {

				if (strcmp(b_name, rentsys[i].b_name) == 0) {
					if (rentsys[i].b_state) {
						cout << "이미 대여중입니다." << endl;
					}
					else {
						cout << "대여 금액은 " << rentsys[i].b_price << "원 입니다." << endl;
						enrollll = 0;
						cout << "대여 하시겠습니까? Y = (1) / N = (2)";
						cin >> enrollll;
						if (enrollll == 1) {
							cout << "대여 완료되었습니다. ";
							rentsys[i].b_state = true;
						}
						else {
							break;
						}
					}
				}
			}
			if (enrollll ==  0) {
				cout << "존재하지 않는 도서 입니다 ." << endl;
			}
			break;

		case(BOOK_RETURN):
			system("cls");
			cout << "========== 도서 반납 =========" << endl;
			cout << "반납할 책 이름을 입력해주세요. : " << endl;
			cin.ignore(1024, '\n');
			cin.getline(b_name, BOOK_SIZE);
			for (int i = 0; i < booknumber; i++) {

				if (strcmp(b_name, rentsys[i].b_name) == 0) {
					rentsys[i].b_state = false;
					cout << "반납 완료되었습니다. ";
					enrollll = 1;
				}

			}
			if (enrollll == 0) {
				cout << "존재하지 않는 도서 입니다 ." << endl;
			}
			break;

		case(BOOK_LIST):
			system("cls");
			cout << "========== 도서 목록 =========" << endl;
			for (int i = 0; i < booknumber; i++) {
				cout << "====================================================" << endl;
				cout << "책 이름  : " << rentsys[i].b_name << endl;
				cout << "대여 금액  : " << rentsys[i].b_price << endl;
				cout << "책 번호  : " << rentsys[i].b_number << endl;
				if (rentsys[i].b_state) {
					cout << "책 대여 여부  : 대출중 " << endl;
				}
				else {
					cout << "책 대여 여부  : 대여가능 " << endl;
				}
			}
			break;

		case(END):
			return 0;

		default: 
			cout << "메뉴를 잘못 선택했습니다." << endl;
			break;
		}
		system("pause");
	}

	
}