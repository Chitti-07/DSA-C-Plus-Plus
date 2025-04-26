#include <iostream>
using namespace std;


void Pattern(int n) {

	if (n == 0) {
		//cout << n << " ";
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		cout << i << " "; 
	}
	cout<<'\n';

	Pattern(n-1);
}


int sum_n(int n) {

	if (n == 0) {
		return 0;
	}
	int left = sum_n(n-1);
	return left + n;
}

int main() {
	Pattern(5);
	cout << sum_n(5);
}