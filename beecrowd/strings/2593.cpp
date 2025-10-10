#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

template<typename T> vector<int> matching(T& s, T& t) {
	vector<int> p = pi(s), match;
	for (int i = 0, j = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()) match.push_back(i-j+1), j = p[j-1];
	}
	return match;
}

int main()
{
    _;
    
    string t;
    getline(cin, t);
    
    int q; cin >> q;
    while (q--) {
        string s; cin >> s;
        
        auto kmp = matching(s, t);
        vector<int> v;
        
        for (int pos : kmp) {
            int ok = 1;
            if (pos > 0 and t[pos-1] != ' ') ok = 0;
            if (pos + s.size() < t.size() and t[pos + s.size()] != ' ') ok = 0;
            if (ok) v.push_back(pos);
        }
        
        if (v.empty()) {
            cout << -1 << endl;
		} else {
            for (int i = 0; i < (int)v.size(); i++) {
                cout << v[i] << " \n"[i == (int)v.size()-1];
            }
        }
    }
    
    return(0);
}

