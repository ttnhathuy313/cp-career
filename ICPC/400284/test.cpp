#include <bits/stdc++.h>
#include <regex>

using namespace std;

int solution(vector <string> members, vector <string> messages) {
	for (string message : messages) {
		regex exp("@(id)");
	    smatch res;
	    string str = message;

	    string::const_iterator searchStart( str.cbegin() );
	    while ( regex_search( searchStart, str.cend(), res, exp ) )
	    {
	        cout << ( searchStart == str.cbegin() ? "" : " " ) << res[0];  
	        searchStart = res.suffix().first;
	    }
	    cout << endl;
	}
	return 0;
}

int main() {
	vector <string> messages = {"@id12,id12,i good job @id42,id1"};
	vector <string> members = {};
	cout << solution(members, messages) << endl;
}