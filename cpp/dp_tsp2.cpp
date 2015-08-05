#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>

using namespace std;

#define n 6     //结点个数

int main()
{
    int i,j,k,min,temp;
    int b=(int)pow(2,n-1);
    int D[20][20];//原图的邻接矩阵
    
    fstream fin("TSPinput1.txt",ios::in);//打开输入文件
    fstream fout("TSPoutput.txt",ios::out);//打开输出文件

    //读入数据到邻接矩阵D中
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            fin>>D[i][j];

    //申请二维数组F和M
    int ** F = new int* [n];//n行b列的二维数组，存放阶段最优值
    int ** M = new int* [n];//n行b列的二维数组，存放最优策略
    for(i=0;i<n;i++)
    {
        F[i] = new int[b];//每行有2的n-1次方列，代表2^(n-1)个集合
        M[i] = new int[b];//使用pow(2, j-1) & i 判断i是否在j集合中
    }

    //初始化F[][]和M[][]
    for(i=0;i<b;i++)
        for(j=0;j<n;j++)
        {
            F[j][i] = -1;
            M[j][i] = -1;
        }
    
    //给F的第0列赋初值
    for(i=0;i<n;i++)
        // F[i][0] = 0; //普通最短路径，不需要回到起点
        F[i][0] = D[i][0]; //tsp问题，D[i][0] 表示从i回到起点的距离
        
    //遍历并填表，最后一列不在循环里计算
    //i表示当前的集合，其中列标号对应二进制，
    //i=1, 000001, 表示访问的集合为{1}。
    //i=31,011111, 表示访问的集合为{1,2,3,4,5}
    for(i=1;i<b-1;i++)
    {
        //j表示当前要访问的城市
        for(j=1;j<n;j++)
        {
            //int p=(int)pow(2,j-1);
            //int res=p & i;
            //结点j不在i表示的集合中,(1,{2,3,4,5,6})代表1不在Sk中
            if( ((int)pow(2,j-1) & i) == 0)
            {
                min=65535;
                //k表示下一个要访问的城市
                for(k=1;k<n;k++)
                {
                    //非零表示结点k在i表示的集合中，(1,{2,3,4,5,6})代表[2-6]在Sk中
                    if( (int)pow(2,k-1) & i )
                    {
                        //i-(int)pow(2,k-1)表示Sk-{j}
                        //eg:31-2^4 = 15 = 001111,
                        //则代表011111=D[j][4] + F[4][15]=D[j][4] + 001111
                        temp = D[j][k] + F[k][i-(int)pow(2,k-1)]; 
                        if(temp < min)
                        {
                            min = temp;
                            F[j][i] = min;//保存阶段最优值
                            M[j][i] = k;//保存最优决策
                        }
                    }
                }        
            }
        }
    }
       
        
    //最后一列，即总最优值的计算
    min=65535;
    for(k=1;k<n;k++)
    {
        //b-1的二进制全1，表示集合{1,2,3,4,5}，从中去掉k结点即将k对应的二进制位置0
        temp = D[0][k] + F[k][b-1 - (int)pow(2,k-1)];
        if(temp < min)
        {
            min = temp;
            F[0][b-1] = min;//总最优解
            M[0][b-1] = k;
        }
    }
    fout<<"最短路径长度："<<F[0][b-1]<<endl;//最短路径长度


    //回溯查表M输出最短路径(编号0~n-1)
    fout<<"最短路径(编号0—n-1)："<<"0";
    for(i=b-1,j=0; i>0; )//i的二进制是5个1，表示集合{1,2,3,4,5}
    {
        j = M[j][i];//下一步去往哪个结点
        i = i - (int)pow(2,j-1);//从i中去掉j结点
        fout<<"->"<<j;
    }
    fout<<"->0"<<endl;

    //输出表格F到文件
    for(i=0;i<n;i++)
    {
        for(j=0;j<b;j++)
            fout<<F[i][j]<<" ";
        fout<<endl;
    }

    return 0;

}