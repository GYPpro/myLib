/**
 * 说明：
 * 线性空间不支持无限维线性空间
 * 不支持无限维矩阵
 * 不支持任何无限项代数式
 * 暂时不支持含sin cos等函数的代数式?
 * 
 * 高精度无理数支持：
 * s:sqrt pie eul(2.718) ln log 
 * 
 */


#include <vector>
#include <string>
#include <string.h>

#ifndef _NUMBER_THEORY 1
#include <myNumberTheory.h>
#endif

using namespace std;

template<class T>
class myMathSymble;
class myMathSymbleSpace;
class myCoordinates;
class myLinearEntire;
class myLinearEntireArr;
class myLinearSpace;
class myBasicAlgebraicExpression;
class myPolynomial;
class myMatrix;
class myVector;
class myRealNum;

template<class T>
class myMathSymble{//符号
public:
    string symble;
    string type;
    T* targetEntire;
    vector<int> indexs;
    vector<myRealNum> value;

public:

};

class myMathSymbleSpace{//符号空间
private:
    vector<myMathSymble<myRealNum>*> usedSymbles_Value;
    vector<myMathSymble<myLinearEntire>*> usedSymbles_LE;
    vector<myMathSymble<myLinearSpace>*> usedSymbles_LS;
    //vector<myMathSymble<myValue>> usedSymbles_;//为线性映射准备，空着先

    vector<string> avlSymbles_Value;
    vector<string> avlSymbles_LE;
    vector<string> avlSymbles_LS;
    vector<string> avlSymbles_;//这个也空在这里

    vector<myPair<myLinearEntire>> indexPair_Value;

public:
    myMathSymble<myRealNum> getNewMS(myRealNum* data)
    {
    
    }

    myMathSymble<myRealNum> getNewMS(myRealNum* data,myPair<myRealNum> idx)
    {
    
    }

    myMathSymble<myLinearEntire> getNewMS(myLinearEntire* data)
    {
    
    }
    
    myMathSymble<myLinearSpace> getNewMS(myLinearSpace* data)
    {
    
    }
    
    // myMathSymble<myRealNum> getNewMS(myRealNum* data)
    // {
    //     //
    // }

    

};

// class myValue{//有理数
// private:
//     vector<int> P,Q;
// };

class myCoordinates{//坐标
private:
    myLinearEntireArr * LEA;
    vector<myRealNum> coorValues;
};

class myLinearEntire{//线性空间元素
private:
    vector<myCoordinates> coor;
    myMathSymble<myLinearEntire> *symble;
    
public:

};

class myLinearSpace{//线性空间
private:
    vector<myLinearEntire*> entires;
    myLinearEntireArr basis;
    int Dimansion;


};

class myBasicAlgebraicExpression:public myLinearEntire{ //初等代数式
private:
    bool ifPol;
    vector<myBasicAlgebraicExpression> exp1,exp2;
    char connOp;// + - * /
    vector<myPolynomial> exp3;

public:
    myBasicAlgebraicExpression(string initStr)
    {

    }

    myBasicAlgebraicExpression operator+(myBasicAlgebraicExpression b)
    {

    }

    myBasicAlgebraicExpression operator-(myBasicAlgebraicExpression b)
    {

    }

    myBasicAlgebraicExpression operator*(myBasicAlgebraicExpression b)
    {

    }

    myBasicAlgebraicExpression operator/(myBasicAlgebraicExpression b)
    {

    }

    bool operator==(myBasicAlgebraicExpression b)
    {
        
    }

    bool operator!=(myBasicAlgebraicExpression b)
    {
        
    }

    myBasicAlgebraicExpression partialFractionDecomp()//部分分式分解
    {

    }

};

class myPolynomial:public myLinearEntire{//多项式
private:
    vector<myRealNum> coefArr;//系数表
    myMathSymble<myPolynomial> *symble;

public:
    myPolynomial(vector<myRealNum> initArr)
    {

    }

    myPolynomial operator+(myPolynomial b)
    {

    }

    myPolynomial operator-(myPolynomial b)
    {

    }

    myPolynomial operator*(myPolynomial b)
    {

    }

