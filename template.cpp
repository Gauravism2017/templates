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
template <typename T, typename=typename enable_if<is_arithmetic<T>::value, T>::type> T mod(T val) {while(val > MOD) {val -= MOD;}if(val < 0) {val += MOD;} return val;}
template <typename T, typename=typename enable_if<is_arithmetic<T>::value, T>::type> T __lcm(T a, T b) {return (T)(ll)a*b / __gcd(a, b);}
template <typename T> istream &operator >>(istream& in, vector<T> &vec) {for(int i = 0; i < vec.size(); i++) in>>vec[i];return in;}
template <typename T> ostream &operator <<(ostream& out, vector<T> &vec) {for(int i = 0; i < vec.size(); i++) out<<vec[i];return out;}
template <typename T> struct TreeNode {T val;TreeNode* left;TreeNode* right;TreeNode() {val = 0;left = nullptr;right = nullptr;}TreeNode(T x) {val = x;left = nullptr;right = nullptr;}};
template <typename T> struct ListNode {T val;ListNode* next;ListNode* prev;ListNode() {val = 0;next = nullptr;prev = nullptr;}ListNode(T x) {val = x;next = nullptr;prev = nullptr;}};
void Grapher(vector<vector<int>>&Graph, vector<vector<int>> & input, bool directed) {for(auto vec : input) {Graph[vec[0]].pb(vec[1]);if(!directed) Graph[vec[1]].pb(vec[0]);}}



void solve() {

}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}