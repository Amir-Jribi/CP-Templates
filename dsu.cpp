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

int n,m;
int p[N];
int sz[N];
//dont forget to initialize p[i]=i and sz[i]=1 for each i from 1 to n
int find_set (int i)
{
    if (p[i]==i) return i ;
    return p[i]=find_set(p[i]);
    // return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}
bool is_same_set (int i,int j)
{
    return find_set(i)==find_set(j);
}
void union_set(int i,int j)
{
    int a=find_set(i);
    int b=find_set(j);
    if (a!=b)
    {
        if (sz[a]<sz[b]) swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
    }
}

void testcase(){
    for(int i=1;i<=n;i++) {
        p[i]=i;
        sz[i]=1;
    }

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