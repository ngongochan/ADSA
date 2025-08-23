#include <bits/stdc++.h>

// helper function for addition
int intAddition(int a, int b, int base) {
    int digitA;
    int digitB;
    int multiplier = 1;
    int carry = 0;
    int sum = 0;
    int temp = 0;
    while (a > 0 || b > 0 || carry == 1) { // or digitA and digitB
        digitA = a % 10;
        digitB = b % 10;
        temp = digitA + digitB + carry;
        if (temp >= base) {
            carry = 1;
            sum = sum + (temp - base) * multiplier;
        } else {
            carry = 0;            
            sum = sum + temp * multiplier;
        }
        multiplier *= 10;
        a = (a - digitA)/10;
        b = (b - digitB)/10;
    }
    return sum;
}


// int intMultiplication(int a, int b, int base) {

//     return product;
// }

void calculate(int a, int b, int base) {
    int sum = intAddition(a, b, base);
    std::cout << sum << " 0" << " 0" << std::endl;
}

// int main() {
//     calculate(456, 123, 7);      // output: 612
//     calculate(101, 5, 10);       // output: 106 505 20
//     calculate(10, 111, 2);       // output: 1001 1110 0
//     calculate(111, 10, 2);       // output: 1001 1110 11
// }