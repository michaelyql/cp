#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
    int key, prio;
    node* l;
    node* r;
    node(int key): key(key), prio(rng()), l(nullptr), r(nullptr) {}
};

using pnode = node *;

void split(pnode t, int key, pnode& l, pnode& r) {
    if (!t) l = r = nullptr;
    else if (t->key < key) split(t->l, key, l, t->r), r = t;
    else split(t->r, key, t->l, r), l = t;
}

void merge(pnode& t, pnode l, pnode r) {
    if (!l || !r) t = l ? l : r;
    else if (l->prio < r->prio) merge(r->l, l, r->l), t = r;
    else merge(l->r, l->r, r), t = l;
}

void insert(pnode& t, pnode it) {
    if (!t) t = it;
    else if (t->prio < it->prio) split(t, it->key, it->l, it->r), t = it;
    else insert(it->key < t->key ? t->l : t-> r, it);
}

void erase(pnode& t, int key) {
    if (!t) return;
    if (t->key == key) {
        pnode temp = t;
        merge(t, t->l, t->r);
        delete temp;
    } else {
        erase(key < t->key ? t->l : t->r, key);
    }
}

pnode unite(pnode l, pnode r) {
    if (!l || !r) return l ? l : r;
    if (l->prio < r->prio) swap(l, r);
    pnode tl, tr;
    split(r, l->key, tl, tr);
    l->l = unite(l->l, tl);
    l->r = unite(l->r, tr); 
    return l;
}

void print_treap(pnode t, int level) {
    if (!t) return;
    print_treap(t->l, level + 1);
    printf("key=%d,prio=%d,level=%d\n", t->key, t->prio, level);
    print_treap(t->r, level + 1);
}

// Test code
int main() {
    // Init
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    shuffle(a.begin(), a.end(), rng);
    cout << "a: ";
    for (auto x : a) cout << x << " ";
    cout << endl;
    
    // Build treap
    pnode root = nullptr;
    for (auto x : a) insert(root, new node(x));
    print_treap(root, 0);
}
