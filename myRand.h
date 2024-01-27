#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class myRandToolkit{
private:
    int RandSeed = 114514;
    vector<int> value;
    vector<int> weight;
public:
    myRandToolkit(){
        srand(RandSeed);
    };

    myRandToolkit(int seed){
        srand(seed);
    };

    myRandToolkit(vector<int> valueIn,vector<int> weightIn){
    //set weight which needs every integer weight match a value and the sum of weight is 1000
        value = valueIn;
        weight = weightIn;
    }

    int Get_List_Rnad_Int()
    {
        int tmp = Get_Rand_Int(1,1000);
        int sum = 0;
        if(value.size() != weight.size()) return INT_MAX+1;
        for(int i = 0;i < value.size();i ++)
        {    
            sum += weight[i];
            if(sum >= tmp) return value[i];
        }
        return value[value.size()-1];
    }

    int Get_Rand_Int(int min,int max)
    {
       // srand(seedIn);
        //int r = rand();
        // return (int)((r * (max - min))/(RAND_MAX) + min);
        int r = min-1;
        for(;!((r >= min) && (r <= max));) r = rand();
        return r;
    }

    int Get_Rand_Int_mod(int min,int max)
    {
        int r = rand();
        return (int)((r * (max - min))/(RAND_MAX) + min);
    }

    int Get_Rand_Int()
    {
        return rand();
    }
};