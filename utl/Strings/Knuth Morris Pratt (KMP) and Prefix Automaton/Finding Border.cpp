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

int main()
{
    _;

	string s; cin >> s;
	vector<int> res, v = pi(s);

	int k = v.back();
	while (k) {
		res.push_back(k);
		k = v[k - 1];
	}

	reverse(res.begin(), res.end());
	for (int i : res) cout << i << ' ';
	cout << endl;
    
    return(0);
}
