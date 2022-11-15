#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> DAT;

int main(){
	int arr[] = {4,2,5,6,7,1,3,4,5,2,5,4,4,2,6,4,5,6};

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
		DAT[arr[i]] += 1;

	/*
		unordered_map default value is 0.
		so, if you use key not in hash, its value will be 0.
		DAT[999]'s value: 0
	*/

	return 0;
} 