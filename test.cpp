#include <bits/stdc++.h>
using namespace std;
#include <vector>

// helper function for addition
string intAddition(string a, string b, int base) {
    vector<int> va;
    vector<int> vb;    
    // convert string to integer vector using transform
    transform(a.begin(), a.end(), back_inserter(va), [](char c) { return c - '0'; });
    transform(b.begin(), b.end(), back_inserter(vb), [](char c) { return c - '0'; });

    int digitA;
    int digitB;
    // int multiplier = 1;
    vector<int> result;
    int carry = 0;
    int temp = 0;
    int lenA = va.size();
    int lenB = vb.size();
    while (lenA > 0 || lenB > 0 || carry == 1) { // or digitA and digitB
        digitA = va.back();
        digitB = vb.back();
        temp = digitA + digitB + carry;
        if (temp >= base) {
            carry = 1;
            temp -= base;
        } else {
            carry = 0;            
        }
        result.push_back(temp);
        // multiplier *= 10;
        va.pop_back();
        vb.pop_back();
        lenA = va.size();
        lenB = vb.size();        
    }
    // reverse vector result
    std::reverse(result.begin(), result.end());

    // convert int vector to string
    string s;
    transform(result.begin(), result.end(), back_inserter(s), [](int i) { return i + '0'; });

    // return string result
    return s;
}

/*
void calculate(string a, string b, int base) {
    // int sum = intAddition(a, b, base);
    // std::cout << sum << " 0" << " 0" << std::endl;
}
*/

int main() {
    string a, b;
    int base;
    std::cin >> a >> b >> base;
    // this works but with a condition of input numbers being strings
    // cout << intAddition("456", "123", 7) << endl;
    cout << intAddition("33774022283743315542623650011778280736723644410316427185", "36823874817726422221662722", 9) << endl;
}