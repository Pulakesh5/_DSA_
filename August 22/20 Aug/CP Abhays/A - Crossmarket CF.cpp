bool solve() {
	int n, m;
	cin >> n >> m;
 
	if (n == 1 && m == 1)
		cout << 0;
	else if (n == 1)
		cout << m;
	else if (m == 1)
		cout << n;
	else
		cout << (n + m - 2 + min(n, m));
 
	return 0;
 
}
