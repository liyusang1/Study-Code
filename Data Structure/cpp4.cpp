#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

int main() {
    string str1 = " hello!!";
    cout << "# str1 : " << str1 << endl;

    string::reverse_iterator rit;
    cout << " # reverse of str1 : ";
    for (rit = str1.rbegin(); rit != str1.rend(); ++rit)
        cout << *rit;

    cout << endl << endl;
    string str2 = "my name is yusang";
    cout << "# str2 : " << str2 << endl;

    str1.swap(str2);
    cout << "----After swap-----" << endl;
    cout << "# str1: " << str1 << endl;
    cout << "# str2 : " << str2 << endl;

    cout << "# replace str1 : ";
    str1 = str1.replace(11, 17, "jamesStevePParkgosu");
    cout << str1 << endl;
    str1 += str2;
    cout << "# After str1+=str2 : ";
    cout << str1 << endl;
    str1 = str1.erase(11, 19);
    cout << "# After erase(11,19) : ";
    cout << str1 << endl;

    str1 = str1.insert(11, "Steve");
    cout << "# After insert(11,\"Steve\") : ";
    cout << str1 << endl;

    cout << "#compare str1 , str2 : ";
    int check = str1.compare(str2);
    if (check == 0)
        cout << "same string";
    else
        cout << "different string";

    return 0;
}
