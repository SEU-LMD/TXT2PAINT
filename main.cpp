#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "test.h"
using namespace std;

struct myData {
	double time;
	double d[3];
	double angle[4];
};


vector<myData> read_txt(string addr) {
	vector<myData> res;

	ifstream in_file;
	in_file.open("07.txt");

	string line;
	while (getline(in_file, line)) {
		cout << line.size() << endl;
		myData t;
		vector<double> ds;
		int last = 0;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == ' ') {
				auto s = line.substr(last, i - last);
				auto d = stod(s);
				ds.push_back(d);
				last = i + 1;
			}
		}

		ds.push_back(stod(line.substr(last)));


		t.time = ds[0];
		t.d[0] = ds[1], t.d[1] = ds[2], t.d[2] = ds[3];
		t.angle[0] = ds[4], t.angle[1] = ds[5];
		t.angle[2] = ds[6], t.angle[3] = ds[7];
		res.push_back(t);
	}
	in_file.close();
	return res;
}

int main() {
	auto t = read_txt("07.txt");
        callPythonDraw(data_set);
	return 0;

}
