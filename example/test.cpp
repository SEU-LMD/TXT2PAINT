#include <vector>
#include <unistd.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include "draw2d.h"
#include "Python.h"
using namespace std;
int main()
{

    //1.read data froms
    std::vector<std::vector<double>> data_set;
    ifstream in_file;
    in_file.open("./example/data.txt");
    string line;
    while (getline(in_file, line)) {
        //cout << line.size() << endl;
        std::vector<double> ds;
        int last = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                auto s = line.substr(last, i - last);
                auto d = std::stod(s);
                ds.push_back(d);
                last = i + 1;
            }
        }

        ds.push_back(stod(line.substr(last)));

        data_set.push_back(ds);
    }
     in_file.close();

     //2.call c++-python interface
     PythonDraw::Draw2D draw2d;
    

     
     if(draw2d.init(false,true)){
          for(int i = 0;i<100;i++){
              draw2d.push_draw_data(data_set);
              sleep(1);
          }
     }
    //  for(int i = 0 ;i<data_set.size();i++){
    //           std::vector<std::vector<double>> cur_data;
    //           cur_data.push_back(data_set[i]);
    //           draw2d.push_draw_data(cur_data);
    //           sleep(1);
    //  }
     cout << "finish drawing!"<<endl;
     return 0;
}

