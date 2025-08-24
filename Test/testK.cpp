#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v1 = {4, 5};
    vector<int> v2 = {1, 2};
    int b = v1.back(); v1.pop_back();
    int a = v1.back();
    int d = v2.back(); v2.pop_back();
    int c = v2.back();
    std::cout << a << b << c << d << std::endl;     // correct
    std::cout << 100*a*c + 10*((a+b)*(c+d) - a*c - b*d) + b*d << std::endl;     // but why 100ac?
}
