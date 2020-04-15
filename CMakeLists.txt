# cmake version to be used
cmake_minimum_required (VERSION 2.6)

# project name
project (rasp-onotes-lib)


# files

# include
include_directories( ./include ./src  )

# target
add_executable( binary ./src/main.cpp)


