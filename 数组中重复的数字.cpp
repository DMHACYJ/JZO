#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;


//������⡣ʱ��O(nlogn)���ռ�O(1)
int test1(int num[], int n) {
	if (num == nullptr || n <= 0) {
		return -1;
	}
	sort(num, num + n); // ʱ��O(nlogn)
	for (int i = 0; i < n - 1; i++) { // O(n)
		if (num[i] == num[i + 1]) {
			return num[i];
		}
	}
	return -1;
}

//�����������ֶ��� 0 - n - 1 ��Χ��ʱ�������¹�ϣ���
int test2(int num[], int n) {
	if (num == nullptr || n <= 0) {
		return -1;
	}
	for (int i = 0; i < n; ++i) {
		if (num[i] < 0 || num[i] > n - 1) {
			return -1;
		}
	}
	for (int i = 0; i < n; ++i) {//ʱ�临�Ӷ�O(n)���ռ�O(1)
		while (num[i] != i) {
			if (num[i] == num[num[i]]) {
				return num[i];
			}
			swap(num[i], num[num[i]]);
		}
	}
	return -1;
}

//��Ҫ�󲻸ı�ԭ����
//�������
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

//�ռ任ʱ��
//��ϣunordered_set�����������ִ�С
int test4(int num[], int n) {
	if (num == nullptr || n <= 0) {
		return -1;
	}
	unordered_set<int> us; //�ռ临�Ӷ�O(n)
	for (int i = 0; i < n; ++i) {//ʱ�临�Ӷ�O(n)
		if (us.find(num[i]) != us.end())
			return num[i];
		else us.insert(num[i]);
	}
	return -1;
}

//��ϣ�����������ִ�С������Ҫ�����ÿ�������ظ����ٸ�
int test5(int num[], int n) {
	if (num == nullptr || n <= 0) {
		return -1;
	}
	unordered_map<int, int> um; //�ռ临�Ӷ�O(n)
	for (int i = 0; i < n; ++i) {//ʱ�临�Ӷ�O(n)
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