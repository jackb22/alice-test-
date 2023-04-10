cmake_minimum_required(VERSION 3.24)
project(Alice_And_Wonderland)

set(CMAKE_CXX_STANDARD 17)

add_executable(Alice_And_Wonderland main.cpp Locations.h Locations.cpp Items.cpp Items.h Character.cpp Character.h Actions.cpp Actions.h Inventory.cpp Inventory.h Control.cpp Control.h)
