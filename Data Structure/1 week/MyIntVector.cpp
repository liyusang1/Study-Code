//소프트웨어학부 이유상
//class implementaion 
#include "MyIntVector.h"

MyIntVector::MyIntVector(size_t init_capacity) {

	data = new type[init_capacity];
	Capacity = init_capacity;
	used = 0;
}

MyIntVector::~MyIntVector() {

	delete[]data;
}

MyIntVector::MyIntVector(const MyIntVector& source) {

	data = new type[source.Capacity];
	Capacity = source.Capacity;
	used = source.used;
	copy(source.data, source.data + used, data);

}

MyIntVector& MyIntVector::operator=(const MyIntVector& source) {

	if (this == &source)
		return *this;
	if (Capacity != source.Capacity)
	{
		delete[]data;
		data = new type[source.Capacity];
		Capacity = source.Capacity;
	}
	used = source.used;
	copy(source.data, source.data + used, data);
	return *this;
}

MyIntVector& MyIntVector :: operator+=(const MyIntVector& source) {

	size_t temp = used;
	reserve(Capacity + source.Capacity);
	used += source.used;
	copy(source.data, source.data + used, data + temp);

	return *this;
}

void MyIntVector::push_back(int x) {
	
	if (used == Capacity)
		reserve(used+1);  //

	data[used] = x;
	used++;
}

void MyIntVector::check() {

	
	cout << "[ ";
	for (size_t i = 0; i < used; i++) {
		cout << data[i] << ",";
	}
	cout << " ]" << endl;

}

void MyIntVector::reserve(size_t new_capacity) {

	int* larger_array;
	if (new_capacity == Capacity)
		return;
	if (new_capacity < used)
		new_capacity = used;

	larger_array = new type[new_capacity];
	copy(data, data + used, larger_array);
	delete[]data;
	data = larger_array;
	Capacity = new_capacity;

}

int& MyIntVector::operator[](size_t index) {

	if (index >= used) {
		cout << "***** operator [] - index num error *****" << endl;
		assert(!(index >= used));
	}

		return data[index];
}

MyIntVector MyIntVector::operator+(const MyIntVector& source) {

	assert((used == source.used));

	MyIntVector newVector=*this;

	for (size_t i = 0; i < used; i++) {
		newVector.data[i] = data[i] + source.data[i];
	}

	return newVector;
}

MyIntVector MyIntVector::operator-(const MyIntVector& source) {

	assert((used == source.used));

	MyIntVector newVector = *this;

	for (size_t i = 0; i < used; i++) {
		newVector.data[i] = data[i] - source.data[i];
	}

	return newVector;
}

MyIntVector& MyIntVector::operator-() {

	for (size_t i = 0; i < used; i++) {
		data[i] *= -1;
	}

	return *this;
}

bool MyIntVector :: operator==(const MyIntVector& source) {

	if (used != source.used)
		return false;
	
	for (size_t i = 0; i < used; i++) {

		if (data[i] != source.data[i])
			return false;
	}

	return true;
}

int MyIntVector::operator*(const MyIntVector& source) {

	assert((used == source.used));

	int scalar = 0;

	for (size_t i = 0; i < used; i++) {
		scalar += data[i] * source.data[i];
	}

	return scalar;
}

MyIntVector& MyIntVector::operator()(const type change) {

	for (size_t i = 0; i < used; i++) {
		data[i] = change;
	}
	return *this;
}

size_t MyIntVector::capacity() const{
	
	return Capacity;
}

size_t MyIntVector::size() const {

	return used;
}

void MyIntVector::pop_back() {

	if (used != 0)
		used--;

}

bool MyIntVector::is_empty() const {

	if (used == 0)
		return true;
	else
		return false;
}

void MyIntVector::clear() {

	used =0;
}
