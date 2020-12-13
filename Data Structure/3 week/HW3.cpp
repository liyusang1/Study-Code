#include <string>
#include <sstream>
#include <iostream>
#include <unordered_map>
//¿Ã¿ØªÛ

using namespace std;

int main() {

	string str;
	unordered_map<string, int> findPassword;
	string word;
	int count;

	cin >> count;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		word = str.substr(i, count);
		if (word.length() < count)
			break;
		findPassword[word]++;
	}

	unordered_map<string, int>::iterator p;
	int max = findPassword.begin()->second;
	string maxString;

	for (p = findPassword.begin(); p != findPassword.end(); p++) {
		if (p->second > max) {
			max = p->second;
			maxString = p->first;
		}

		//cout << p->first << " " << p->second << endl;   
	}

	cout << "Max Value : " << maxString << endl;

	return 0;
}