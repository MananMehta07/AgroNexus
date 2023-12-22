// Lets go to the next level
// AIM EXP at CF *__* asap
// Hit A,B,C faster and reach Expert
// Remember you were also a novice when you started,
// hence never be rude to anyone who wants to learn something!Be calm and help everyone.
// Never open the rank list until and unless you are done with solving problems!
/*HACK ME IF YOU CAN!
░░███▒▒░░░░░░░░░░░░░░░░████
░░████▒░░░░░░░░░░░░░░░███▒█
░░██████░░░░░░░░░░░░░███▒▒▒█
░░██▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒█████▒██
░▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▓▓▓▓▓▓▒▒▒░██
▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒█
▒▒▓▓███████▓░▓▓███████▓▒▒▒▒▒▒
▒▒▓▓▓█▓▄▓█▓░░░▓▓█▓▄▓█▓▓▒▒▒▒▒▒
▒▒▓▓▓▓███▓░░░░░▓▓███▓▓▓▒▒▒▒▒▒
▒▒▒▓▓▓▓▓▓████▓▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒
▒▒▒▒▓▓▓▓▓▒██▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒
▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
░▒▒▒▒▒▒▒▒█████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
░░▒▒▒▒▒▒█▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒
░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
*/

#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
using namespace std;
#define ll long long int
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define yess cout<<"YES"<<endl;
#define noo cout<<"NO"<<endl;
#define vi vector<ll>

//int power(int a,ll b,int m=MOD){ int ans=1; a=a%m;  while(b>0) {  if(b&1)  ans=(1ll*a*ans)%m; b>>=1;a=(1ll*a*a)%m;}return ans;}
void dispvector(vector<ll>& v) {
    if (v.size() == 0) {
        cout << "empty\n";
        return;
    }
    cout << v[0];
    for (int i = 1; i<(int)v.size(); i++) cout << " " << v[i];
    cout << endl;
}
ll lcm( ll x, ll y) { return (x*y)/__gcd(x,y);}
bool isprime(ll n){if(n < 2) return 0; ll i = 2; while(i*i <= n){if(n%i == 0) return 0; i++;} return 1;}
bool isPowerOfTwo(int x) {
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x & (x - 1)));
}

bool isPrime[1000001];
void seive()  {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    isPrime[2] = true;
    for(ll i = 2; i*i < 1000001; ++i) {
        if(isPrime[i]) {
            for(ll j = i*i; j < 1000001; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
vector<ll> getFactors(ll n){vector<ll> v;for(ll i=1; i*i <= n; i++){if(n%i == 0){v.push_back(i);if(i != n/i) v.push_back(n/i);}}return v;}


//ll giveSqrt(ll x) {
//    ll low = 1, high = 3e9, ans = 1;
//    while (low <= high) {
//        ll mid = (low + high) / 2;
//        if (mid * mid <= x) {
//            ans = mid;
//            low = mid + 1;
//        } else high = mid - 1;
//    }
//    return ans;1
//}

int main() {
    fast_io;
    cout << setprecision(12) << fixed;
    ll mod = 10e9+7;
    int n = 0,m=0,q=0;
    cin>>n>>m>>q;
    while(q--){
        int s=0;
        cin>>s;
        int k = 0;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += (i*n);
            if(sum>=s){
                k = i;
                break;
            }
        }
        sum -= k*m;
        int keep = 0;
        for (int i = 1; i <= m; ++i) {
            sum += k;
            if(sum>=s){
                keep= i;
                break;
            }
        }
        int remove = sum - s;
        int a[k+1];
        for (int i = 1; i < k; ++i) {
            if(i==remove){
                a[i] = m - 1;
            }
            else{
                a[i] = 1;
            }
        }
        a[k] = keep;
        cout<<1<<" "<<k<<" ";
        for (int i = 1; i <= k; ++i) {
            cout<<a[i]<<" ";
        }

    }
}









