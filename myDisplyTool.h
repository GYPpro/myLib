#ifndef MY_TIMER
#include<myTimer.h>
#endif
#ifndef _INC_STDIO
#include <stdio.h>
#endif
#ifndef _GLIBCXX_IOSTREAM 1
#include <iostream>
#endif
#ifndef TIME_H
#include <time.h>
#endif
// #include <myTimer.h>
// #define long long long long

class myPrc{
private:
    unsigned long long int TTL; //进度条最大值
    unsigned long long int Rec; //目前值
    unsigned long long int Wed; //输出宽度 
    unsigned long long int ltr; //目前进度条走到哪了
    std::string mes;            //进度条文本
    myTimer timer;              //计时器

    enum UPGRADE_TYPE {Linear,Power,Log};
    UPGRADE_TYPE constomUpdType;//拟合类型
    long double LinearK,        //线性系数
                PowerK,PowerIdx,//指数系数与幂
                LogK;           //对数系数
    bool ifCompleteFitting;     //是否完成拟合
    unsigned long long int nextUpdateIdx;

    std::string ral = "-\\|/";

    long double LinearTic(unsigned long long int x)
    {
        return LinearK*x;
    }

    long double PowerTic(unsigned long long int x)
    {
        return PowerK * pow(x,PowerIdx);
    }

    long double LogTic(unsigned long long int x)
    {
        return LogK * log(x);
    }

    void UpdatePrc()
    {
        
    }

    void Fitting(std::vector<unsigned long long int> upgradeTicList) //TODO：非线性拟合
    {
        if(ifCompleteFitting)
        {
            reFitting(upgradeTicList);
            return;
        }
        if (upgradeTicList.size() < 100) return;

        ifCompleteFitting = 1;
        long double LinearCmp = 0;   //线性拟合贴合度
        long double PowerCmp = 0;    //指数拟合贴合度
        long double LogCmp = 0;      //对数拟合贴合度
        long double x1 = (long double)49;
        long double y1 = (long double)upgradeTicList[49];
        long double x2 = (long double)99;
        long double y2 = (long double)upgradeTicList[99];

        //完成三项函数拟合
        LinearK = (long double)(upgradeTicList[99] - upgradeTicList[0])/100.0;
        PowerIdx = log(y2/y1)/log(x2/x1);
        PowerK = y2/(pow(x2,PowerIdx));
        LogK = (y1-y2)/(log(x1)-log(x2));
        
        for(int i = 1;i < upgradeTicList.size();i ++)
        {
            LinearCmp += LinearTic(i) - 
        }
        return;
    }

    void reFitting(std::vector<unsigned long long int> &upgradeTicList)
    {

        return;
    }

    void LinearFitting()
    {
        unsigned long long int durTime = timer.getDurFromInit();
        LinearK = (long double)durTime/(long double)Rec;
        ifCompleteFitting = true;
        constomUpdType = Linear;
        return;
    }
    
public:
    myPrc(unsigned long long int _TTL,unsigned long long int _Wed,std::string _mes)
    {
        TTL = _TTL;
        Rec = 0;
        Wed = _Wed;
        mes = _mes;
        ifCompleteFitting = 0;
        nextUpdateIdx = 1;
        timer.reset();
        return this;
    }

    myPrc()
    {
        TTL = 1;
        Rec = 0;
        Wed = 50;
        ifCompleteFitting = 0;
        nextUpdateIdx = 1;
        mes = "PrcInitError\n";
        timer.reset();
        return this;
    }

    void reset()
    {
        Rec = 0;
        timer.reset();
        return;
    }

    void update()// [----...----]00.00%:s\n
    {
        Rec ++;
        if(Rec > nextUpdateIdx)
        {
            LinearFitting();
            unsigned long long int newltr = Rec*Wed/TTL;

        } else return;
        return;
    }

    void finished()
    {

        return;
    }

};

// void UpdatePrc(long long int TTL,long long int Rec,long long int Wed,std::string s)
// {
//     system("cls");
//     double p = (double)Rec / (double) TTL;
//     printf("%.2lf",p * 100);
//     cout << "% [ " ;
//     long long int num = (long long int)((double)Wed * p);
//     for (int i = 0;i < num;i ++)
//         cout << "-";
//     for(int i = num;i < Wed;i ++)
//         cout << " ";
//     cout << " ]:" << s;
//     cout << endl;
// }