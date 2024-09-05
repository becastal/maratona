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

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	vector<int> a(k), b(k);
	for (int& i : a) cin >> i, i--;
	for (int& i : b) cin >> i, i--;

	int q; cin >> q;
	vector<int> cont(n+1);
	for (int i = 0, x; i < q; i++) {
		cin >> x; cont[x-1]++;
	}

	string res = "";

	for (int i = 0; i < k; i++) {
		string s1 = s.substr(a[i], b[i]-a[i]+1);

		int soma = 0, l = a[i], r = b[i];
		for (int j = l; j <= (l+r)/2; j++) {
			soma += cont[j] + cont[r-j+l];
			if (soma&1) swap(s1[j-l], s1[r-j]);
		}
		res += s1;
	}

	cout << res << endl;

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
