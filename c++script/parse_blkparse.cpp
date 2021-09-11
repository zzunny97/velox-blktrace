#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;
void print_vec(vector<string>& v) {
	for(auto iter=v.begin(); iter!=v.end(); iter++)
		cout << *iter << endl;
}

bool compare(string a, string b) {
	double comp_a, comp_b;
	stringstream ss(a);
	string buf;
	ss >> buf;
	comp_a = stod(buf);
	stringstream ss2(b);
	ss2 >> buf;
	comp_b = stod(buf);
	return comp_a < comp_b;


}

int main(int argc, char** argv) {
	ifstream in(argv[1]);
	vector<string> query;
	uint64_t num = 0;
	if(in.is_open()) {
		while(!in.eof()) {
			char line[100];
			in.getline(line, 100);
			string buf;
			stringstream ss(line);
			vector<string> tmp;
			while(ss >> buf) {
				tmp.push_back(buf);
			}
			//print_vec(tmp);
			if(tmp.size() == 12) {
				if(tmp[11] == "[eclipse_node]") {
					if(tmp[6] == "D") {
						string output="";
						output.append(tmp[4]+"\t"+tmp[8]+"\t"+tmp[9]+"\t"+tmp[10]);
						query.push_back(output);
						//print_vec(query);
					}
				}
			}
			num++;
			//break;
		}
		//cout << "printing..." << endl;

		//cout << "Before sort" << endl;
		//print_vec(query);
		sort(query.begin(), query.end(), compare);
		//cout << "After sort" << endl;
		query.erase(unique(query.begin(), query.end()), query.end());
		print_vec(query);
		
	}
	else { 
		cout << "Error" << endl;
		exit(1);
	}

}
