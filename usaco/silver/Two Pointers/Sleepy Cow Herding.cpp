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
	setIO("herding");

	int n; cin >> n;
	vector<int> v(n);
	for (int& i : v) cin >> i;
	sort(v.begin(), v.end());

	int min_ = INF;
	if ((v[n-2]-v[0] == n-2 and v[n-1]-v[n-2] > 2) or (v[n-1]-v[1] == n-2 and v[1]-v[0] > 2)) {
		min_ = 2;
	} else {
		for (int l = 0, r = 0; l < n; l++) {
			while (r + 1 < n and v[r+1] - v[l] < n) {
				r++;
			}
			min_ = min(min_, n - (r - l + 1));
		}
	}

	int tam = 0;
	for (int i = 1; i < n; i++) {
		tam += v[i] - v[i-1] - 1;
	}
	
	int max_ = max(tam - (v[1] - v[0] - 1), tam - (v[n-1] - v[n-2] - 1));
	cout << min_ << endl << max_ << endl;

    return(0);
}
