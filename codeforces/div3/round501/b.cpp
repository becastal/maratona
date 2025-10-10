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

int main()
{
    _;

	int n; cin >> n;
	string s, t; cin >> s >> t;

	vector<int> cs(26, 0), ct(26, 0);
	for (char c : s) cs[c-'a']++;
	for (char c : t) ct[c-'a']++;

	if (cs != ct) return cout << -1 << endl, 0;
	vector<int> res;

	for (int i = 0; i < n; i++) {
		if (s[i] == t[i]) continue;

		int ii = -1;
		for (int j = i+1; j < n; j++) {
			if (s[j] == t[i]) {
				ii = j;
				break;
			}
		}

		for (int j = ii; j > i; j--) {
			res.push_back(j);
			swap(s[j], s[j-1]);
		}
	}

	cout << res.size() << endl;
	for (int i : res) cout << i << ' '; cout << endl;
    
    return(0);
}
