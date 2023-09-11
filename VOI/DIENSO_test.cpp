#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "DIENSO"; 
// Số test kiểm tra
const int NTEST = 100;

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int a[4444][4444], w[4444], h[44444];

int main()
{
    srand(time(NULL));
    for(int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        int m = 100, n = 100;
        memset(w, 0, sizeof w);
        memset(h, 0, sizeof h);
        inp << m << ' ' << n << endl;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                a[i][j] = Rand(1, 100);
                w[i] += a[i][j];
                h[j] += a[i][j];
            }
        }
        for (int i = 1; i <= m; ++i) {
            inp << w[i] << ' ';
        } inp << endl;
        for (int i = 1; i <= n; ++i) {
            inp << h[i] << ' ';
        } inp << endl;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                inp << Rand(0, a[i][j]) << ' ';
            }
            inp << endl;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                inp << Rand(a[i][j], 110) << ' ';
            }
            inp << endl;
        }
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if(system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}