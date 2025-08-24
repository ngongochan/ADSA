#include <bits/stdc++.h>
using namespace std;

int karatsuba(vector<int> v1, vector<int> v2) {
    int len1 = v1.size();
    int len2 = v2.size();
    if(len1 < 2 && len2 < 2) {
        return v1.back() * v2.back();
    }
    int n = std::max(len1, len2);
    if (n % 2 != 0) n++;
    while (len1 <= n) v1.insert(v1.begin(), 0);
    while (len2 <= n) v2.insert(v2.begin(), 0);
    vector<int> a(v1.begin(), v1.begin() + n/2);
    vector<int> b(v1.begin() + n/2, v1.begin() + n);
    vector<int> c(v2.begin(), v2.begin() + n/2);
    vector<int> d(v2.begin() + n/2, v2.begin() + n);
    
    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int adbc = karatsuba(a + b, c - d) - ac - bd;

    return pow(10, n/2) * ac + pow(10, n/4) * adbc + bd;
}

int main() {

}
