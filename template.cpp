#include <bits/stdc++.h>
using namespace std;
#define MOD (int)1e9+7;
typedef long long int ll;
template <typename T> void print(T &vec) {for(auto d : vec) {cout<<d<<' ';}}
template <typename T> void print(T &vec, bool debug) {int = 0; for(auto d : vec) {cout<<i<<" : " << d<<'\n';i++}}
template <typename T> void print2D(T &mat) {for(auto vec : mat) {print(vec);cout<<'\n';}}
template <typename T> void print2D(T &mat, bool debug) {int = 0; for(auto vec : mat) {cout<<"row : "<<i++<<'\n';print(vec, true);cout<<'\n';}}
template <typename T> void add(T a, T b) {a += b;}
template <typename T> T add(T a, T b) {reurn a += b;}
template <typename T, typename=typename enable_if<is_arithmetic<T>::value, T>::type> void mod(T &val) {while(val > MOD) {val -= MOD;}if(val < 0) {val += MOD;}}
template <typename T, typename=typename enable_if<is_arithmetic<T>::value, T>::type> T mod(T val) {while(val > MOD) {val -= MOD;}if(val < 0) {val += MOD;} return val;}
template <typename T, typename=typename enable_if<is_arithmetic<T>::value, T>::type> T __lcm(T a, T b) {return (T)(ll)a*b / __gcd(a, b);}

void solve() {

}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}