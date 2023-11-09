#include <iostream>

using namespace std;
#define int long long

struct int_huy {
    int value, MOD = (int)1e9 + 7;
    int_huy() {
        value = 0;
    }
    int_huy(int x) {
        value = (x + MOD) % MOD;
    }
    bool operator < (const int_huy &other) const {
        return value < other.value;
    }
    int_huy operator + (const int_huy &other) const {
        return int_huy(value + other.value);
    }
    int_huy operator - (const int_huy &other) const {
        return int_huy(value - other.value);
    }
    int_huy operator * (const int_huy &other) const {
        return int_huy(value * other.value);
    }
    bool operator = (const int_huy &other)  {
        return value = other.value;
    }
    bool operator = (const int &other)  {
        return value = other;
    }
};

int32_t main() {
    int_huy a, b, c;
    a = 132535;
    b = 200000000000;
    c = a + b;
    cout << c.value << endl;
}