
## Description

- Dijkstra's algorithm is an algorithm for finding the ***<u>shortest paths</u>*** between nodes in a graph

- It was conceived by computer scientist [Edsger W. Dijkstra](https://en.wikipedia.org/wiki/Edsger_W._Dijkstra) in 1956 and published three years later

- Original algorithm : between <u>***two***</u> given nodes<br>
  Common variants : between ***<u>source</u>*** node "to ***<u>all other</u>*** nodes" 

- Condition : using labels that are ***<u>positive</u> integers*** or real numbers, which are ***<u>[totally ordered](https://en.wikipedia.org/wiki/Total_order)</u>***

- ***<u>`Generic Dijkstra`</u>*** shortest-path algorithm <br>
  : It can be generalized to use any labels that are ***[partially ordered](https://en.wikipedia.org/wiki/Partially_ordered_set)*** provided the ***subsequent labels<br>(⇢ produced when traversing an edge)*** are ***[monotonically](https://en.wikipedia.org/wiki/Monotonic_function) non-decreasing***

- Because the negative labels make the sum of edge costs lower for every step

- Reference: [wikipedia](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)

	<details><summary>해석</summary> 

	- 다익스트라 알고리즘은 그래프 노드간 최단 경로를 찾는 알고리즘

	- 1956년 컴퓨터 과학자 `에드거 W. 다익스트라`가 인지하여 3년 후에 출판하였습니다
  
	- 초기 알고리즘 : ***두 노드*** 간 최단 경로
      흔한 변형 : 하나의 노드(="소스" 노드)로부터 ***모든 다른 노드*** 간 최단 경로

    - 조건 : 양의 정수 혹은 양의 실수 레이블(ex.엣지의 가중치)을 가짐<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;***음의 가중치*** 는 사용불가
    - 음수 사이클이 있으면 최단 경로가 정의되지 않는다. 사이클을 돌 수록 가중치의 합이 작아지기 때문

	- 일반
	
		|장점|단점|
		|:---------:|:---------:|
		|빠른 접근가능 - O(1)| 음수를 다루기가 까다롭다 |
		||메모리 낭비를 초래할 수 있다<br>ex) int arr[] = {1, 10000000000, 2, 3, 5};|
	</details>

<br>

- example

	Suppose that I want to find a frequency of '6' in the array that I have.<br>
	Maybe I can use `for` statement from the first. <br>
	But, what if I want to find out '100000's frequency? <br>
	Do I need to iterate for 100000 times?<br>
	No. If I use DAT, we can get at the O(1).
	<details><summary>해석</summary> 
	현재 가지고 있는 arr 배열에서 6의 출현 횟수를 세고 싶다고 해보자.<br>
	보통 for문을 사용해 6을 확인하면 카운트를 올리는 식으로 생각할 수 있다.<br>
	그러면 100000을 찾고 싶다면 어떨까? 100000을 다 사용해야할까?<br>
	아니다. DAT를 사용하면 O(1)에 접근 가능하다.<br>
	</details><br>

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
	But, for some purpose, we can set DAT when we get the input values like below.
	<details><summary>해석</summary> 
	아마도 DAT가 미리 세팅되어있어야만 하는가를 생각할 수 있다. 그렇다<br>
	그치만 목적에 따라 입력 데이터를 받으면서 아래와 같이 쉽게 설정한다<br>
	</details><br>

	```cpp
	for (int i=0; i<10; i++){
		cin >> arr[i]; // get the i's value and put it to arr
		DAT[arr[i]]++; 
		// index: number(key)
		// value: frequency from the each number(record)
	}
	```