    myBasicAlgebraicExpression operator/(myPolynomial b)
    {

    }

    bool operator==(myPolynomial b)
    {

    }

    bool operator!=(myPolynomial b)
    {

    }

    myPolynomial standardDecomp()//标准分解
    {

    }

};

class myMatrix:public myLinearEntire{//矩阵
private:
    vector<vector<myBasicAlgebraicExpression>> oriMatrix;//原矩阵数据
    vector<vector<myBasicAlgebraicExpression>> stdMatrix;//标准型

public:
    myMatrix operator+(myMatrix b)
    {

    }

    myMatrix operator-(myMatrix b)
    {

    }

    myMatrix operator*(myMatrix b)
    {

    }
    
    myMatrix operator/(myMatrix b)
    {

    }

    bool operator==(myMatrix b)
    {

    }

    bool operator!=(myMatrix b)
    {
        
    }

    myRealNum getDet()//求行列式
    {

    }

    myRealNum getRank()//求秩
    {

    }

    myRealNum getTrace()//求迹
    {

    }

    vector<myRealNum> getEigenValue()//求特征值
    {

    }

    myLinearEntireArr getEigenVector()//求特征向量
    {

    }

    myMatrix getInverse()//求逆矩阵
    {

    }

    myMatrix getTranspose()//求转置矩阵
    {

    }

    myMatrix getAdjoint()//求伴随矩阵
    {

    }

    myMatrix getStandard()//求标准型
    {

    }

    myMatrix getRowEchelon()//求行阶梯型
    {

    }

    myMatrix getDiagonalization()//对角化
    {

    }

    myMatrix getOrthogonalization()//正交化
    {

    }

    myMatrix getJordan()//求约当标准型
    {

    }

    bool isSymmetric()//判断是否对称
    {

    }

    bool isSkewSymmetric()//判断是否反对称
    {

    }

    bool isSimilar(myMatrix b)//判断是否相似
    {

    }

    bool ifOffset(myMatrix b)//判断是否相抵
    {

    }

    bool ifCongruent(myMatrix b)//判断是否合同
    {

    }
    
};

class myVector:public myLinearEntire{//向量
vector<myRealNum> oriVector;//原向量数据


};

class myRealNum:public myLinearEntire{//实数
friend istream &operator<<(istream &is,myRealNum &item);
friend istream &operator>>(istream &is,myRealNum &item);
private:
    char type; //r-有理数 n-精确无理数式子 s-单个精确无理数 f-高精浮点数-200位有效
    vector<int> Fraction;//分数
    vector<myBasicAlgebraicExpression> irrExp;//含有精确单个无理数的初等代数式
    vector<string> irrNum;//单个精确无理数
    vector<int> floNum;//高精度浮点数

public:
    myRealNum(string initStr)
    {

    }

    myRealNum operator+(myRealNum b)
    {

    }

    myRealNum operator-(myRealNum b)
    {
        
    }

    myRealNum operator*(myRealNum b)
    {
        
    }

    myRealNum operator/(myRealNum b)
    {
        
    }
    
    bool operator==(myRealNum b)
    {

    }

    bool operator!=(myRealNum b)
    {

    }

    bool operator<(myRealNum b)
    {

    }

    bool operator>(myRealNum b)
    {

    }

    bool operator==(int b)
    {

    }

};

class myLinearEntireArr{//向量组
private:
    vector<myLinearEntire*> LEs;
    int rank;//秩

public:
    myLinearEntireArr(vector<myLinearEntire*> _LES)
    {

    }

    int getRank()//计算秩
    {

    }

    bool operator==(myLinearEntireArr b)//判断是否等价
    {

    }

    bool operator==(myVector b)//判断是否线性相关
    {

    }

    bool operator!=(myLinearEntireArr b)//同上
    {

    }

    bool operator!=(myVector b)//同上
    {

    }

    myLinearEntireArr getMaxIrreArr()//获取极大无关组
    {

    }

//求过渡矩阵？

};

istream &operator<<(istream &is,myRealNum &item)//实数输入
{

};

ostream &operator>>(ostream &is,myRealNum &item)//实数输出
{

};

