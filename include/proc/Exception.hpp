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
|   File    : Exception.hpp                                           |
|   Created : 30-Jan-2011                                                 |
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

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

using namespace std;

namespace Pipeskel {

    /**
     * @class Exception
     * @brief Object to throw when an exception occurs.
     *
     * @author Alexandre Trilla (atrilla)
     */
    class Exception : public exception {
        protected:
            /**
             * @brief The entity that caused the exception.
             */
            string theSinner;
            /**
             * @brief The details about the exception.
             */
            string theDetails;
        public:
            /**
             * @brief Plain constructor.
             */
            Exception();
            /**
             * @brief Constructor with parameters.
             * @param std::string Who caused the exception.
             * @param std::string What happened.
             */
            Exception(const string sinner, const string details);
            /**
             * @brief Gets the entity who caused the exception.
             * @return const char* Who caused the exception.
             */
            const char* who() const throw();
            /**
             * @brief Gets the details of the exception.
             * @return const char* What caused the exception.
             */
            const char* what() const throw();
            /**
             * @brief Destructor.
             */
            ~Exception() throw();
    };

}

#endif

