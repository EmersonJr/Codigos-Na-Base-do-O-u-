#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define vii vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
#define pcc pair<char, char>
#define iii array<int, 3>
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "Yes";
const string NO = "No";
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
bool vis[100];
bool grid[100][100];
int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b, a%b);
}
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}




void fluminense(){
    int n, a, b; cin >> n>> a >> b;

    vector<float> memo(n+1);
    float ans  = 0;
    if(a!=0){
        for(int i=n-1; i>=0; i--){
           if(i+a<=n)ans+= memo[i+a];
           if(i+b+1<=n)ans-= memo[i+b+1];
           memo[i] = (1.0*(ans+b+1-a))/ (b-a+1); 
        }
    }else {
        for(int i=n-1; i>=0; i--){
           if(i+a+1<=n)ans+= memo[i+a+1];
           if(i+b+1<=n)ans-= memo[i+b+1];
           memo[i] = (1.0*(ans-a+b+1))/(b-a); 
        }
    }
    cout << fixed << setprecision(10);
    // for(int i=0; i<=n; i++) cout << memo[i]<< " ";
    // cout << endl;
    cout << memo[0]  << endl;
}   

int32_t main(){
    sws;  
    int T=1;
    // cin >> T;
    while(T--)fluminense(); 
    
}