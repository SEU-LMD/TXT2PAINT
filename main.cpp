#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include "callpythondraw.h"
#include <Python.h>
using namespace std;
int main()
{
    Py_Initialize();
    //vector<myData> data_set;
    ifstream in_file;
    in_file.open("07.txt");
    cout <<"07.txt" <<endl;
    string line;
    while (getline(in_file, line)) {
        //cout << line.size() << endl;
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

        cout<< "ds"<<endl;
        t.time = ds[0];
        t.d[0] = ds[1], t.d[1] = ds[2], t.d[2] = ds[3];
        t.angle[0] = ds[4], t.angle[1] = ds[5];
        t.angle[2] = ds[6], t.angle[3] = ds[7];
        data_set.push_back(t);
        //cout<< "ds "
        //in_file.close();
    }
     in_file.close();
     callPythonDraw(data_set);
     cout << "diaoyongchenggong"<<endl;
     Py_Finalize();
     return 0;
}

