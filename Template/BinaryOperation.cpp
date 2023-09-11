int bi(string s) {
	reverse(s.begin(), s.end());
	int res = 0;
	for (int i = 0; i < s.size(); ++i) if (s[i] == '1')
		res += (1 << i);
	return res;
}

string show(int d) {
	string ret; ret.clear();
	while (d) {
		ret = char((d % 2) + '0') + ret;
		d /= 2;
	}
	return ret;
}
