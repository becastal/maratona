#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

const int MAX = 2e5 + 10;
namespace sparse {
    int t[MAX][18], v[MAX];
    int n;

    void build() {
        for (int i = 0; i < n; ++i) t[i][0] = v[i];
        for (int k = 1; (1 << k) <= n; ++k) {
            for (int i = 0; i + (1 << k) <= n; ++i) {
                t[i][k] = min(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    int query(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return min(t[l][k], t[r - (1 << k) + 1][k]);
    }
};

int main() {
    _;
    int n, m; 
    cin >> n >> m;
    vector<int> a(n);

    for (int& i : a) cin >> i;

    vector<int> as(n), apos(n);
    iota(apos.begin(), apos.end(), 0);

    as = a;
    sort(as.begin(), as.end());
    sort(apos.begin(), apos.end(), [&] (int i, int j) {
        return a[i] < a[j];
    }); 

    //cout << "as: "; for (int i : as) cout << i << ' '; cout << endl;
    //cout << "apos: "; for (int i : apos) cout << i+1 << ' '; cout << endl;

    sparse::n = n;
    for (int i = 0; i < n; i++) {
        sparse::v[i] = apos[i]+1;
    }
    sparse::build();

    for (int i = 0, bi; i < m; i++) {
        cin >> bi;

		auto ub = upper_bound(as.begin(), as.end(), bi);
        if (ub == as.begin()) {
            cout << -1 << endl;
            continue;
        }

        int r = (ub - as.begin()) - 1;
        cout << sparse::query(0, r) << endl;
	}

    return 0;
}

