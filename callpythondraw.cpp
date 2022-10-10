#include <Python.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct myData {
    double time;
    double d[3];
    double angle[4];
};


int callPythonDraw(const vector<myData>& data_set)
{
    PyObject* pName, * pModule, * pFunc;
    PyObject* pArgs, * pValue;
    pValue = NULL;
    pArgs = NULL;
cout<<"c1"<<endl;
    PyObject* pList = PyList_New(0); // 创建一个列表
    vector<string> _data_set;
cout<<"c2"<<endl;
    for (int i = 0; i < data_set.size(); i++)
    {
        string str = to_string(data_set[i].time);
        for (int k = 0; k < 3; k++)
        {
            str += " " + to_string(data_set[i].d[k]);
        }
        for (int k = 0; k < 4; k++)
        {
            str += " " + to_string(data_set[i].angle[k]);
        }
        _data_set.push_back(str);
    }
cout<<"c3"<<endl;
    for (int i = 0; i < _data_set.size(); i++)
    {
        PyList_Append(pList, Py_BuildValue("s", _data_set[i].c_str()));
    }
cout<<"c4"<<endl;
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");

cout<<"c5"<<endl;
    pName = PyUnicode_FromString("exercise1");
    /* Error checking of pName left out */


    pModule = PyImport_Import(pName);
    Py_DECREF(pName);
cout<<"c6"<<endl;
    if (pModule != NULL) {

        pFunc = PyObject_GetAttrString(pModule, "paint");
        /* pFunc is a new reference */

        if (pFunc && PyCallable_Check(pFunc)) {

            pArgs = PyTuple_New(1);
            // PyObject* item = Py_BuildValue("s");
            PyTuple_SetItem(pArgs, 0, pList);
            pValue = PyObject_CallObject(pFunc, pArgs);

            //Py_DECREF(pArgs);
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
    return 0;
}

int main(int argc, char *argv[])
{
    
   // if (argc < 4) {
        //fprintf(stderr,"Usage: call pythonfile funcname filename_of_data\n");
       // return 1;
   // }

    //Py_SetPythonHome(L"/home/wxy/9.16/python-3.6");
    Py_Initialize();
    // 测试
    vector<myData> data_set;
    
    // data_set 构建好然后传入即可
ifstream in_file;
    in_file.open("07.txt");
    int n=0;
    string line;
    //从txt中逐行读取
    //Py_Initialize();
    while (getline(in_file, line)) {
        cout << "line.size:"<<line.size() << endl;
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
        //将数据从ds中喂给data_set
        t.time = ds[0];
        t.d[0] = ds[1], t.d[1] = ds[2], t.d[2] = ds[3];
        t.angle[0] = ds[4], t.angle[1] = ds[5];
        t.angle[2] = ds[6], t.angle[3] = ds[7];
        data_set.push_back(t);
        cout<<data_set.size()<<endl;
        //callPythonDraw(data_set);
        //cout << n <<endl;
        ++n;    
    }
    in_file.close();
    callPythonDraw(data_set);
    Py_Finalize();
    return 0;
}

