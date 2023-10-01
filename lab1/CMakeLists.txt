cmake_minimum_required(VERSION 3.26.0)

project(lab1)

set(SOURCES
        main.cpp
        entity/Garage.cpp
        entity/Auto.cpp
        
)       

set(Headers  
        entity/Garage.h
        entity/Auto.h
        entity/Motorcycle.h
)

add_executable(lab1 ${SOURCES} ${Headers})