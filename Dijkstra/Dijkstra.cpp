#include "Dijkstra.h"

void DijkstraGraph::Init()
{
    pointNumber = 0;
    cout << "请输入顶点个数:" << endl;
    cin >> pointNumber;
    graph.resize(pointNumber );
    visited.resize(pointNumber , false);
    pre.resize(pointNumber, -1);
    distance.resize(pointNumber , MAX);
    cout << "请输入顶点的关系,from - to - distance" << endl;
    int a, b, dis;
    
    while (cin >> a >> b >> dis) 
    {
        if (a == -1 || b == -1 || dis == -1)
            break;
        node temp;
        temp.distance = dis;
        temp.to = b;
        graph[a].push_back(temp);
    }

    cout << "存储好了邻接表" << endl;
}

void DijkstraGraph::Dijkstra()
{
    vector<node>::iterator iter1;
    int start;
    int min = MAX;
    int index = 0;
    cout << "请输入出发点" << endl;
    cin >> start;
    this->start = start;
    pre[start] = 0;
    distance[start] = 0;
    
    for (int i = 0; i < pointNumber; i++)
    {
        visited[start] = true;
        //index = 0;
        min = MAX;
        for (iter1 = graph[start].begin(); iter1 < graph[start].end(); iter1++)
        {
            if (!visited[iter1->to] && distance[start] + iter1->distance < distance[iter1->to])
            {
                pre[iter1->to] = start;//进行前驱更新
                distance[iter1->to] = iter1->distance+distance[start];//距离更新
            }
        }
        for (int j = 0; j < pointNumber; j++) //找没经历过的最小的元素值
        {
            if (!visited[j] && min > distance[j])
            {
                min = distance[j];
                start = j;
            }
        }
    }
}

void DijkstraGraph::Output()
{
    stack<int>s;
    //cout << "距离:" << endl;
    //vector<int>::iterator iter;
    //for (iter = distance.begin(); iter < distance.end(); iter++)
        //cout << *iter << " ";
    int temp;
    cout << "-----------------------" << endl;
    cout << "出发点" << this->start << endl;
    for (int i = 0; i < pointNumber; i++)
    {
        cout << "到达点 " << i << " 经过路径: ";
        temp = pre[i];
        s.push(i);
        while (temp != this->start)
        {
            s.push(temp);
            temp = pre[temp];
        }
        s.push(this->start);
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << "\t\t 距离是:" << distance[i] << endl;

    }
    cout << "------------------------" << endl;
    
}
