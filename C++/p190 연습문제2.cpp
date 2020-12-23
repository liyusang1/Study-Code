#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>

using std::cout;
using std::cin;;
using std::endl;

class COMP_POS
{
public:
	enum
	{
		CLERK = 1, SENIOR = 2, ASSIST = 3, MANAGER = 4
	};
	COMP_POS(int x);
};



COMP_POS ::COMP_POS(int x)
{
	switch (x)
	{
	case 1:
		cout << "직급 : 사원" << endl;
		break;
	case 2:
		cout << "직급 : 주임" << endl;
		break;
	case 3:
		cout << "직급 : 대리" << endl;
		break;
	case 4:
		cout << "직급 : 과장" << endl;
		break;
	}
}


class NameCard
{
	char *name;
	char *company;
	char *tel;
	int level;

public:
	NameCard(const char* getname, const char* getcompany, const char* gettel,int x);
	~NameCard();
	void ShowNameCardInfo();
};



NameCard::NameCard(const char* getname, const char* getcompany, const char* gettel,int x)
{
	int len = strlen(getname) + 1;
	name = new char[len];
	strcpy(name, getname);

	len = strlen(getcompany) + 1;
	company = new char[len];
	strcpy(company, getcompany);

	len = strlen(gettel) + 1;
	tel = new char[len];
	strcpy(tel, gettel);

	level = x;
}

NameCard::~NameCard()
{
		delete[]name;
		delete[]company;
		delete[]tel;
}

void NameCard::ShowNameCardInfo()
{
	cout << "이름 :" << name << endl;
	cout << "회사 :" << company << endl;
	cout << "전화번호 :" << tel << endl;	
	COMP_POS::COMP_POS(level);
	cout << endl;
}



int main()
{
	NameCard manClerk("lee", "abcCOMPANY", "010-2222-3333", COMP_POS::CLERK);
	NameCard manSenior("kim", "NAVER", "010-1234-5678", COMP_POS::SENIOR);
	NameCard manAssist("park", "KAKAO", "010-5678-3231", COMP_POS::ASSIST);
	NameCard manManager("yoon", "GOOGLE", "010-1212-8282", COMP_POS::MANAGER);

	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	manManager.ShowNameCardInfo();


	return 0;
}