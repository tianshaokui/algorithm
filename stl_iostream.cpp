#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

int main()
{
	list<double> dList;
	copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(dList));   // back_inserter_iterator  inserter_iterator
	copy(dList.begin(), dList.end(),ostream_iterator<double>(cout, ", "));
	cout<<"\b\b  "<<endl;
	//for_each(dList.begin(), dList.end(), [](double a){ return a+10;});
	for(i=dList.begin(); i!=dList.end(); i++)
		*i += 10;
	return 0;
}
