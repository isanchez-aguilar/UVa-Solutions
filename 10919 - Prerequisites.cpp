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

	int categories;
	int freddieCourses;
	bool availableCourse[10000];
	// Read while freddieCourse is nonzero.
	while(cin >> freddieCourses and freddieCourses)
	{
		memset(availableCourse, false, sizeof availableCourse);
		// Read the number of categories.
		cin >> categories;
		// Read the id courses.
		for(int i = 0; i < freddieCourses; ++i)
		{
			int id;
			cin >> id;
			availableCourse[id] = true;
		}
		// Assume that is possible to graduate.
		bool possible = true;
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
				if(availableCourse[currentCourse])
					--minimumCourses;
			}
			// If the minum courses is bigger than zero then you can not graduate.
			if(minimumCourses > 0)
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
