#include <bits/stdc++.h>

int intAddition(int a, int b, int base) {
    int digitA;
    int digitB;
    int multiplier = 1;
    int carry = 0;
    int sum = 0;
    int temp = 0;

    // infinite loop
    while (a > 0 || b > 0 || carry == 1) { // or digitA and digitB
        digitA = a % 10;
        digitB = b % 10;

        std::cout << "digitA = " << digitA << "; digitB = " << digitB << std::endl;

        temp = digitA + digitB + carry;
        if (temp >= base) {
            carry = 1;
            sum = sum + (temp - base) * multiplier;
        } else {
            carry = 0;            
            sum = sum + temp * multiplier;
        }
        multiplier *= 10;
        
        std::cout << "sum = " << sum << "; multiplier = " << multiplier << std::endl;

        a = (a - digitA)/10;
        b = (b - digitB)/10;

        std::cout << "a = " << a << "; b = " << b << std::endl;
    }
    return sum;
}

int main() {
    // std::cout << intAddition(1234, 789, 10) << std::endl;   // supposed to print 2023
    // std::cout << intAddition(123456789, 987654321, 10) << std::endl;   // supposed to print 1111111110
    std::cout << intAddition(456, 123, 7) << std::endl;   // supposed to print 612
}