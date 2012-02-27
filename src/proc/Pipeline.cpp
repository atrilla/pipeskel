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
|   File    : Pipeline.cpp                                                |
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

#include "proc/Pipeline.hpp"
#include "extern/ticpp/ticpp.h"
#include <string>
#include <iostream>

using namespace ticpp;

namespace Pipeskel {

    Pipeline::Pipeline() {
    }
    
    void Pipeline::loadConfig(string configFilePath) {
        // Parse the XML config file.
        try {
            Document doc(configFilePath.c_str());
            doc.LoadFile();
            // Get the processors.
            Iterator<Element> processor;
            for (processor = processor.begin(doc.FirstChildElement()); 
                    processor != processor.end(); processor++) {
                // Processor name.
                string name;
                processor->GetValue(&name);
                // If OK, does not throw any exception.
                DataProcessor* dProc = loadDataProcessor(name);
                dProc->setName(name);
                // Processor parameters.
                string value;
                Iterator<Attribute> parameter;
                for (parameter = parameter.begin(processor.Get());
                        parameter != parameter.end(); parameter++) {
                    parameter->GetName(&name);
                    parameter->GetValue(&value);
                    dProc->setParameter(name, value);
                }
                // Init processor.
                dProc->init();
                // Pipe this processor
                thePipe.push_back(dProc);
            }
        } catch (ticpp::Exception& ex) {
            cout << "Pipeline: XML parsing problem:" << endl;
            cout << ex.what() << endl;
            exit(EXIT_FAILURE);
        } catch (Exception& ex) {
            cout << "Pipeline: data processor config problem:" << endl;
            cout << ex.who() << " --> " << ex.what() << endl;
            exit(EXIT_FAILURE);
        }
    }
    
    void Pipeline::processData(Data* dat) {
        if (!thePipe.empty()) {
            try {
                for (vector<DataProcessor*>::const_iterator nProc = 
                        thePipe.begin(); nProc != thePipe.end(); ++nProc) {
                    (*nProc)->processData(dat);
                }
            } catch (Exception& ex) {
                cout << "Pipeline: data processing problem:" << endl;
                cout << ex.who() << " --> " << ex.what() << endl;
                exit(EXIT_FAILURE);
            }
        } else {
            cout << "Pipeline data processing before its configuration!"
                << endl;
            exit(EXIT_FAILURE);
        }
    }
    
    Pipeline::~Pipeline() {
        if (!thePipe.empty()) {
            for (int nProc = 0; nProc < thePipe.size(); nProc++) {
                delete thePipe[nProc];
            }
        }
    }

}

