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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("");

	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	int res = n;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int s = 0;
			for (int k = i; k <= j; k++) {
				s += a[k];
			}
				
			if (s % (j - i + 1)) continue;
			int m = s / (j - i + 1), agr = 0;

			for (int k = i; k <= j; k++) {
				agr |= a[k] == m;
			}
			res += agr;
		}
	}
	cout << res << endl;

    return(0);
}
