#include <iostream>
using namespace std;

#define NAME_SIZE 32
#define STUDENT_SIZE 10
#define PHONE_SIZE 14
#define ADDRESS_SIZE 128

struct _tagStudent
{
	char strName[NAME_SIZE];
	char strAddress[ADDRESS_SIZE];
	char strPhoneNumber[PHONE_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};


int main() {
	_tagStudent tStudentArr[STUDENT_SIZE] = {};
	int iStudentNumber = 1;
	int iStudentCount = 0;
	char strName[NAME_SIZE] = {};

	while (true) {
		system("cls");


		cout << "1. �л����" << endl;
		cout << "2. �л�����" << endl;
		cout << "3. �л�Ž��" << endl;
		cout << "4. �л����" << endl;
		cout << "5. ����" << endl;
		cout << "�޴��� �����ϼ���." << endl;
		int iMenu;
		cin >> iMenu;
		
		// cin ���� ó���� �������۸� �����ְ� �Է¹��ۿ� �Է��� ���� ������ �� ���� ������ �־��ش�.
		// �׸��� \m�� ���� �����Ƿ� ���۸� ��ȸ�� �����ش�.
		// ���� : �ӽ���������̴�.

		if (cin.fail()) {
			// ���� ���� ����ֱ�
			cin.clear();
			// \n�� ���������Ƿ� ���������.
			// ù�������� �˻��ϰ��� �ϴ� ���� ũ�⸦ ������(�˳��ϰ� 1024��)
			// �ι�°�� ã�����ϴ� ���ڸ� �־��ش�.
			// �׷��� �Է¹��� ó������ \n�� �ִ� ������ ã�Ƽ� �� �κ��� ��� ����
			// �Է¹ް� ���ش�.
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MENU_EXIT) {
			break;
		}

		switch (iMenu) {
		case MENU_INSERT:
			system("cls");
			cout << "======================== �л��߰� ========================" << endl;
			
			// ��ϵ� �л��� ����� �� �ִ� �ִ�ġ �� ���.
			if (iStudentCount == STUDENT_SIZE) {
				break;
			}

			// �л����� �߰��Ѵ�. �й�, �̸�, �ּ�, ��ȭ��ȣ
			// ����, ���� ���� ������ �Է¹ް� �й�, ���� ����� ������ ���� ���.
			cout << "�̸� : ";
			cin >> tStudentArr[iStudentCount].strName;
			
			// ���� ���ڸ� �Է¹����� ������ ����Űó�� �ν��Ͽ� ���� ������ ������ �Ѵ�.
			// �׷��⿡ getline�� �̿��Ͽ� �����Ⱥ�����ŭ�� ���ڿ��� �νĹ޴´�. 
			// �̶� cin �� cin.getline�� ���̾��� cin.getline�� �����ϰ� �Ѿ�� ��찡 �ִ�.
			// �̷� ��� �Ʒ��� �ڵ带 ����ϸ� �ȴ�.
			cin.ignore(1024, '\n');

			cout << "�ּ� : ";
			cin.getline(tStudentArr[iStudentCount].strAddress , ADDRESS_SIZE);

			cout << "��ȭ��ȣ : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);
			
			while (true) {
				cout << "���� : ";
				cin >> tStudentArr[iStudentCount].iKor;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "������ ���ڸ� �Է����ּ���." << endl;
					continue;
				}
				else {
					break;
				}
			}

			while (true) {
				cout << "���� : ";
				cin >> tStudentArr[iStudentCount].iEng;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "������ ���ڸ� �Է����ּ���." << endl;
					continue;
				}
				else {
					break;
				}
			}
			
			while (true) {
				cout << "���� : ";
				cin >> tStudentArr[iStudentCount].iMath;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "������ ���ڸ� �Է����ּ���." << endl;
					continue;
				}
				else {
					break;
				}
			}

			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].fAvg =
				tStudentArr[iStudentCount].iTotal / 3.f;

			tStudentArr[iStudentCount].iNumber = iStudentNumber;
			iStudentCount++;
			iStudentNumber++;

			cout << "�л� �߰� �Ϸ� " << endl;
			break;

		case MENU_DELETE:
			system("cls");

			cout << "======================== �л����� ========================" << endl;
			cin.ignore(1024, '\n');
			cout << "Ž���� �̸��� �Է��ϼ���. : ";
			cin.getline(strName, NAME_SIZE);
			for (int i = 0; i < iStudentCount; i++) {
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					for (int j = i; j < iStudentCount - i; j++) {
						tStudentArr[i] = tStudentArr[i + 1];
					}
				}
				iStudentCount--;
			}

			break;

		case MENU_SEARCH:
			system("cls");

			cout << "======================== �л�Ž�� ========================" << endl;
			cin.ignore(1024, '\n');
			cout << "Ž���� �̸��� �Է��ϼ���. : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < iStudentCount; i++) {
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					cout << "�̸� : " << tStudentArr[i].strName << endl;
					cout << "��ȭ��ȣ : " << tStudentArr[i].strPhoneNumber << endl;
					cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
					cout << "�й� : " << tStudentArr[i].iNumber << endl;
					cout << "���� : " << tStudentArr[i].iEng << endl;
					cout << "���� : " << tStudentArr[i].iEng << endl;
					cout << "���� : " << tStudentArr[i].iMath << endl;
					cout << "���� : " << tStudentArr[i].iTotal << endl;
					cout << "��� : " << tStudentArr[i].fAvg << endl;
					break;
				}
				else {
					cout << "��ϵ� �л��� �����ϴ�. " << endl;
				}

			}
			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "======================== �л���� ========================" << endl;

			// ��ϵ� �л� �� ��ŭ �ݺ��ϸ� �л������� ����Ѵ�.
			for (int i = 0; i < iStudentCount; i++) {
				cout << "�̸� : " << tStudentArr[i].strName << endl;
				cout << "��ȭ��ȣ : " << tStudentArr[i].strPhoneNumber << endl;
				cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
				cout << "�й� : " << tStudentArr[i].iNumber << endl;
				cout << "���� : " << tStudentArr[i].iEng << endl;
				cout << "���� : " << tStudentArr[i].iEng << endl;
				cout << "���� : " << tStudentArr[i].iMath << endl;
				cout << "���� : " << tStudentArr[i].iTotal << endl;
				cout << "��� : " << tStudentArr[i].fAvg << endl;

			}
			break;
		default :
			cout << "�޴��� �߸� �����߽��ϴ�." << endl;
		}
		system("pause");

	}
}