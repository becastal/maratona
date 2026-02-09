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
	map<int, multiset<int>> M;

	Trie(int sigma_ = 26, int norm_ = 'a') : sigma(sigma_), norm(norm_) {
		to = {vector<int>(sigma)};
		end = {0}, pref = {0};
		M[0].insert(0);
	}
    void insert(string s) {
        int x = 0, p = 0;
        for (char c : s) {
            int &nxt = to[x][c - norm];
            if (!nxt) {
                nxt = (int)to.size();
                to.push_back(vector<int>(sigma, 0));
                end.push_back(0), pref.push_back(0);
                M[p + 1].insert(0);
            }
            x = nxt;

            auto &ms = M[p + 1];
            auto it = ms.find(pref[x]);
            if (it != ms.end()) ms.erase(it);
            ++pref[x];
            ms.insert(pref[x]);

            ++p;
        }
        ++end[x], ++pref[0];
    }
	void erase(string s) {
        int x = 0, p = 0;
        for (char c : s) {
            int &nxt = to[x][c - norm];
            if (!nxt) return;
            x = nxt;

            auto &ms = M[p + 1];
            auto it = ms.find(pref[x]);
            if (it != ms.end()) ms.erase(it);
            --pref[x];
            ms.insert(pref[x]);

            if (!pref[x]) nxt = 0;
            ++p;
        }
		--end[x], --pref[0];
    }
	int query(int l) {
		return *M[l].rbegin();
	}
};

int solve() {
	int q; cin >> q;
	vector<string> A(q);

	Trie T(26, 'a');
	for (int qi = 0; qi < q; qi++) {
		int tp; cin >> tp;


		if (tp == 1) {
			cin >> A[qi];
			reverse(all(A[qi]));
			T.insert(A[qi]);
		} else if (tp == 2) {
			int k, l; cin >> k >> l;
			cout << (T.query(l) >= k ? "YES" : "NO") << endl;
		} else if (tp == 3) {
			int id; cin >> id; id--;
			T.erase(A[id]);
		}
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

