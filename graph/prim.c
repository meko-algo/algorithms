#include <stdio.h>
#include <limits.h>

//图的顶点数
#define V 9

//寻找距离目前mstree最近的并且不在mstree里的顶点
int min_key(int key[], int mstree[])
{
    //INI_MAX是定义在limits.h的表示C语言int最大值得数
    int min = INT_MAX, min_index;
    
    int v;
    for (v = 0; v < V; v++)
        if (mstree[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    
    return min_index;
}

//输出结果
int print(int parent[], int n, int graph[V][V])
{
    printf("Edge   Weight\n");
    int i;
    for (i = 1; i < V; i++)
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
}

//prim最小生成树算法
void prim(int graph[V][V])
{
    //parent用来保存每个顶点在最小生成树里的父结点
    int parent[V];
    //key用来保存每个顶点距离目前最小生成树的距离
    int key[V];
    //mstree用来保存目前最小生成树已经包含的顶点，mstree[i]=1表示顶点i在最小生成树里，否则不在
    int mstree[V];
    
    //将key全都初始化为INT_MAX
    //mstree初始化不包含任何顶点
    int i;
    for (i = 0; i < V; i++)
        key[i] = INT_MAX, mstree[i] = 0;
    
    //起始点的key初始化为0
    key[0] = 0;
    //起始点设置为没有父结点
    parent[0] = -1;
    
    //寻找所有最小生成树的边
    for (i = 0; i < V-1; i++)
    {
        //找到距离目前mstree最近的并且不在mstree里的顶点
        int u = min_key(key, mstree);
        //将这个顶点加到mstree里
        mstree[u] = 1;
        
        //更新所有顶点距离目前mstree的距离
        int v;
        for (v = 0; v < V; v++)
            //需要更新的顶点需要满足以下几个条件：
            //1. 和顶点u相连 (graph[u][v] ！= 0)
            //2. 不在当前mstree内 (mstree[v] == 0)
            //3. 和u的距离比和当前mstree的距离比小 (graph[u][v] < key[v])
            if (graph[u][v] && mstree[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    
    //输出最小生成树
    print(parent, V, graph);
}


//主函数
int main()
{
    //新建一个图(参照undirected.jpg)
    int graph[V][V] = { {0, 4, 0, 0, 0, 0, 0, 8, 0  },
                        {4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        {0, 8, 0, 7, 0, 4, 0, 0, 2  },
                        {0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        {0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        {0, 0, 4, 14, 10, 0, 2, 0, 0},
                        {0, 0, 0, 0, 0, 2, 0, 1, 6  },
                        {8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        {0, 0, 2, 0, 0, 0, 6, 7, 0  }
                      };
    
    prim(graph);
    return 0;
}