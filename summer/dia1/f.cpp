#include <bits/stdc++.h>
#define f first
#define s secont
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

vector<string> res;
int solve(ll n, ll m, ll k) {
	ll agr = 0;

	if (n == 1) {
		if (agr + (m-1) > k) {
			ll falta = k - agr;
			res.push_back(to_string(falta) + " R");
			return 0;
		} else {
			res.push_back(to_string((m-1)) + " R");
			agr += (m-1);
		}

		if (agr + (m-1) > k) {
			ll falta = k - agr;
			res.push_back(to_string(falta) + " L");
			return 0;
		} else {
			res.push_back(to_string((m-1)) + " L");
			agr += (m-1);
		}

		return 0;
	}

	for (int i = 0; i < m-1; i++) {
		if (agr + ((n-1)*3) > k) {
			ll falta = k - agr;

			if (falta / 3) res.push_back(to_string(falta / 3) + " DRL");
			if (falta % 3 == 1) res.push_back("1 D");
			else if (falta % 3 == 2) res.push_back("1 DR");
			return 0;
		} else {
			res.push_back(to_string((n-1)) + " DRL");
			agr += ((n-1)*3);
		}
		if (agr == k) return 0;

		if (agr + (n-1) > k) {
			ll falta = k - agr;
			res.push_back(to_string(falta) + " U");
			return 0;
		} else {
			res.push_back(to_string((n-1)) + " U");
			agr += (n-1);
		}
		if (agr == k) return 0;

		res.push_back("1 R");
		agr++;
		if (agr == k) return 0;
	}

	if (agr + (n-1) > k) {
		ll falta = k - agr;
		res.push_back(to_string(falta) + " D");
		return 0;
	} else {
		res.push_back(to_string((n-1)) + " D");
		agr += (n-1);
	}
	if (agr == k) return 0;

	if (agr + (n-1) > k) {
		ll falta = k - agr;
		res.push_back(to_string(falta) + " U");
		return 0;
	} else {
		res.push_back(to_string((n-1)) + " U");
		agr += (n-1);
	}
	if (agr == k) return 0;

	if (agr + (m-1) > k) {
		ll falta = k - agr;
		res.push_back(to_string(falta) + " L");
		return 0;
	} else {
		res.push_back(to_string((m-1)) + " L");
		agr += (m-1);
	}
	assert((int)res.size() <= 3000);
	return 0;
}
 
int main() {
	_;

	ll n, m, k; cin >> n >> m >> k;

	if (k > (4*n*m-2*n-2*m)) return cout << "NO" << endl, 0;
	solve(n, m, k);
	cout << "YES" << endl;
	cout << (int)res.size() << endl;
	for (auto s : res) cout << s << endl;

 	return 0;
}
