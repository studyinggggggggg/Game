#include <iostream>
#define NAME_SIZE  32
using namespace std;

/*
구조체 : 관련있는 변수들을 모아서 하나의 새로운 타입을 만들어주는 기능
사용자 정의의 변수 타입
형태 : struct 구조체명 {}; 의 형태로 구성된다.
배열과 구조체의 공통점 : 
1. 데이터의 집합.
2. 연속된 메모리 블럭에 할당된다
*/

struct _tagStudent {
	
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main() {
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};

	// 구조체 멤버에 접근할떄는 .을 이용해서 접근
	// 문자열을 배열에 넣어줄 떄는 단순 대입으로는 불가능
	// strcpy_s 라는 함수를 이용해서 문자열을 복사해 주여야 한다.
	strcpy_s(tStudent.strName, "홍길동");
	tStudent.iKor = 100;
	tStudent.strName[0] = 'a';
	tStudent.strName[1] = 'b';

	cout << "이름 길이 : " << strlen(tStudent.strName) << endl;

	// strcat_s 함수는 문자열을 붙여주는 기능이다.
	// strcat_s(tStudent.strName, "안녕하세요.");
	
	// strcmp 함수는 두 문자열을 비교하여 같을 경우 0을 반환하고 다를경우 다른 값을 반환
	
	char 

	if (strcmp(tStudent.strName, a) == 0) {
		cout << "존재하는 사람입니다.";
	}
	else {
		cout << "존재하지 않은 사람입니다.";
	}
	


	cout << "이름 : " << tStudent.strName << endl;
	cout << "학번 : " << tStudent.iNumber << endl;
	cout << "국어 : " << tStudent.iKor << endl;
	cout << "영어 : " << tStudent.iEng << endl;
	cout << "수학 : " << tStudent.iMath << endl;
	cout << "총점 : " << tStudent.iTotal << endl;
	cout << "평균 : " << tStudent.fAvg << endl;

	return 0;
}