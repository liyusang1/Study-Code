//2016317028 소프트웨어학부 이유상
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
	mbstowcs(text1, argv[1], strlen(argv[1]) + 1); //char 를 LPCWSTR로 바꾸는 코드 , URLDownloadToFile의 인자로 LPCWSTR을 넣어야 하기때문에 변환이 필요
	LPCWSTR test = text1;
	
	check = URLDownloadToFile(NULL,test,
		L"origin.txt", 0, 0);

	if (SUCCEEDED(check))
		cout << "다운로드에 성공하였습니다." << endl;
	else
		cout << "다운로드에 실패하였습니다." << endl;

	string fileName;
	cout << "생성할 파일의 이름을 입력하세요 (ex : 1342-0.txt) : ";
	cin >> fileName;
	
		
	string str;
	ifstream file("origin.txt");
	ofstream ofile(fileName);
	while (file) {
		getline(file, str);
		transform(str.begin(), str.end(), str.begin(), ::toupper); //다운받은 문서를 모두 대문자로 변환하는 코드 
		ofile << str<<endl;	
	} 
	file.close();
	ofile.close();

	remove("origin.txt");

	return 0;
}
