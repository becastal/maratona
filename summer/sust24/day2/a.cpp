#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int q, e = 0; cin >> q;

	deque<int> Q;
	auto front = [&]() {
		if (Q.empty()) {
			cout << "No job for Ada?" << endl;	
			return;
		}

		if (e) cout << Q.back() << endl, Q.pop_back();
		else cout << Q.front() << endl, Q.pop_front();
	};
	auto back = [&]() {
		if (Q.empty()) {
			cout << "No job for Ada?" << endl;	
			return;
		}

		if (!e) cout << Q.back() << endl, Q.pop_back();
		else cout << Q.front() << endl, Q.pop_front();
	};
	auto push_front = [&](int a) {
		if (e) Q.push_back(a);
		else Q.push_front(a);
	};
	auto push_back = [&](int a) {
		if (!e) Q.push_back(a);
		else Q.push_front(a);
	};

	while (q--) {
		string S; cin >> S;

		if (S == "reverse") e ^= 1;
		else if (S == "back") {
			back();
		} else if (S == "front") {
			front();
		} else if (S == "push_back") {
			int x; cin >> x;
			push_back(x);
		} else if (S == "toFront") {
			int x; cin >> x;
			push_front(x);
		}
	}

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

