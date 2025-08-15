#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using Node = struct node {
    char c;
    int prio;
    int sz;
    bool rev;
    int l, r;
};

const int MAXN = 2e5 + 2;
struct node t[MAXN];
int id = 0;

int sz(int i) {
    return i ? t[i].sz : 0;
}

void update(int i) {
    if (i) t[i].sz = sz(t[i].l) + sz(t[i].r) + 1;
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
    if (!i) {
        l = r = 0;
        return;
    }
    push(i);
    if (sz(t[i].l) < key) {
        split(t[i].r, key - sz(t[i].l) - 1, t[i].r, r);
        l = i;
    } else {
        split(t[i].l, key, l, t[i].l);
        r = i;
    }
    update(i);
}

void merge(int& i, int l, int r) {
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

void insert(int& i, int v, int pos) {
    if (!i) i = v;
    else if (t[i].prio < t[v].prio) {
        split(i, pos, t[v].l, t[v].r);
        i = v;
    } else {
        if (pos < sz(t[i].l)) {
            insert(t[i].l, v, pos);
        } else {
            insert(t[i].r, v, pos - sz(t[i].l) - 1);
        }
    }
    update(i);
}

int node(char c) {
    id++;
    t[id].c = c;
    t[id].prio = rng();
    t[id].sz = 1;
    return id;
}

void rev(int& i, int l, int r) {
    int t1, t2, t3;
    split(i, r + 1, t2, t3);
    split(t2, l, t1, t2);
    t[t2].rev ^= 1;
    int t;
    merge(t, t2, t3);
    merge(i, t1, t);
}

void inorder(int i) {
    if (!i) return;
    push(i);
    inorder(t[i].rev ? t[i].r : t[i].l);
    printf("%c", t[i].c);
    inorder(t[i].rev ? t[i].l : t[i].r);
}

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int root = 0;
    for (char c : s) {
        int i = node(c);
        insert(root, i, sz(root));
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        rev(root, a, b);
    }
    inorder(root);
    cout << endl;
}
