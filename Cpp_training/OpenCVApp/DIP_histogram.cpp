#include <iostream>
using namespace std;

int main() {
	int data[5 * 5] = { 1,2,3,4,5,
						1,0,2,0,4,
						2,3,0,2,3,
						3,1,2,3,2,
						1,2,3,0,2 };
	int data_max = 0;
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		if (data_max < data[i])data_max = data[i] + 1;
	}
	int dsize = sizeof(data) / sizeof(data[1]);
	//int dcnt[6] = { 0, };
	int dcnt_s = data_max;
	int* dcnt = new int[dcnt_s] {0, };
	int dcnt_max = 0;
	for (int i = 0; i < dsize; i++) {
		dcnt[data[i]]++;
	}
	for (int i = 0; i < dcnt_s; i++) {
		cout << i << ":" << dcnt[i] << endl;
	}
	/*for (int i = 0; i < 6; i++) {
		for (int j = 0; j < dcnt[i]; j++) {
			cout << "*";
		}
		cout << endl;
	}*/
	for (int i = 0; i < dcnt_s; i++) {
		if (dcnt_max < dcnt[i]) dcnt_max = dcnt[i];
	}
	cout << endl;
	for (int i = dcnt_max; i > 0; i--) {
		cout << i;
		for (int j = 0; j < dcnt_s; j++) {
			if (dcnt[j] >= i)cout << "^";
			else cout << " ";
		}
		cout << endl;
	}
	cout << " ";
	for (int j = 0; j < dcnt_s; j++) {
		cout << j;
	}
	if (dcnt != nullptr) {
		delete[] dcnt;
		dcnt = nullptr;
	}
	// histogram Ãâ·Â
}