
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

	</details>

<br>
