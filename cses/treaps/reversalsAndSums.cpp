#include <bits/stdc++.h>

#define DEBUG 0

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
    int v;
    int sz;
    int prio;
    int l;
    int r;
    long long s;
    bool rev;
};

const int MAX_N = 2e5 + 5;
struct node t[MAX_N];
int id = 0;

int sz(int i) {
    return i ? t[i].sz : 0;
}

long long s(int i) {
    return i ? t[i].s : 0;
}

void update(int i) {
    if (i) {
        t[i].sz = sz(t[i].l) + sz(t[i].r) + 1;
        t[i].s = s(t[i].l) + s(t[i].r) + t[i].v; 
    }
}

void push(int i) {
    if (i && t[i].rev) {
        swap(t[i].l, t[i].r);
        if (t[i].l) t[t[i].l].rev ^= 1;
        if (t[i].r) t[t[i].r].rev ^= 1;
        t[i].rev = false;
    }
}

void split(int i, int key, int& l, int& r) {
    if (DEBUG) printf("split(%d,%d,%d,%d)\n",i,key,l,r);
    push(i);
    if (!i) l = r = 0;
    else if (key <= sz(t[i].l)) {
        split(t[i].l, key, l, t[i].l);
        r = i;
    } else {
        split(t[i].r, key - sz(t[i].l) - 1, t[i].r, r);
        l = i;
    }
    update(i);
}

void merge(int& i, int l, int r) {
    if (DEBUG) printf("merge(%d,%d,%d)\n",i,l,r);
    push(l);
    push(r);
    if (!l || !r) i = l ? l : r;
    else if (t[l].prio > t[r].prio) {
        merge(t[l].r, t[l].r, r), i = l;
    } else {
        merge(t[r].l, l, t[r].l), i = r;
    }
    update(i);
}

void rev(int& i, int l, int r) {
    if (DEBUG) printf("rev(%d,%d,%d)\n",i,l,r);

    int t1, t2, t3;
    split(i, r + 1, t2, t3);
    split(t2, l, t1, t2);
    t[t2].rev ^= 1;
    int t;
    merge(t, t2, t3);
    merge(i, t1, t);
}

void sum(int& i, int l, int r) {
    if (DEBUG) printf("sum(%d,%d,%d)\n",i,l,r);
    int t1, t2, t3;
    split(i, r + 1, t2, t3);
    split(t2, l, t1, t2);
    cout << t[t2].s << endl;
    int t;
    merge(t, t2, t3);
    merge(i, t1, t);
}

int new_node(int v) {
    id++;
    t[id].v = v;
    t[id].sz = 1;
    t[id].prio = rng();
    t[id].s = v;
    t[id].l = t[id].r = 0;
    t[id].rev = false;
    return id;
}

void insert(int& i, int w, int pos) {
    if (!i) i = w; 
    else if (t[i].prio < t[w].prio) {
        split(i, pos, t[w].l, t[w].r), i = w; 
    } else {
        if (sz(t[i].l) < pos) {
            insert(t[i].r, w, pos - sz(t[i].l) - 1);
        } else {
            insert(t[i].l, w, pos);
        }
    }
    update(i);
}

void inorder_helper(int i) {
    if (!i) return;
    inorder_helper(t[i].rev ? t[i].r : t[i].l);
    printf("%d ", t[i].v);
    inorder_helper(t[i].rev ? t[i].l : t[i].r);
}

void inorder(int i) {
    inorder_helper(i);
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int root = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int w = new_node(a[i]);
        insert(root, w, sz(root));
    }
    for (int i = 0; i < m; i++) {
        int x, l, r;
        cin >> x >> l >> r;
        l--, r--;
        if (x == 1) {
            rev(root, l, r);
        } else {
            sum(root, l, r);
        }
    }
}
