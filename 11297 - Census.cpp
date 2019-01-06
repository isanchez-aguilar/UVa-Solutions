/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11297 - Census
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_LENGTH = 500;

vector< vector<int> > citiesPopulation(MAX_LENGTH, vector<int>(MAX_LENGTH));

class SegmentTree2D {
public:
	int ySize;
	int xSize;
	int width;
	int height;
	vector< vector< pair<int, int> > > treeMinMaxValue;
	vector< vector<int> > data;
	
	SegmentTree2D(vector< vector<int> > _data, int _width, int _height):data(_data), width(_width), height(_height)
	{
		xSize = 4 * width;
		ySize = 4 * height;
		treeMinMaxValue = vector< vector< pair<int, int> > >(ySize, vector< pair<int, int> >(xSize));

		buildYTree(1, 0, height - 1);
	}

	inline int getLeftIndex(int index) { return 2 * index; }

	inline int getRightIndex(int index) { return 2 * index + 1; }

	inline void buildYTree(int index, int currentLeft, int currentRight)
	{
		if (currentLeft != currentRight)
		{
			int leftIndex = getLeftIndex(index);
			int rightIndex = getRightIndex(index);
			int middle = (currentLeft + currentRight) / 2;

			buildYTree(leftIndex, currentLeft, middle);
			buildYTree(rightIndex, middle + 1, currentRight);
		}

		buildXTree(1, 0, width - 1, index, currentLeft, currentRight);

		return;
	}

	inline void buildXTree(int indexX, int currentLeftX, int currentRightX, int indexY, int currentLeftY, int currentRightY)
	{
		if (currentLeftX == currentRightX)
		{
			if (currentLeftY == currentRightY)
			{
				treeMinMaxValue[indexY][indexX].first = data[currentLeftY][currentLeftX];
				treeMinMaxValue[indexY][indexX].second = data[currentLeftY][currentLeftX];
			}
			else
			{
				int leftIndexY = getLeftIndex(indexY);
				int rightIndexY = getRightIndex(indexY);

				treeMinMaxValue[indexY][indexX].first = min(treeMinMaxValue[leftIndexY][indexX].first, treeMinMaxValue[rightIndexY][indexX].first);
				treeMinMaxValue[indexY][indexX].second = max(treeMinMaxValue[leftIndexY][indexX].second, treeMinMaxValue[rightIndexY][indexX].second);
			}
		}
		else
		{
			int leftIndex = getLeftIndex(indexX);
			int rightIndex = getRightIndex(indexX);
			int middle = (currentLeftX + currentRightX) / 2;

			buildXTree(leftIndex, currentLeftX, middle, indexY, currentLeftY, currentRightY);
			buildXTree(rightIndex, middle + 1, currentRightX, indexY, currentLeftY, currentRightY);

			treeMinMaxValue[indexY][indexX].first = min(treeMinMaxValue[indexY][leftIndex].first, treeMinMaxValue[indexY][rightIndex].first);
			treeMinMaxValue[indexY][indexX].second = max(treeMinMaxValue[indexY][leftIndex].second, treeMinMaxValue[indexY][rightIndex].second);
		}

		return;
	}

	inline void update(int x, int y, int value)
	{
		updateY(1, 0, height - 1, x, y, value);
		return;
	}

	inline pair<int, int> getMinMax(int x1, int y1, int x2, int y2)
	{
		return getMinMaxY(1, 0, height - 1, x1, y1, x2, y2);
	}

	inline void updateY(int index, int currentLeft, int currentRight, const int& x, const int& y, const int& value)
	{
		if (currentLeft != currentRight)
		{
			int middle = (currentLeft + currentRight) / 2;

			if (y <= middle)
				updateY(getLeftIndex(index), currentLeft, middle, x, y, value);
			else
				updateY(getRightIndex(index), middle + 1, currentRight, x, y, value);
		}

		updateX(1, 0, width - 1, index, currentLeft, currentRight, x, value);
	}

