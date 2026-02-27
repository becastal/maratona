#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

// swag (sliding-window aggregate)
//
// o(1) amortizado pra manter uma queue com os valores
// de uma janela.
// serve pra qualquer operacao que seja assossiativa ,
// que tenha um identidade, e que nao tenha inverso.
// (se tiver inverso facil nao precisa codar isso)
//
// op() tem que ser a operacao.
// e() tem que ser a identidade.

template<typename T>
struct swag {
#define s second
	stack<pair<T, T>> in, out;

	T e() { return LLONG_MIN; };
	T op(T a, T b) {
		return max(a, b);
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
		if (empty()) return 0;
		return op(in.empty() ? e() : in.top().s, out.empty() ? e() : out.top().s);
	}
	int size() { return in.size() + out.size(); };
	bool empty() { return in.empty() and out.empty(); };
};

int solve() {
	int n, k; cin >> n >> k;
	vector<int> A(n), dp(n + 1, LLONG_MAX);
	for (int& i : A) {
		cin >> i;
	}
	dp[0] = 0;

	swag<int> Q;
	for (int i = 1; i <= n; i++) {
		if (Q.size() > k) Q.pop();

		dp[i] = A[i-1] + Q.query();
		Q.push(dp[i]);
		//cout << dp[i] << " \n"[i==n];
	}

	cout << dp[n] << endl;

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

