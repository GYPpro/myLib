// #include <iostream>
// #include <myDisplyTool.h>
// using namespace std;

// #define uul unsigned long long 

// uul int jc(int n)
// {
//     uul int ans = 1;
//     for(int i = 1;i <= n;i ++) ans *= i;
//     return ans;
// }

// uul int c(uul int m,uul int n)
// {
//     return (jc(m)/jc(n))/jc(m-n);
// }

// void solve()
// {
//     int m,n;
//     cin >> m >> n;
    
//     cout << c(m+n-1,n-1) << endl;
// }

// int main()
// {
//     int T;
//     cin >> T;
//     for(int i = 0;i < T;i ++) solve();
//     system("pause");
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <myTimer.h>
#include <iostream>
#include <myRand.h>

int main()
{
    // std::ios::sync_with_stdio(0);
    // std::cout.tie(0);
    // // printf("1234567890\n");
    // std::string s = "1234567890";
    // // printf("%s",s.c_str());
    // // printf("\x1b[5D*\x1b[4C#\n");
    // // system("pause");
    // myTimer timer;
    // for(int i = 0;i < 1e5;i ++) 
    //     std::cout << s << "\n";
    //     // printf("%s",s.c_str());
    // // printf("\n");
    // // timer.printDurFromInit();
    // unsigned long long int tr = timer.getDurFromInit();
    // std::cout << "\n" << (double)tr/CLOCKS_PER_SEC << std::endl;

    myRandToolkit mrt;

    for(;;)
    {
        cout << mrt.Get_Rand_Int_mod(1,3) << "\n";
        system("pause");
    }

    system("pause");
}