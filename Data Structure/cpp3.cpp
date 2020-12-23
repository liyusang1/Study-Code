#include <iostream>
#include <vector>
using namespace ::std;

int main() {
    vector<int> v(5);
    vector<int>::iterator vec1;

    cout << "# size of vector : " << v.size() << endl;
    v.resize(10);
    cout << "# resize of vector to 10, check size of vector : " << v.size()
         << endl;
    cout << "# capacity of vector :  " << v.capacity() << endl;
    cout << "# elements of vector :  ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl << endl;

    for (int i = 0; i < v.size(); i++)
        v[i] = i + 1;
    for (int i = 10; i < 20; ++i)
        v.push_back(i);

    cout << "-----After push_back-----" << endl;
    cout << "# size of vector :" << v.size() << endl;
    cout << "# capacity of vector " << v.capacity() << endl;
    cout << "elements of vector : ";
    for (vec1 = v.begin(); vec1 != v.end(); ++vec1)
        cout << *vec1 << " ";
    cout << endl << endl;

    for (int i = 0; i < 4; i++)
        v.pop_back();

    cout << "------After pop_back -------" << endl;
    cout << "# size of vector :" << v.size() << endl;
    cout << "# capacity of vector " << v.capacity() << endl;
    cout << "elements of vector : ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl << endl;

    cout << "# front of vector : " << v.front() << endl;
    cout << "# back of vector : " << v.back() << endl;
    cout << "# Vector[3] : " << v[3] << endl;
    cout << "#clear vector ";
    v.clear();

    cout << "------After clear -------" << endl;
    cout << "# size of vector :" << v.size() << endl;
    cout << "# capacity of vector " << v.capacity() << endl;
    cout << "elements of vector : ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl << endl;

    return 0;
}