	inline void updateX(int indexX, int currentLeftX, int currentRightX, int indexY, int currentLeftY, int currentRightY, const int& x, const int& value)
	{
		if (currentLeftX == currentRightX)
		{
			if (currentLeftY == currentRightY)
			{
				treeMinMaxValue[indexY][indexX].first = value;
				treeMinMaxValue[indexY][indexX].second = value;
			}
			else
			{
				int leftIndexY = getLeftIndex(indexY);
				int rightIndexY = getRightIndex(indexY);

				treeMinMaxValue[indexY][indexX].first = min(treeMinMaxValue[leftIndexY][indexX].first, treeMinMaxValue[rightIndexY][indexX].first);
				treeMinMaxValue[indexY][indexX].second = max(treeMinMaxValue[leftIndexY][indexX].second, treeMinMaxValue[rightIndexY][indexX].second);
			}
		}
		else
		{
			int leftIndex = getLeftIndex(indexX);
			int rightIndex = getRightIndex(indexX);
			int middle = (currentLeftX + currentRightX) / 2;

			if (x <= middle)
				updateX(leftIndex, currentLeftX, middle, indexY, currentLeftY, currentRightY, x, value);
			else
				updateX(rightIndex, middle + 1, currentRightX, indexY, currentLeftY, currentRightY, x, value);

			treeMinMaxValue[indexY][indexX].first = min(treeMinMaxValue[indexY][leftIndex].first, treeMinMaxValue[indexY][rightIndex].first);
			treeMinMaxValue[indexY][indexX].second = max(treeMinMaxValue[indexY][leftIndex].second, treeMinMaxValue[indexY][rightIndex].second);
		}

		return;
	}

	inline pair<int, int> getMinMaxY(int index, int currentLeft, int currentRight, const int& x1, const int& y1, const int& x2, const int& y2)
	{
		if (currentRight < y1 or y2 < currentLeft)
			return make_pair(INT_MAX, INT_MIN);

		pair<int, int> currentMinMax;

		if (y1 <= currentLeft and currentRight <= y2)
			currentMinMax = getMinMaxX(1, 0, width - 1, index, x1, x2, currentLeft, currentRight);
		else
		{
			int leftIndex = getLeftIndex(index);
			int rightIndex = getRightIndex(index);
			int middle = (currentLeft + currentRight) / 2;

			pair<int, int> leftMinMax = getMinMaxY(leftIndex, currentLeft, middle, x1, y1, x2, y2);
			pair<int, int> rightMinMax = getMinMaxY(rightIndex, middle + 1, currentRight, x1, y1, x2, y2);

			currentMinMax.first = min(leftMinMax.first, rightMinMax.first);
			currentMinMax.second = max(leftMinMax.second, rightMinMax.second);
		}

		return currentMinMax;
	}

	inline pair<int, int> getMinMaxX(int indexX, int currentLeft, int currentRight, int indexY, const int& x1, const int& x2, const int& y1, const int& y2)
	{
		if (currentRight < x1 or x2 < currentLeft)
			return make_pair(INT_MAX, INT_MIN);

		pair<int, int> currentMinMax;

		if (x1 <= currentLeft and currentRight <= x2)
			currentMinMax = treeMinMaxValue[indexY][indexX];
		else
		{
			int leftIndex = getLeftIndex(indexX);
			int rightIndex = getRightIndex(indexX);
			int middle = (currentLeft + currentRight) / 2;

			pair<int, int> leftMinMax = getMinMaxX(leftIndex, currentLeft, middle, indexY, x1, x2, y1, y2);
			pair<int, int> rightMinMax = getMinMaxX(rightIndex, middle + 1, currentRight, indexY, x1, x2, y1, y2);

			currentMinMax.first = min(leftMinMax.first, rightMinMax.first);
			currentMinMax.second = max(leftMinMax.second, rightMinMax.second);
		}

		return currentMinMax;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int size;
	cin >> size;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			cin >> citiesPopulation[i][j];
	}

	SegmentTree2D population(citiesPopulation, size, size);
	
	int querires;
	cin >> querires;

	while (querires--)
	{
		int x1;
		int y1;
		char type;
		cin >> type >> y1 >> x1;

		if (type == 'c')
		{
			int newValue;
			cin >> newValue;
			population.update(x1 - 1, y1 - 1, newValue);
		}
		else
		{
			int x2;
			int y2;
			cin >> y2 >> x2;

			pair<int, int> queryResult = population.getMinMax(x1 - 1, y1 - 1, x2 - 1, y2 - 1);

			cout << queryResult.second << " " << queryResult.first << "\n";
		}
	}

	return 0;
}