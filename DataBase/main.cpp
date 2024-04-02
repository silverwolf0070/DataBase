#include<iostream>
#include"func.h"
#include<fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");
	/*int n = 2;
	Video* arr = new Video[n];
	for (int i = 0; i < 2; i++) {
		cin >> arr[i];
		cout << arr[i];
	}
	/*/
	bool work = true;
	Video* arr = NULL;
	Video* arr1 = NULL;
	while (work) {
		cout << "1-create 2-read 3-search 4-add 5-edit 6-delete 7-exit" << endl;
		cout << "key=";
		int n = 0;
		int key = 0;
		cin >> key;
		switch (key) {
		case 1:
			cout << "n=";
			cin >> n;
			arr = new Video[n];
			create(arr, n);
			break;
		case 2:
			read(&arr, &n);
			for (int i = 0; i < n; i++) {
				cout << arr[i] << endl;
			}
			break;
		case 3:
			read(&arr, &n);
			cout << "1-id 2-name 3-views 4-likes 5-dislikes" << endl;
			search(arr, n);
			break;
		case 4:
			read(&arr, &n);
			arr1 = arr;
			n += 1;
			arr = new Video[n];
			for (int i = 0; i < n - 1; i++) {
				arr[i] = arr1[i];
			}
			add(arr, n);
			break;
		case 5:
			read(&arr, &n);
			edit(arr, n);
			break;
		case 6:
			read(&arr, &n);
			dele(&arr, &n);
			break;
		case 7:
			work = false;
		}
	}
	/*ideo test;
	cin >> test;
	cout << test;
	*/
}