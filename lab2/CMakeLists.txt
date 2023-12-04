cmake_minimum_required(VERSION 3.26.4)

project(lab2)

set(SOURCES
        main.cpp
        part1/keeper.cpp
        part1/Menu.cpp 
        part1/Student.cpp
        )       

set(Headers  
       part1/Keeper.h
       part1/Menu.h
       part1/MyException.h  
       part1/Student.h
       part1/StudentWrap.h
       part2/part2.h

)

add_executable(lab2 ${SOURCES})

target_sources(lab2 PRIVATE ${Headers})