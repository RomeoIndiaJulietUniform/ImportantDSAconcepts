#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(x) (ll)((x).size())
#define all(x) begin(x), end(x)
#define ff first
#define ss second
#define SIZE 26

#define endl '\n'



class UF {
    vector<int> parent;
public:
    UF(int size) {
        parent.resize(size);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool Union(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return false;

        parent[xr] = yr;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        UF uf(n);

        for (const auto& e : edges) {
            if (!uf.Union(e[0], e[1])) {
                return e;
            }
        }

        return {};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> redundantConnection = sol.findRedundantConnection(edges);
    for (int i : redundantConnection) {
        cout << i << " ";
    }
    return 0;
}
