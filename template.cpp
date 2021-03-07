#include <bits/stdc++.h>
using namespace std;
#define MOD (int)1e9+7
#define pb push_back
typedef long long int ll;
template <typename T> void print(T &vec) {for(auto d : vec) {cout<<d<<' ';}}
template <typename T> void print(T &vec, bool debug) {int i = 0; for(auto d : vec) {cout<<i<<" : " << d<<'\n';i++;}}
template <typename T> void print2D(T &mat) {for(auto vec : mat) {print(vec);cout<<'\n';}}
template <typename T> void print2D(T &mat, bool debug) {int i = 0; for(auto vec : mat) {cout<<"row : "<<i++<<'\n';print(vec, true);cout<<'\n';}}
template <typename T> void add(T a, T b) {a += b;}
template <typename T> T add(T a, T b) {return a += b;}
template <typename T, typename=typename enable_if<is_arithmetic<T>::value, T>::type> void mod(T &val) {while(val > MOD) {val -= MOD;}if(val < 0) {val += MOD;}}
template <typename T, typename=typename enable_if<is_arithmetic<T>::value, T>::type> T __mod__(T val) {while(val > MOD) {val -= MOD;}if(val < 0) {val += MOD;} return val;}
template <typename T, typename=typename enable_if<is_arithmetic<T>::value, T>::type> T __lcm(T a, T b) {return (T)(ll)a*b / __gcd(a, b);}
template <typename T> istream &operator >>(istream& in, vector<T> &vec) {for(int i = 0; i < vec.size(); i++) in>>vec[i];return in;}
template <typename T> ostream &operator <<(ostream& out, vector<T> &vec) {for(int i = 0; i < vec.size(); i++) out<<vec[i]<<' ';return out;}
template <typename T> struct TreeNode {T val;TreeNode* left;TreeNode* right;TreeNode() {val = 0;left = nullptr;right = nullptr;}TreeNode(T x) {val = x;left = nullptr;right = nullptr;}};
template <typename T> struct ListNode {T val;ListNode* next;ListNode* prev;ListNode() {val = 0;next = nullptr;prev = nullptr;}ListNode(T x) {val = x;next = nullptr;prev = nullptr;}};
void Grapher(vector<vector<int>>&Graph, vector<vector<int>> & input, bool directed) {for(auto vec : input) {Graph[vec[0]].pb(vec[1]);if(!directed) Graph[vec[1]].pb(vec[0]);}}
template <typename T, typename=typename enable_if<is_arithmetic<T>::value, T>::type> struct SegmentTree {vector<T> vec;vector<T> lazy;size_t size;SegmentTree() {}SegmentTree(int n) {this->vec.assign((int)pow(2, (int)log2(n) + 1) + 1, 0); size = n;}SegmentTree(vector<T> &inp) {size = inp.size();this->vec.assign((int)pow(2, (int)log2(size) + 1) + 1, 0);set(inp, 0, size, 0);}
T query(int l, int r) {return query(l, r, 0, size, 0);}void set(vector<T> &inp, int lx, int rx, int node) {if(rx - lx == 1) this->vec[node] = inp[lx];else {int mid = lx + (rx - lx) / 2;set(inp, lx, mid, 2*node + 1);set(inp, mid, rx, 2*node + 2);this->vec[node] = this->vec[node*2 + 1] + this->vec[2*node + 2];} }T query(int l, int r, int lx, int rx, int node) {if(r <= lx || l >= rx) return 0;if(lx >= l and rx <= r) return this->vec[node];int mid = lx + (rx - lx) / 2;T p1 = query(l, r, lx, mid, 2*node + 1);T p2 = query(l, r, mid, rx, 2*node + 2);return (p1 + p2);}};
vector<int> erosthanos(int n) {vector<bool> prime(n + 1, true);int counter = n - 1;for(int p = 2; p * p <= n; p++) {if(prime[p]) {for(int i = p * p; i <= n; i+=p) {if(prime[i]) counter--;prime[i] = false;}}}vector<int> ans(counter);for(int p = 2,i = 0; p <= n; p++) {if(prime[p]) {ans[i] = p;i++;}}return ans;}
vector<bool> sieve(int n) {vector<bool> prime(n + 1, true);for(int p = 2; p * p <= n; p++) {if(prime[p]) {for(int i = p * p; i <= n; i+=p) {prime[i] = false;}}}return prime;}
vector<int> factorial(int n) {vector<int> ans(n + 1);ans[0] = 1;for(int i = 0; i <= n; i++) {ans[i] = __mod__(ans[i - 1] * i);}return ans;}
vector<int> Dijkstra(vector<vector<int>> &Graph, int src) {auto mindist = [&](vector<int> &dist, vector<bool> &spr){int min = INT_MAX, min_index; for (int v = 0; v < dist.size(); v++) if (spr[v] == false && dist[v] <= min) min = dist[v], min_index = v; return min_index; };int n = Graph.size();vector<int> dist(Graph.size(), INT_MAX);vector<bool> spr(Graph.size(), false);dist[src] = 0;for(int count = 1; count<n; count++ ) {int u = mindist(dist, spr);spr[u] = true;for(int v = 0; v < n; v++)if (!spr[v] && Graph[u][v] && dist[u] != INT_MAX && dist[u] + Graph[u][v] < dist[v]) dist[v] = dist[u] + Graph[u][v]; }return dist;}
vector<int> Rabin(string txt, string pattern, int q, int d=256) {vector<int> ans;int M = pattern.size();int N = txt.size();int i, j, p = 0, t = 0, h = 1;for(int i = 0; i < M - 1; i++) h = (h * d) % q;for(int i = 0; i < M; i++) {p = (d * p + pattern[i]) % q;t = (d * t + txt[i]) % q;}for(int i = 0; i <= N - M; i++) {if(p == t) {for(j = 0; j < M; j++) {if(txt[i + j] != pattern[j]) break;}if(j == M) ans.push_back(i);}if(i < N - M) {t = (d*(t - txt[i]*h)+ txt[i + M])%q;if(t < 0) t += q;}}return ans;}
vector<int> KMP(string txt, string pattern) {auto LPS = [](string pattern){int i = 1, len = 0, size = pattern.size();vector<int> lps(size, 0);while(i < pattern.size()) {if(pattern[i] == pattern[len]) {len++;lps[i] = len;i++;}else {if(len) len = lps[len - 1];else {lps[i] = 0;i++;}}}return lps;};vector<int> ans;int M = pattern.size(), N = txt.size(), i = 0, j = 0;auto lps = LPS(pattern);while(i < N) {if(pattern[j] == txt[i]) {j++;i++;}if(j == M) {ans.push_back(i - j); j = lps[j - 1];}else if(i < N and pattern[j] != txt[i]) {if(j) j = lps[j - 1];else i++;}}return ans;}
string Manachers(string s) {auto convert = [](string &s) {string str = "@";for(int i = 0; i < s.size(); i++) {str += "#"; str += s[i];}str += "#$";return str;};string str = convert(s);vector<int> log(str.size());int c = 0, r = 0;for(int i = 1; i < str.size() - 1; i++) {int mir = c - (i - c);if(r > i) {log[i] = min(r - i, log[mir]);}while(str[i + 1 + log[i]] == str[i - 1 - log[i]]) log[i]++;if(i + log[i] > r) {c = i;r = i + log[i];}}int maxLen = 0, center = 0;for(int i = 1; i < str.size() - 1; i++) {if(log[i] > maxLen) {maxLen = log[i];center = i;}}return s.substr((center - 1 - maxLen) / 2, maxLen);}



void solve() {
    cout<<Manachers("Gaurauuarhj");
}

int main() {
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}


