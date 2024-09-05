/**
 * Este programa resolve o problema de encontrar interseções entre segmentos horizontais e verticais
 * em um plano 2D. Utiliza uma combinação de compressão de coordenadas e uma árvore binária indexada (BIT)
 * para alcançar uma solução eficiente.
 *
 * A abordagem geral é a seguinte:
 * 1. Lê os segmentos de entrada na main.
 * 2. Para cada segmento lido, são gerados eventos:
 *    - Início e fim de segmentos horizontais.
 *    - Segmentos verticais.
 * 3. Comprima as coordenadas y para reduzir o espaço de coordenadas e trabalhar eficientemente.
 * 4. Ordena os eventos por coordenada x.
 * 5. Usa um BIT para manter e consultar a contagem de segmentos horizontais ativos durante a varredura dos eventos.
 * 6. Calcula e imprime o número de interseções entre os segmentos horizontais e verticais.
 */

#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0); // Macros para otimização de I/O
#define endl '\n' // Definição de endl para melhorar performance de saída
#define dbg(x) cout << #x << " = " << x << endl // Macro para debug

typedef long long ll; // Definição de tipo para números inteiros longos
using namespace std;

typedef pair<int,int> point; // Tipo de dado para representar um ponto (coordenadas x e y)
struct event {
    point p1, p2; // Pontos que definem o evento
    int type; // Tipo de evento (0: início de segmento horizontal, 1: fim de segmento horizontal, 2: segmento vertical)
    event() {}; // Construtor padrão
    event(point p1, point p2, int type) : p1(p1), p2(p2), type(type) {}; // Construtor com parâmetros
};

const int MAX = 1e6+10; // Tamanho máximo pré-definido para arrays
int n, e; // Variáveis para o número de segmentos e eventos
event events[MAX]; // Array para armazenar os eventos
vector<int> coords; // Vetor para armazenar as coordenadas y únicas
map<int, int> compress; // Mapa para mapear coordenadas comprimidas para índices do BIT
int bit[MAX]; // BIT (Binary Indexed Tree) para manter contagem de segmentos ativos

// Função de comparação para ordenação dos eventos
bool compare(event a, event b) {
    if (a.p1.f == b.p1.f)
        return a.type < b.type; // Se coordenadas x são iguais, ordena por tipo (0 antes de 1)
    return a.p1.f < b.p1.f; // Ordena por coordenada x
}

// Função para atualizar o BIT
void update(int idx, int val) {
    while (idx < MAX) {
        bit[idx] += val; // Adiciona val ao BIT na posição idx
        idx += idx & -idx; // Atualiza idx para o próximo índice no BIT
    }
}

// Função para consultar a soma acumulada no BIT até o índice idx
int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx]; // Soma o valor do BIT na posição idx
        idx -= idx & -idx; // Atualiza idx para o índice anterior no BIT
    }
    return sum;
}

// Função principal para calcular o número de interseções
ll hv_intersection() {
    ll cont = 0; // Variável para contar interseções
    for (int i = 0; i < e; ++i) { // Itera sobre todos os eventos
        event c = events[i]; // Obtém o evento atual
        if (c.type == 0) { // Se é o início de um segmento horizontal
            update(compress[c.p1.s], 1); // Adiciona um ao BIT na posição correspondente à coordenada y
        } else if (c.type == 1) { // Se é o fim de um segmento horizontal
            update(compress[c.p2.s], -1); // Remove um do BIT na posição correspondente à coordenada y
        } else { // Se é um segmento vertical
            // Calcula o número de segmentos horizontais ativos entre as coordenadas y do segmento vertical
            cont += query(compress[c.p2.s]) - query(compress[c.p1.s] - 1);
        }
    }
    return cont; // Retorna o número total de interseções encontradas
}

int main() {
    _
    cin >> n; // Lê o número de segmentos

    e = 0;
    for (int i = 0; i < n; ++i) {
        int p1x, p1y, p2x, p2y;
        cin >> p1x >> p1y >> p2x >> p2y; // Lê as coordenadas do segmento

        // Gera os eventos para o segmento atual
        if (p1x == p2x) { // Se o segmento é vertical
            events[e++] = event(make_pair(p1x, min(p1y, p2y)), make_pair(p2x, max(p1y, p2y)), 2);
            coords.push_back(min(p1y, p2y)); // Adiciona coordenada y mínima
            coords.push_back(max(p1y, p2y)); // Adiciona coordenada y máxima
        } else { // Se o segmento é horizontal
            events[e++] = event(make_pair(min(p1x, p2x), p1y), make_pair(max(p1x, p2x), p2y), 0);
            events[e++] = event(make_pair(max(p1x, p2x), p1y), make_pair(min(p1x, p2x), p2y), 1);
            coords.push_back(p1y); // Adiciona coordenada y do primeiro ponto
            coords.push_back(p2y); // Adiciona coordenada y do segundo ponto
        }
    }

    sort(coords.begin(), coords.end()); // Ordena as coordenadas
    coords.erase(unique(coords.begin(), coords.end()), coords.end()); // Remove duplicatas

    for (int i = 0; i < coords.size(); ++i) {
        compress[coords[i]] = i + 1; // Mapeia cada coordenada para um índice no BIT
    }

    sort(events, events + e, compare); // Ordena os eventos por coordenada x

    cout << hv_intersection() << endl; // Calcula e imprime o número de interseções entre os segmentos

    return 0; // Retorna 0 para indicar sucesso
}
