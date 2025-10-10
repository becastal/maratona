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

template<class T> struct maxstack {
	stack<pair<T, T>> s;

	void push(T x) {
		if (!s.size()) s.push({x, x});
		else s.emplace(x, std::max(s.top().second, x));
	}
	T top() { return s.top().first;	}
	T pop() {
		T ans = s.top().first;
		s.pop();
		return ans;
	}
	int size() { return s.size(); }
	T max() { return s.top().second; }
};

template<class T> struct maxqueue {
	maxstack<T> s1, s2;

	void push(T x) { s1.push(x); }
	void move() {
		if (s2.size()) return;
		while (s1.size()) {
			T x = s1.pop();
			s2.push(x);
		}
	}
	T front() { return move(), s2.top(); }
	T pop() { return move(), s2.pop(); }
	int size() { return s1.size()+s2.size(); }
	T max() {
		if (!s1.size()) return s2.max();
		else if (!s2.size()) return s1.max();
		return std::max(s1.max(), s2.max());
	}
};

int solve() {
	int n; cin >> n;
	ll m;  cin >> m;

	maxqueue<int> Q;
	vector<int> F(n), S(n);
	for (int i = 0; i < n; i++) {
		cin >> F[i] >> S[i];
	}

	int res = INF;
	ll s = 0;
	for (int r = 0, l = 0; r < n; r++) {
		s += F[r];
		Q.push(S[r]);

		while (l < n and s >= m) {
			res = min(res, Q.max());
			Q.pop();
			s -= F[l++];
		}
	}

	assert(res != INF);
	cout << res << endl;

	return(0);
}

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main() {
    _;
	setIO("hayfeast");

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

    return(0);
}
