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

ll n,c;
ll a[N];
ll tree[4*N];
ll lzy[4*N];
//lazy propagation:
//range update O(log(n))+range query O(log(n))
ll  mrg(ll vl,ll vr){
    return min(vl,vr);
}
void build(ll id=0,ll ns=0,ll ne=n-1){
    lzy[id]=0;
    if (ns==ne){
        tree[id]=a[ns];
        return;//!!!
    }
    ll l=2*id+1;
    ll r=l+1;
    ll md=ns+(ne-ns)/2;
    build(l,ns,md);
    build(r,md+1,ne);
    tree[id]=mrg(tree[l],tree[r]);
}
 
void upd_rng(ll qs,ll qe,ll v,ll id=0,ll ns=0,ll ne=n-1){
    if (lzy[id]){
        tree[id]+=lzy[id]; //tree[id]+=(ne-ns+1)*lzy[id];
        if (ns!=ne){
            lzy[2*id+1]+=lzy[id];
            lzy[2*id+2]+=lzy[id];
        }
        lzy[id]=0;
    }
    if (ns>qe||ne<qs) return;
    if (qs<=ns && qe>=ne){
        tree[id]+=v; //tree[id]+=(ne-ns+1)*v;
        if (ns!=ne){
            lzy[2*id+1]+=v;
            lzy[2*id+2]+=v;
        }
        return;
    }
    ll l=2*id+1;
    ll r=l+1;
    ll md=ns+(ne-ns)/2;
    upd_rng(qs,qe,v,l,ns,md);
    upd_rng(qs,qe,v,r,md+1,ne);
    tree[id]=mrg(tree[l],tree[r]);
}
 
ll query(ll qs,ll qe,ll id=0,ll ns=0,ll ne=n-1){
    if (lzy[id]){
        tree[id]+=lzy[id]; //tree[id]+=(ne-ns+1)*lzy[id];
        if (ns!=ne){
            lzy[2*id+1]+=lzy[id];
            lzy[2*id+2]+=lzy[id];
        }
        lzy[id]=0;
    }
    if (ns>qe||ne<qs) return 1e18;
    if (qs<=ns && qe>=ne){
        return tree[id];
    }
    ll l=2*id+1;
    ll r=l+1;
    ll md=ns+(ne-ns)/2;
    ll vl=query(qs,qe,l,ns,md);
    ll vr=query(qs,qe,r,md+1,ne);
    return mrg(vl,vr);  
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