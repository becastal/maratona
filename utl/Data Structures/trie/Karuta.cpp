#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct Trie {
	vector<vector<int>> to;
	vector<int> end, pref;
	int sigma; char norm;
	Trie(int sigma_=26, char norm_='a') : sigma(sigma_), norm(norm_) {
		to = {vector<int>(sigma)};
		end = {0}, pref = {0};
	}
	void insert(string s) {
		int x = 0;
		for (auto c : s) {
			int& nxt = to[x][c-norm];
			if (!nxt) {
				nxt = to.size();
				to.push_back(vector<int>(sigma));
				end.push_back(0), pref.push_back(0);
			}
			x = nxt, pref[x]++;
		}
		end[x]++, pref[0]++;
	}
	int lcp(string s) {
		int u = 0, res = 0;
		for (char c : s) {
			int &nxt = to[u][c-norm];
			if (!nxt) break;
			u = nxt;
			res++;
		}
		return res;
	}
};

int solve() {
	int n; cin >> n;

	vector<string> A(n);
	for (auto& i : A) {
		cin >> i;
	}

	vector<int> R(n);
	
	Trie T1(26, 'a'), T2(26, 'a');
	for (int i = 0; i < n; i++) {
		R[i] = max(R[i], T1.lcp(A[i]));
		T1.insert(A[i]);
	}

	for (int i = n-1; i >= 0; i--) {
		R[i] = max(R[i], T2.lcp(A[i]));
		T2.insert(A[i]);
	}

	for (int i : R) {
		cout << i << endl;
	}

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

