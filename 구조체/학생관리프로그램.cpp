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


		cout << "1. 학생등록" << endl;
		cout << "2. 학생삭제" << endl;
		cout << "3. 학생탐색" << endl;
		cout << "4. 학생출력" << endl;
		cout << "5. 종료" << endl;
		cout << "메뉴를 선택하세요." << endl;
		int iMenu;
		cin >> iMenu;
		
		// cin 예외 처리는 에러버퍼를 지워주고 입력버퍼에 입력한 값을 저장해 그 값을 변수에 넣어준다.
		// 그리고 \m이 남아 있으므로 버퍼를 순회해 지워준다.
		// 버퍼 : 임시저장공간이다.

		if (cin.fail()) {
			// 에러 버퍼 비워주기
			cin.clear();
			// \n이 남아있으므로 지워줘야함.
			// 첫번쨰에는 검색하고자 하는 버퍼 크기를 지정함(넉넉하게 1024개)
			// 두번째는 찾고자하는 문자를 넣어준다.
			// 그래서 입력버퍼 처음부터 \n이 있는 곳까지 찾아서 그 부분을 모두 지워
			// 입력받게 해준다.
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MENU_EXIT) {
			break;
		}

		switch (iMenu) {
		case MENU_INSERT:
			system("cls");
			cout << "======================== 학생추가 ========================" << endl;
			
			// 등록된 학생이 등록할 수 있는 최대치 일 경우.
			if (iStudentCount == STUDENT_SIZE) {
				break;
			}

			// 학생정보 추가한다. 학번, 이름, 주소, 전화번호
			// 국어, 영어 수학 점수는 입력받고 학번, 총점 평균은 연산을 통해 계산.
			cout << "이름 : ";
			cin >> tStudentArr[iStudentCount].strName;
			
			// 공백 문자를 입력받으면 공백을 엔터키처럼 인식하여 다음 변수에 저장을 한다.
			// 그렇기에 getline을 이용하여 지정된변수만큼의 문자열을 인식받는다. 
			// 이때 cin 과 cin.getline을 같이쓰면 cin.getline을 무시하고 넘어가는 경우가 있다.
			// 이럴 경우 아래의 코드를 사용하면 된다.
			cin.ignore(1024, '\n');

			cout << "주소 : ";
			cin.getline(tStudentArr[iStudentCount].strAddress , ADDRESS_SIZE);

			cout << "전화번호 : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);
			
			while (true) {
				cout << "국어 : ";
				cin >> tStudentArr[iStudentCount].iKor;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "점수는 숫자만 입력해주세요." << endl;
					continue;
				}
				else {
					break;
				}
			}

			while (true) {
				cout << "영어 : ";
				cin >> tStudentArr[iStudentCount].iEng;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "점수는 숫자만 입력해주세요." << endl;
					continue;
				}
				else {
					break;
				}
			}
			
			while (true) {
				cout << "수학 : ";
				cin >> tStudentArr[iStudentCount].iMath;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "점수는 숫자만 입력해주세요." << endl;
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

			cout << "학생 추가 완료 " << endl;
			break;

		case MENU_DELETE:
			system("cls");

			cout << "======================== 학생삭제 ========================" << endl;
			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력하세요. : ";
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

			cout << "======================== 학생탐색 ========================" << endl;
			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력하세요. : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < iStudentCount; i++) {
				if (strcmp(tStudentArr[i].strName, strName) == 0) {
					cout << "이름 : " << tStudentArr[i].strName << endl;
					cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
					cout << "주소 : " << tStudentArr[i].strAddress << endl;
					cout << "학번 : " << tStudentArr[i].iNumber << endl;
					cout << "국어 : " << tStudentArr[i].iEng << endl;
					cout << "영어 : " << tStudentArr[i].iEng << endl;
					cout << "수학 : " << tStudentArr[i].iMath << endl;
					cout << "총점 : " << tStudentArr[i].iTotal << endl;
					cout << "평균 : " << tStudentArr[i].fAvg << endl;
					break;
				}
				else {
					cout << "등록된 학생이 없습니다. " << endl;
				}

			}
			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "======================== 학생출력 ========================" << endl;

			// 등록된 학생 수 만큼 반복하며 학생정보를 출력한다.
			for (int i = 0; i < iStudentCount; i++) {
				cout << "이름 : " << tStudentArr[i].strName << endl;
				cout << "전화번호 : " << tStudentArr[i].strPhoneNumber << endl;
				cout << "주소 : " << tStudentArr[i].strAddress << endl;
				cout << "학번 : " << tStudentArr[i].iNumber << endl;
				cout << "국어 : " << tStudentArr[i].iEng << endl;
				cout << "영어 : " << tStudentArr[i].iEng << endl;
				cout << "수학 : " << tStudentArr[i].iMath << endl;
				cout << "총점 : " << tStudentArr[i].iTotal << endl;
				cout << "평균 : " << tStudentArr[i].fAvg << endl;

			}
			break;
		default :
			cout << "메뉴를 잘못 선택했습니다." << endl;
		}
		system("pause");

	}
}