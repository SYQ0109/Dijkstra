#include "Assistance.h"					// ʵ�ó��������
#include "AdjListDirNetwork.h"		// �ڽӾ���������
#include "ShortestPathDij.h"			// ���·���Ͻ�˹�����㷨

#define MAXN 100

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
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
			{	// �����ڽӾ������
				for (int v = n-1; v >=0; v--)
				{	// �����ڽӾ���Ԫ�ص�ֵ
					if (m[u][v] != infity) net.InsertArc(u, v, m[u][v]);
				}
			}
			int dist[n], path[n], v0 = 0;
			ShortestPathDij(net, v0, path, dist);		//��Dijskstra�㷨�����·��
			DisplayPathAndDist(net, v0, path, dist,s,t);	//��ʾ���·�� 
			cout << endl;
		}
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}

