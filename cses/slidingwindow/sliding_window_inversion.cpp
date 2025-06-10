#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
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

struct node {
    int val;
    int height;
    ll freq;
    ll size;
    node* left;
    node* right;
    node(int x): val(x) {
        height = 0;
        freq = 1;
        size = 1;
        left = right = nullptr;
    }
};

int height(node* u) {
    if (u == nullptr) return -1;
    return u->height;
}

ll size(node* u) {
    if (u == nullptr) return 0;
    return u->size;
}

int get_balance(node* u) {
    if (u == nullptr) return 0;
    return height(u->left) - height(u->right);
}

void update(node* u) {
    if (u == nullptr) return;
    u->height = 1 + max(height(u->left), height(u->right));
    u->size = size(u->left) + size(u->right) + u->freq;
}

node* left_rotate(node* u) {
    if (u->right == nullptr) throw runtime_error("right child cannot be null for left rotate");
    node* right_child = u->right;
    node* left = right_child->left;
    u->right = left;
    right_child->left = u;
    update(u);
    update(right_child);
    return right_child;
}

node* right_rotate(node* u) {
    if (u->left == nullptr) throw runtime_error("left child cannot be null for right rotate");
    node* left_child = u->left;
    node* right = left_child->right;
    u->left = right;
    left_child->right = u;
    update(u);
    update(left_child);
    return left_child;
}

node* rebalance(node* u) {
    int b = get_balance(u);
    if (b < -1) {
        if (get_balance(u->right) > 0) {
            u->right = right_rotate(u->right);
        }
        return left_rotate(u);
    } else if (b > 1) {
        if (get_balance(u->left) < 0) {
            u->left = left_rotate(u->left);
        }
        return right_rotate(u);
    } else {
        return u;
    }
}

node* insert(int x, node** root) {
    if (*root == nullptr) {
        *root = new node(x);
        return *root;
    } else {
        int v = (*root)->val;
        if (x == v) {
            (*root)->freq++;
        } else if (x < v) {
            (*root)->left = insert(x, &(*root)->left);
        } else {
            (*root)->right = insert(x, &(*root)->right);
        }
        update(*root);
        return rebalance(*root);
    }
}

node* successor(node* cur) {
    if (cur == nullptr) throw runtime_error("cur cannot be null for successor");
    while (cur->left != nullptr) {
        cur = cur->left;
    }
    return cur;
}

node* predecessor(node* cur) {
    if (cur == nullptr) throw runtime_error("cur cannot be null for predecessor");
    while (cur->right != nullptr) {
        cur = cur->right;
    }
    return cur;
}

node* remove(int x, node** root) {
    if (*root == nullptr) {
        throw runtime_error("can't find " + to_string(x) + " in the tree");
    }
    if ((*root)->val == x) {
        if ((*root)->freq > 1) {
            (*root)->freq--;
            return *root;
        } else {
            bool has_left_child = (*root)->left != nullptr;
            bool has_right_child = (*root)->right != nullptr;

            if (has_left_child && has_right_child) {
                node* succ = successor((*root)->right);
                (*root)->val = succ->val;
                (*root)->freq = succ->freq;
                succ->freq = 1;
                (*root)->right = remove(succ->val, &(*root)->right);
                update((*root)->right);
                update((*root));
                return rebalance(*root);
            } else if (has_left_child) {
                node* left_child = (*root)->left;
                delete (*root);
                return left_child;
            } else if (has_right_child) {
                node* right_child = (*root)->right;
                delete (*root);
                return right_child;
            } else {
                delete (*root);
                return nullptr;
            }
        }
    } else if (x < (*root)->val) {
        (*root)->left = remove(x, &(*root)->left);
        update((*root)->left);
        return rebalance(*root);
    } else {
        (*root)->right = remove(x, &(*root)->right);
        update((*root)->right);
        return rebalance(*root);
    }
}

/**
 * find how many elements in the tree are strictly greater than x
 */
ll query_bigger(int x, node* root) {
    if (root == nullptr) return 0;
    if (x == root->val) return size(root->right);
    else if (x < root->val) return root->freq + size(root->right) + query_bigger(x, root->left);
    else return query_bigger(x, root->right);
}

/**
 * find how many elements in the tree are strictly less than x
 */
ll query_smaller(int x, node* root) {
    if (root == nullptr) return 0;
    if (x == root->val) return size(root->left);
    else if (x > root->val) return root->freq + size(root->left) + query_smaller(x, root->right);
    else return query_smaller(x, root->left);
}

void print_node(node* u, bool show_details = true, bool newline = true) {
    if (u == nullptr) return;
    cout << " u=" << u->val;
    if (show_details) {
        cout << ", freq=" << u->freq << ", height=" << u->height << ", size=" << u->size << " ";
    }
    if (newline) cout << endl;
}

void bfs(node* u) {
    if (u == nullptr) return;
    queue<node*> q;
    q.push(u);
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            node* v = q.front();
            q.pop();
            print_node(v, true, false);
            if (v->left != nullptr) q.push(v->left);
            if (v->right != nullptr) q.push(v->right);
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    
    node* root = nullptr;
    ll inv = 0;
    for (int i = 0; i < k; i++) {
        inv += query_bigger(a[i], root);
        root = insert(a[i], &root);
    }
    cout << inv << " ";
    for (int i = 1; i < n - k + 1; i++) {
        inv -= query_smaller(a[i - 1], root);
        root = remove(a[i - 1], &root);
        inv += query_bigger(a[i + k - 1], root);
        root = insert(a[i + k - 1], &root);
        cout << inv << " ";
    }
    cout << endl;
}
