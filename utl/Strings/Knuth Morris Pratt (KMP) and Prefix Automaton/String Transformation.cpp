#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int P = 69420;
const int M = 1e9+9;

vector<int> get_z(string s) {
	int n = s.size();
	vector<int> z(n, 0);

	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}

	return z;
}

int solve() {
	string A, B;
	getline(cin, A), getline(cin, B);

	if (A.size() != B.size()) return cout << "-1 -1" << endl, 0;
	int n = (int)A.size();
	if (n < 2) return cout << "-1 -1" << endl, 0;

	auto rev = [](string a) {
		reverse(all(a));
		return a;
	};

	if (rev(A) == B) {
		cout << (n - 2) << ' ' << (n - 1) << endl;
		return 0;
	}

	vector<int> base(n + 1);
	base[0] = 1;
	for (int i = 1; i <= n; i++) {
		base[i] = base[i - 1] * P % M;
	}

	auto pref = [&](string &S) {
		vector<int> pre(n + 1);
		for (int i = 1; i <= n; i++) {
			pre[i] = (pre[i - 1] * P + (unsigned char)S[i - 1]) % M;
		}
		return pre;
	};

	string RA = rev(A);
	vector<int> preA = pref(A);
	vector<int> preB = pref(B);
	vector<int> preR = pref(RA);

	auto hash = [&] (vector<int> &pre, int l, int r) -> int {
		if (l > r) return 0;
		int h = (pre[r + 1] - base[r - l + 1] * pre[l] % M + M) % M;
		return h;
	};

	vector<int> pi(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j and B[i] != B[j]) j = pi[j-1];
		pi[i] = (j += B[i] == B[j]);
	}

	vector<int> Match(n);
	for (int i = 0, j = 0; i < n; i++) {
		while (j and B[j] != A[i]) j = pi[j-1];
		j += (B[j] == A[i]);
		if (j == n) j = pi[j-1];
		Match[i] = j;
	}

	vector<int> Z = get_z(B + "$" + A);

	auto ok = [&](int l, int r) {
		if (l < 1 or r > n - 2 or l > r + 1) return 0;
		int tam = r - l + 1;
		int suf = n - r - 1;
		if (tam and hash(preA, l, r) != hash(preB, 0, tam - 1)) return 0;
		if (hash(preR, 0, suf - 1) != hash(preB, tam, tam + suf - 1)) return 0;
		if (hash(preR, n - l, n - 1) != hash(preB, n - l, n - 1)) return 0;

		return 1;
	};

	int resa = -1, resb = -1;
	auto up = [&](int l, int r) {
		int a = l - 1, b = r + 1;
		if (a > resa or (a == resa and b < resb)) {
			resa = a;
			resb = b;
		}
	};

	for (int i = 0; i <= n - 2; i++) if (Match[i]) {
		int r = i, l = i - Match[i] + 1;
		if (ok(l, r)) up(l, r);

		int z = Z[n + 1 + i];
		if (z) {
			l = i;
			r = i + z - 1;
			if (ok(l, r)) up(l, r);
		}
	}

	cout << resa << ' ' << resb << endl;
	return 0;
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

