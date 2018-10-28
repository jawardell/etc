#include <iostream>
#include <iterator>
#include "sha256.h"
//#include "timer.h"
#include <map>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	//Timer timer;
	//unsigned long start = timer.get_time();
	float phi, epsilon;
	cout << "Enter phi: ";
	cin >> phi;
	cout << "Enter epsilon: ";
	cin >> epsilon;

	int len = ceil(1/epsilon);

	
	// hash,count
	std::map<string, int> my_map;


	string n;
	int m = 0;
	string path = "/Users/joannewardell/Desktop/joanne/code/misc/etc/recreation/forfun/algo/ips.txt";

	ifstream ifs;
	ifs.open(path);
	ifs >> n;
	while(!ifs.eof()) {
		m++;
		//if(m>10000)break;
//		cout << n << "  -  "<<my_map.size()<<endl;
		if(my_map.find(n) != my_map.end()) {
			my_map[n]++;
		} else {
			//if map is full, perform decriment
			if(my_map.size() == len) {
		//		cout<<"map is full"<<endl;
				std::map<string,int>::iterator it=my_map.begin();
			       while(	it!=my_map.end()){
					string key = it -> first;
					my_map[key]--;
					if(my_map[key]==0){

						// delete key
						std::map<string,int>::iterator toDel=it++;
						my_map.erase(toDel);
					}
					else
						it++;
				}
				// delete all that are zero
			} else {
				
				my_map[n] = 1;
			}
		}


		//insert hash data and insert into map with initial count 0
		//		if the item is not found in the list and the map has room
		if(my_map.size() < len) {
			my_map.insert(std::pair<string,int>(n,0));
		}

		ifs >> n;
	}

	int low = (phi - epsilon) * m;
	cout << "low: " << low << endl;
	puts("\nheavy hitters\n");

	map<string, int>::iterator it;
	for (std::map<string,int>::iterator it=my_map.begin(); it!=my_map.end();it++) {
		if(it -> second >= low)
			cout << it -> first << "\t\t" << it -> second << endl;
		
	}


	cout << "\nArray:\n";
	ifs.close();
	//unsigned long end = timer.get_time();
	//unsigned long total = end - start;
	//printf("\n%s%lu%s\n", "total time: ", total, "ms");
	return 0;
}

