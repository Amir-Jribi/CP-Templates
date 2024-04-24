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

// point query , range update !! be careful
//store for exemple at each node the index of the query!!

ll tree[4 * N];
ll a[N];
ll n;

void upd_rng(int qs, int qe, int v, int id = 0, int ns = 0, int ne = n - 1) {
    if (qs > ne || qe < ns) {
        return;
    }
    if (qs <= ns && qe >= ne) {
        return tree[id] += v;
    }
    int l = 2 * id + 1;
    int r = l + 1;
    int md = ns + (ne - ns) / 2;
    upd_rng(qs, qe, v, l, ns, md);
    upd_rng(qs, qe, v, r, md + 1, ne);
}

ll query(int p, int id = 0, int ns = 0, int ne = n - 1) {
    if (ns == ne) {
        return tree[id];
    }
    int l = 2 * id + 1;
    int r = l + 1;
    int md = ns + (ne - ns) / 2;
    if (p <= md) {
        return tree[id] + query(p, l, ns, md);
    } else {
        return tree[id] + query(p, r, md + 1, ne);
    }
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