vector <int> convert_base(int a, int base) {
	vector <int> ret;
	while (a) {
		ret.push_back(a % base);
		a /= base;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}