//����Ʈ�����к� ������
//main function
#include "MyIntVector.h"


int main() {

	MyIntVector vec1(20); //Capacity�� 20�� vec1����
	vec1.push_back(55);   //vec1�� data �迭�� 55�߰�
	vec1.push_back(12);   //vec1�� data �迭�� 12�߰�
	vec1.push_back(26);   //vec1�� data �迭�� 26�߰�
	vec1.check();         //vec1�� data �迭�� ��� �� Ȯ��
	cout <<vec1[2] << endl;  //vec1�� data[2] �� Ȯ��
	cout <<vec1[1] << endl;  //vec1�� data[1] �� Ȯ��
	vec1.pop_back();  //vec1�� ������ data �� ����
	vec1.check();
	vec1.clear();    //vec1�� data�迭�� �ִ� ��� �� ����
	vec1.check();    
	if (vec1.is_empty())  //vec1�� data�迭�� ����ִ��� Ȯ�� ���̸� true��ȯ
		cout << "element�� �����ϴ�." << endl;
	cout << "# vec1�� size : " << vec1.size() << endl;
	cout << "# vec1�� capacity : " << vec1.capacity() << endl;
	vec1.reserve(5);  //vec1�� capacity�� 5�� ����
	cout << "# vec1�� capacity : " << vec1.capacity() << endl;
	vec1.push_back(312); //vec1�� data �迭�� 312�߰�
	cout << "# vec1�� size : " << vec1.size() << endl;

	vec1.push_back(312);
	vec1.push_back(253);
	vec1.check();
	vec1(5);   //vec1�� element�� ��� ���� 5�� �ٲ�
	vec1.check();
	MyIntVector vec2;
	vec2.push_back(325);
	vec2.push_back(5212);
	vec2.push_back(512);
	vec2(5);
	if (vec1 == vec2)
		cout << "#vec1�� vec2�� ��� element�� �����ϴ�" << endl;
	cout << "# vec1�� vec2�� elements���� ���� �� : " << vec1 * vec2 << endl;

	MyIntVector vec3 = vec1;  //vec1�� �Ȱ��� vec3Ŭ���� ����
	cout << "#vec3�� element : ";
	vec3.check(); 
	-vec3;     //vec3�� element�� ��� ���� ���밪�� �ݴ�� ��
	vec3.check();
	vec1=vec1 - vec3;  //vec1�� element������ vec3�� element���� ��
	vec1.check();
	MyIntVector vec4 = vec1 + vec2;  //vec1�� vec2�� element���� ���� vec4 ����
	vec4.check();
	vec4 += vec1;    //vec4�� element�ڿ� vec1�� ��� element�� ������
	vec4.check();
	MyIntVector vec5;
	vec5.push_back(5);
	vec5.push_back(6);
	vec5.push_back(7);
	MyIntVector vec6;
	vec6.push_back(4);
	vec5.push_back(2);
	vec5 = vec6;
	if (vec5 == vec6)
		cout << "true" << endl;


	
	return 0;
}