#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
long long cost[N];
int freq[N];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
    int c;
    node* l;
    node* r;
    int prio;
    multiset<int> s;
    long long sum;
    int sz;
    node(int c, int e): c(c), l(nullptr), r(nullptr), prio(rng()), sum(c), sz(1) {
        s.insert(e);
    }
};

using pnode = node*;

int sz(pnode t) {
    return t ? t->sz : 0;
}

long long sum(pnode t) {
    return t ? t->sum : 0;
}

void update(pnode t) {
    if (t) {
        t->sum = 1ll * t->c * t->s.size() + sum(t->l) + sum(t->r);
        t->sz = t->s.size() + sz(t->l) + sz(t->r);
    }
}

void split(pnode t, int key, pnode& l, pnode& r) {
    // cout<<"split("<<(t?t->c:-1)<<",key="<<key<<")"<<endl;
    if (!t) {
        l = r = nullptr;
    } else if (t->c < key) {
        split(t->r, key, t->r, r), l = t;
    } else {
        split(t->l, key, l, t->l), r = t;
    }
    update(t);
}

void merge(pnode& t, pnode l, pnode r) {
    if (!l || !r) t = l ? l : r;
    else if (l->prio > r->prio) {
        merge(l->r, l->r, r), t = l;
    } else {
        merge(r->l, l, r->l), t = r;
    }
    update(t);
}

pnode find_and_add(pnode t, pnode u) {
    if (!t) return nullptr;
    if (t->c == u->c) {
        t->s.insert(*u->s.begin());
        update(t);
        return t;
    } else if (u->c < t->c) {
        pnode s = find_and_add(t->l, u);
        update(t);
        return s;
    } else {
        pnode s = find_and_add(t->r, u);
        update(t);
        return s;
    }
}

void insert_helper(pnode& t, pnode u) {
    if (!t) {
        t = u;
    } else if (t->prio < u->prio) {
        split(t, u->c, u->l, u->r);
        t = u;
    } else {
        insert_helper(u->c < t->c ? t->l : t->r, u);
    }
    update(t);
}

void insert(pnode& t, pnode u) {
    pnode nd = find_and_add(t, u);
    if (nd) return;
    else insert_helper(t, u); 
}

long long que(pnode t, int k) {
    if (!t || !k) return 0;
    if (sz(t) == k) return sum(t);
    else if (sz(t->l) < k) {
        int x = min((int) t->s.size(), k - sz(t->l));
        return sum(t->l) + 1ll * t->c * x + que(t->r, k - sz(t->l) - x);
    } else {
        return que(t->l, k); 
    }
}

void inorder(pnode t, int level = 0) {
    if (!t) return;
    inorder(t->l, level + 1);
    cout << "cost="<<t->c<<",nodes=[";
    for (auto it = t->s.begin(); it != t->s.end(); it++) {
        cout << *it << " ";
    }
    cout << "], prio=" << t->prio << ", level="<<level<<endl;
    inorder(t->r, level + 1);
}

void erase(pnode& t, int c, int e) {
    if (!t) return;
    if (t->c == c) {
        if (t->s.size() > 1) {
            t->s.erase(t->s.find(e));
        } else {
            pnode temp = t;
            merge(t, t->l, t->r);
            delete temp;
        }
    } else {
        erase(c < t->c ? t->l : t->r, c, e);
    }
    update(t);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    unordered_map<int, vector<int>> m; // can also just use static array since n is small enough
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    pnode root = nullptr;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
        cost[a[i]] += b[i];
        m[a[i]].push_back(b[i]);
        pnode u = new node(b[i], a[i]);
        insert(root, u);
        // cout << "after inserting " << a[i] << " with cost " << b[i] << ":"<<endl;
        // inorder(root);
    }
    // cout<<"------"<<endl;
    // inorder(root);
    // for (int i = 0; i <= n; i++) {
    //     cout << "i="<< i;
    //     cout << ",f="<<find(root, i) <<endl;
    // }
    vector<int> c;
    for (int i = 1; i < N; i++) if (freq[i]) c.push_back(i);
    int q = c.size();
    long long ans = LLONG_MAX;
    long long cur = 0;
    int sz = n;
    for (int i = q - 1; i >= 0; i--) {
        for (auto it = m[c[i]].begin(); it != m[c[i]].end(); it++) {
            // printf("erase(%d,%d,%d)\n", root ? root->c : -1, *it, c[i]);
            erase(root, *it, c[i]);
            // inorder(root);
        }
        if (2 * freq[c[i]] > sz) {
            ans = min(ans, cur);
        } else {
            int k = sz - freq[c[i]] * 2 + 1;
            // cout<<"k="<<k<<",";
            // take sum of lowest k costs to make c[i] the majority
            ans = min(ans, cur + que(root, k));
        }
        // cout<<"q="<<q<<",freq="<<freq[c[i]]<<",";
        cur += cost[c[i]]; 
        sz -= freq[c[i]];

        // cout<<"c="<<c[i]<<",ans="<<ans<<endl;
    }
    cout << ans << endl;
    return 0;
}
