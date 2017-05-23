/*
*	User: Isanchez_Aguilar
*	Problem: UVA 10919 - Prerequisites?
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int freddieCourses;
	int categories;
	vector<int> idCourses(100);
	vector<int>::iterator begin = idCourses.begin();
	// Read while freddieCourse is nonzero.
	while(cin >> freddieCourses && freddieCourses)
	{
		// Read the number of categories.
		cin >> categories;
		// Read the id courses.
		for(int i = 0; i < freddieCourses; ++i)
			cin >> idCourses[i];
		// Sort the ids.
		sort(begin, begin + freddieCourses);
		// Assume that is possible to graduate.
		bool possible = 1;
		// Read the categories.
		while(categories--)
		{
			int numberCourses;
			int minimumCourses;
			// Read the number of courses in the current category.
			cin >> numberCourses >> minimumCourses;
			while(numberCourses--)
			{
				int currentCourse;
				// Read the id of current course.
				cin >> currentCourse;
				// If you have not yet completed the course minimum then search the current.
				if(minimumCourses && possible && binary_search(begin, begin + freddieCourses, currentCourse))
					--minimumCourses;
			}
			// If the minum courses is bigger than zero then you can not graduate.
			if(minimumCourses)
				possible = 0;
		}
		// Evaluate possible.
		switch(possible)
		{
			// If It is true then print yes.
			case 1:
				cout << "yes\n";
				break;
			// If It is not possible then print no.
			default:
				cout << "no\n";
		}
	}
	return 0;
}
