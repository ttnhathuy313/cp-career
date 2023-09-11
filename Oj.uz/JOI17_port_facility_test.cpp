#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "JOI17_port_facility"; 
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

        int n = 4;
        inp << n << endl;
        set <int> rem; rem.clear();
        for (int i = 1; i <= 2 * n; ++i) {
            rem.insert(i);
        }
        for (int i = 1; i <= n; ++i) {
            int sz = rem.size();
            int id = Rand(1, sz), cnt = 0, ii;
            for (int u : rem) {
                cnt++;
                if (cnt == id) {
                    ii = u;
                    break;
                }
            }
            rem.erase(ii);
            sz = rem.size();
            id = Rand(1, sz), cnt = 0;
            int j;
            for (int v : rem) {
                cnt++;
                if (cnt == id) {
                    j = v;
                    break;
                }
            }
            rem.erase(j);
            if (ii > j) swap(ii, j);
            inp << ii << ' ' << j << endl;
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