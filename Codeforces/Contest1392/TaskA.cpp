#include <bits/stdc++.h>

using namespace std;
 
signed main() {
  	int t, n;
  	cin >> t;
  	while (t--) {
  		cin >> n;
  		
  		int tmp, p;
  		bool flag = 0;
  		
  		cin >> p;
  		for(int i = 1; i < n; ++i) {
  			cin >> tmp;
  			if(p != tmp)
  				flag = true;
  		}
  		if(flag)
  			cout << "1\n";
  		else
  			cout <<n <<endl;
  	}
  	
  	return 0;
}