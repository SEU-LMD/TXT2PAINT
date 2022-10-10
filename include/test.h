#ifndef TEST_LIBRARY_H
#define TEST_LIBRARY_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class draw {
public:

    struct myData {
        double time;
        double d[3];
        double angle[4];
    };
	void PyInit(char filename[]);
    int callPythonDraw(const vector<myData>& data_set);
    void GetFileInfo(string file_name, vector<string>& data);
    //vector<myData> read_txt(string addr);
};
#endif //TEST_LIBRARY_H
