#include<iostream>
using namespace std;

const int ROW = 4;
const int COL = 4;

void bin_search(int(* num)[COL], int key) {
	if (num == nullptr)
		cout << -1 << endl;
	int row = 0;
	int col = COL - 1;
	while (row < ROW && col >= 0) {
		if (num[row][col] == key) {
			cout << "(" << row +1 << ", " << col + 1 << ")" << endl;
			break;
		}
		else if (num[row][col] > key)
			--col;
		else
			++row;
	}
	if (row == ROW || col == COL)
		cout << -1 << endl;
}

void bin_search1(int nums[], int rows, int cols, int key) {
	if (nums == nullptr)
		cout << -1 << endl;
	int row = 0;
	int col = cols - 1;
	while (row < rows && col >= 0) {
		if (nums[row * cols + col] == key) {
			cout << "(" << row + 1 << ", " << col + 1 << ")" << endl;
			break;
		}
		else if (nums[row * cols + col] > key)
			--col;
		else
			++row;
	}
	if (row == rows || col == cols)
		cout << -1 << endl;
}

int main() {
	int num[][COL] = {
		1, 2,  8,   9,
		2, 4,  9,  12,
		4, 7, 10, 13,
		6, 8, 11, 15
	};
	bin_search(num, 7);

	int nums[] = {
		1, 2,  8,   9,
		2, 4,  9,  12,
		4, 7, 10, 13,
		6, 8, 11, 15
	};
	bin_search1(nums, 4, 4, 7);
	getchar();
	return 0;
}