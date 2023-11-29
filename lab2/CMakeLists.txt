cmake_minimum_required(VERSION 3.26.4)

project(lab2)

set(SOURCES
        main.cpp
        
)       

set(Headers  
       
)

add_executable(lab2 ${SOURCES})

target_sources(lab2 PRIVATE ${Headers})