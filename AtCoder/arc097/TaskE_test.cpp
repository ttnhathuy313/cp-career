#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> ii;
// Tên chương trình
const string NAME = "TaskE"; 
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
        vector <ii> a; a.clear();
        int n = 500;
        inp << n << endl;
        for (int i = 1; i <= n; ++i)
            a.push_back({1, i});
        for (int i = 1; i <= n; ++i)
            a.push_back({0, i});
        random_shuffle(a.begin(), a.end());
        for (ii d : a) {
            if (d.first == 0) inp << "W ";
            else inp << "B ";
            inp << d.second << endl;
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