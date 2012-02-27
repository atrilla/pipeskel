/*
______ _            _ _             _____ _         _      _               
| ___ (_)          | (_)           /  ___| |       | |    | |              
| |_/ /_ _ __   ___| |_ _ __   ___ \ `--.| | __ ___| | ___| |_  ___  _ __  
|  __/| | '_ \ / _ \ | | '_ \ / _ \ `--. \ |/ // _ \ |/ _ \ __|/ _ \| '_ \ 
| |   | | |_) |  __/ | | | | |  __//\__/ /   <|  __/ |  __/ |_| (_) | | | |
\_|   |_| .__/ \___|_|_|_| |_|\___|\____/|_|\_\\___|_|\___|\__|\___/|_| |_|
 _______| |_____________________________________________________________
|       |_|                                                            |\
|                                                                      |_\
|   File    : example.cpp                                                 |
|   Created : 25-Jan-2011                                                 |
|   By      : atrilla                                                     |
|                                                                         |
|   Pipeline Skeleton - Skeletal application based on a pipeline          |
|                       architecture                                      |
|                                                                         |
|   Copyright (c) 2011 Alexandre Trilla                                   |
|                                                                         |
|   -------------------------------------------------------------------   |
|                                                                         |
|   This file is part of Pipeline Skeleton.                               |
|                                                                         |
|   Pipeline Skeleton is free software: you can redistribute it and/or    |
|   modify it under the terms of the MIT/X11 License as published by the  |
|   Massachusetts Institute of Technology. See the MIT/X11 License for    |
|   more details.                                                         |
|                                                                         |
|   You should have received a copy of the MIT/X11 License along with     |
|   this source code distribution of Pipeline Skeleton (see the COPYING   |
|   file in the root directory). If not, see                              |
|   <http://www.opensource.org/licenses/mit-license>.                     |
|________________________________________________________________________*/

#include "Pipeskel.hpp"
#include <cstdlib>
#include <iostream>

using namespace Pipeskel;
using namespace std;

class MyData : public Data {
    private:
        int theCounter;
    public:
        MyData() { theCounter = 0; }
        void setCounter(int newC) { theCounter = newC; }
        int getCounter() const { return theCounter; }
        ~MyData() { }
};

class MyDataProcessor : public DataProcessor {
    private:
        int theParam;
    public:
        MyDataProcessor() { theParam = 0; }
        void setParameter(string name, string value) throw(Exception) {
            if (name == "myparam") {
                theParam = atoi(value.c_str());
            } else {
                throw Exception("MyDataProcessor", "Parameter " + name +
                    " does not exist!");
            }
        }
        void init() throw(Exception) { }
        void processData(Data* dat) throw(Exception) {
            // Cast to my data class.
            MyData* mydat = (MyData*)dat;
            // Process my data.
            mydat->setCounter(mydat->getCounter() + theParam);
        }
        ~MyDataProcessor() { }
};

class MyPipeline : public Pipeline {
    protected:
        DataProcessor* loadDataProcessor(string name) const 
                throw(Exception) {
            DataProcessor* retProc = NULL;
            if (name == "myproc") {
                retProc = new MyDataProcessor();
            } else {
                throw Exception("MyPipeline", "processor " + name +
                    " does not exist!");
            }
            return retProc;
        }
    public:
        MyPipeline() { }
        ~MyPipeline() { }
};

int main(int argc, const char* argv[]) {
    if (argc == 2) {
        // API level.
        MyPipeline pipe;
        pipe.loadConfig(argv[1]);
        MyData* data = new MyData();
        pipe.processData(data);
        cout << "data result counter: " << data->getCounter() << endl;
        delete data;
    } else {
        cout << "Hey, no args!!!" << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

