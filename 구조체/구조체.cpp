#include <iostream>
#define NAME_SIZE  32
using namespace std;

/*
����ü : �����ִ� �������� ��Ƽ� �ϳ��� ���ο� Ÿ���� ������ִ� ���
����� ������ ���� Ÿ��
���� : struct ����ü�� {}; �� ���·� �����ȴ�.
�迭�� ����ü�� ������ : 
1. �������� ����.
2. ���ӵ� �޸� ���� �Ҵ�ȴ�
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

	// ����ü ����� �����ҋ��� .�� �̿��ؼ� ����
	// ���ڿ��� �迭�� �־��� ���� �ܼ� �������δ� �Ұ���
	// strcpy_s ��� �Լ��� �̿��ؼ� ���ڿ��� ������ �ֿ��� �Ѵ�.
	strcpy_s(tStudent.strName, "ȫ�浿");
	tStudent.iKor = 100;
	tStudent.strName[0] = 'a';
	tStudent.strName[1] = 'b';

	cout << "�̸� ���� : " << strlen(tStudent.strName) << endl;

	// strcat_s �Լ��� ���ڿ��� �ٿ��ִ� ����̴�.
	// strcat_s(tStudent.strName, "�ȳ��ϼ���.");
	
	// strcmp �Լ��� �� ���ڿ��� ���Ͽ� ���� ��� 0�� ��ȯ�ϰ� �ٸ���� �ٸ� ���� ��ȯ
	
	char 

	if (strcmp(tStudent.strName, a) == 0) {
		cout << "�����ϴ� ����Դϴ�.";
	}
	else {
		cout << "�������� ���� ����Դϴ�.";
	}
	


	cout << "�̸� : " << tStudent.strName << endl;
	cout << "�й� : " << tStudent.iNumber << endl;
	cout << "���� : " << tStudent.iKor << endl;
	cout << "���� : " << tStudent.iEng << endl;
	cout << "���� : " << tStudent.iMath << endl;
	cout << "���� : " << tStudent.iTotal << endl;
	cout << "��� : " << tStudent.fAvg << endl;

	return 0;
}