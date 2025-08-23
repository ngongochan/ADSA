#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// helper function for addition
string intAddition(string a, string b, int base) {
    vector<int> va;
    vector<int> vb;
    // converted from strings to int vectors correctly
    transform(a.begin(), a.end(), back_inserter(va), [](char c) { return c - '0'; });
    transform(b.begin(), b.end(), back_inserter(vb), [](char c) { return c - '0'; });
    int digitA;
    int digitB;
    vector<int> result;
    int carry = 0;
    int temp = 0;
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
    string s;
    transform(result.begin(), result.end(), back_inserter(s), [](int i) { return i + '0'; });
    return s;
}

void calculate(string a, string b, int base) {
    string sum = intAddition(a, b, base);
    std::cout << sum << " 0" << " 0" << std::endl;
}

int main() {
    string a, b;
    int base;
    std::cin >> a >> b >> base;
    calculate(a, b, base);
}