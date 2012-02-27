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
|   File    : Pipeline.hpp                                                |
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

#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include "data/Data.hpp"
#include "proc/DataProcessor.hpp"
#include "proc/Exception.hpp"
#include <vector>
#include <string>

using namespace std;

namespace Pipeskel {

    /**
     * @class Pipeline
     * @brief Sequential processing structure containing several 
     *     processors that are defined in an external XML config
     *     file.
     *
     * @author Alexandre Trilla (atrilla)
     */
    class Pipeline {
        protected:
            /**
             * @brief The structure that is to contain the processors.
             */
            vector<DataProcessor*> thePipe;
            /**
             * @bief Matches the name of a processor as it is found in the
             *     config file with the actual implementation of the
             *     processor. TBD.
             * @param std::string The name of the processor.
             * @return The processor identified by the name.
             * @throws Exception Processor does not exist.
             */
            virtual DataProcessor* loadDataProcessor(string name)
                const throw(Exception) = 0;
        public:
            /**
             * @brief Plain constructor.
             */
            Pipeline();
            /**
             * @brief Loads the configuration defined in the external
             *     XML config file.
             * @param std::string The XML file path.
             */
            void loadConfig(string configFilePath);
            /**
             * @brief Iterates over the pipeline to process the given
             *     data.
             * @param The given data.
             */
            void processData(Data* dat);
            /**
             * @brief Destructor.
             */
            virtual ~Pipeline();
    };

}

#endif

