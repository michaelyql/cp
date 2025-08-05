#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define LSOne(S) ((S) & -(S))
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
    int key, sz, freq;
    uint32_t prio;
    node *l, *r;
    node() {};
    node(int key): key(key), sz(1), freq(1), prio(rng()), l(NULL), r(NULL) {}
    node(int key, uint32_t prio): key(key), sz(1), freq(1), prio(prio), l(NULL), r(NULL) {}
};

typedef node* pnode;

int sz(pnode t) {
    return t ? t->sz: 0;
}

void update(pnode t) {
    if (t) t->sz = t->freq + sz(t->l) + sz(t->r); 
}

// split treap based on key, store results in l and r
void split(pnode t, int key, pnode& l, pnode& r) {
    if (!t) {
        l = r = NULL;
    } else if (key >= t->key) {
        split(t->r, key, t->r, r), l = t;
    } else {
        split(t->l, key, l, t->l), r = t;
    }
    update(l);
    update(r);
}

// merge two treaps l and r, store result in t
// Assumes all keys in l < all keys in r (i.e. sorted)
void merge(pnode& t, pnode l, pnode r) {
    if (!l) t = r;
    else if (!r) t = l;
    else if (l->prio > r->prio) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    update(t);
}

// insert element into treap t
void insert(pnode& t, pnode it) {
    if (!t) t = it;
    else if (it->key == t->key) {
        t->freq++;
        delete it; // duplicate node, need to free memory
    } else if (it->prio > t->prio) {
        split(t, it->key, it->l, it->r), t = it;
    } else {
        insert(it->key < t->key ? t->l : t->r, it);
    }
    update(t);
}

// erase key from treap
void erase(pnode& t, int key) {
    if (!t) {
        cerr << "key " << key << " not found in treap\n"; 
        throw runtime_error("key not found in treap");
    }
    if (t->key == key) {
        if (t->freq > 1) t->freq--; 
        else {
            pnode temp = t;
            merge(t, t->l, t->r);
            delete temp;
        }
    } else {
        erase(key >= t->key ? t->r : t->l, key);
    }
    update(t);
}

// union of two treaps (not necessarily the case that all keys of l < r)
pnode unite(pnode l, pnode r) {
    if (!l || !r) return l ? l : r;
    if (l->prio < r->prio) swap(l, r);
    pnode lt, rt;
    split(r, l->key, lt, rt);
    l->l = unite(l->l, lt);
    l->r = unite(l->r, rt);
    update(l);
    return l;
}

// search for first node with key < v, and return the size of the subtree
int search(pnode t, int v) {
    if (!t) return 0;
    if (t->key < v) {
        return sz(t->l) + t->freq + search(t->r, v);
    } else {
        return search(t->l, v);
    }
} 

void print_tree(pnode t, int level) {
    if (!t) return;
    print_tree(t->l, level + 1);
    printf("level=%d,key=%d,prio=%u,freq=%d,sz=%d\n", level, t->key, t->prio, t->freq, t->sz);
    print_tree(t->r, level + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    pnode root = NULL;
    rep(i, 0, n) {
        cin >> a[i];
        pnode u = new node(a[i]);
        insert(root, u);
    }
    // print_tree(root, 0);
    ll ans = 0;
    rep(i, 0, n - 1) {
        erase(root, a[i]);
        ans += search(root, a[i]);
        // printf("ans=%lld\n", ans);
    }
    cout << ans << endl;
}
