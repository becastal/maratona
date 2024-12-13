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

ll escolhe(int n, int k) {
	if (k > n - k) { k = n - k; }
	long long ret = 1;
	for (int i = 0; i < k; i++) {
		ret = ret * (n - i) / (i + 1);
	}
	return ret;

}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		cout << escolhe(n-1, k-1) << endl;
	}

    return(0);
}
