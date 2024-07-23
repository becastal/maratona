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
	vector<int> a(n), b(n);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;
	int k, l; cin >> k >> l;

	vector<ll> prea(n + 1, 0), preb(n + 1, 0);
	vector<vector<int>> presa(n + 1), presb(n + 1);

	for (int i = 1; i <= n; i++)
		prea[i] = prea[i - 1] + (ll)a[i - 1];

	for (int i = n - 2; i >= -1; i--)
		preb[i + 1] = preb[i + 2] + (ll)a[i + 1];

	//for (int i : preb)
	//	cout << i << ' ';
	//cout << endl;
	int sum = -INF;
	for (int l = 0; l < k; i++) {
		int r = n - l;

		sum = max(sum, prea[l] + preb[r];
	}

	cout << sum << endl;

    return(0);
}
