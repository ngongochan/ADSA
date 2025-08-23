#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// helper function for converting from strings to int vectors
vector<int> toVector(string s) {
    vector<int> v;
    transform(s.begin(), s.end(), back_inserter(v), [](char c) { return c - '0'; });
    return v;
}

// helper function for converting from int vectors to strings
string toString(vector<int> v) {
    string s;
    transform(v.begin(), v.end(), back_inserter(s), [](int i) { return i + '0'; });
    return s;
}

// helper function for addition
string intAddition(string a, string b, int base) {
    vector<int> va = toVector(a);
    vector<int> vb = toVector(b);
    int digitA;
    int digitB;
    int carry = 0;
    int temp = 0;
    vector<int> result;
    int lenA = va.size();
    int lenB = vb.size();
    while (lenA > 0 || lenB > 0 || carry == 1) {    // or digitA and digitB
        digitA = (lenA > 0) ? va.back() : 0;        // IMPORTANT to check if either va or vb is empty!! 
        digitB = (lenB > 0) ? vb.back() : 0;        // IMPORTANT to check if either va or vb is empty!!
        temp = digitA + digitB + carry;
        if (temp >= base) {
            carry = 1;
            temp -= base;
        } else {
            carry = 0;            
        }
        result.push_back(temp);
        if (lenA > 0) va.pop_back();                // IMPORTANT to check lenA and lenB before pop_back()!!
        if (lenB > 0) vb.pop_back();                // IMPORTANT to check lenA and lenB before pop_back()!!
        lenA = va.size();
        lenB = vb.size();
    }
    std::reverse(result.begin(), result.end());
    string s = toString(result);
    return s;
}

// string intMultiplication(string a, string b, int base) {
//     vector<int> va = toVector(a);
//     vector<int> vb = toVector(b);

//     string s = toString(result);
//     return s;
// }

void calculate(string a, string b, int base) {
    string sum = intAddition(a, b, base);
    // string sum = intMultiplication(a, b, base);
    std::cout << sum << " 0" << " 0" << std::endl;
}

int main() {
    string a, b;
    int base;
    std::cin >> a >> b >> base;
    calculate(a, b, base);
}