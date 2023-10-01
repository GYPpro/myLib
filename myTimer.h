#ifndef TIME_H
#include <time.h>
#endif
#ifndef _GLIBCXX_VECTOR
#include <vector>
#endif
#ifndef _INC_STDIO
#include <stdio.h>
#endif
#ifndef _GLIBCXX_IOSTREAM 1
#include <iostream>
#endif

class myTimer{
private:
    unsigned long long int initTic;
    std::vector<unsigned long long int> recTicList;
    unsigned long long int nowTic;

    void updateNowTic()
    {
        nowTic = (unsigned long long int)clock();
    }

public:

    void printTime(long double sec)
    {
        int min = (int)sec / 60;
        int hour = min / 60;
        int day = hour / 24;
        int year = day / 365;
        if(year > 0){
            printf("%dy ",year);
            day -= year * 365;
        }
        if(day > 0){
            printf("%dd ",day);
            hour -= day * 24;
        }
        if(hour > 0){
            printf("%dh ",hour);
            min -= hour * 60;
        }
        if(min > 0){
            printf("%dm ",min);
            sec -= min * 60;
        }
        printf("%.3lfs ",sec);
    }

    myTimer()
    {
        initTic = clock();
        nowTic = initTic;
    }

    void clearList()
    {
        recTicList.clear();
    }

    void reset()
    {
        initTic = clock();
        nowTic = initTic;
        clearList();
    }

    void addTic()
    {
        updateNowTic();
        recTicList.push_back(nowTic);
    }

    void printDurFromInit()
    {
        updateNowTic();
        unsigned long long int duration = nowTic - initTic;
        long double sec = (long double)duration/CLOCKS_PER_SEC;
        printTime(sec);
    }

    void printDurFromLast()
    {
        updateNowTic();
        unsigned long long int duration = nowTic - recTicList[recTicList.size() - 1];
        long double sec = (long double)duration/CLOCKS_PER_SEC;
        printTime(sec);
    }

    void printTicList()
    {
        for(int i = 0;i < recTicList.size();i ++)
        {
            unsigned long long int duration = recTicList[i] - initTic;
            long double sec = (long double)duration/CLOCKS_PER_SEC;
            printf("%d: ",i);
            printTime(sec);
            printf("\n");
        }
    }

    unsigned long long int getDurFromInit()
    {
        updateNowTic();
        unsigned long long int duration = nowTic - initTic;
        return duration;
    }

    unsigned long long int getDurFromLast()
    {
        updateNowTic();
        unsigned long long int duration = nowTic - recTicList[recTicList.size() - 1];
        return duration;
    }

    unsigned long long int getAvgLast()
    {
        unsigned long long int sum = 0;
        if(recTicList.size() < 2)
            return 0;
        for(int i = 1;i < recTicList.size()-1;i ++)
            sum += recTicList[i] - recTicList[i-1];
        return sum / (recTicList.size() - 1);
    }
    
    vector<unsigned long long int> getRecTicList()
    {
        vector<unsigned long long int> returnValue;
        for(int i = 1;i < recTicList.size();i ++) returnValue.push_back(recTicList[i]);
        return returnValuel;
    }
};