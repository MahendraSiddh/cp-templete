#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#include <bits/stdc++.h>
using namespace std;

using uint = uint32_t;
using ll = int64_t;
using ull = uint64_t;

const ll mod = 1e9 + 7;
const ll N = 3 * 1e5 + 1;

#if defined(LOCAL)
#include "_debug.h"
#else
#define clg(...)
#endif


void solve() {

    int n,k;
    cin>>n>>k;

    string a,b;
    cin>>a>>b;

    vector<int>v;
    vector<ll>p(n+1),s(n+1),v1(n+2),v2(n+2);

    ll l = 0;
    for(int i=0; i<n; ++i){

        if(i) p[i] = p[i-1];
        if(a[i]==b[i]){
            p[i] = 1;
            if(i) p[i] = 1 + p[i-1] + l;
            ++l;
        }else{
            l = 0;
            v.push_back(i);
        }
        v1[i] = l;
    }

    l = 0ll;
    for(int i=n-1; i>=0; --i){

        s[i] = s[i + 1];
        if (a[i] == b[i]) {
            s[i] = 1 + s[i+1] + l;
            ++l;
        } else l = 0;

        v2[i] = l;
    }

    if(k==0){
        cout<<p[n-1]<<endl;
        return;
    }

    ll ans = 0;


    int m = v.size();

    for(int i=0; i<m; ++i){

        ll curr = 0;
        l = 0;
        int r = 0;
        if(v[i]) l = v[i] - v1[v[i]-1];

        set<char>st;

        for(int j=i; j<m; ++j){

            if(st.find(a[v[j]])!=st.end() || st.size()<k){

                st.insert(a[v[j]]);
                r = v[j] + v2[v[j]+1];
            }else break;
        }

        ll len = r-l+1;
        curr = len*(len+1)/2 + s[r+1];
        if(l) curr = curr + p[l-1];

        ans = max(ans,curr);

        cout<<r<<" ";

    }

    cout<<ans<<endl;
}

int32_t main() {
#ifdef CDEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        solve();
    }
    return 0;
}