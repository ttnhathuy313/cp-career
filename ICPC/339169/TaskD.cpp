#include <bits/stdc++.h>
using namespace std;
 
int main() {
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

    int cases; 
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int n;
        cin >> n;
 
        long long a[n];
        for (int j = 0; j < n; j++) {
            long long element; 
            cin >> element;
            a[j] = element;
        }
 
        int count = 0;
        int actualEndIndex = 0;
        for (int j = n - 1; j > 0; j--) {
            if (a[j] == 0) {
                count++;
            }
            else {
                actualEndIndex = n - count - 1; 
                break;
            }
        }
 
        if (accumulate(a, a+n, 0) != 0) {
            cout << "No";
        }
        else {
            long long fragsum = 0;
            int start = 0;
            for (int j = 0; j < n; j++) {
                fragsum += a[j];  
                if ((a[j] <= 0 && j == 0 && n > 1) || (a[n - 1] > 0)) {
                    cout << "No";   
                    goto testcase; 
                }     
                else if (a[j] == 0 && n == 1) {
                    cout << "Yes";   
                    goto testcase;
                }   
                else if (a[j] < 0 && (j == n - 1 || a[j + 1] >= 0)) {
                    if (fragsum == 0 && j != actualEndIndex) {
                        cout << "No";   
                        goto testcase; 
                    }
                    else if (fragsum + start >= 0) {
                        start = j + 1;
                        fragsum = 0;
                    }
                    else {
                        cout << "No";   
                        goto testcase; 
                    } 
                }
            }
            cout << "Yes";
        }
        testcase: 
        cout << endl;
    }
}