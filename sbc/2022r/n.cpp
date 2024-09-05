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

const int MAX = 1e5 + 10;

int main()
{
    _;

	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;
	int K, L; cin >> K >> L;

	vector<ll> prea(n + 1, 0), preb(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		prea[i] = prea[i - 1] + (ll)a[i - 1];
	}

	for (int l = 0; l < k; l++) {
		int r = n - l;

	}

    return(0);
}
