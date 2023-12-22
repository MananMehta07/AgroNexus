////#include <iostream>
////#include<vector>
////#include<algorithm>
////#include<math.h>
////#include<bits/stdc++.h>
////using namespace std;
////int MOD = 1e9 + 7;
////const int MAXN = 2e5+ 10;
////#pragma GCC optimize("Ofast")
////#pragma GCC optimize ("unroll-loops")
////#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
////#pragma GCC optimize("O2")
////typedef long long ll;
////#define int long long
////#define endl '\n'
////#define  ps(x,y)     fixed<<setprecision(y)<<x
////#define sz(x) ((long long)(x).size())
////#define all(x)  x.begin(),x.end()
////#define rall(x) (x).rbegin(), (x).rend()
////#define trav(a,x) for (auto& a : x)
////#define ff first
////#define ss second
////#define pb push_back
////#define setbits(x)      __builtin_popcountll(x)
////#define zerobits(x)      __builtin_ctzll(x)
////#define leastsigbit(x)     __builtin_ffs(x)
////#define hmap        unordered_map
////#define hset        unordered_set
////#define vi vector<int>
////#define vs vector<string>
////#define vvi vector<vector<int>>
////#define vl vector<ll>>
////#define vvl vector<vl>
////#define pii pair<int,int>
////#define vpii vector<pii>
////#define pll pair<ll, ll> ;
////#define _ << " " <<
////#define deb(x) cout << #x << "=" << x << endl
////#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
////#define fo(i, n) for(int i=0;i<n;i++)
////#define Fo(i, k, n) for(int i=k; i<n;i++)
////#define tt ll tt;cin >> tt;while(tt--)
////#define  fio ios::sync_with_stdio(0); cin.tie(NULL);
////#define D1(x) { cerr << " [" << #x << ": " << x << "]\n"; }
////#define D2(x) { cerr << " [" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n";}
////#define debug(...) fprintf(stderr, _VA_ARGS_), fflush(stderr) \
////const double PI = acos(-1);
////void fileIo(){
////#ifndef ONLINE_JUDGE
////    freopen("input.txt", "r", stdin);
////    freopen("output.txt", "w", stdout);
////#endif
////}
////
////int rand(long long a, long long b) {
////    return a + rand() % (b - a + 1);
////}
////ll add(ll x, ll y) {ll res=x+y; return(res>=MOD?res-MOD:res);}
////ll mul(ll x, ll y) {ll res=x*y; return(res>=MOD?res%MOD:res);}
////ll sub(ll x, ll y) {ll res=x-y; return(res<0?res+MOD:res);}
////ll power(ll a,ll b,ll m=MOD){ ll ans=1; a=a%m;  while(b>0) {  if(b&1)  ans=(1ll*a*ans)%m; b>>=1;a=(1ll*a*a)%m;}return ans;}
////ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
////ll lcm( ll x, ll y) { return (x*y)/gcd(x,y);}
////ll cubic_root(ll x) {
////    ll l = 0, r = 1e6;
////    while (l != r) {
////        ll m = (l + r + 1) / 2;
////        if (m * m * m > x)
////            r = m - 1;
////        else
////            l = m;
////    }
////    return l;
////}
////bool isprime(ll n){if(n < 2) return 0; ll i = 2; while(i*i <= n){if(n%i == 0) return 0; i++;} return 1;}
////bool isPowerOfTwo(int x) {
////    /* First x in the below expression is for the case when x is 0 */
////    return x && (!(x&(x-1)));
////}
////double distform(int x, int y, int z, int w) {//(x1,y1,x2,y2)
////    return sqrt(1. * pow(x-z,2) + 1. * pow(y-w,2));
////}
////int dx[] = {-1,1,0,0,-1,1,1,-1};
////int dy[] = {0,0,1,-1,1,1,-1,-1};
////const ll inf = 1e18;
////template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
////template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
////
////int intlog(double base, double x) {
////    return (int)(log(x) / log(base));
////}
////bool isvalid (int x, int y,int n,int m) {
////    return x >= 0 and x < n and y >= 0 and y < m;
////}
////#define yess cout<<"YES"<<endl
////#define noo cout<<"NO"<<endl
////template <typename T> void read(T &x) {for (int i = 0; i < sz(x); ++i) cin >> x[i];
////}
////struct custom_hash {
////    static uint64_t splitmix64(uint64_t x) {
////        // http://xorshift.di.unimi.it/splitmix64.c
////        x += 0x9e3779b97f4a7c15;
////        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
////        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
////        return x ^ (x >> 31);
////    }
////
////    size_t operator()(uint64_t x) const {
////        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
////        return splitmix64(x + FIXED_RANDOM);
////    }
////    //unordered_map<long long, int, custom_hash> safe_map;
////};
////struct Local {
////    char paramA;
////    Local(char paramA) { this->paramA = paramA; }
////    bool operator () (int i, int j, ...) {
////        return false;
////    }
////
////};
////// Operator overloads
////template <typename T1, typename T2> // cin >> pair<T1, T2>
////istream &operator>>(istream &istream, pair<T1, T2> &p)
////{
////    return (istream >> p.first >> p.second);
////}
////
////template <typename T> // cin >> vector<T>
////istream &operator>>(istream &istream, vector<T> &v)
////{
////    for (auto &it : v)
////        cin >> it;
////    return istream;
////}
////
////template <typename T1, typename T2> // cout << pair<T1, T2>
////ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
////{
////    return (ostream << p.first << " " << p.second << ", ");
////}
////template <typename T> // cout << vector<T>
////ostream &operator<<(ostream &ostream, const vector<T> &c)
////{
////    for (auto &it : c)
////        cout << it << " ";
////    return ostream;
////}
////int getNum(char c){return c-'0';}
////
////int factorial(int nums){
////    if(nums==0) return 1;
////    else return nums--* factorial(nums);
////}
////
////
////int binary_search()
////{
////    while(low<=high){
////        int mid=low+(high-low)/2;
////        if(nums[mid]==target){
////            first=mid;
////            high=mid-1;
////        }
////        else if(nums[mid]>target){
////            high=mid-1;
////        }
////        else{
////            low=mid+1;
////        }
////    }
////}
////
////// It will only take 5 mins to recheck your code
////// Always check the
////// Run your code on some corner cases before submitting
////// Did you handle all the corner cases?
////// Special case n == 1 ?
////// Sorting helps?a
////void lessgo() {
////}
////
////int32_t main() {
////    tt
////        lessgo();
////}
//
//
//
//
//int lcsUtil(string& s1, string& s2, int ind1, int ind2,  vector<vector<int>>& dp){
//
//    if(ind1<0 || ind2<0)
//        return 0;
//
//    if(dp[ind1][ind2]!=-1)
//        return dp[ind1][ind2];
//
//    if(s1[ind1] == s2[ind2])
//        return dp[ind1][ind2] = 1 + lcsUtil(s1,s2,ind1-1,ind2-1,dp);
//
//    else
//        return dp[ind1][ind2] = 0 + max(lcsUtil(s1,s2,ind1,ind2-1,dp),lcsUtil
//                (s1,s2,ind1-1,ind2,dp));
//
//}
//
//
//int lcs(string s1, string s2) {
//
//    int n=s1.size();
//    int m=s2.size();
//
//    vector<vector<int>> dp(n,vector<int>(m,-1));
//    return lcsUtil(s1,s2,n-1,m-1,dp);
//}
//
//int main() {
//
//    string s1= "acd";
//    string s2= "ced";
//
//    cout<<"The Length of Longest Common Subsequence is "<<lcs(s1,s2);
////}   }
////};
//
//#include <iostream>
//#include <bits/stdc++.h>
//#include <cmath>
//using namespace std;
//#define ll long long
//#define pb push_back
//#define yes cout<<"YES"<<endl;
//#define no cout<<"NO"<<endl;
