//2016317028 ����Ʈ�����к� ������
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <urlmon.h>
#include <fstream>
#include <direct.h>
#include <string>
#include <algorithm>
#pragma comment(lib, "urlmon.lib")

//http://www.gutenberg.org/files/1342/1342-0.txt

using namespace std;

int main(int argc, char * argv[])
{
	DWORD check;

	wchar_t text1[30];
	mbstowcs(text1, argv[1], strlen(argv[1]) + 1); //char �� LPCWSTR�� �ٲٴ� �ڵ� , URLDownloadToFile�� ���ڷ� LPCWSTR�� �־�� �ϱ⶧���� ��ȯ�� �ʿ�
	LPCWSTR test = text1;
	
	check = URLDownloadToFile(NULL,test,
		L"origin.txt", 0, 0);

	if (SUCCEEDED(check))
		cout << "�ٿ�ε忡 �����Ͽ����ϴ�." << endl;
	else
		cout << "�ٿ�ε忡 �����Ͽ����ϴ�." << endl;

	string fileName;
	cout << "������ ������ �̸��� �Է��ϼ��� (ex : 1342-0.txt) : ";
	cin >> fileName;
	
		
	string str;
	ifstream file("origin.txt");
	ofstream ofile(fileName);
	while (file) {
		getline(file, str);
		transform(str.begin(), str.end(), str.begin(), ::toupper); //�ٿ���� ������ ��� �빮�ڷ� ��ȯ�ϴ� �ڵ� 
		ofile << str<<endl;	
	} 
	file.close();
	ofile.close();

	remove("origin.txt");

	return 0;
}
