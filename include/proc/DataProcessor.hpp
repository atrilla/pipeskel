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
|   File    : DataProcessor.hpp                                           |
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

#ifndef DATAPROCESSOR_HPP
#define DATAPROCESSOR_HPP

#include "data/Data.hpp"
#include "proc/Exception.hpp"
#include <string>

using namespace std;

namespace Pipeskel {

    /**
     * @class DataProcessor
     * @brief Common interface that is to be implemented by
     * the processors in the pipeline.
     *
     * @author Alexandre Trilla (atrilla)
     */
    class DataProcessor {
        protected:
            /**
             * @brief Processor identifier, useful to throw exceptions.
             */
            string theName;
        public:
            /**
             * @brief Plain constructor.
             */
            DataProcessor();
            /**
             * @brief Sets the name identifier of the processor.
             * @param std::string The name of the processor.
             */
            void setName(string name);
            /**
             * @brief Gets the name identifier of the processor.
             * @return The name of the processor.
             */
            string getName() const;
            /**
             * @brief Sets the value of the given processor parameter.
             *     TBD.
             * @param std::string The name of the parameter.
             * @param std::string The value of the parameter.
             * @throws Exception Parameter does not exist.
             */
            virtual void setParameter(string name, string value)
                throw(Exception) = 0;
            /**
             * @brief Initialises the processor. TBD.
             * @throws Exception Initialisation problem.
             */
            virtual void init() throw(Exception) = 0;
            /**
             * @brief Processes the given data. TBD.
             * @param Data The data.
             * @throws Exception The given data cannot be processed.
             */
            virtual void processData(Data* dat) throw(Exception) = 0;
            /**
             * @brief Destructor.
             */
            virtual ~DataProcessor();
    };

}

#endif

