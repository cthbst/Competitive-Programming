#include <bits/stdc++.h>
#include <message.h>
using namespace std;

int main(){
	int my = MyNodeId();

	if (my == 0){
		int cntNode = NumberOfNodes();
		int sum=0;
		for (int i=1; i<cntNode; i++){
			Receive(i);
			int a = GetInt(i);
			sum += a;
		}
		cout << sum << endl;
	}
	else {
		PutInt(0,my);
		Send(0);
	}
}

