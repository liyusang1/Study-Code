#include <array>
#include <iostream>
using namespace ::std;
int main(int argc, char const *argv[]) {

    array<int, 8> arr1 = {1, 2, 3, 4, 5, 6, 7, 8};
    array<int, 8> arr2 = {10, 11, 12, 13, 14, 15, 16, 17};
    array<int, 8>::iterator iter;

    cout << "# arr1 :";
    for (iter = arr1.begin(); iter != arr1.end(); ++iter) {
        cout << *iter << " ";
    }
    size_t arr1Size = arr1.size();
    cout << "# arr1 size : " << arr1Size << endl;

    bool arr1Check = arr1.empty();
    if (arr1Check)
        cout << "# arr1 is empty" << endl;
    else
        cout << "# arr1 is not empty" << endl;

    cout << "# arr1[2] : " << arr1[2] << endl;
    cout << "# front of arr1 : " << arr1.front() << endl;
    cout << "# back of arr1 : " << arr1.back() << endl;

    arr1.fill(77);
    cout << "# change arr1's all elements to 77" << endl;
    cout << "# arr1 :";
    for (iter = arr1.begin(); iter != arr1.end(); ++iter) {
        cout << *iter << " ";
    }
    arr1.swap(arr2);
    cout << endl;
    cout << "# swap arr1 " << endl;
    cout << "# arr1 :";
    for (iter = arr1.begin(); iter != arr1.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    cout << "# reverse of arr1 : ";
    array<int, 8>::reverse_iterator riter;
    for (riter = arr1.rbegin(); riter != arr1.rend(); ++riter) {
        cout << *riter << " ";
    }
    return 0;
}
