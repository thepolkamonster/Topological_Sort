#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node * next;
};
class ll
{
    node * front;
public:
    ll(){front=nullptr;}
    void insert(int a)
    {
        node * temp= new node;
        temp->next=nullptr;
        temp->data=a;
        temp->next=front;
        front=temp;
    }
    void display()
    {
        node*temp=front;
        while(temp)
        {
            cout<<temp->data;
            temp=temp->next;
        }
    }
};
class graph
{
    map<int,list<int>> m;
    map<int,int> visit;
public:
    void addEdge(int x,int y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
    }
    void bfs(int src)
    {
        this->visit=visit;
        visit[src]=1;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            cout<<node;
            for(int x: m[node])
            {
                if(visit[x]==0)
                {
                    q.push(x);
                    visit[x]=1;
                }
            }
        }
    }
    void DFSrec(int src)
    {
        visit[src]=1;
        cout<<src;
        list<int> :: iterator it;
        for(int x:m[src])
        {
            if(visit[x]==0)
                DFSrec(x);
        }
    }
    ll DFSit(int src)
    {
        ll topsort;
        stack<int>s;
        s.push(src);
        while(!s.empty())
        {
            int node=s.top();
            s.pop();
            if(visit[node]==0)
            {
                visit[node]=1;
            }
            for(int x: m[node])
            {
                if(visit[x]==0)
                {
                    s.push(x);
                }
            }
            topsort.insert(node);
        }
        return topsort;
    }
};
int main()
{
    graph g;
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    ll l1=g.DFSit(5);
    l1.display();
    cout<<"\n";
    //542310
    /*
    5->0<-4
    |v    |v
    2->3->1
    */
}