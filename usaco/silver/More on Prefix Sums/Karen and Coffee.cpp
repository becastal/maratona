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
const int MAX = 200010;

int main()
{
    _;
	setIO("");

	int n, k, q; cin >> n >> k >> q;
	vector<int> diff(MAX+1, 0);

	for (int i = 0, l, r; i < n; i++) {
		cin >> l >> r;
		diff[l]++, diff[r+1]--;
	}
	for (int i = 1; i <= MAX; i++) {
		diff[i] += diff[i-1];
	}

	vector<int> bom(MAX+1, 0);
	for (int i = 0; i <= MAX; i++) {
		bom[i] = diff[i] >= k;
	}
	for (int i = 1; i <= MAX; i++) {
		bom[i] += bom[i-1];
	}

	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r;
		cout << bom[r] - bom[l-1] << endl;
	}

    return(0);
}
