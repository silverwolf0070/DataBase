#pragma once
class Video {
private:
	unsigned int id;
	char name[40] = {};
	unsigned int views={0};
	unsigned int likes={0};
	unsigned int dislikes={0};
public:
	void setId(int x);
	friend std::istream& operator >>(std::istream& in, Video& r);
	friend std::ostream& operator <<(std::ostream& out, const Video& r);
	int getId();
	std::string getName();
	int getViews();
	int getLikes();
	int getDis();

};


void create(Video *arr, int n);
void read(Video** arr, int* n);
void search(Video* arr, int n);
void add(Video* arr,int n);
void edit(Video* arr, int n);
void dele(Video** arr, int* n);