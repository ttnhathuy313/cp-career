#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "TaskF"; 
// Số test kiểm tra
const int NTEST = 100;
typedef pair <int, int> ii;

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
        int n, m, q;
        n = 6, m = 9, q = 3;
        inp << n << ' ' << m << endl;
        set <ii> edges; edges.clear();
        while (m--) {
            int u = Rand(1, n - 1), v = Rand(u + 1, n);
            while (edges.find(ii(u, v)) != edges.end()) {
                u = Rand(1, n - 1), v = Rand(u + 1, n);
            }
            edges.insert({u, v});
            inp << u << ' ' << v << ' ' << Rand(1, 13) << endl;
        }
        inp << q << endl;
        edges.clear();
        while (q--) {
            int u = Rand(1, n - 1), v = Rand(u + 1, n);
            while (edges.find(ii(u, v)) != edges.end()) {
                u = Rand(1, n - 1), v = Rand(u + 1, n);
            }
            edges.insert({u, v});
            inp << u << ' ' << v << ' ' << Rand(1, 13) << endl;
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