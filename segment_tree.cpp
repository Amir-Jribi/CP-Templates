#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vii;
typedef vector<long long> vll;
double eps = 1e-12;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define ll long long int    
#define llu unsigned
long long mod =1e9+7;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
int gcd (int a,int b) { return b ? gcd (b,a%b):a;}
int lcm (int a,int b){ return a*(b/gcd(a,b));}
const int N=1e6+1,M=20;

ll tree[4 * N];
ll a[N];
ll n;


ll mrg(ll vl, ll vr) {
    return max(vl, vr);
}
//build
void build(ll id = 0, ll ns = 0, ll ne = n - 1) {
    if (ns == ne) {
        tree[id] = a[ns];
        return;
    }
    ll l = 2 * id + 1;
    ll r = l + 1;
    ll md = ns + (ne - ns) / 2;  //(ns+ne)/2;
    build(l, ns, md);
    build(r, md + 1, ne);
    tree[id] = mrg(tree[2 * id + 1], tree[2 * id + 2]);
}

// range query , point update 

void updPosition(ll p, ll v, ll id = 0, ll ns = 0, ll ne = n - 1) {
    if (ns == ne) {
        tree[id] = v;
        return;
    }
    ll l = 2 * id + 1;
    ll r = l + 1;
    ll md = ns + (ne - ns) / 2;
    if (p <= md) {
        updPosition(p, v, l, ns, md);
    } else {
        updPosition(p, v, r, md + 1, ne);
    }
    tree[id] = mrg(tree[2 * id + 1], tree[2 * id + 2]);
    
}

ll query(ll qs, ll qe, ll id = 0, ll ns = 0, ll ne = n - 1) {
    if (qs > ne || qe < ns) return 0;
    if (qs <= ns && qe >= ne) return tree[id];
    ll l = 2 * id + 1;
    ll r = l + 1;
    ll md = ns + (ne - ns) / 2;
    return mrg(query(qs, qe, l, ns, md), query(qs, qe, r, md + 1, ne));

    //query(qs, qe, l, ns, md): might return 0 if it's out of range
    //query(qs, qe, r, md + 1, ne): might return 0 if it's out of range
    //and it's useless to merge 2 nodes because we already made a merge in updPosition
}

void testcase(){

}


int main(){
    fast;
 // #ifndef ONLINE_JUDGE
 //     freopen("C:/Users/LENOVO/cp/input.txt","r",stdin);
 //     freopen("C:/Users/LENOVO/cp/output.txt","w",stdout);
 // #endif
 //    clock_t z=clock();
    int T=1;
    cin>>T;
    while(T--) {
        //cout<<"Case #"<<tt++<<": ";
        testcase();
    }
    //cerr <<endl<<"Run Time: " <<((double)(clock() -z) / CLOCKS_PER_SEC)<<endl;
    return 0;
}
