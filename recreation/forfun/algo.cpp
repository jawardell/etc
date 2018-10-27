#include <iostream>
//#include "sha256.h"
#include <map>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

struct Element{
	string ID;
	int count;
};

int main()
{
	float phi, epsilon;
	cout << "Enter phi: ";
	cin >> phi;
	cout << "Enter epsilon: ";
	cin >> epsilon;

	Element items[(int)ceil(1/epsilon)];
	int len = ceil(1/epsilon);

	//initialize array to empty key value pairs
	for(int i = 0; i < len; i++){
		items[i].ID = "";
		items[i].count = 0;
	}


	map<int, string> addresses;


	string n;
	int m = 0;
	string path = "/Users/joannewardell/Desktop/joanne/code/misc/etc/recreation/forfun/synthetic.txt";

	ifstream ifs;
	ifs.open(path);
	ifs >> n;
	cout << n << endl;
	while(!ifs.eof()) {
		m++;
		//map.insert()
		bool found = false;
		for(int i = 0; i < len; i++){
			if(items[i].ID.compare(n) == 0){
				items[i].count++;
				found = true;
				break;
			}
		}

		bool full = true;
		int index;
		if(!found){
			for(int i = 0; i < len; i++){
				if(items[i].count == 0){
					full = false;
					index = i;
				}
			}

			if(!full){
				items[index].ID = n;
				items[index].count = 1;
			}
			else{
				for(int i = 0; i < len; i++)
					if(items[i].count >= 0)
						items[i].count--;
			}
		}

		ifs >> n;
	}

	cout << "\nNumbers:\n";
	int low = (phi - epsilon) * m;
	cout << "low: " << low << endl;
	puts("heavy hitters\n");
	for(int i = 0; i < len; i++)
		if(items[i].count >= low)
			cout << items[i].ID << "\t\t" << items[i].count << endl;
		//	cout << items[i].ID << endl;

	cout << "\nArray:\n";
	//for(int i = 0; i < len; i++) 
	//	cout << items[i].ID << "   " << items[i].count << endl;

	ifs.close();
	return 0;
}

