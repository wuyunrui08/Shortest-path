#pragma once
#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_
#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
using namespace std;

struct node
{
	int to;
	int distance;
	node() {
		to = -1;
		distance = -1;
	}
};
//可以用迭代器指针去模拟
class DijkstraGraph //使用邻接表来存储
{
private:
	const int MAX = 0x3f3f3f;
	vector<vector<node>>graph;//存放图
	vector<bool>visited;
	vector<int>pre;//存放前驱
	vector<int>distance;//存放点什么到什么的距离
	int pointNumber;	
	int start;
public:
	void Init();//初始化邻接表
	void Dijkstra();//进行迪杰斯特拉算法
	void Output();//输出图示

};
