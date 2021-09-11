#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

int main(int argc, char** argv) {
	ifstream in(argv[1]);
	int seek_per_second[200];
	memset(seek_per_second, -1, sizeof(seek_per_second));

	if(in.is_open()) {
		while(!in.eof()) {
			char line[100];
			in.getline(line, 100);
			string buf;
			stringstream ss(line);
			ss >> buf;
			
			if(buf.length() != 0) {
				if(seek_per_second[(int)(stod(buf))] == -1) {	
					seek_per_second[(int)(stod(buf))]=0;
				}
				seek_per_second[(int)(stod(buf))]++;
			}
		}
	}
	for(int i=0; i<200; i++) {
		if(seek_per_second[i] != -1)
			cout << i << "sec: " << seek_per_second[i] << endl;
	}
}
