
## Definition

- DAT : ***D***irect ***A***ddress ***T***able<br>
- ***D***irect ***A***ddress ***T***able is a data structure that has the capability of mapping records to their corresponding keys using arrays. In direct address tables, `records` are placed `using` their `key values` directly `as indexes`. They facilitate fast searching, insertion and deletion operations

- `Array` has a `meaning` or special `purpose`

- ***index*** : `key` value

- ***value*** : `records`
  |Merit|Demerits|
  |:---------:|:---------:|
  |Quick Approach (O(1))| Hard to handle negative integer|
  ||Could be wasting memory<br>ex) int arr[] = {1, 10000000000, 2, 3, 5};|

	<details><summary>해석</summary> 

	- DAT는 배열을 사용하여 특정 키에 특정 기록을 매핑하는 자료구조. 빠른 탐색, 삽입 그리고 삭제가 가능
  
	- 배열은 의미 또는 목적을 가진다

	- index : 접근하는 키 값 (ex. {1, 3, 5, 2, 1, 3};)

	- value : 기록 내용 (ex. value : DAT\[5\] ⇢  5에 해당하는 횟수)
	
		|장점|단점|
		|:---------:|:---------:|
		|빠른 접근가능 - O(1)| 음수를 다루기가 까다롭다 |
		||메모리 낭비를 초래할 수 있다<br>ex) int arr[] = {1, 10000000000, 2, 3, 5};|
	</details>

<br>

- example

	Suppose that I want to find a frequency of '6' in the array that I have.
	Maybe I can use `for` statement from the first. <br>
	But, what if I want to find out '100000's frequency? 
	Do I need to iterate for 100000 times?<br>
	No. If I use DAT, we can get at the O(1).
	- Data<br>
  		|array|values|
  		|:--:|:--:|
		|arr[]|{4,2,5,6,7,1,3,4,5,2,5,4,4,2,6,4,5,6}|
	```c++
	// This is general 'for' iteration

	#include <iostream>
	using namespace std;
	
	int main(){
		int arr[] = {4,2,5,6,7,1,3,4,5,2,5,4,4,2,6,4,5,6};
		int DAT[] = {0,1,3,1,5,4,3,1}; //{ frequencies for each index }
		int cntFromFor = 0;

		// Get the frequency of '6' from arr
		// 1) using 'for' statement
		for (int i=0; i<100001; i++){
			if (i==6)
				cntFromFor++;
		}
		cout << cntFromFor << '\n'; 

		// 2) using 'DAT' 
		cout << DAT[6] << '\n'; 

		return 0;
	}
	```

	Maybe, you can think that DAT should be set before. Yes it is.<br>
	But we can set DAT when we get the input values like below.
	```cpp
	for (int i=0; i<10; i++){
		cin >> arr[i]; // get the i's value and put it to arr
		DAT[arr[i]]++; 
		// index: number(key)
		// value: frequency from the each number(record)
	}
	```
