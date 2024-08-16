#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

vector<int> pi(string& s) {
    int n = (int) s.size();
    vector<int> p(n, 0);
    for (int i = 1, j = 0; i < n; i++) {
        while (j and s[i] != s[j]) 
            j = p[j - 1];
		j += s[i] == s[j];
        p[i] = j;
    }
    return p;
}

vector<int> kmp(string& s, string& t) {
    int n = (int)s.size(), m = (int)t.size();
    string q = s + "&" + t;
    vector<int> res, c = pi(q);
    for (int i = n + 1; i < n + m + 1; i++) {
        if (c[i] == n) res.push_back(i - 2 * n);
    }
    return res;
}

void solve() {
	string t, s; cin >> t >> s;

	auto v = kmp(s, t);
	if (v.empty()) {
		cout << "Not Found" << endl;
	} else {
		cout << v.size() << endl;
		for (int i : v) cout << i + 1 << ' ';
		cout << endl;
	}
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
