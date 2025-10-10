#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
using namespace std;

int main()
{
    _;
    
    int n;
    while (cin >> n) {
        if (n != 1) break;
        
        vector<int> v;
        string s;
        while (cin >> s) {
            if (s == "0") break;
            int x; cin >> x;
            v.push_back(x);
        }
        
        sort(v.begin(), v.end());
        for (int i : v) {
            cout << "Package " << setw(3) << setfill('0') << i << endl;
        }
        cout << endl;
    }
    
    return 0;
}

