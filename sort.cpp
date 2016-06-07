#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename T>
void max_heapify( T arr[], int begin, int end)
{
	int dad = begin;
	int son = dad*2+1;
	while(son<end){
		if( son+1<end && arr[son+1]>arr[son])
			son++;
		if( arr[dad]>=arr[son])
			return;
		else{
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad*2+1;
		}
	}
}
template <typename T>
void heap_sort( T arr[], const int len)
{
	for(int i=len/2-1; i>=0; i--)
		max_heapify(arr, i, len);
	for(int i=len-1; i>0; i--){
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i);
	}
}


struct Range{
	int left, right;
	Range(int s=0, int e=0):left(s), right(e){
	}
};
template <typename T>
void quick_sort(T arr[], const int len)
{
	if( len <= 0) return;
	Range* r = new Range[len]; int p = 0;
	r[p++] = Range(0, len-1);
	while(p){
		Range range(r[--p]);
		if(range.left >= range.right) continue;
		int left=range.left, right=range.right;
		T mid = arr[range.right];
		while(left < right){
			while(arr[left]<mid && left<right) left++;
			while(arr[right]>=mid && left<right) right--;
			swap(arr[left], arr[right]);
		}
		if(arr[left]>=arr[range.right])
			swap(arr[left], arr[range.right]);
		r[p++] = Range(range.left,left-1);
		r[p++] = Range(left+1, range.right);
	}
	delete[] r;
}

template <typename T>
void insertion_sort(T arr[], const int len){
	int i, j;
	for(i=1; i<len; i++){
		T temp = arr[i];
		for(j=i-1; j>=0 && arr[j]>temp; j--)
			arr[j+1] = arr[j];
		arr[++j] = temp;
	}
}





int main()
{
	double dList[]={43,53.43,43.5,54,65,43,564,12,43,645,43};
	heap_sort(dList, sizeof(dList)/sizeof(double));
	copy(dList, dList+sizeof(dList)/sizeof(double), ostream_iterator<double>(cout, ", "));
	cout<<"\b\b  "<<endl;
	return 0;
}

