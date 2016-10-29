#include <stdio.h>
#include <limits.h>

#define V 9

//在剩下的顶点中寻找距离起始点最近的顶点
int min_dist(int dist[], int sptree[]) {
    //INI_MAX是定义在limits.h的表示C语言int最大值得数
    int min = INT_MAX, min_index;

    int v;
    for (v = 0; v < V; v++)
        if (sptree[v] == 0 && dist[v] < min)
            min = dist[v], min_index = v;

    return min_index;
}

//输出结果
int print(int dist[], int n) {
    printf("Vertex   Distance from Source\n");
    int i;
    for (i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

//dijkstra单一起点最小路径算法
void dijkstra(int graph[V][V], int src) {
    //每个顶点与起始点的距离
    int dist[V];

    //如果顶点i已经在sptree中，则sptree[i]=1,否则为0
    int sptree[V];

    //初始化所有顶点到起始点的距离为INT_MAX
    //最短路径树初始化为不包含任何顶点
    int i;
    for (i = 0; i < V; i++)
        dist[i] = INT_MAX, sptree[i] = 0;

    //起始点到自己的距离设为0
    dist[src] = 0;

    //计算到所有顶点的最短路径
    for (i = 0; i < V - 1; i++) {
        //在剩下的顶点中寻找距离起始点最近的顶点
        int u = min_dist(dist, sptree);
        //将这个顶点包含到最短路径树中
        sptree[u] = 1;

        //更新所有顶点到起始点的距离
        int v;
        for (v = 0; v < V; v++)
            //需要更新的顶点需要满足以下几个条件：
            //1. 不在当前sptree内 (sptree[v] == 0)
            //2. 和顶点u相连 (graph[u][v] ！= 0)
            //3. 顶点u(刚才找到的顶点)距离起始点的距离不等于INT_MAX (dist[u] != INT_MAX)
            //4. 经过u到达v的距离比目前的距离小 (dist[u] + graph[u][v] < dist[v])
            if (!sptree[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    //输出最短路径
    print(dist, V);
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
  
    dijkstra(graph, 0);
    return 0;
}