#ifndef PYTHONDRAW_DRAWBASE_HEADER
#define PYTHONDRAW_DRAWBASE_HEADER
#include <string>
#include <iostream>
#include <vector>
#include "Python.h"
#include <string>
#include <fstream>
#include <thread>
#include <mutex>
#include <deque>

#include "config.h"
namespace PythonDraw{

    class DrawBase
        {
            protected:
                std::mutex mutex_draw_data;
                std::deque<std::vector<std::vector<double>>> draw_data_queue;
                std::vector<std::vector<double>> add_on_data;//just use when addon = true
                std::thread draw_thread;
                bool addon = false;
                bool exit = false;//whether to exit thread
                bool block = true;//whether to open a new thread to draw img
                PyObject* pFunc,*pModule;

                void draw_thread_work()
                {
                    while(!exit){
                        std::vector<std::vector<double>> d;

                        mutex_draw_data.lock();
                        if(draw_data_queue.size()!=0){
                            d = draw_data_queue.front();
                            draw_data_queue.pop_front();
                        }
                        mutex_draw_data.unlock();

                        if(d.size()!=0){
                            callPythonDraw(d);
                        }
                    }
                    std::cout<<"exit draw thread!"<<std::endl;
                }
            public:
                virtual bool init(bool addon_ = false, bool block_ = true) = 0;
                virtual bool callPythonDraw(std::vector<std::vector<double>>& data_set) = 0;

                void push_draw_data(std::vector<std::vector<double>>& data){
                    if(!block){
                        mutex_draw_data.lock();
                        draw_data_queue.push_back(data);
                        mutex_draw_data.unlock();
                    }
                    else{
                        callPythonDraw(data);
                    }
                }
                
                ~DrawBase()
                {
                    exit = true;
                    add_on_data.clear();
                    Py_XDECREF(pFunc);
                    Py_DECREF(pModule);
                    Py_Finalize();
                }                
        };
}//end namespace PythonDraw
#endif