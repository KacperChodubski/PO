cmake_minimum_required(VERSION 3.21)
project(Projekt1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projekt1 main.cpp World.cpp World.h Organism.cpp Organism.h Animal.cpp Animal.h Plant.cpp Plant.h OrganismList.cpp OrganismList.h Wolf.cpp Wolf.h)
