bool solve() {
	int n, k, b, s;
	cin >> n >> k >> b >> s;
 
	if (((b * k) + (n * (k - 1))) < s || ((b * k) > s))
		cout << -1;
	else {
		vector<int> a(n, 0);
		//input(a,n);
		a[0] = b * k;
		s -= (b * k);
		int d = INT_MAX;
		for (int i = 1; i < n && s > 0; i++) {
			d = min(k - 1, s);
			a[i] = d;
			s -= d;
		}
		if (s > 0 && s < k)
			a[0] += s;
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
	}
 
 
	return 0;
 
}
