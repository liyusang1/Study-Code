//����Ʈ�����к� 2016317028 ������
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

		//		str.find()�� ����Ͽ� �ܾ ã�´�.
		while (str.find(argv[2], found) != string::npos)
		{
			count++;
			found = str.find(argv[2], found) + 1;
		}
	}

	file.close();

	cout << "ã�� �ܾ� " << argv[2] << "�� " << count << "�� �Դϴ�.";

	return 0;
}
