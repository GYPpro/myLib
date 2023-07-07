#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <MyLib\myMathTool.h>
#include <MyLib\myRand.h>

using namespace std;

class Determinant//行列式
{
private:
    vector<vector<int>> A;
    int Dimansion;
    myRandToolkit randtool;

public:
    Determinant(string s,int d,myRandToolkit randtoolIn) 
    {
        randtool = randtoolIn;
        Dimansion = d;
        A = new vector<int>;
        if(s == "rand") 
        {
            for(int i = 0;i < d;i ++)
            {
                vector<int> tmp;
                for(int j = 0;j < d;j ++)
                {
                    tmp.push_back(randtool.Get_List_Rnad_Int());
                }
                A.push_back(tmp);
            }
        } else {
            int idx = 0;
            for(int i = 0;i < d;i ++)
            {
                vector<int> tmp;
                for(int j = 0;j < d;j ++)
                {
                    while(s[idx] == ' ') idx++;
                    string tmpsubs;
                    while(s[idx] != ' ')
                    {
                        tmpsubs.push_back(s[idx]);
                        idx ++;
                    };
                    tmp.push_back(Str_to_Int(tmpsubs));  
                }
                A.push_back(tmp);
            }
        }
    }

    Determinant(vector<vector<int>> copyA)
    {
        A = copyA;
        Dimansion = copyA.size();
    }

    int getDimansion()
    {
        return Dimansion;
    };

    Determinant getRemain(int ti,int tj)
    {
        int vector<vector<int>> ans;
        for(int ti = 0;ti < Dimansion;ti ++)
        {
            if(ti == i) continue;
            vector<int> restmp;
            for(int j = 0;j < Dimansion;j ++)
            {
                if(tj == j) continue;
                restmp.push_back(A[i][j]);
            }
            ans.push_back(restmp);
        }
        return Determinant(ans);
    };

    vector<vector<int>> getCofactor(int ti,int tj)//代数余子式
    {

    }

    int getAns()
    {

    }

};
