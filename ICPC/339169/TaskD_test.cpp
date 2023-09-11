#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "TaskD"; 
// Số test kiểm tra
const int NTEST = 1000;

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
        inp << 1 << endl;
        int z = Rand(3, 4);
        int n = Rand(4, 6);
        inp << n + z << endl;
        int cur = 0;
        for (int i = 1; i < n; ++i) {
            int val = Rand(-10, 10);
            cur += val;
            inp << val << ' ';
        }
        inp << -cur << ' ';
        for (int i = 0; i < z; ++i) {
            inp << 0 << ' ';
        }
        inp << endl;
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