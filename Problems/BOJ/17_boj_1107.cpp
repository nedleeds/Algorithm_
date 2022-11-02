#include <iostream>
using namespace std;

typedef struct inputs{
	string num;
	int cnt;
	int brokenNum;
	bool broken[11] = {false, };
}Input;

void setInputs(Input *arg){
	cin >> arg->num;
	arg->cnt = arg->num.size();
	cin >> arg->brokenNum;

	for (int i = 0; i < arg->brokenNum; i++){
		int idx;
		cin >> idx;
		arg->broken[idx] = true;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen("../SampleInput/input.txt", "r", stdin);

	Input arg;
	setInputs(&arg);


	// check whether broken or not
	for (int i=0; i<arg.num.size(); i++){

	}

	return 0;
}