#ifndef _INC_STDIO
#include <stdio.h>
#endif
#ifndef _GLIBCXX_IOSTREAM 1
#include <iostream>
#endif

using namespace std;

void UpdatePrc(int TTL,int Rec,int Wed)
{
    system("cls");
    double p = (double)Rec / (double) TTL;
    printf("%.2lf",p * 100);
    cout << "% - " ;
    int num = (int)((double)Wed * p);
    for (int i = 0;i < num;i ++)
    {
        cout << "��";
    }
    cout << endl;
}