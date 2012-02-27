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
|   File    : DataProcessor.cpp                                           |
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

#include "proc/DataProcessor.hpp"
#include <string>

namespace Pipeskel {

    DataProcessor::DataProcessor() {
        theName = "unnamed";
    }
    
    void DataProcessor::setName(string name) {
        theName = name;
    }
    
    string DataProcessor::getName() const {
        return theName;
    }
    
    DataProcessor::~DataProcessor() {
    }

}

