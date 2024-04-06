#include<iostream>
#include<string>
#include"func.h"
#include<fstream>

std::istream& operator >> (std::istream& in, Video& r) {
	std::cout << "name=";
	std::string str;
	in >> str;
	int len = str.length();
	if (len <= 40) {
		for (int i = 0; i < len; i++) {
			r.name[i] = str[i];
		}
		for (int i = len; i < 40; i++) {
			r.name[i] = {};
		}
	}
	else
		for (int i = 0; i < 40; i++) {
			r.name[i] = str[i];
		}
	std::cout << "views=";
	in >> r.views;
	std::cout << "likes=";
	in >> r.likes;
	std::cout << "dislikes=";
	in >> r.dislikes;
	return in;
}

std::ostream& operator << (std::ostream & out, const Video & r) {
	out << r.id << " " << r.name << " " << r.views << " " << r.likes << " " << r.dislikes;
	return out;
}

void Video::setId(int x) {
	id = x;
}

int Video::getId() {
	return id;
}

std::string Video::getName() {
	return name;
}

int Video::getViews() {
	return views;
}

int Video::getLikes() {
	return likes;
}

int Video::getDis() {
	return dislikes;
}

namespace dat {
	void create(Video* arr, int n) {
		std::ofstream out;
		out.open("data", std::ios_base::binary);
		if (!out.is_open()) {
			std::cout << "error" << std::endl;//проверка открытия файла
			return;
		}

		out.write((char*)&n, sizeof(int));
		size_t size = sizeof(Video);
		for (int i = 0; i < n; i++) {
			//std::cout << i<<std::endl;
			//std::cout << arr[i] << std::endl;
			std::cin >> arr[i];
			arr[i].setId(i);
			//std::cout <<
			out.write((char*)&arr[i], size);
		}
		out.close();
		return;
	}

	void read(Video** arr, int* n) {
		std::ifstream in;
		in.open("data", std::ios_base::binary);
		if (!in.is_open()) {
			std::cout << "error" << std::endl;
			return;
		}
		in.read((char*)n, sizeof(int));
		//std::cout << *n << std::endl;
		*arr = new Video[*n];
		std::cout << *n << std::endl;
		for (int i = 0; i < *n; i++) {
			//std::cout << in.tellg() << std::endl;
			in.read((char*)&(*arr)[i], sizeof(Video));
			//std::cout << *arr[i] << std::endl;
			//std::cout << in.tellg() << std::endl;
		}
		in.close();
		return;
	}

	void search(Video* arr, int n) {
		std::cout << "key=";
		int key = 0;
		std::cin >> key;
		int x;
		std::string name;
		int mn;
		int mx;
		switch (key) {
		case 1:

			std::cout << "x=";
			std::cin >> x;
			for (int i = 0; i < n; i++) {
				if (x == arr[i].getId())
					std::cout << arr[i] << std::endl;
			}
			break;
		case 2:

			std::cout << "name=";
			std::cin >> name;
			for (int i = 0; i < n; i++) {
				if (name == arr[i].getName()) {
					std::cout << arr[i] << std::endl;
				}
			}
			break;
		case 3:

			std::cout << "min=";
			std::cin >> mn;
			std::cout << "max=";
			std::cin >> mx;
			for (int i = 0; i < n; i++) {
				if (arr[i].getViews() < mx && arr[i].getViews() > mn)
					std::cout << arr[i] << std::endl;
			}
			break;
		case 4:
			std::cout << "min=";
			std::cin >> mn;
			std::cout << "max=";
			std::cin >> mx;
			for (int i = 0; i < n; i++) {
				if (arr[i].getLikes() < mx && arr[i].getLikes() > mn)
					std::cout << arr[i] << std::endl;
			}
			break;
		case 5:
			std::cout << "min=";
			std::cin >> mn;
			std::cout << "max=";
			std::cin >> mx;
			for (int i = 0; i < n; i++) {
				if (arr[i].getDis() < mx && arr[i].getDis() > mn)
					std::cout << arr[i] << std::endl;
			}
			break;
		}
	}

	void add(Video* arr, int n) {
		if (n >= 2)
			arr[n - 1].setId(arr[n - 2].getId() + 1);
		else
			arr[n - 1].setId(0);
		std::cin >> arr[n - 1];
		std::ofstream out;
		out.open("data", std::ios_base::binary);
		if (!out.is_open()) {
			std::cout << "error" << std::endl;//проверка открытия файла
			return;
		}
		out.write((char*)&n, sizeof(int));
		size_t size = sizeof(Video);
		for (int i = 0; i < n; i++) {
			out.write((char*)&(arr[i]), size);
		}
		out.close();
		return;
	}

	void edit(Video* arr, int n) {
		std::cout << "id=";
		int x;
		std::cin >> x;
		for (int i = 0; i < n; i++) {
			if (x == arr[i].getId()) {
				std::cin >> arr[i];
			}
		}
		std::ofstream out;
		out.open("data", std::ios_base::binary);
		if (!out.is_open()) {
			std::cout << "error" << std::endl;//проверка открытия файла
			return;
		}
		out.write((char*)&n, sizeof(int));
		size_t size = sizeof(Video);
		for (int i = 0; i < n; i++) {
			out.write((char*)&(arr[i]), size);
		}
		out.close();
		return;
	}

	void dele(Video** arr, int* n) {
		std::cout << "id=";
		int x = 0;
		int k = 0;
		std::cin >> x;
		for (int i = 0; i < *n; i++) {
			if ((*arr)[i].getId() == x) {
				k = i;
				break;
			}
		}
		*n -= 1;
		for (int i = k; i < *n; i++) {
			(*arr)[i] = (*arr)[i + 1];
		}
		std::ofstream out;
		out.open("data", std::ios_base::binary);
		if (!out.is_open()) {
			std::cout << "error" << std::endl;//проверка открытия файла
			return;
		}
		out.write((char*)n, sizeof(int));
		size_t size = sizeof(Video);
		out.write(reinterpret_cast<char*>(*arr), size * (*n));
		out.close();
		//read(arr, n);
		return;
	}
}