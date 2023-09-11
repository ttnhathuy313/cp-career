#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> ii;
// Tên chương trình
const string NAME = "TaskF"; 
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

int main()
{
    srand(time(NULL));
    for(int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        set <ii> al; al.clear();
        int n = 1000, m = Rand(600, (int)1e5);
        inp << n << ' ' << m << endl;
        for (int i = 1; i <= m; ++i) {
            int u, v;
            while (1) {
                u = Rand(1, n), v = Rand(1, n);
                if (u == v || al.find({u, v}) != al.end()) continue;
                else break;
            }
            al.insert({u, v});
            inp << u << ' ' << v << endl;
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