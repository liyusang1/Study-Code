//소프트웨어학부 이유상
//main function
#include "MyIntVector.h"


int main() {

	MyIntVector vec1(20); //Capacity가 20인 vec1생성
	vec1.push_back(55);   //vec1의 data 배열에 55추가
	vec1.push_back(12);   //vec1의 data 배열에 12추가
	vec1.push_back(26);   //vec1의 data 배열에 26추가
	vec1.check();         //vec1의 data 배열의 모두 값 확인
	cout <<vec1[2] << endl;  //vec1의 data[2] 값 확인
	cout <<vec1[1] << endl;  //vec1의 data[1] 값 확인
	vec1.pop_back();  //vec1의 마지막 data 값 제거
	vec1.check();
	vec1.clear();    //vec1의 data배열에 있는 모든 값 제거
	vec1.check();    
	if (vec1.is_empty())  //vec1의 data배열이 비어있는지 확인 참이면 true반환
		cout << "element가 없습니다." << endl;
	cout << "# vec1의 size : " << vec1.size() << endl;
	cout << "# vec1의 capacity : " << vec1.capacity() << endl;
	vec1.reserve(5);  //vec1의 capacity를 5로 변경
	cout << "# vec1의 capacity : " << vec1.capacity() << endl;
	vec1.push_back(312); //vec1의 data 배열에 312추가
	cout << "# vec1의 size : " << vec1.size() << endl;

	vec1.push_back(312);
	vec1.push_back(253);
	vec1.check();
	vec1(5);   //vec1의 element의 모든 값을 5로 바꿈
	vec1.check();
	MyIntVector vec2;
	vec2.push_back(325);
	vec2.push_back(5212);
	vec2.push_back(512);
	vec2(5);
	if (vec1 == vec2)
		cout << "#vec1과 vec2의 모든 element는 같습니다" << endl;
	cout << "# vec1과 vec2의 elements들의 곱의 합 : " << vec1 * vec2 << endl;

	MyIntVector vec3 = vec1;  //vec1과 똑같은 vec3클래스 생성
	cout << "#vec3의 element : ";
	vec3.check(); 
	-vec3;     //vec3의 element의 모든 값의 절대값을 반대로 함
	vec3.check();
	vec1=vec1 - vec3;  //vec1의 element값에서 vec3의 element값을 뺌
	vec1.check();
	MyIntVector vec4 = vec1 + vec2;  //vec1과 vec2를 element값을 더한 vec4 생성
	vec4.check();
	vec4 += vec1;    //vec4의 element뒤에 vec1의 모든 element를 덧붙임
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