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
    bool negative = false;
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
    if(negative == true) str = "-" + str;
    return str;
}

string intMultiplication(string a, string b, int base) {
    int lenA = a.length();
    int lenB = b.length();
    if(lenA == 1 && lenB == 1) {  // base case
        int shortResult = (a[0]-'0') * (b[0]-'0');
        return to_string(shortResult);
    }
    if(lenA < lenB || (lenA == lenB && a < b)) {    // IMPORTANT: a < b means lexicographical string comparison in C++ ('0' < '9')
        swap(a, b);
    }
    string product;
    int n = std::max(lenA, lenB);
    if (n % 2 != 0) n++;
    while (a.length() < n) a = "0" + a; // why < not <= ?
    while (b.length() < n) b = "0" + b;
    string Al = a.substr(0, n/2);
    string Ar = a.substr(n/2);    
    string Bl = b.substr(0, n/2);
    string Br = b.substr(n/2);    
    // 100*a*c + 10*((a+b)*(c+d) - a*c - b*d) + b*d
    // 100*Al*Bl + 10*((Al+Ar)*(Bl+Br) - Al*Bl - Ar*Br) + Ar*Br
    string AlBl = intMultiplication(Al, Bl, base);
    string ArBr = intMultiplication(Ar, Br, base);
    string sum1  = intAddition(Al, Ar, base);
    string sum2  = intAddition(Bl, Br, base);
    string Sum   = intMultiplication(sum1, sum2, base);
    string Sub = intSubtraction(intSubtraction(Sum, AlBl, base), ArBr, base);
    string part1 = AlBl + string(n, '0');      // * base^n
    string part2 = Sub + string(n/2, '0');     // * base^(n/2)
    string result = intAddition(intAddition(part1, part2, base), ArBr, base);
    return result;
}

int main() {
    string a, b;
    int base;
    cin >> a >> b >> base;
    cout << intAddition(a, b, base) << " " << intSubtraction(a, b, base) << " " << intMultiplication(a, b, base) << " 0" << endl;
}