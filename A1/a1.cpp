#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
	int n;
	cin >> n;
	int k;
	cin >> k;
	queue<int> t;
	int m = 0;
	for (int i = 0; i < n; i++) {
		int k = 0;
		cin >> k;
		t.push(k);
		m = max(m, k);
	}
	int tempK = 0;
	int temp = 0;

	int player1 = t.front();
	t.pop();

	int player2 = t.front();
	t.pop();

	if (player1 < player2) {
		temp = player1;
		player1 = player2;
		player2 = temp;
	}


	while (tempK != k) {
		if (player1 == m) break;
		if (player1 > player2) {
			tempK++;
			t.push(player2);
			player2 = t.front();
			t.pop();
		}
		else {
			tempK = 0;
			t.push(player1);
			player1 = player2;
			player2 = t.front();
			t.pop();
		}
	}
	cout << player1;
}