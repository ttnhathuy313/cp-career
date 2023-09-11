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
        int w = 6, h = 5;
        vector <ii> D;
        for (int i = 0; i <= w; ++i) {
            for (int j = 0; j <= h; ++j)
                D.push_back({i, j});
        }
        random_shuffle(D.begin(), D.end());
        int n = Rand(1, (w + 1) * (h + 1));
        inp << w << ' ' << h << ' ' << n << endl;
        for (int i = 0; i < n; ++i)
            inp << D[i].first << ' ' << D[i].second << endl;;
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