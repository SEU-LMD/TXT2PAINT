//
// Created by ��ѩ�� on 2022/9/18.
//
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <fstream>
#include <Python.h>
using namespace std;

struct myData {
    double time;
    double d[3];
    double angle[4];
};
int callPythonDraw(const vector<myData>& data_set ) {

    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    pValue = NULL;
    pArgs = NULL;
   /* 
    vector<myData> data_set;
     vector<myData> read_txt(string addr){
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
        _data_set.push_back(str);//���б��м�����
        //cout << str <<endl;
    }
        
    for (int i = 0; i < _data_set.size(); i++)
    {
        PyList_Append(pList, Py_BuildValue("s", _data_set[i].c_str()));//���ַ�������pList
    }
*/
     //cout << "pList" <<endl;
    Py_Initialize();//��ʼ��
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");//�ҵ�py�ļ���·��
    //cout << "pList" <<endl;
    //pModule = PyImport_ImportModule("exercise1");//����ģ��
       pName = PyUnicode_FromString("exercise1");
       pModule = PyImport_Import(pName);
       Py_DECREF(pName);
      if (!pModule)		// ����ģ��ʧ��
    {
        cout << "[ERROR] Python get module failed." << endl;
        int a; cin >> a;
        return 0;
    }
        pFunc = PyObject_GetAttrString(pModule, "paint");//���ú���
        /* pFunc is a new reference */
       cout << "pList" <<endl;
        if (pFunc && PyCallable_Check(pFunc)) {//�ж�pFunc�Ƿ���Ա�����
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
        _data_set.push_back(str);//���б��м�����
        
    }
       cout << "liebiao successful" <<endl; 
    for (int i = 0; i < _data_set.size(); i++)
    {
        PyList_Append(pList, Py_BuildValue("s", _data_set[i].c_str()));//���ַ�������pList
    }
            pArgs = PyTuple_New(1);//����һ������
            // PyObject* item = Py_BuildValue("s");
            PyTuple_SetItem(pArgs, 0, pList);//���б�������
            pValue = PyObject_CallObject(pFunc, pArgs);//���ú������������

            Py_DECREF(pArgs);
            // Py_DECREF(item);
             //cout << "if" <<endl;
        }
       // else{
            //cout << "else" <<endl;
             //}
        if (pValue != NULL) {
            printf("Result of call: %ld\n", PyLong_AsLong(pValue));
            Py_DECREF(pValue);//判断参数是否调用成功
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
int main()
{
    Py_Initialize();
    // ����
    vector<myData> data_set;
    ifstream in_file;
    in_file.open("07.txt");

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


        t.time = ds[0];
        t.d[0] = ds[1], t.d[1] = ds[2], t.d[2] = ds[3];
        t.angle[0] = ds[4], t.angle[1] = ds[5];
        t.angle[2] = ds[6], t.angle[3] = ds[7];
        data_set.push_back(t);

        in_file.close();
    }
    // data_set ������Ȼ���뼴��
     callPythonDraw(data_set);
    Py_Finalize();
    return 0;
}
