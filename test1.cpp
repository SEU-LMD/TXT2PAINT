//
// Created by 王雪妍 on 2022/9/18.
//
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <fstream>
#include <Python.h>
using namespace std;
int callPythonDraw(){
    struct myData {
        double time;
        double d[3];
        double angle[4];
    };

    PyObject* pName, * pModule, * pFunc;
    PyObject* pArgs, * pValue;
    pValue = NULL;
    pArgs = NULL;
    Py_Initialize();//初始化
    vector<myData> data_set;
    vector<myData> read_txt(string addr) {

        ifstream in_file;
        in_file.open(addr.data());

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
            data_set.push_back(t);
        }
        in_file.close();

        return data_set;
    }
    PyObject* pList = PyList_New(0);
    vector<string> _data_set;
    for (int i = 0; i < data_set.size(); i++)
    {
        auto str = to_string(data_set[i].time);
        for (int k = 0; k < 3; k++)
        {
            str += " " + to_string(data_set[i].d[k]);
        }
        for (int k = 0; k < 4; k++)
        {
            str += " " + to_string(data_set[i].angle[k]);
        }
        _data_set.push_back(str);//向列表中加入项
    }
    for (int i = 0; i < _data_set.size(); i++)
    {
        PyList_Append(pList, Py_BuildValue("s", _data_set[i].c_str()));//把字符串传给pList
    }
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");//找到py文件的路径
    pModule = PyImport_ImportModule("exercise1");//加载模块
    if (pModule != NULL) {

        pFunc = PyObject_GetAttrString(pModule, "paint");//调用函数
        /* pFunc is a new reference */

        if (pFunc && PyCallable_Check(pFunc)) {//判断pFunc是否可以被调用

            pArgs = PyTuple_New(1);//定义一个参数
            // PyObject* item = Py_BuildValue("s");
            PyTuple_SetItem(pArgs, 0, pList);//将列表赋给参数
            pValue = PyObject_CallObject(pFunc, pArgs);//调用函数，传入参数

            Py_DECREF(pArgs);
            // Py_DECREF(item);
        }
        if (pValue != NULL) {
            printf("Result of call: %ld\n", PyLong_AsLong(pValue));
            Py_DECREF(pValue);
        }
        else {
            Py_DECREF(pFunc);
            Py_DECREF(pModule);
            PyErr_Print();
            fprintf(stderr, "Call failed\n");
            return 1;
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    Py_Finalize();


    return 0;

}


