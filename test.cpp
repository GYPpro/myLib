#include <iostream>
using namespace std;

#define uul unsigned long long 

uul int jc(int n)
{
    uul int ans = 1;
    for(int i = 1;i <= n;i ++) ans *= i;
    return ans;
}

uul int c(uul int m,uul int n)
{
    return (jc(m)/jc(n))/jc(m-n);
}

void solve()
{
    int m,n;
    cin >> m >> n;
    
    cout << c(m+n-1,n-1) << endl;
}

int main()
{
    int T;
    cin >> T;
    for(int i = 0;i < T;i ++) solve();
    system("pause");
    return 0;
}