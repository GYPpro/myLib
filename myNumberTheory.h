#include <math.h>
#include <stdlib.h>
#include <vector>
using namespace std;

template<class T>
class myPair;

class myInt{
public:
    int a;
};

template <class T>
class myPair{
public:
    T a,b;

public:
    myPair(T _a,T _b)
    {
        a = _a;
        b = _b;
    };
    myPair()
    {
        a = 0;
        b = 0;    
    };
    bool operator==(myPair c)
    {
        if(a != c.a) return false;
        if(b != c.b) return false;
    };
};