#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define debug

#ifdef debug
#define db(x) cout << #x " = " << x << endl;
#define bp(x) cout << #x << endl;
#else
#define db(x)
#define bp(x)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vb = vector<bool>;
using uint = unsigned int;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// usage: shuffle(all(a), rng)
// usage: uint32_t r = rng()

struct node {
    node *l;
    node *r;
    int sz;
    int prio;
    char c;
    node(char c): c(c), sz(1), prio(rng()), l(nullptr), r(nullptr) {};
};

using pnode = node*;

int sz(pnode t) {
    return t ? t->sz : 0;
}

void update(pnode t) {
    if (t) t->sz = sz(t->l) + sz(t->r) + 1;
}

void split(pnode t, int key, pnode& l, pnode& r) {
    if (!t) l = r = nullptr;
    else if (sz(t->l) + 1 <= key) split(t->r, key - sz(t->l) - 1, t->r, r), l = t; 
    else split(t->l, key, l, t->l), r = t; 
    update(t);
}

void merge(pnode& t, pnode l, pnode r) {
    if (!l || !r) t = l ? l : r;
    else if (l->prio > r->prio) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    update(t);
}

void insert(pnode& t, pnode x, int p) { 
    if (!t) t = x;
    else if (t->prio < x->prio) {
        split(t, p, x->l, x->r), t = x;
    } else {
        if (p < sz(t->l) + 1) insert(t->l, x, p);
        else insert(t->r, x, p - sz(t->l) - 1);
    } 
    update(t);
}

void inorder(pnode& t) {
    if (!t) return;
    inorder(t->l);
    printf("%c", t->c);
    inorder(t->r);
}

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    pnode root = nullptr;
    for (char c : s) {
        pnode u = new node(c);
        insert(root, u, sz(root));
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        pnode tl, tm, tr;
        split(root, b, tm, tr);
        split(tm, a, tl, tm);
        pnode l;
        merge(l, tl, tr);
        merge(root, l, tm);
    }
    inorder(root);
    cout << endl; 
}
