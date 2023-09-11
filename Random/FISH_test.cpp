#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "FISH"; 
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
    if(system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test "<< ": WRONG!\n";
            return 0;
        }
        cout << "Test " << ": CORRECT!\n";
    // for(int iTest = 1; iTest <= NTEST; iTest++)
    // {
    //     ofstream inp((NAME + ".inp").c_str());
    //     int n = 400, m = Rand(600, 900), q = 4000;
    //     inp << n << ' ' << m << ' ' << q << endl;
    //     for (int i= 1; i <= n; ++i) {
    //         inp << Rand(1, m) << " ";
    //     } inp << endl;
    //     for (int i = 2; i <= n; ++i) {
    //         inp << Rand(1, i - 1) << ' ' << i << endl;
    //     }
    //     for (int i = 1; i <= q; ++i) {
    //         int type = Rand(0, Rand(0, 1));
    //         if (type == 0) {
    //             int u = Rand(1, n - 1), v = Rand(u + 1, n);
    //             inp << type << ' ' << u << ' ' << v << ' ' << Rand(1, 39) << endl;
    //         } else {
    //             int u = Rand(1, n - 1), v = Rand(u + 1, n);
    //             inp << type << ' ' << u << ' ' << v << endl;                
    //         }
    //     }
    //     inp.close();
    //     // Nếu dùng Linux thì "./" + Tên chương trình
    //     system((NAME + ".exe").c_str());
    //     system((NAME + "_trau.exe").c_str());
    //     // Nếu dùng linux thì thay fc bằng diff
    //     if(system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
    //     {
    //         cout << "Test " << iTest << ": WRONG!\n";
    //         return 0;
    //     }
    //     cout << "Test " << iTest << ": CORRECT!\n";
    // }
    return 0;
}