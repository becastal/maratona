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

	int n, k; cin >> n >> k;
	vector<int> v(n+2, 0);

	for (int i = 0, a, b; i < k; i++) {
		cin >> a >> b;
		v[a]++, v[b+1]--;
	}

	for (int i = 1; i < n+2; i++) {
		v[i] += v[i-1];
	}

	vector<int> v_;
	for (int i = 1; i <= n; i++) {
		v_.push_back(v[i]);
	}

	sort(v_.begin(), v_.end());
	//for (int i : v_) cout << i << ' '; cout << endl;
	cout << v_[(int)v_.size()/2] << endl;

    return(0);
}
