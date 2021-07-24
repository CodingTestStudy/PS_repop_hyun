#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int func(vector<int> & v,int from, int to)
{   
	if (from == to)return v[from]; //base case : 높이자체가 넓이가됨

	int mid = (from + to) / 2;
	int minheight = v[mid]; 
	int ret = 0;
	int cnt = 1; //밑변

	int right = mid; //한칸오른쪽
	int left = mid;
	while (from < left || right < to)
	{
		if(right<to &&(left == from || v[right+1]>= v[left-1])) //오른쪽으로 가기
		{
			minheight = min(minheight, v[right+1]);
			++right;
			++cnt;
			ret = max(ret,cnt * minheight); //최댓값갱신

			continue;
		}

		if (from < left &&(right == to ||v[left-1] > v[right+1])) //왼쪽으로 가기
		{
			minheight = min(minheight, v[left-1]);
			--left;
			++cnt;
			ret = max(ret, cnt * minheight);
		}
		
	}
	
	

	int ret2 = max(func(v, mid + 1, to), func(v, from, mid));
	
	ret = max(ret, ret2);
	

	
	return ret;

}
int main()
{
	vector<int> v;

	int in;
	int N;
	cin >> N;


	for (int i = 0; i < N; i++)
	{

		cin >> in;
		v.push_back(in);


	}
	
	
	cout << func(v, 0, v.size() - 1);
	
	return 0;

}