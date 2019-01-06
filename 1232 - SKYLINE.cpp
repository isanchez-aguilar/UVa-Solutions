/*
*	User: Isanchez_Aguilar
*	Problem: UVA 1232 - SKYLINE
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_WIDTH = 100001;
const int SIZE_SEGMENT_TREE = 4 * MAX_WIDTH;

typedef int Long;

class SegmentTree
{
public:
	vector<Long> lazy;
	vector< pair<Long, Long> > treeMinMaxValue;

	SegmentTree():lazy(SIZE_SEGMENT_TREE), treeMinMaxValue(SIZE_SEGMENT_TREE) {}

	inline int getLeftIndex(int index) { return 2 * index; }

	inline int getRightIndex(int index) { return 2 * index + 1; }

	inline void joinRange(const int left, const int right, const Long height)
	{
		joinRange(1, 0, MAX_WIDTH, left, right, height);
		return;
	}

	inline int getOverlapLengthRange(const int left, const int right, const Long height)
	{
		return getOverlapLengthRange(1, 0, MAX_WIDTH, left, right, height);
	}

	inline void joinRange(int index, int currentLeft, int currentRight, const int& left, const int& right, const Long& height)
	{
		Long updateHeight = height;
		int newLeftIndex = getLeftIndex(index);
		int newRightIndex = getRightIndex(index);
		
		if (lazy[index] != 0)
		{
			if (updateHeight < lazy[index])
				updateHeight = lazy[index];
		
			lazy[index] = 0;

			if (currentLeft != currentRight)
			{
				lazy[newLeftIndex] = updateHeight;
				lazy[newRightIndex] = updateHeight;
			}
		}
		
		if (currentRight <= left or right <= currentLeft)
			return;

		treeMinMaxValue[index].second = max(updateHeight, treeMinMaxValue[index].second);
		
		if (left <= currentLeft and currentRight <= right)
			treeMinMaxValue[index].first = max(updateHeight, treeMinMaxValue[index].first);
		else
		{
			int middle = (currentLeft + currentRight) / 2;
			joinRange(newLeftIndex, currentLeft, middle, left, right, updateHeight);
			joinRange(newRightIndex, middle, currentRight, left, right, updateHeight);

			treeMinMaxValue[index].first = max(treeMinMaxValue[index].first, min(treeMinMaxValue[newLeftIndex].first, treeMinMaxValue[newRightIndex].first));
		}

		return;
	}

	inline int getOverlapLengthRange(int index, int currentLeft, int currentRight, const int& left, const int& right, const Long& height)
	{
		int newLeftIndex = getLeftIndex(index);
		int newRightIndex = getRightIndex(index);
		
		if (lazy[index] != 0)
		{
			treeMinMaxValue[index].first = min(lazy[index], treeMinMaxValue[index].first);
			treeMinMaxValue[index].second = max(lazy[index], treeMinMaxValue[index].second);
			
			if (currentLeft != currentRight)
			{
				lazy[newLeftIndex] = lazy[index];
				lazy[newRightIndex] = lazy[index];
			}

			lazy[index] = 0;
		}
		
		if (currentRight <= left or right <= currentLeft)
			return 0;

		if (height < treeMinMaxValue[index].first)
			return 0;
		
		int overlapsLength = 0;
		
		if (treeMinMaxValue[index].second <= height)
			overlapsLength = min(currentRight, right) - max(currentLeft, left);
		else
		{
			int middle = (currentLeft + currentRight) / 2;
			overlapsLength += getOverlapLengthRange(newLeftIndex, currentLeft, middle, left, right, height);
			overlapsLength += getOverlapLengthRange(newRightIndex, middle, currentRight, left, right, height);
		}

		return overlapsLength;
	}
};


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int left;
		int right;
		Long height;
		int buildings;
		SegmentTree skyline;

		cin >> buildings;
		cin >> left >> right >> height;

		int overlapsLength = right - left;
		skyline.joinRange(left, right, height);
		
		for (int i = 1; i < buildings; ++i)
		{
			cin >> left >> right >> height;
			
			int currentOverlaps = skyline.getOverlapLengthRange(left, right, height);
			
			if (currentOverlaps > 0)
				skyline.joinRange(left, right, height);
			
			overlapsLength += currentOverlaps;
		}

		cout << overlapsLength << "\n";
	}

	return 0;
}