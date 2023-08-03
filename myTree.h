#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class mypair{
public:
    int l;
    int r;

public:
    mypair(int _l,int _r)
    {
        l = _l;
        r = _r;
    }

    void input()
    {
        cin >> l >> r;
    }

    int getDiff()
    {
        return abs(l-r)+1;
    }
}

class myTreeNode{
public:
    int child;//第一个儿子
    int sub;//兄弟
    vector<int> adj;//邻接表
    int parent;//父
    int dfn;//DFS序
    int deep;//深度
    int size;//所在子树的大小
    int hson;//重儿子
    int htop;//所在重链的顶部节点

public:
    myTreeNode()
    {
        child = -1;
        sub = -1;
        parent = -1;
        dfn = -1;
        deep = -1;
        size = -1;
        hson = -1;
        htop = -1;
    }
    
    int getHson()
    {
        return adj[hson];
    }

    void addAdj(int _adj)
    {
        adj.push_back(_adj);
    }
};

class myTree {
private:
    vector<myTreeNode> treeNode;
    vector<int> rnk;//记录DFS序对应的节点编号
    int dfn = 0;

private:

    int INIT(int node)//DFS,return value is size
    {
        treeNode[node].child = treeNode[node].adj[0];
        //dfn ++;
        //if(treeNode[node].dfn != -1) return;
        //treeNode[node].dfn = dfn;
        int thisSize = 1;
        int maxSizeId = -1,maxSize = 0;
        for(int i = 0;i < treeNode[node].adj.size();i ++)
        {
            //if(getNodeSize())
            treeNode[treeNode[node].adj[i]].parent = node;
            if(i < treeNode[node].adj.size() -1) treeNode[treeNode[node].adj[i]].sub = treeNode[node].adj[i +1];
            int tmpSize = INIT(treeNode[node].adj[i]);
            if(tmpSize > maxSize)
            {
                maxSizeId = i;
                maxSize = tmpSize;
            }
            thisSize += tmpSize;
        }
        treeNode[node].hson = maxSizeId;
        treeNode[node].size = thisSize;
        return thisSize;
    }
    
    void DivDFS(int node)//do DFS which make Hson is priority,cacu the Htop
    {
        if(treeNode[node].parent == -1) treeNode[node].htop = node;
        else if(treeNode[treeNode[node].parent].getHson() != node) treeNode[node].htop = node;
        else treeNode[node].htop = treeNode[treeNode[node].parent].htop;
        dfn ++;
        if(treeNode[node].dfn != -1) return;
        treeNode[node].dfn = dfn;
        if(!treeNode[node].adj.size()) return;
        DivDFS(treeNode[node].adj[treeNode[node].hson]);
        for(int i = 0;i < treeNode[node].adj.size();i ++)
        {
            if(i == treeNode[node].hson) continue;
            DivDFS(treeNode[node].adj[i]);
        }
        return;
    }

    int getNodeSize(int node)//useless
    {
        if(treeNode[node].deep != -1) return treeNode[node].deep;
        else {
            int ANS = 0;
            for(int i = 0;i < treeNode[node].adj.size();i ++) ANS += this->getNodeSize(treeNode[node].adj[i]);
            treeNode[node].deep = ANS;
            return ANS;
        }
    };
    
public:
    void AddLine(pair line)
    {
        if(treeNode.size() <= line.l) do(treeNode.push_back(myTreeNode()))while(treeNode.size() < line.l)
        treeNode[line.l].addAdj(line.r);
    };

    void INIT()//标准初始化
    {
        //this->getNodeSize(1);
        this->INIT(1);
        return;
    };
    
    void doDiv()//进行树链剖分
    {
        this->DFS(1);
        return;
    }

    void input_line()
    {
        int N;
        cin >> N;
        for(int i = 0;i < N-1;i ++)
        {
            pair line;
            line.input();
            this->AddLine(line);
        }
    }

    void output()
    {
        cout << "|output start , num of node:" << treeNode.size()-1 << " |"<< endl;
        for(int i = 1;i <= treeNode.size();i ++)
        {
            cout << "--------------------------------" << endl 
                 << "node:" << i << " deep:" << treeNode[i].deep << " parent:" << parent << endl
                 << "size:" << treeNode[i].size << "  dfn:" << treeNode[i].dfn << endl
                 << "adj:";
            for(int j = 0;j < treeNode[i].adj.size();j ++) cout << treeNode[i].adj[j] << " ";
            cout << endl;
            cout << "Hson:"  << treeNode[i].hson  << " Htop:" << treeNode[i].hTop << endl
                 << "child:" << treeNode[i].child << " sub:"  << treeNode[i].sub << endl;
        }
    }

};

class mySegTreeNode{
    mypair area;    //区间
    int leftson;  
    int rightson;
    int parent;
    int lasyTag;  //懒惰标记
    int sum;
    int maxn;
    int minn;
    bool isLastNode;//是否为携带数据的叶节点
    myTreeNode data;
}

class mySegTree { //区间最值、单个节点修改
private:
    vector<mySegTreeNode> treeNode;

public:
    mySegTree(vector<int> _data)
    {
        this->treeNode.push_back(mySegTreeNode());
        this->treeNode[0].area = mypair(0,_data.size()-1);
        this->treeNode[0].parent = -1;
        this->treeNode[0].leftson = 1;
        this->treeNode[0].rightson = 2;
        this->treeNode[0].isLastNode = false;
        this->treeNode[0].maxn = INT_MAX+1;
        this->treeNode[0].minn = INT_MAX;
        for(int i = 0;i < _data.size();i ++)
        {
            if(_data[i] > maxn) maxn = _data[i];
            if(_data[i] < minn) minn = _data[i];
        }
        buildSegTree(0,_data.size()-1,0);
    }

    void buildSegTree(int l,int r,int p)
    {
        if(l == r)
        {
            return;
        }
        
    }

}

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i = 0;i < T;i ++)
    {
        myTree tree;
        tree.input_line();
        tree.INIT();
        tree.output();
        tree.doDiv();
        tree.output();
    }
    return 0;
}