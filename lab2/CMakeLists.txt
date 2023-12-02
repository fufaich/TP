cmake_minimum_required(VERSION 3.26.4)

project(lab2)

set(SOURCES
        main.cpp
        part1/Student.cpp
        part1/keeper.cpp
        part1/Menu.cpp

)       

set(Headers  
        menu.h
        part1/Student.h
        part1/StudentWrap.h
        part1/Keeper.h
        part1/Menu.h
)

add_executable(lab2 ${SOURCES})

target_sources(lab2 PRIVATE ${Headers})