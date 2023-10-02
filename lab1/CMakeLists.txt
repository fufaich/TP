cmake_minimum_required(VERSION 3.26.0)

project(lab1)

set(SOURCES
        main.cpp
        entity/Garage.cpp
        entity/Auto.cpp
        entity/Bus.cpp 
        entity/Motorcycle.cpp
        
)       

set(Headers  
        entity/Garage.h
        entity/Auto.h
        entity/Motorcycle.h
        entity/Bus.h
)

add_executable(lab1 ${SOURCES})

target_sources(lab1 PRIVATE ${Headers})