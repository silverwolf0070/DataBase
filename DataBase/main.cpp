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
	
	int n = 0;
	while (work) {
		cout << "1-create 2-read 3-search 4-add 5-edit 6-delete 7-exit" << endl;
		cout << "key=";

		int key = 0;
		cin >> key;
		switch (key) {
		case 1:
			cout << "n=";
			cin >> n;
			arr = new Video[n];
			dat::create(arr, n);
			break;
		case 2:
			if(arr==NULL)
				dat::read(&arr, &n);
			for (int i = 0; i < n; i++) {
				cout << arr[i] << endl;
			}
			break;
		case 3:
			if(arr==NULL)
				dat::read(&arr, &n);
			cout << "1-id 2-name 3-views 4-likes 5-dislikes" << endl;
			dat::search(arr, n);
			break;
		case 4:
		{
			Video* arr1 = NULL;
			if (arr == NULL)
				dat::read(&arr, &n);
			arr1 = arr;
			n += 1;
			arr = new Video[n];
			for (int i = 0; i < n - 1; i++) {
				arr[i] = arr1[i];
			}
			dat::add(arr, n);
			delete[]arr1;
		}
			break;
		case 5:
			if(arr==NULL)
				dat::read(&arr, &n);
			dat::edit(arr, n);
			break;
		case 6:
			if(arr==NULL)
				dat::read(&arr, &n);
			dat::dele(&arr, &n);
			dat::read(&arr, &n);
			break;
		case 7:
			work = false;
		}
	}
	delete[]arr;
}