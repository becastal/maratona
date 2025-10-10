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

	int T, n; cin >> T >> n;

	vector<int> v(n);
	for (int& i : v) cin >> i;

	vector<int> dp(T+1, 0), pai(T+1), idx(T+1);
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = T; j >= v[i]; j--) {
			if (!dp[j] and dp[j-v[i]]) {
				dp[j] = 1;
				pai[j] = j-v[i];
				idx[j] = i;
			}
		}
	}

	vector<int> res(n), usei(n, 0), rec;

	int agr = T, ok = 0;
	for (; !ok;) {
		ok |= dp[agr];
		agr -= !ok;
	}

	for (int i = agr; i; i = pai[i]) {
		rec.push_back(idx[i]);
	}

	int pos = 0;
	for (int i : rec) {
		res[i] = pos;
		pos += v[i];
		usei[i] = 1;
	}

	pos = 0;
	for (int i = 0; i < n; i++) {
		if (!usei[i]) {
			res[i] = pos;
			pos += v[i];
		}
	}

	for (int i : res) cout << i << ' '; cout << endl;
    
    return(0);
}
