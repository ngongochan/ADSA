#include <bits/stdc++.h>
using namespace std;

// trim leading zeros
string trimLeadingZeros(string s) {
    while (s.size() > 1 && s[0] == '0')
        s.erase(0, 1);
    return s;
}

// add 2 strings
string intAddition(string a, string b, int base) {
    int lenA = a.length(), lenB = b.length();
    if (lenA < lenB) swap(a, b), swap(lenA, lenB);
    while (b.length() < a.length()) b = "0" + b;

    int carry = 0;
    string result = "";
    for (int i = lenA - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / base;
        result = to_string(sum % base) + result;
    }
    if (carry) result = to_string(carry) + result;
    return result;
}

// subtract b from a, assume a >= b
string intSubtraction(string a, string b, int base) {
    int lenA = a.length(), lenB = b.length();
    bool negative = false;
    if (lenA < lenB || (lenA == lenB && a < b)) {
        swap(a, b);
        swap(lenA, lenB);
        negative = true;
    }
    while (b.length() < a.length()) b = "0" + b;
    int borrow = 0;
    string result = "";
    for (int i = lenA - 1; i >= 0; i--) {
        int diff = (a[i] - '0') - (b[i] - '0') - borrow;
        if (diff < 0) {
            diff += base;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = to_string(diff) + result;
    }

    result = trimLeadingZeros(result);
    if (negative) result = "-" + result;
    return result;
}

// multiply two single-digit characters
string multiplySingleDigits(char a, char b, int base) {
    int result = (a - '0') * (b - '0');
    string str = "";
    do {
        str = to_string(result % base) + str;
        result /= base;
    } while (result > 0);
    return str;
}

// naive multiplication for small strings
string naiveMultiplication(string a, string b, int base) {
    string result = "0";
    int lenB = b.length();
    for (int i = lenB - 1; i >= 0; i--) {
        string temp = "";
        int carry = 0;
        for (int j = a.length() - 1; j >= 0; j--) {
            int mul = (a[j] - '0') * (b[i] - '0') + carry;
            carry = mul / base;
            temp = to_string(mul % base) + temp;
        }
        if (carry) temp = to_string(carry) + temp;
        temp += string(lenB - 1 - i, '0');
        result = intAddition(result, temp, base);
    }
    return trimLeadingZeros(result);
}

// Karatsuba multiplication with recursion
string intMultiplication(string a, string b, int base) {
    a = trimLeadingZeros(a);
    b = trimLeadingZeros(b);
    int lenA = a.length(), lenB = b.length();

    // cutoff to naive multiplication for small inputs
    if (lenA <= 4 || lenB <= 4) {
        return naiveMultiplication(a, b, base);
    }
    // make lengths equal
    int n = max(lenA, lenB);
    if (n % 2 != 0) n++;
    while (a.length() < n) a = "0" + a;
    while (b.length() < n) b = "0" + b;

    string Al = a.substr(0, n / 2);
    string Ar = a.substr(n / 2);
    string Bl = b.substr(0, n / 2);
    string Br = b.substr(n / 2);

    string AlBl = intMultiplication(Al, Bl, base);
    string ArBr = intMultiplication(Ar, Br, base);
    string AlPlusAr = intAddition(Al, Ar, base);
    string BlPlusBr = intAddition(Bl, Br, base);
    string sumProduct = intMultiplication(AlPlusAr, BlPlusBr, base);
    string middleTerm = intSubtraction(intSubtraction(sumProduct, AlBl, base), ArBr, base);
    string part1 = AlBl + string(n, '0');           // AlBl * base^n
    string part2 = middleTerm + string(n / 2, '0'); // middleTerm * base^(n/2)
    string result = intAddition(intAddition(part1, part2, base), ArBr, base);
    return trimLeadingZeros(result);
}

// Main
int main() {
    string a, b;
    int base;
    cin >> a >> b >> base;
    cout << intAddition(a, b, base) << " " << intMultiplication(a, b, base) << " 0" << endl;
    return 0;
}