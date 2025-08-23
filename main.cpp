#include <bits/stdc++.h>
using namespace std;

// convert strings to int vectors
vector<int> toVector(string s) {
    vector<int> v;
    transform(s.begin(), s.end(), back_inserter(v), [](char c) { return c - '0'; });
    return v;
}

// convert int vectors to strings
string toString(vector<int> v) {
    string s;
    transform(v.begin(), v.end(), back_inserter(s), [](int i) { return i + '0'; });
    return s;
}

// addition
string intAddition(string a, string b, int base) {
    vector<int> va = toVector(a);
    vector<int> vb = toVector(b);
    int digitA, digitB;
    int carry = 0, temp = 0;
    vector<int> result;
    int lenA = va.size();
    int lenB = vb.size();
    while (lenA > 0 || lenB > 0 || carry == 1) {    // or digitA and digitB
        digitA = (lenA > 0) ? va.back() : 0;        // IMPORTANT to check if either va or vb is empty!! 
        digitB = (lenB > 0) ? vb.back() : 0;        // IMPORTANT to check if either va or vb is empty!!
        temp = digitA + digitB + carry;
        carry = (temp) / base;
        temp = temp % base;
        result.push_back(temp);
        if (lenA > 0) va.pop_back();                // IMPORTANT to check lenA and lenB before pop_back()!!
        if (lenB > 0) vb.pop_back();                // IMPORTANT to check lenA and lenB before pop_back()!!
        lenA--;                                     // lenA = va.size();
        lenB--;                                     // lenB = vb.size();
    }
    std::reverse(result.begin(), result.end());
    return toString(result);
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
    cout << intAddition(a, b, base) << " 0" << " 0" << endl;
}