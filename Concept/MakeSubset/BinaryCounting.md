## Definition

- Binary Counting: Literally, it's ***counting the binary***. The point is, where it <u>is applied to.</u><br></br>
  

## Concept
- Well, when we need to make a subset from the given items or elements, many people easily consider using `DFS` for the first including me.

- However, as you know, `DFS` algorithm using `recursion` is queit slow. Because it calls the function again and again.

- Using `Binary Counting`, we can reduce time to make total subsets from given items by using `bit operation` and `without calling function repeatedly`
<br></br>

## Method
- It's quiet simple. Only `2 for iteration` needed.
- The `1st for statement` is related to `total amount of Combination`

    - ex) [1, 2, 3, 4] -> total amount of Combination: $2^{4}$ <br></br>
- The `2nd for statement` is related to `checking each bit` whether it's 1 or not
  - ex) $3$ = $0011_{(2)}$ = bit[3], bit[2], bit[1], bit[0] = 0 0 1 1<br></br>

- Additionally, bit operation is needed
  - ex) 1 << 1 = $00000001_{(2)}$
  - &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1 << 2 = $00000010_{(2)}$ 
  - &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1 << 3 = $00000100_{(2)}$ 
  - &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1 << 4 = $00001000_{(2)}$ 
      <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;... </br>
  - &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1 << 7 = $10000000_{(2)}$ 
<details>
<summary> Bit Operation</summary>

> Code 
```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main(){

    for (int i = 0; i < 8; i++)
    {
        cout << bitset<8>(1 <<i) << ": ";
        cout << (1 << i) << '\n';
    }

    return 0;
}
```
> [output]<br>
> 00000001: 1 (1<<0)<br>
> 00000010: 2 (1<<1)<br>
> 00000100: 4 (1<<2)<br>
> 00001000: 8 (1<<3)<br>
> 00010000: 16 (1<<4)<br>
> 00100000: 32 (1<<5)<br>
> 01000000: 64 (1<<6)<br>
> 10000000: 128 (1<<7)<br>

</details>
<br></br>

<details><summary>Example 01</summary>

### [ Code ]
```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main(){

    // try making combination from 4 items
    int cntItem = 4;
    for (int i = 0; i < (2 << (cntItem - 1)); i++)
    {
        // print i in the binary format with 4 digit
        cout << bitset<4>(i) << " : ";
        for (int bit = cntItem - 1; bit >= 0; bit--)
        {
            if (i & (1 << bit)) 
            {
                // print bit when its value is 1.
                cout << (bit) << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
```

### [ Output ]
```
0000 : 
0001 : 0 
0010 : 1 
0011 : 1 0 
0100 : 2 
0101 : 2 0 
0110 : 2 1 
0111 : 2 1 0 
1000 : 3 
1001 : 3 0 
1010 : 3 1 
1011 : 3 1 0 
1100 : 3 2 
1101 : 3 2 0 
1110 : 3 2 1 
1111 : 3 2 1 0 
```
</details>


<details><summary>Example 02</summary>

### [ Code ]
```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main(){

    // try making combination from 4 items
    int cntItem = 4;
    // idx : 0('e'), 1('r') ,2('i') ,3('f')
    char s[4] = {'e', 'r', 'i', 'f'};

    for (int i = 0; i < (2 << (cntItem - 1)); i++)
    {
        cout << bitset<4>(i) << " : ";
        for (int bit = cntItem - 1; bit >= 0; bit--)
        {
            if (i & (1 << bit)) 
            {
                // print bit when its value is 1.
                cout << s[bit] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
```

### [ Output ]
```
0000 : 
0001 : e 
0010 : r 
0011 : r e 
0100 : i 
0101 : i e 
0110 : i r 
0111 : i r e 
1000 : f 
1001 : f e 
1010 : f r 
1011 : f r e 
1100 : f i 
1101 : f i e 
1110 : f i r 
1111 : f i r e 
```
</details>