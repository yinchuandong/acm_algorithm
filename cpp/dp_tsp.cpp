#include <iostream>
#include <set>
#include <vector>

#define MAX 6

using namespace std;

int dis[MAX][MAX]={
	0, 10, 20, 30, 40, 50,
	12, 0 ,18, 30, 25, 21,
	23, 19, 0, 5,  10, 15,
	34, 32, 4, 0,  8,  16,
	45, 27, 11,10, 0,  18,
	56, 22, 16,20, 12,  0
};

typedef struct
{
	int curcity;//当前所在的城市
	vector<int> unvisited;//当前未访问的城市
	set<int> type;//由于set自动排序，相同状态的vector可能不同，但set必然相同
	int distance;//从当前城市到终点回到起点的距离
}status;

/*测试用*/
void printVec( vector<status> vec)
{
	vector<status>::iterator iter;
	vector<int>::iterator it;
	for(iter=vec.begin();iter!=vec.end();iter++)
	{    
		cout<<(*iter).curcity<<" <";
		for(it=(*iter).unvisited.begin();it!=(*iter).unvisited.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<">"<<"  distance:"<<(*iter).distance<<endl;
	}

}
//看看当前状态的城市中是否包括城市i
bool contain(int i, status &sta)
{
	vector<int>::iterator iter;
	if(i==sta.curcity)
		return true;
	else
	{
		for(iter=sta.unvisited.begin();iter!=sta.unvisited.end();iter++)
			if(i==*iter)
				return true;
	}
	return false;
}
/*合并相同状态*/
vector<status> combine(vector<status> vec)
{
	vector<status> new_vec;
	vector<status>::iterator iter;
	status temp;
	while(vec.size()>0)
	{
		iter=vec.begin();
		temp=*iter;
		vec.erase(iter);
		for(;iter!=vec.end();iter++)
		{
			if((temp.curcity==(*iter).curcity)&&(temp.type==(*iter).type))
			{
				if((*iter).distance<temp.distance)
					temp=*iter;
				iter=vec.erase(iter);
				iter--;

			}
		}
		new_vec.push_back(temp);
	}
	return new_vec;
}

int main()
{
	vector<status> pre_vector;
	vector<status> cur_vector;
	//从后往前推，初始化
	for(int i=1;i<MAX;i++)
	{
		status sta;
		sta.curcity=i;
		sta.distance=dis[i][0];
		cur_vector.push_back(sta);
	}
	//依次递推，递推MAX-2次
	for(int j=0;j<MAX-2;j++){    
		pre_vector=cur_vector;
		cur_vector.clear();

		for(int i=1;i<MAX;i++)
		{
			vector<status>::iterator iter;
			for(iter=pre_vector.begin();iter!=pre_vector.end();iter++)
			{
				status temp=*iter;
				if(contain(i,temp)==false)//为确保状态中没有重复路径
				{
					status new_stat=temp;
					vector<int>::iterator int_iter=new_stat.unvisited.begin();
					new_stat.unvisited.insert(int_iter,new_stat.curcity);//加入vector
					new_stat.type.insert(new_stat.curcity);//加入set
					new_stat.distance+=dis[i][new_stat.curcity];//计算距离
					new_stat.curcity=i;
					cur_vector.push_back(new_stat);    
				}
			}
		}
		//记录相同状态最短路径，并合并相同状态
		cur_vector=combine(cur_vector);
	}//end for


	//printVec(cur_vector);


	//递推完毕后，最后一步，计算起点到每个状态的距离，找到最短路径
	vector<status>::iterator iter=cur_vector.begin();
	status shortest=*iter;
	int min_dis=shortest.distance+dis[0][shortest.curcity];
	iter++;
	for(;iter!=cur_vector.end();iter++)
	{
		int temp_dis=dis[0][(*iter).curcity]+(*iter).distance;
		if(temp_dis<min_dis)
		{
			min_dis=temp_dis;
			shortest=*iter;
		}    
	}
	//打印结果
	vector<int>::iterator iter_city;
	cout<<"minimum distance is "<<min_dis<<endl;
	cout<<"the shortest path is "<<"1 "<<shortest.curcity+1;
	for(iter_city=shortest.unvisited.begin();iter_city!=shortest.unvisited.end();iter_city++)
		cout<<" "<<*iter_city+1;
	cout<<" 1"<<endl;
	return 0;
}
