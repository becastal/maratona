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

const int maxn = 1550;
int n;
void solve() {
	vector<int> v(maxn, -8);

	for (int i = 0; i < n; i++) {
		int mi; cin >> mi;	
		double xi; cin >> xi;
		v[mi] += round(xi*100);
	}

	vector<int> vp(maxn+1, 0);
	for (int i = 1; i <= maxn; i++) {
		vp[i] = vp[i-1] + v[i-1];
	}

	tuple<int, int, int>  res = {-1, 0, 0};

	for (int i = 0; i < maxn; i++) {
		for (int j = i+1; j < maxn; j++) {
			if (vp[j] > vp[i]) {
				res = max(res, {vp[j]-vp[i], i-j, -i});
			}
		}
	}

	auto [tot, l, r] = res;
	if (tot == -1) {
		cout << "no profit" << endl;
		return;
	}

	cout << fixed << setprecision(2) << double(tot) / 100.0 << ' ' << -r << ' ' << -r-l-1 << endl;
}

int main()
{
    _;

	while (cin >> n and n) {
		solve();
	}
    
    return(0);
}

