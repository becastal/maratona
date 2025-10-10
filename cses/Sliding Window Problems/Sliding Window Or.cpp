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

template<typename T>
struct swag { 
	stack<pair<T, T>> in, out;

	T e() { return 0; };
	T op(T a, T b) {
		return a | b;
	}
	void push(T x) {
		in.emplace(x, op(x, in.empty() ? e() : in.top().s));
	}
	void pop() {
		if (!out.empty()) {
			out.pop();
			return;
		}

		while (!in.empty()) {
			auto [a, b] = in.top(); in.pop();
			out.emplace(a, op(a, out.empty() ? e() : out.top().s));
		}
		out.pop();
	}
	T query() {
		return op(in.empty() ? e() : in.top().s, out.empty() ? e() : out.top().s);
	}
	int size() { return in.size() + out.size(); };
	bool empty() { return in.empty() and out.empty(); };
};
 
int solve() {
	int n, k; cin >> n >> k;
 
	int x_, a_, b_, c_; cin >> x_ >> a_ >> b_ >> c_;
	vector<ll> A(n); A[0] = x_;
	for (int i = 1; i < n; i++) {
		A[i] = ((a_ * A[i-1] % c_) + b_) % c_;
	}
 
	swag<int> S;
	for (int i = 0; i < k; i++) {
		S.push(A[i]);	
	}

	int res = S.query();
	for (int i = k; i < n; i++) {
		S.pop();
		S.push(A[i]);
		res ^= S.query();
	}
	cout << res << endl;
 
	return(0);
}
 
int main()
{
    _;
 
	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
