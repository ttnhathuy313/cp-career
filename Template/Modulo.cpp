
int norm(int x) {
    if (x < 0) {
        x += MOD;
    }
    if (x >= MOD) {
        x -= MOD;
    }
    return x;
}
template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct mod_int { // basically just the modulo stuff
    int x;
    mod_int(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    mod_int operator-() const {
        return mod_int(norm(MOD - x));
    }
    mod_int inv() const {
        assert(x != 0);
        return power(*this, MOD - 2);
    }
    mod_int &operator*=(const mod_int &rhs) {
        x = i64(x) * rhs.x % MOD;
        return *this;
    }
    mod_int &operator+=(const mod_int &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    mod_int &operator-=(const mod_int &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    mod_int &operator/=(const mod_int &rhs) {
        return *this *= rhs.inv();
    }
    friend mod_int operator*(const mod_int &lhs, const mod_int &rhs) {
        mod_int res = lhs;
        res *= rhs;
        return res;
    }
    friend mod_int operator+(const mod_int &lhs, const mod_int &rhs) {
        mod_int res = lhs;
        res += rhs;
        return res;
    }
    friend mod_int operator-(const mod_int &lhs, const mod_int &rhs) {
        mod_int res = lhs;
        res -= rhs;
        return res;
    }
    friend mod_int operator/(const mod_int &lhs, const mod_int &rhs) {
        mod_int res = lhs;
        res /= rhs;
        return res;
    }
};