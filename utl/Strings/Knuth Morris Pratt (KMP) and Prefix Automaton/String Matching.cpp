#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
using namespace std;

vector<int> pi(string& s) {
    int n = (int) s.size();
    vector<int> p(n, 0);
    for (int i = 1, j = 0; i < n; i++) {
        while (j and s[i] != s[j]) 
            j = p[j - 1];
		j += s[i] == s[j];
        p[i] = j;
    }
    return p;
}

int kmp(string& s, string& t) {
    int n = (int)s.size(), m = (int)t.size(), res = 0;
    string q = s + "&" + t;
    vector<int> c = pi(q);
    for (int i = n; i < n + m + 1; i++) {
        if (c[i] == n) res++;
    }
    return res;
}

int main()
{
    _;

    string s, t; cin >> t >> s;
	cout << kmp(s, t) << endl;

    return 0;
}

