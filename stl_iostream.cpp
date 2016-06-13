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
	for_each(dList.begin(), dList.end(), [](double &a){ a+=10;});
	copy(dList.begin(), dList.end(),ostream_iterator<double>(cout, ", "));
	cout<<"\b\b  "<<endl;
	return 0;
}
