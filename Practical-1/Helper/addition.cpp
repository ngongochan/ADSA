#include <bits/stdc++.h>

int intAddition(int a, int b) {
    // base 10 first
    /*
        int digitA = a % 10;
        int digitB = b % 10;
        
        int sum = 0;
        int multiplier = 1;

        while(a > 0 || b > 0) {
        // while(a == 0 || b == 0) {
            sum = sum + (digitA + digitB) * multiplier;		
            multiplier *= 10;
            a = (a - digitA)/10;
            b = (b - digitB)/10;
        }
        return sum;
    */
    int digitA;
    int digitB;
    int multiplier = 1;
    int carry = 0;
    int sum = 0;
    int temp = 0;
    while (a > 0 || b > 0 || carry == 1) { // or digitA and digitB
        digitA = a % 10;
        digitB = b % 10;

        std::cout << "digitA = " << digitA << "; digitB = " << digitB << std::endl;

        temp = digitA + digitB + carry;
        if (temp > 9) {
            carry = 1;
            sum = sum + (temp - 10) * multiplier;
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
    std::cout << intAddition(1234, 789) << std::endl;   // supposed to print 2023
    std::cout << intAddition(123456789, 987654321) << std::endl;   // supposed to print 1111111110
}