#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

int main(int argc, char** argv) {
	ifstream in(argv[1]);
	int arr[200];
	memset(arr, -1, sizeof(arr));

	uint64_t sum = 0;
	if(in.is_open()) {
		while(!in.eof()) {
			char line[100];
			in.getline(line, 100);
			if(strlen(line) == 0) break;
			string buf;
			stringstream ss(line);
			while(ss>>buf) {}
			sum += stoi(buf);



			
			/*
			if(buf.length() != 0) {
				if(seek_per_second[(int)(stod(buf))] == -1) {	
					seek_per_second[(int)(stod(buf))]=0;
				}
				seek_per_second[(int)(stod(buf))]++;
			}*/
		}
	}
	cout << sum << endl;
	/*
	for(int i=0; i<200; i++) {
		if(seek_per_second[i] != -1)
			cout << i << "sec: " << seek_per_second[i] << endl;
	}*/
}
