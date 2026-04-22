#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

template<typename T, auto op, auto e>
struct swag {
	stack<array<T, 2>> in, out;

	void push(T x) {
		T agg = in.empty() ? x : op(in.top()[1], x);
		in.push({x, agg});
	}

	void pop() {
		if (out.empty()) {
			while (!in.empty()) {
				auto [x, agg] = in.top();
				in.pop();

				T cur = out.empty() ? x : op(x, out.top()[1]);
				out.push({x, cur});
			}
		}
		out.pop();
	}

	T query() {
		if (in.empty() and out.empty()) return e();
		if (in.empty()) return out.top()[1];
		if (out.empty()) return in.top()[1];
		return op(out.top()[1], in.top()[1]);
	}

	int size() { return (int)in.size() + (int)out.size(); }
	bool empty() { return in.empty() and out.empty(); }
};

int solve() {
	int n, k; cin >> n >> k;
	vector<int> P(n), P_(n);
	for (int i = 0; i < n; i++) {
		cin >> P[i]; P[i]--;
		P_[P[i]] = i;
	}

	swag<int, [](int a, int b) { return min(a, b); }, []() { return LLONG_MAX; }> swag_min;
	swag<int, [](int a, int b) { return max(a, b); }, []() { return LLONG_MIN; }> swag_max;

	for (int i = 0; i < k; i++) {
		swag_min.push(P_[i]);
		swag_max.push(P_[i]);
	}

	int res = swag_max.query() - swag_min.query();
	for (int i = k; i < n; i++) {
		swag_min.pop();
		swag_max.pop();
		swag_min.push(P_[i]);
		swag_max.push(P_[i]);
		res = min(res, swag_max.query() - swag_min.query());
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

