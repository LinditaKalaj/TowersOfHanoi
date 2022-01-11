#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, to = 1, from = 0, candidate = 1, move = 0, change1 = 1, change2 = 2;
	vector<int> t[3];
	cout << "Enter rings: ";
	cin >> n;

	if( (n % 2) == 0){
		to = 2;
		change2 = 1;
		change1 = 2;
	}

	for(int i = n+1; i >= 1; i--){
		t[0].push_back(i);
	}
	t[1].push_back(n+1);
	t[2].push_back(n+2);

	while(t[1].size() < n+1){

		cout<<"Move number "<<++move<<": Transfer ring "<<candidate<<" from tower "<<char(from+65)<<" to tower "<<char(to+65)<<endl;

		t[to].push_back(t[from].back());
		t[from].pop_back();
		if(t[(to+1)%3].back() < t[(to+2)%3].back()){
			from=(to+1)%3;
		}
    else {
      from=(to+2)%3;
		}
		if(t[(from)].back() < t[(from + change1) %3].back()){
			to = (from + change1) %3;
		}
    else{
       to = (from + change2) % 3;
		}
		 candidate=(t[from].back());
	}
	return 0;
}