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
	//precondition : init_capacity > 0 && int형 정수
	//postcondition : Vector클래스의 동적할당 배열크기를 init_capacity 값 만큼 지정함.

	~MyIntVector();
	//precondition : 
	//postcondition : 클래스의 소멸자 핟당받은 data값을 delete함

	MyIntVector(const MyIntVector &source);
	//precondition : 복사할 MyIntVector 클래스.
	//postcondition : source 클래스를 복사하여 새로운 클래스를 생성.

	MyIntVector& operator=(const MyIntVector &source);
	//precondition : 복사할 MyIntVector 클래스.
	//postcondition : source 클래스를 복사하여 source와 똑같은 새로운 클래스를 생성.

	MyIntVector& operator+=(const MyIntVector &source);
	//precondition : 다른 클래스에 덧붙일 element가 들어있는 클래스
	//postcondition : 기존의 클래스의 element에 이어서 source클래스의 element가 덧붙여 저장된다.

	MyIntVector operator+(const MyIntVector& source);
	//precondition : 기존 클래스와 size가 같은 MyIntVector source 클래스, source 클래스의 size와 기존 클래스의 size가 같지 않을 경우 에러발생.
	//postcondition : source의 element값 만큼 기존 클래스의 element값이 증가한다.

	MyIntVector operator-(const MyIntVector& source);
	//precondition : 기존 클래스와 size가 같은 MyIntVector source 클래스, source 클래스의 size와 기존 클래스의 size가 같지 않을 경우 에러발생.
	//postcondition : source의 element값 만큼 기존 클래스의 element값이 감소한다.

	MyIntVector& operator-();
	//precondition : 
	//postcondition : source의 element값의 절대값이 반대로 된다.

	bool operator==(const MyIntVector& source);
	//precondition : MyIntVector 클래스
	//postcondition : source의 element값과 기존 클래스의 element값을 전부 비교하여 같을경우 true반환, 다를 경우 false반환

	MyIntVector& operator()(const type change);
	//precondition : change는 int형 정수
	//postcondition : 기존의 element의 모든 값을 change로 모두 변경함

	int operator*(const MyIntVector& source);
	//precondition : 기존 클래스와 size가 같은 MyIntVector source 클래스, source 클래스의 size와 기존 클래스의 size가 같지 않을 경우 에러발생.
	//postcondition : source의 element값과 기존 클래스의 element값을 곱하고 전부 합한 값을 반환

	size_t capacity() const;
	//precondition : 
	//postcondition : 클래스의 Capacity를 반환

	size_t size() const;
	//precondition : 
	//postcondition : 클래스의 size를 반환, used 값과 같음

	void clear();
	//precondition : 
	//postcondition : 클래스의 모든 요소의 값을 없앰

	bool is_empty() const;
	//precondition : 
	//postcondition : 클래스의 size가 0인지 확인, size가 0이면 true반환, 그렇지 않으면 false 반환

	void pop_back();
	//precondition : 
	//postcondition : 클래스의 마지막 element를 제거함

	void push_back(int x);
	//precondition : int형 정수
	//postcondition : 클래스의 마지막 element로 x값이 추가됨

	void check();
	//precondition : 
	//postcondition : 클래스의 element들을 모두 출력함

	void reserve(size_t new_capacity);
	//precondition : new_capacity > 0 && 정수
	//postcondition : 클래스의 Capacity가 new_capacity로 재설정 됨.

	int& operator[](size_t index);
	//precondition : index < used && 양의 정수
	//postcondition : 클래스의 index번째 data값(element)을 반환
	
private:
	int * data;
	size_t used;
	size_t Capacity;
};
