#include <iostream>
#include <list>

using namespace std;
 
//定义一个图的数据类型(使用邻接表)
class Graph
{
    int V; //顶点的个数
    list<int> *adj; //邻接表
public:
    Graph(int V); //构造函数
    void add_edge(int v, int w); //增加一条边
    void bfs(); //广度优先搜索
    void _bfs(int v, bool visited[]); //从某一顶点开始的广度优先搜索
    void dfs(); //深度优先搜索
    void _dfs(int v, bool visited[]); //从某一顶点开始的深度优先搜索

};

//构造函数
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V]; //一个包含V个链表的数组
}
 
//增加一条v到w的边(如果是无向图则需要调用add_edge(v, w)和add_edge(w, v)
void Graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
}

//从顶点v开始的深度优先搜索
void Graph::_bfs(int v, bool visited[])
{
    //新建一个队列
    list<int> queue;
 
    //将起始顶点v加进队列，并且v设为已访问
    visited[v] = true;
    queue.push_back(v);
 
    //定义一个迭代器i
    list<int>::iterator i;
 
    //从起始点开始广度优先遍历
    while(!queue.empty())
    {
        //输出队首顶点并出队列
        v = queue.front();
        cout << v << " ";
        queue.pop_front();
 
        //对于所有v(刚刚输出的顶点)的相邻顶点
        //如果还没有访问过则标记为已访问并加入队列(但是不会输出)
        for(i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

//广度优先搜索
void Graph::bfs()
{
    //初始化所有顶点为未访问
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    //从每一个顶点开始尝试一次广度优先搜索(因为只从一个点出发可能访问不了所有顶点)
    //在之前已经访问过的顶点将不会在被访问
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            _bfs(i, visited);
}

//从顶点v开始的深度优先搜索(递归函数)
void Graph::_dfs(int v, bool visited[])
{
    //输出起始顶点并将其设为已访问
    visited[v] = true;
    cout << v << " ";
 
    //对于所有起始顶点的相邻顶点，
    //如果没有被访问过，则从该顶点开始继续深度优先访问
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++)
        if(!visited[*i])
            _dfs(*i, visited);
}
 
//深度优先访问
void Graph::dfs()
{
    //初始化所有结点为未访问
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    //从每一个顶点开始尝试一次深度优先搜索(因为只从一个点出发可能访问不了所有顶点)
    //在之前已经访问过的顶点将不会在被访问
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            _dfs(i, visited);
}

//主函数
int main()
{
    //新建一个图
    Graph g(9);
    g.add_edge(0, 1); g.add_edge(0, 7);
    g.add_edge(1, 0); g.add_edge(1, 2); g.add_edge(1, 7);
    g.add_edge(2, 1); g.add_edge(2, 3); g.add_edge(2, 5); g.add_edge(2, 6);
    g.add_edge(3, 2); g.add_edge(3, 4); g.add_edge(3, 5);
    g.add_edge(4, 3); g.add_edge(4, 5);
    g.add_edge(5, 2); g.add_edge(5, 3); g.add_edge(5, 4); g.add_edge(5, 6);
    g.add_edge(6, 5); g.add_edge(6, 7); g.add_edge(6, 8);
    g.add_edge(7, 0); g.add_edge(7, 1); g.add_edge(7, 6); g.add_edge(7, 8);
    g.add_edge(8, 2); g.add_edge(8, 6); g.add_edge(8, 7);

    //广度优先搜索
    g.bfs(); cout << endl;
    //深度优先搜索
    g.dfs(); cout << endl;
 
    return 0;
}