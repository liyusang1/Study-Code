//소프트웨어학부 이유상
#include <iostream>
#include <stack>
#include <cstring>
#include <fstream>
#include <string>
#define MAX_LEN 3

//testcase (a@b#c)&b , (b#c)}&(a#b@b), {c#b@(a@a&b)}@(a#a), (a&b#(a@c@b))#[(c&b)@{c&a#c}@b]

using namespace::std;

void makeOperation(); 
void calculate(string calculate);
bool check(string calculate);
void makePostfix(string calculate, char* buf);
void answer(char *answer, int length);

char operation1[MAX_LEN][MAX_LEN];
char operation2[MAX_LEN][MAX_LEN];
char operation3[MAX_LEN][MAX_LEN];

int main() {

	makeOperation();
	string tempInput;
	cout << "input : " << endl;

	while (1) {
		cin >> tempInput;
		if (tempInput == "EOI")
			break;
		calculate(tempInput);
	}

	cout << "프로그램 종료. " << endl;

	return 0;
}

void makeOperation() {  //operation1=@,  operation2=#, operation3=&

	ifstream operations;
	operations.open("operations.txt");
	char character;

	operations >> character;
	for (int i = 0; i < MAX_LEN; i++) {
		for (int j = 0; j < MAX_LEN; j++) {
			operations >> character;
			operation1[i][j] = character;
		}
	}

	operations >> character;
	for (int i = 0; i < MAX_LEN; i++) {
		for (int j = 0; j < MAX_LEN; j++) {
			operations >> character;
			operation2[i][j] = character;
		}
	}

	operations >> character;
	for (int i = 0; i < MAX_LEN; i++) {
		for (int j = 0; j < MAX_LEN; j++) {
			operations >> character;
			operation3[i][j] = character;
		}
	}
	operations.close();
}

void calculate(string temp) {

	if (check(temp) == false) {  //괄호 검사
		cout << "# Error !! #" << endl;
	}

	else {
		char* buf = new char[temp.length()]; //동적할당으로 postfix로 담을 공간 생성
		makePostfix(temp, buf); //buf에 postfix로 변경한 식 담음.
		answer(buf,(int)strlen(buf)); //postfix로 변경한 식 계산.
		delete []buf;
	}
}

bool check(string calculate) {

	stack<char> check;
	char check_right;
	int size = (int)calculate.size();

	for (int i = 0; i < size; i++) {

		if (calculate[i] == '[' || calculate[i] == '{' || calculate[i] == '(')
			check.push(calculate[i]);
			
		if (calculate[i] == ']' || calculate[i] == '}' || calculate[i] == ')') {

			if (check.empty())
				return false;

			if (calculate[i] == ')')
				check_right = '(';

			else if (calculate[i] == ']')
				check_right = '[';

			else if (calculate[i] == '}')
				check_right = '{';

			if (check.top() != check_right)
				return false;

			check.pop();
		}
	}
	if (check.empty())
		return true;
	else
		return false;
}

void makePostfix(string calculate, char* buf) {
	stack<char> checkStack;
	char currentPos;
	char check_right;
	int size = (int)calculate.length();
	int iter = 0;

	for (int i = 0; i < size; i++) {
		currentPos = calculate[i];
		if (currentPos == '(' || currentPos == '{' || currentPos == '[')
			checkStack.push(currentPos);

		else if (currentPos == 'a' || currentPos == 'b' || currentPos == 'c') {
			buf[iter] = currentPos;
			iter++;
		}

		else if (currentPos == '@' || currentPos == '#' || currentPos == '&') {
			if (checkStack.empty() || checkStack.top() == '('
				|| checkStack.top() == '{' || checkStack.top() == '[') {
				checkStack.push(currentPos);
			}
			else if (currentPos == '&') {         
				if (checkStack.top() == '&') {
					buf[iter] = currentPos;
					iter++;
					checkStack.pop();
					checkStack.push(currentPos);
				}
				else checkStack.push(currentPos);
			}
			else {
				buf[iter] = checkStack.top();
				iter++;
				checkStack.pop();
				checkStack.push(currentPos);
			}
		}
		else if (currentPos == ')' || currentPos == '}' || currentPos == ']') {

			if (currentPos == ')')
				check_right = '(';

			else if (currentPos == '}')
				check_right = '{';

			else if (currentPos == ']')
				check_right = '[';

			while (1) {
				if ((char)checkStack.top() == check_right) {
					checkStack.pop();
					break;
				}
				buf[iter] = checkStack.top();
				iter++;
				checkStack.pop();
			}
		}
	}
	if (checkStack.empty())
		return;

	while (checkStack.empty() != true) {
		buf[iter] = checkStack.top();
		checkStack.pop();
		iter++;
	}
}

void answer(char* answer, int length) {
	stack<char>calculate;
	char currentPos;
	int fir, snd;

	for (int i = 0; i < length; i++) {
		currentPos = answer[i];

		if (currentPos == 'a' || currentPos == 'b' || currentPos == 'c') {
			calculate.push(currentPos);
		}

		else if (currentPos == '@' || currentPos == '#' || currentPos == '&') {
			if (calculate.top() == 'a')
				snd = 0;
			else if (calculate.top() == 'b')
				snd = 1;
			else if (calculate.top() == 'c')
				snd = 2;
			calculate.pop();

			if (calculate.top() == 'a')
				fir = 0;
			else if (calculate.top() == 'b')
				fir = 1;
			else if (calculate.top() == 'c')
				fir = 2;
			calculate.pop();

			if (currentPos == '@')
				calculate.push(operation1[fir][snd]);

			else if (currentPos == '#')
				calculate.push(operation2[fir][snd]);

			else if (currentPos == '&')
				calculate.push(operation3[fir][snd]);
		}
	}
	cout << calculate.top() << endl;
}


