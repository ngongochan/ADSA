#include <bits/stdc++.h>
using namespace std;

string calculate(string a, string b, int base) {
    int lenA = a.length();
    int lenB = b.length();
    if(lenA < lenB) {
        swap(a, b);
        swap(lenA, lenB);
    }
    int diff = lenA - lenB;
    for (int i = 0; i < diff; i++) {
        b = "0" + b;
    }
    int carry = 0;
    string str = "";
    for(int i = lenA-1; i >= 0; i--) {
        int sum = (a[i]-'0') + (b[i]-'0') + carry;
        carry = sum / base;
        sum = sum % base;
        str = to_string(sum) + str;
    }
    if (carry > 0) str = to_string(carry) + str;
    return str;
}

int main() {
    string a, b;
    int base;
    cin >> a >> b >> base;
    cout << calculate(a, b, base) << endl;
}
