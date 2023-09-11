#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "TaskE"; 
// Số test kiểm tra
const int NTEST = 100;

const int N = 500;
int p[N];

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for(int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        int n = 20, q = 20;
        inp << n << ' ' << q << endl;
        for (int i = 2; i <= n; ++i) {
            p[i] = Rand(1, i - 1);
        }
        for (int i = 1; i <= n; ++i) inp << Rand(-20, 20) << ' ';
        inp << endl;
        for (int i = 2; i <= n; ++i) {
            inp << p[i] << ' ' << i << endl;
        }
        while (q--) {
            int type;
            if (Rand(1, 10) >= 9) type = 1;
            else if (Rand(1,5) >= 3) type = 2;
            else type = 3;
            inp << type << ' ';
            if (type == 1) {
                inp << Rand(1, n) << endl;
            } else if (type == 2) {
                inp << Rand(1, n) << ' ' << Rand(1, n) << ' ' << Rand(-20, 20) << endl;
            } else {
                inp << Rand(1, n) << endl;
            }
        }
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
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