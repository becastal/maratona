#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

// SegTree
//
// Recursiva com Lazy Propagation
// Query: soma do range [a, b]
// Update: soma x em cada elemento do range [a, b]
// Pode usar a seguinte funcao para indexar os nohs:
// f(l, r) = (l+r)|(l!=r), usando 2N de memoria
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log(n))

const int MAX = 2e5+10;
namespace seg {
	array<int, 2> seg[4*MAX];
	int lazy[4*MAX];
	int n;

	array<int, 2> merge(array<int, 2> A, array<int, 2> B) {
		if (A[0] < B[0]) return A;
		if (A[0] > B[0]) return B;
		return array<int, 2>{A[0], A[1] + B[1]};
	}
	array<int, 2> build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = {0, 1};
		int m = (l+r)/2;
		return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void prop(int p, int l, int r) {
		if (lazy[p] == 0) return;

		seg[p][0] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	array<int, 2> query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return array<int, 2>{LLONG_MAX, 0};
		int m = (l+r)/2;
		return merge(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	array<int, 2> update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = merge(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}
};

vector<array<int, 3>> Ev[MAX];

int solve() {
	int n; cin >> n; seg:: n = MAX - 1;
	vector<array<int, 4>> A(n);
	for (auto& [x1, y1, x2, y2] : A) {
		cin >> x1 >> y1 >> x2 >> y2;
	}
	int p, a1, b1, a2, b2; cin >> p >> a1 >> b1 >> a2 >> b2;
	int area = (a2 - a1) * (b2 - b1);

	auto da = [&](int rad) {
		seg::build();

        for (auto [x1, y1, x2, y2] : A) {
            int l = min(x1, x2) - rad;
            int r = max(x1, x2) + rad;
            l = max(l, a1);
            r = min(r, a2);

            int baixo = min(y1, y2) - rad;
            int cima = max(y1, y2) + rad;
            baixo = max(baixo, b1);
            cima = min(cima, b2);

            if (l >= r or baixo >= cima) continue;
            Ev[baixo].push_back({l, r - 1, +1});
            Ev[cima].push_back({l, r - 1, -1});
        }

        int cont = 0;
        for (int y = b1; y <= b2; y++) {
            for (auto [x1, x2, add] : Ev[y]) {
                seg::update(x1, x2, add);
            }
            Ev[y].clear();

            if (y == b2) break;
            cont += (a2 - a1);

            if (a1 <= a2 - 1) {
                auto q = seg::query(a1, a2 - 1);
                if (q[0] == 0) cont -= q[1];
            }
        }

        return 100 * cont >= p * area;
    };

	int l = 0, r = 1.5e5, res = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (da(mid)){ 
			r = mid - 1;
			res = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << res << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

