#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define pb push_back
#define endl "\n"
#define input(x) for (auto &it : x) cin >> it;
#define output(x) for (auto &it : x) cout << it << ' ';
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const double PI = acos(-1);

const int MOD = 1e9 + 7;
vector<int> fib(90);
void fibo()
{
	
	fib[0] = 1;
	fib[1] = 1;
	for(int i = 2; i < 90; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
	return;
}
char solve_F(int n, int i)
{
	if(i == 1) return 'B';
	if(i == 2) return 'A';
	int aux = fib[i-1];
	if(n > aux) return solve_F(n-aux, i-2);
	else return solve_F(n, i-1);
}
char solve_S(int n, int i)
{
	if(i == 1) return 'B';
	if(i == 2) return 'A';
	int aux = fib[i-2];
	if(n > aux) return solve_S(n-aux, i-1);
	else return solve_S(n, i-2);
}

int32_t main()
{   sws		
	fibo();
	for(int i = 0; i < 90; i++) cout << fib[i] << " ";
	cout << endl;
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for(int i = 0; i < n; i++)
	{ 
		int x = v[i];
		auto it = lower_bound(fib.begin(), fib.end(), x) - fib.begin();
		cout << fib[it] << "\n";
		if(solve_F(x, it) != solve_S(x, it))
		{
			cout << "wa\n";
			return 0;
		}
	}
	cout << "ac\n";

    return 0;
}