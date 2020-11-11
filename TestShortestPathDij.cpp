#include "Assistance.h"					// 实用程序软件包
#include "AdjListDirNetwork.h"		// 邻接矩阵有向网
#include "ShortestPathDij.h"			// 最短路径迪杰斯特拉算法

#define MAXN 100

int main(void)
{
    try									// 用try封装可能出现异常的代码
	{
		int infity = DEFAULT_INFINITY;
		char vexs[] = {'A', 'B', 'C', 'D', 'E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		int n = 0;
		int m[MAXN][MAXN];
		int num = 0;
		int s,t;
		cin >> num;
		for (int k=0;k<num;k++)
		{
			cin >> n;
			for (int i=0; i<n; i++)
			{
				for(int j =0;j<n;j++)
				{
					cin>>m[i][j];
				}
			}
			
			for (int i=0; i<n; i++)
			{
				for(int j =0;j<n;j++)
				{
					if(m[i][j]==-1)
					{
						m[i][j]=infity;
					}
				}
			}
			cout << "Case "<< k+1 << ":"<<endl;
	
			AdjListDirNetwork<char, int> net(vexs, n);
	
			for (int u = 0; u < n; u++)
			{	// 生成邻接矩阵的行
				for (int v = n-1; v >=0; v--)
				{	// 生成邻接矩阵元素的值
					if (m[u][v] != infity) net.InsertArc(u, v, m[u][v]);
				}
			}
			int dist[n], path[n], v0 = 0;
			ShortestPathDij(net, v0, path, dist);		//用Dijskstra算法求最短路径
			DisplayPathAndDist(net, v0, path, dist,s,t);	//显示最短路径 
			cout << endl;
		}
	}
	catch (Error err)					// 捕捉并处理异常
	{
		err.Show();						// 显示异常信息
	}

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}

