#include <iostream>
#include <algorithm>
using namespace std;

int Q, N, M;

struct BOX
{   // idx : index of this box
    int idx; 
    BOX *prev, *next; 
}boxes[100005];

struct BELT
{   // cnt : # of boxes
    // front, end boxes in this belt
    int cnt;
    BOX *front, *end;
}belt[100005];

void push_box_back(int belt_idx, BOX* box)
{   // put the box to the belt[belt_idx]'s back.
    belt[belt_idx].cnt++;
    if (belt[belt_idx].front == NULL)
    {   // when the belt is empty
        box->prev = box;
        box->next = box;
        belt[belt_idx].front = box;
        belt[belt_idx].end = box;
    }
    else 
    {   // when the belt is not empty
        box->prev = belt[belt_idx].end;
        box->next = NULL;
        belt[belt_idx].end = box;
        belt[belt_idx].end->next = box;
    }
}

void push_box_front(int belt_idx, BOX* box)
{   // put the box to the front for belt[belt_idx]'s front
    belt[belt_idx].cnt++;
    if (belt[belt_idx].front == NULL)
    {   // when the belt is empty
        box->prev = box;
        box->next = box;
        belt[belt_idx].front = box;
        belt[belt_idx].end = box;
    } 
    else
    {   // when the belt is not empty
        box->prev = NULL;
        box->next = belt[belt_idx].front;
        belt[belt_idx].front->prev = box;
        belt[belt_idx].front = box;
    }

}

void input()
{   // get the input data
    cin 

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("../SampleInput/samsung.txt", "r", stdin);

    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++ )
    {
        int cmd, cnt_belt, cnt_box;
        cin >> cmd >> cnt_belt >> cnt_box;
        
        switch (cmd)
        {
        case 100:
            cout << "Put box\n";
            
            break;
        
        case 200:
            cout << "Move box\n";
            break;

        case 300:
            cout << "Swap front box\n";
            break;
        
        case 400:
            cout << "Divide box\n";
            break;
        
        case 500:
            cout << "Get box info\n";
            break;

        case 600:
            cout << "Get belt info\n";
            break;

        default:
            break;
        }
    }

    return 0;
}