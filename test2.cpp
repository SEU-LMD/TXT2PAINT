#include <Python.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct myData {
    double time;
    double d[3];
    double angle[4];
};
vector<myData> data_set;

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
        auto str = to_string(data_set[i].time);
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
