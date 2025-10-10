#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 2e4+10;
vector<int> divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++)
		for (int j = i; j <= lim; j += i) {
			divi[j].push_back(i);
		}
}

int solve() {
	int A, B, C; cin >> A >> B >> C;

	int res = INF, a_, b_, c_;
	for (int c = 1; c <= 20000; c++) {
		for (int b : divi[c]) {
			for (int a : divi[b]) {
				int preco = abs(C - c) + abs(B - b) + abs(A - a);
				if (res > preco) {
					res = preco;
					c_ = c;
					b_ = b;
					a_ = a;
				}
			}
		}
	}
	cout << res << endl;
	cout << a_ << ' ' << b_ << ' ' << c_ << endl;

	return(0);
}

int main()
{
    _;

	crivo(MAX-1);
	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
