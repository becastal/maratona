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
typedef bitset<257> bs;

// acho que so falta implementar a trie;
// query tem que ser achar o valor que tem o maior xor possivel com o valor que eu tenho agora.

int main() {
    _;

    int n; cin >> n;
    vector<bs> v(n);
    
    TRIE trie;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int mi; cin >> mi;
            v[i][mi].flip();
        }
        trie.insert(v[i]);
    }

    sort(v.begin(), v.end(), [&] (const bs& a, const bs& b) { return a.to_string() < b.to_string(); });
    bs mao = v.back();

	string res = "";
    for (int i = 0; i < n; i++) {
        res += to_string(mao.count());

        bs qr = trie.query(mao);
        mao ^= qr;
        trie.remove(qr);
    }

    cout << res << endl;

    return 0;
}

