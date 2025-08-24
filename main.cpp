#include <bits/stdc++.h>
using namespace std;

string intAddition(string a, string b, int base) {
    int lenA = a.length();
    int lenB = b.length();
    if(lenA < lenB) {
        swap(a, b);
        swap(lenA, lenB);
    }
    for (int i = 0; i < lenA - lenB; i++) {
        b = "0" + b;
    }
    int carry = 0;
    string str = "";
    for (int i = lenA-1; i >= 0; i--) {
        int sum = (a[i]-'0') + (b[i]-'0') + carry;
        carry = sum / base;
        sum = sum % base;
        str = to_string(sum) + str;
    }
    if (carry > 0) str = to_string(carry) + str;
    return str;
}

string intSubtraction(string a, string b, int base) {
    int lenA = a.length();
    int lenB = b.length();
    bool negative;
    if(lenA < lenB || (lenA == lenB && a < b)) {    // IMPORTANT: a < b means lexicographical string comparison in C++ ('0' < '9')
        swap(a, b);
        swap(lenA, lenB);
        negative = true;
    }
    for (int i = 0; i < lenA - lenB; i++) {
        b = "0" + b;
    }
    int borrow = 0;
    string str = "";
    for (int i = lenA-1; i >= 0; i--) {
        int diff = (a[i]-'0') - (b[i]-'0') - borrow;
        if (diff < 0) {
            diff += base;
            borrow = 1;
        } else {
            borrow = 0;
        }
        str = to_string(diff) + str;
    }
    if(negative) str = "-" + str;
    return str;
}

// string intMultiplication(string a, string b, int base) {
//     vector<int> va = toVector(a);
//     vector<int> vb = toVector(b);

//     string s = toString(result);
//     return s;
// }

int main() {
    string a, b;
    int base;
    cin >> a >> b >> base;
    cout << intAddition(a, b, base) << " " << intSubtraction(a, b, base) << " 0" << endl;
}