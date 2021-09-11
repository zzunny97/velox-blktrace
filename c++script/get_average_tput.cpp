#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	int arr[1000];
	int time, seek;
	memset(arr, -1, sizeof(arr));
	for(int i=3; i<=10; i++) {
		string input_file = "/home/velox4/git/blktrace/eternity" + to_string(i) + "/seekwatcher_tput";
		ifstream in(input_file);
		if(in.is_open()) {
			while(!in.eof()) {
				string line;
				getline(in, line);
				stringstream ss(line);
				string buf;
				ss >> buf;
				if(buf.find("sec") != -1) {
					const int idx = buf.find("sec");
					time = stoi(buf.substr(0, idx));
					//cout << time << endl;
					ss >> buf;
					seek = stoi(buf);
					//cout << seek << endl;
					if(arr[time] == -1) {
						arr[time] = 0;
					}
					arr[time] += seek;
				}

			}
		}
		else {
			cout << "file open error" << endl;
			exit(1);
		}
	}
	//cout << "Average tput" << endl;
	for(int i=0; i<1000; i++) {
		if(arr[i] != -1) {
			//cout << i << "sec: " << (double)arr[i] / 20 << endl;
			cout << i << "sec: " << (double)arr[i] / 8 << endl;
		}
	}
}
