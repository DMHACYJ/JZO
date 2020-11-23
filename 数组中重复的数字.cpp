#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;


//暴力求解。时间O(nlogn)，空间O(1)
int test1(int num[], int n) {
	if (num == nullptr || n <= 0) {
		return -1;
	}
	sort(num, num + n); // 时间O(nlogn)
	for (int i = 0; i < n - 1; i++) { // O(n)
		if (num[i] == num[i + 1]) {
			return num[i];
		}
	}
	return -1;
}

//当数组中数字都在 0 - n - 1 范围的时候用如下哈希表解
int test2(int num[], int n) {
	if (num == nullptr || n <= 0) {
		return -1;
	}
	for (int i = 0; i < n; ++i) {
		if (num[i] < 0 || num[i] > n - 1) {
			return -1;
		}
	}
	for (int i = 0; i < n; ++i) {//时间复杂度O(n)，空间O(1)
		while (num[i] != i) {
			if (num[i] == num[num[i]]) {
				return num[i];
			}
			swap(num[i], num[num[i]]);
		}
	}
	return -1;
}

//加要求不改变原数组
//暴力求解
int test3(int num[], int n) {
	if (num == nullptr || n <= 0) {
		return -1;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (num[i] == num[j]) return num[i];
		}
	}
	return -1;
}

//空间换时间
//哈希unordered_set，不限制数字大小
int test4(int num[], int n) {
	if (num == nullptr || n <= 0) {
		return -1;
	}
	unordered_set<int> us; //空间复杂度O(n)
	for (int i = 0; i < n; ++i) {//时间复杂度O(n)
		if (us.find(num[i]) != us.end())
			return num[i];
		else us.insert(num[i]);
	}
	return -1;
}

//哈希，不限制数字大小，有需要可输出每个数字重复多少个
int test5(int num[], int n) {
	if (num == nullptr || n <= 0) {
		return -1;
	}
	unordered_map<int, int> um; //空间复杂度O(n)
	for (int i = 0; i < n; ++i) {//时间复杂度O(n)
		um[num[i]]++;
		if (um[num[i]] > 1)
			return num[i];
	}
	return -1;
}

int main() {
	int num[] = {2, 3, 1, 0, 2, 5, 3};
	cout << test1(num, sizeof(num) / sizeof(int)) << endl;
	cout << test2(num, sizeof(num) / sizeof(int)) << endl;
	cout << test3(num, sizeof(num) / sizeof(int)) << endl;
	cout << test4(num, sizeof(num) / sizeof(int)) << endl;
	cout << test5(num, sizeof(num) / sizeof(int)) << endl;
	getchar();
	return 0;
}