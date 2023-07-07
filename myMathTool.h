#include <math.h>
#include <vector>
#include <string>

using namespace std;

int Get_Int_Digit(int Input);
int AbsNum(int a);
int FindMax(int a[],int im);


int Get_Int_Digit(int Input)//获取Int型数字的位数
{
    int returnValue = 0;
    for(int i = 1;i *= 10;)
    {
       // if()
    }
}

int AbsNum(int a)//绝对值
{
    if (a > 0) return a;
    return -a;
}

void AbsNum(int* a)//绝对值的指针重载
{
    int b = *a;
    if (b > 0) return;
    *a = -*a;
    return;
}

int FindMax(int a[],int im)//找到数组中的最大值
{
    int timelyMax = 0;
    for (int i = 0;i < im;i ++)
    {
        if (a[i] > timelyMax) timelyMax = a[i];
    }
    return timelyMax;
}

int Get_Digit(double a)//获取一个数的整数位数
{
    unsigned long long int tmp = 1;
    int rs = 0;
    for (;a/tmp > 1;rs ++)
    {
          tmp *= 10;
    }
    return rs;
}

int Involution(int base,int index)//计算两数乘方
{
    if(index == 0) return 1;
    int a = base;
    for (int i = 1;i < index;i ++)
    {
        base *= a;
    }
    return base;
}

double Involution(double base,int index)//计算两数乘方的DOUBLE重载
{
    double a = base;
    for (int i = 1;i < index;i ++)
    {
        base *= a;
    }
    return base;
}

double Math_AprxM_equal(double a,int digit)//获取一定位数四舍五入的值<未完成>
{
    int Tot_Digit = Get_Digit(a);
    if (digit < Tot_Digit)
    {//在整数位四舍五入
        int dif = Tot_Digit - digit;
        int tmp = a/Involution(10,dif);
    }
    else
    {//在小数位四舍五入

    }
}  

long long int to_BIN(int a)//返回int的二进制形式（以十进制存储<未完成>
{
    long long int ANS = 0;
    for(int tmp = a;tmp > 0;)
    {
        
    }
}
/*
double Cacu_Distant(double x1,double y1,double x2,double y2)//获取两点间距离
{
    return sqrt(abs( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ));
}

double Cacu_Distant(double x1,double y1,double z1,double x2,double y2,double z2)//获取两点间距离的空间重载
{
    return sqrt(abs( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1+z2)));
}

int Str_to_Int(string s)//string to int
{
    int ANS = 0;
    for(int idx = s.length()-1;idx >= 0;idx --)
    {
        if(s[idx] == '-') ANS = -ANS;
        else ANS += (s[idx]-'0')*Involution(10,s.length()-1-idx);
    }
    return ANS;
}
*/