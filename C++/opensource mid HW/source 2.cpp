//소프트웨어학부 2016317028 이유상
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{

	ifstream file(argv[1]);
	string str;

	int count = 0;

	while (!file.eof()) {
		int found = 0;

		getline(file, str);

		//		str.find()를 사용하여 단어를 찾는다.
		while (str.find(argv[2], found) != string::npos)
		{
			count++;
			found = str.find(argv[2], found) + 1;
		}
	}

	file.close();

	cout << "찾는 단어 " << argv[2] << "는 " << count << "개 입니다.";

	return 0;
}
