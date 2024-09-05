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

struct No {
    int valor;
    struct No *esquerda, *direita;
    No(int valor) {
        this->valor = valor;
        esquerda = direita = NULL;
    }
};

void imprimirEmOrdem(struct No* no) {
    if (no == NULL)
        return;

    imprimirEmOrdem(no->esquerda);
    cout << no->valor << " ";
    imprimirEmOrdem(no->direita);
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return new No(valor);
    }
    queue<No*> q;
    q.push(raiz);
    while (!q.empty()) {
        No* temp = q.front();
        q.pop();

        if (temp->esquerda == NULL) {
            temp->esquerda = new No(valor);
            break;
        } else {
            q.push(temp->esquerda);
        }

        if (temp->direita == NULL) {
            temp->direita = new No(valor);
            break;
        } else {
            q.push(temp->direita);
        }
    }
    return raiz;
}

int main() { 
    _;
    int n, m;
    cin >> n;
    cin >> m;

    No* raiz = NULL;
    for (int i = 0; i < n; ++i) {
        int valor;
        cin >> valor;
        raiz = inserir(raiz, valor);
    }

    cout << "\nA travessia em ordem da árvore binária é \n";
    imprimirEmOrdem(raiz);
    cout << endl;

    return 0;
}

