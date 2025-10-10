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

const int MAX = 1e5+10;
int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

void fact(map<int, int>& v, int n, int k) {
    while(n > 1) {
        int p = divi[n];
        int cnt = 0;
        while(n % p == 0) {
            cnt++;
            n /= p;
        }
        cnt %= k;
        if(cnt) v[p] = cnt;
    }
}

int main()
{
    _;

	crivo(MAX-1);
	map<map<int, int>, int> M;
	int n, k, ok = 0; cin >> n >> k;
	vector<int> v(n);

	ll res = 0;
	for (int& i : v) {
		cin >> i;

		map<int, int> f, mi, mi_;
		fact(f, i, k);
		for (auto [a, b] : f) {
			if ((k - b) % k != 0) mi_[a] = (k - b) % k;
			mi[a] = b;
		}

		//if (M.count(mi_)) {
		//	dbg(i);
		//	for (auto [a, b] : mi_) {
		//		cout << a << ' ' << b << endl;
		//	}
		//	cout << endl;
		//}
		res += M[mi_];
		M[mi]++;
	}
	cout << res << endl;
    
    return(0);
}
