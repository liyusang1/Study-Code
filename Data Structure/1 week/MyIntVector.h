//class documentaion & definition 
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace ::std;

class MyIntVector {

	typedef int type;
	static const size_t DEFAULT_CAPACITY = 10;

public:
	MyIntVector(size_t init_capacity=DEFAULT_CAPACITY);
	//precondition : init_capacity > 0 && int�� ����
	//postcondition : VectorŬ������ �����Ҵ� �迭ũ�⸦ init_capacity �� ��ŭ ������.

	~MyIntVector();
	//precondition : 
	//postcondition : Ŭ������ �Ҹ��� ������� data���� delete��

	MyIntVector(const MyIntVector &source);
	//precondition : ������ MyIntVector Ŭ����.
	//postcondition : source Ŭ������ �����Ͽ� ���ο� Ŭ������ ����.

	MyIntVector& operator=(const MyIntVector &source);
	//precondition : ������ MyIntVector Ŭ����.
	//postcondition : source Ŭ������ �����Ͽ� source�� �Ȱ��� ���ο� Ŭ������ ����.

	MyIntVector& operator+=(const MyIntVector &source);
	//precondition : �ٸ� Ŭ������ ������ element�� ����ִ� Ŭ����
	//postcondition : ������ Ŭ������ element�� �̾ sourceŬ������ element�� ���ٿ� ����ȴ�.

	MyIntVector operator+(const MyIntVector& source);
	//precondition : ���� Ŭ������ size�� ���� MyIntVector source Ŭ����, source Ŭ������ size�� ���� Ŭ������ size�� ���� ���� ��� �����߻�.
	//postcondition : source�� element�� ��ŭ ���� Ŭ������ element���� �����Ѵ�.

	MyIntVector operator-(const MyIntVector& source);
	//precondition : ���� Ŭ������ size�� ���� MyIntVector source Ŭ����, source Ŭ������ size�� ���� Ŭ������ size�� ���� ���� ��� �����߻�.
	//postcondition : source�� element�� ��ŭ ���� Ŭ������ element���� �����Ѵ�.

	MyIntVector& operator-();
	//precondition : 
	//postcondition : source�� element���� ���밪�� �ݴ�� �ȴ�.

	bool operator==(const MyIntVector& source);
	//precondition : MyIntVector Ŭ����
	//postcondition : source�� element���� ���� Ŭ������ element���� ���� ���Ͽ� ������� true��ȯ, �ٸ� ��� false��ȯ

	MyIntVector& operator()(const type change);
	//precondition : change�� int�� ����
	//postcondition : ������ element�� ��� ���� change�� ��� ������

	int operator*(const MyIntVector& source);
	//precondition : ���� Ŭ������ size�� ���� MyIntVector source Ŭ����, source Ŭ������ size�� ���� Ŭ������ size�� ���� ���� ��� �����߻�.
	//postcondition : source�� element���� ���� Ŭ������ element���� ���ϰ� ���� ���� ���� ��ȯ

	size_t capacity() const;
	//precondition : 
	//postcondition : Ŭ������ Capacity�� ��ȯ

	size_t size() const;
	//precondition : 
	//postcondition : Ŭ������ size�� ��ȯ, used ���� ����

	void clear();
	//precondition : 
	//postcondition : Ŭ������ ��� ����� ���� ����

	bool is_empty() const;
	//precondition : 
	//postcondition : Ŭ������ size�� 0���� Ȯ��, size�� 0�̸� true��ȯ, �׷��� ������ false ��ȯ

	void pop_back();
	//precondition : 
	//postcondition : Ŭ������ ������ element�� ������

	void push_back(int x);
	//precondition : int�� ����
	//postcondition : Ŭ������ ������ element�� x���� �߰���

	void check();
	//precondition : 
	//postcondition : Ŭ������ element���� ��� �����

	void reserve(size_t new_capacity);
	//precondition : new_capacity > 0 && ����
	//postcondition : Ŭ������ Capacity�� new_capacity�� �缳�� ��.

	int& operator[](size_t index);
	//precondition : index < used && ���� ����
	//postcondition : Ŭ������ index��° data��(element)�� ��ȯ
	
private:
	int * data;
	size_t used;
	size_t Capacity;
};
