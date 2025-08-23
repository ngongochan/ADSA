#include <bits/stdc++.h>

// helper function for addition
int intAddition(int a, int b, int base) {
    // base 10
    if (base == 10) {
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
            if (temp > 9) {
                carry = 1;
                sum = sum + (temp - 10) * multiplier;
            } else {
                carry = 0;            
                sum = sum + temp * multiplier;
            }
            multiplier *= 10;
            a = (a - digitA)/10;
            b = (b - digitB)/10;
        }
    }

    // base 2
    return sum;
}


int intMultiplication(int a, int b, int base) {

    return product;
}

void calculate(int a, int b, int base) {
    std::cout << sum << " 0" << " 0";
}

int main() {

}