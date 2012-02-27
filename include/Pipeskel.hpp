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
|   File    : Pipeskel.hpp                                                |
|   Created : 28-Jan-2011                                                 |
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

/** 
 * @mainpage Pipeline Skeleton
 *
 * @par General concept
 * Skeletal application based on a pipeline architecture.
 *
 * The Pipeline Skeleton intends to provide an adequate ground framework to
 * buttress a data processing project without compromising its future
 * growth. Therefore, it focuses on:
 *
 * - Modularity - Standard sequential modular framework that is of use 
 * in many speech and language processing applications.
 *
 * - Configurability - The processors (i.e. the modules) that 
 * build the pipeline are defined in an external XML config file (and are
 * loaded at runtime), making it easy to change and organise its different
 * configurations.
 *
 * - Extensibility - Core abstract design to facilitate the adaptation
 * of the pipeline to any particular purpose, environment or application.
 *
 * @image html arch.png "Pipeline architecture"
 *
 *
 * @par Usage details
 *
 * In order to use this pipeline processing structure, the following
 * steps need to be followed:
 * -# Data structure extension: the data to process should
 * be defined and introduced in the structure.
   @verbatim
   #include "Pipeskel.hpp" // Include shortcut

   class MyData : public Data {
       private:
           // Data fields.
       public:
           // Getters and setters are nice.
   }; @endverbatim
 * -# Data processor extension: the processors
 * should be able to handle the data by implementing the interface.
   @verbatim
   class MyDataProcessor : public DataProcessor {
       private:
           // Parameter fields.
       public:
           MyDataProcessor() { ... }
           void setParameter(string name, string value) throw(Exception) {
               if (name == "myparam") {
                   // Handle the processor parameter.
               } else {
                   throw Exception( ... );
               }
           }
           void init() throw(Exception) {
               // Definition of the initialisation procedure.
           }
           void processData(Data* dat) throw(Exception) {
               MyData* mydat = (MyData*)dat;
               // Definition of the processing method.
           }
           ~MyDataProcessor() { ... }
   }; @endverbatim
 * -# Pipeline extension: the pipeline should be able
 * to handle the particular implementations of the data processor.
   @verbatim
   class MyPipeline : public Pipeline {
       protected:
           DataProcessor* loadDataProcessor(string name) const
                   throw(Exception) {
               DataProcessor* retProc = NULL;
               if (name == "myproc") {
                   retProc = new MyDataProcessor();
               } else {
                   throw Exception( ... );
               }
               return retProc;
           }
       public:
           MyPipeline() { ... }
           ~MyPipeline() { ... }
   }; @endverbatim
 * -# Configuration file: in accordance with the particular extensions,
 * the XML config file should be defined as follows.
   @verbatim
   <?xml version="1.0" encoding="UTF-8" ?>
   <pipeline>
       <myproc myparam="value" />
       <!-- other data processors -->
   </pipeline> @endverbatim
 * -# Application usage: the particular implementation of the pipeline
 * should be used as follows.
   @verbatim
   int main(int argc, const char* argv[]) {
       // ...
       MyPipeline pipe; // Build the extended pipeline.
       pipe.loadConfig("XML_config_file_path"); // Configure the extended
                                                // pipeline.
       MyData* data = new MyData(); // Declare and instantiate an extended
                                    // data structure object.
       // Feed the structure with the data to be processed.
       pipe.processData(data); // Process the data.
       // ...
       return EXIT_SUCCESS;
   } @endverbatim
 *
 * To see a working example of an extended pipeline, refer to the
 * "src/example.cpp" file that is to be found in the source code
 * distribution of the Pipeline Skeleton.
 *
 * @author Alexandre Trilla (atrilla)
 * @version 0.0.1
 */

#include "data/Data.hpp"
#include "proc/DataProcessor.hpp"
#include "proc/Exception.hpp"
#include "proc/Pipeline.hpp"

