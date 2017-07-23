/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11995 - I Can Guess the Data Structure!
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n)
	{
		queue<int> data1;
		stack<int> data2;
		priority_queue<int> data3;
		
		bool isStack = 1;
		bool isQueue = 1;
		bool isPriorityQueue = 1;

		while(n--)
		{
			int data;
			int action;

			cin >> action >> data;
			
			if(action == 1)
			{
				if(isQueue)
					data1.push(data);
				if(isStack)
					data2.push(data);
				if(isPriorityQueue)
					data3.push(data);
			}
			else
			{
				if(isQueue)
				{
					if(data1.empty() || data1.front() != data)
						isQueue = 0;
					else
						data1.pop();
				}

				if(isStack)
				{
					if(data2.empty() || data2.top() != data)
						isStack = 0;
					else
						data2.pop();
				}

				if(isPriorityQueue)
				{
					if(data3.empty() || data3.top() != data)
						isPriorityQueue = 0;
					else
						data3.pop();
				}
			}
		}

		if(isStack && !isQueue && !isPriorityQueue)
			cout << "stack\n";
		else if(!isStack && isQueue && !isPriorityQueue)
			cout << "queue\n";
		else if(!isStack && !isQueue && isPriorityQueue)
			cout << "priority queue\n";
		else if(!isStack && !isQueue && !isPriorityQueue)
			cout << "impossible\n";
		else
			cout << "not sure\n";
	}

	return 0;
}