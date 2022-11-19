#ifndef PYTHONDRAW_DRAW2D_HEADER
#define PYTHONDRAW_DRAW2D_HEADER

#include "drawBase.h"
#include "config.h"

namespace PythonDraw{
    class Draw2D:public DrawBase
    {
        public :    
            
            virtual bool init(bool addon_ = false, bool block_ = true){
                    Py_Initialize();
                    this->block = block_;
                    this->addon = addon_;

                    //load pyhon code and function
                    PyRun_SimpleString("import sys");
                    std::string abs_py_path = "sys.path.append('"+PYTHONDRAW_CURPATH+"')";
                    PyRun_SimpleString(abs_py_path.c_str());
                    PyObject*  pName = PyUnicode_FromString("draw2d");
                    this->pModule = PyImport_Import(pName);
                    Py_DECREF(pName);
                    if (this->pModule == NULL) {
                        std::cout<<"load python code failed"<<std::endl;
                        return false;
                    }
                    this->pFunc = PyObject_GetAttrString(this->pModule, "paint");
                    if( this->pFunc == NULL) {
                        std::cout<<"load python code succes but do not exist paint function"<<std::endl;
                        return false;
                    }

                    if(!block){
                        draw_thread = std::thread(&Draw2D::draw_thread_work,this);
                    }
                    return true;
            }
            
            //input_data order : timestamp tx ty tz qw qx qy qz
            virtual bool callPythonDraw(std::vector<std::vector<double>>& data_set)
            {
                if(this->addon){
                    this->add_on_data.insert(this->add_on_data.end(),data_set.begin(),data_set.end());
                }
                
                //1.convert double data to stirng for python interface
                std::vector<std::string> s_data_set;//prepared to send to python
                if(this->addon){//use add_on_data
                    for (auto& pose : this->add_on_data)
                    {
                        std::string s_pose = "";
                        for(auto& d: pose){
                            s_pose += std::to_string(d)+" ";
                        }
                        s_data_set.push_back(s_pose);
                    }
                }
                else{//use data_set
                    for (auto& pose : data_set)
                    {
                        std::string s_pose = "";
                        for(auto& d: pose){
                            s_pose += std::to_string(d)+" ";
                        }
                        s_data_set.push_back(s_pose);
                    }
                }
                
                //2.add data to pyhon list
                PyObject* pList = PyList_New(0);
                for (auto& data: s_data_set)
                {
                    PyList_Append(pList, Py_BuildValue("s",data.c_str()));
                }
                std::cout<<"convet input = "<<add_on_data.size()<<std::endl;
                //4.call python function 
                PyObject* pValue = NULL;
                if (pFunc && PyCallable_Check(pFunc)) {

                    PyObject*  pArgs = PyTuple_New(1);
                    // PyObject* item = Py_BuildValue("s");
                    PyTuple_SetItem(pArgs, 0, pList);
                    pValue = PyObject_CallObject(pFunc, pArgs);
                    Py_DECREF(pArgs);
                    // Py_DECREF(item);
                }

                if (pValue != NULL) {
                    printf("Result of call: %ld\n", PyLong_AsLong(pValue));
                    Py_DECREF(pValue);
                }
                else {
                    Py_DECREF(pValue);
                    Py_DECREF(pFunc);
                    Py_DECREF(pModule);
                    PyErr_Print();
                    std::cout<<"call python function failed"<<std::endl;
                    return false;
                }
                
                return true;
            }
    };//end draw2d
}

#endif
