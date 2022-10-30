#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	freopen("../SampleInput/input.txt", "r", stdin);
	
	while(1){
		vector<char> stack;
		string s;
		getline(cin, s);

		if (s == ".") break;

		bool flag = true;

		for(int i=0; i<s.size(); i++){
			if (s[i] == '(' || s[i] == '['){
				stack.push_back(s[i]);
			}

			else if (s[i]==')'){
				if (stack.empty()){
					flag = false;
					break;
				}
				else if (stack.back() != '('){
					flag = false;
					break;
				}
				else{
					stack.pop_back();
				}
			}

			else if (s[i]==']'){
				if (stack.empty()){
					flag = false;
					break;
				}
				else if (stack.back() != '['){
					flag = false;
					break;
				}
				else{
					stack.pop_back();
				}
			}
		}
		if (flag && stack.empty()){
			cout << "yes\n";
		}
		else
			cout << "no\n";
	}	

	return 0;
}