#include <iostream>
#include <cmath>
using namespace std;

void move(char f, char t, char e, int n){
	if(n == 1){
		cout << "Transfer ring 1 from tower "<< f << " to tower " << t << endl;
		return;
	}
	move(f,e,t,n-1);
	cout << "Transfer ring " << n << " from tower " << f << " to tower "<< t << endl;
	move(e,t,f,n-1); 
	return;
}

int main() {
	int n = 3;
	char f = 'a', t = 'b', e = 'c';
	move( f, t, e, n);
	cout<< "Moves taken: "<< pow(2,n) -1;
	return 0;
}