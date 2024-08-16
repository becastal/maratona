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

class TRIE {
private:
    struct Node {
        Node* child[2];
        bs value;
        Node() {
            child[0] = child[1] = nullptr;
        }
    };

    Node* root;

public:
    TRIE() {
        root = new Node();
    }

    void insert(const bs& b) {
        Node* node = root;
        for (int i = 0; i < 257; i++) {
            int bit = b[i];
            if (!node->child[bit]) {
                node->child[bit] = new Node();
            }
            node = node->child[bit];
        }
        node->value = b;
    }

    void remove(const bs& b) {
        remove(root, b, 0);
    }

    bs query(const bs& b) {
        Node* node = root;
        bs result;
        for (int i = 0; i < 257; i++) {
            int bit = b[i];
            if (node->child[!bit]) {
                result[i] = !bit;
                node = node->child[!bit];
            } else {
                result[i] = bit;
                node = node->child[bit];
            }
        }
        return result;
    }

private:
    void remove(Node* node, const bs& b, int idx) {
        if (idx == 256) {
            if (node->value == b) {
                node->value.reset();
            }
            return;
        }

        int bit = b[idx];
        Node* child = node->child[bit];
        if (!child) return;

        remove(child, b, idx + 1);

        if (!child->child[0] && !child->child[1] && child->value.none()) {
            delete child;
            node->child[bit] = nullptr;
        }
    }
};


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
		cout << te << endl;

        bs qr = trie.query(mao);
        mao ^= qr;
        trie.remove(qr);
    }

    cout << res << endl;

    return 0;
}

