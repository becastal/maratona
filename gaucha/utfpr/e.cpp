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

template<typename T> vector<int> pi(T& s) {
    vector<int> p(s.size());
    for (int i = 1, j = 0; i < s.size(); i++) {
        while (j > 0 && s[j] != s[i]) j = p[j-1];
        if (s[j] == s[i]) j++;
        p[i] = j;
    }
    return p;
}

template<typename T> vector<int> matching(T& s, T& t) {
    vector<int> p = pi(s), match;
    for (int i = 0, j = 0; i < t.size(); i++) {
        while (j > 0 && s[j] != t[i]) j = p[j-1];
        if (s[j] == t[i]) j++;
        if (j == s.size()) match.push_back(i-j+1), j = p[j-1];
    }
    return match;
}

int main()
{
    _;

    string si, p; 
    cin >> si >> p;

    string rp = p;
    reverse(rp.begin(), rp.end());

    vector<int> contp(26, 0);
    for (char c : p) {
        contp[c - 'a']++;
    }

    string s = si;
    //for (char c : si) {
    //    if (contp[c - 'a'] > 0) {
    //        s.push_back(c);
    //    }
    //}
    
	// kmp nas duas dirs
    auto k1 = matching(p, s);
    auto k2 = matching(rp, s);

    set<int> S;
    for (int i : k1) S.insert(i);
    for (int i : k2) S.insert(i);

    cout << S.size() << endl;

    return 0;
}

