# Tell the cmake file the minimum version required
cmake_minimum_required(VERSION 3.16.3)

# usefull This variable
# if you wanna change the name of your code
# you ony have to change it here
set(This NQueens)

# Tell cmake what languages you are using
project(${This} C CXX)

# Tell cmake what versions of the langauges are
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Tell cmake that you are gonna have unit tests
enable_testing()

# Pull in all of the dependencie for tests
# Right now we only have one
add_subdirectory(googletest)

# Add the headers and source files to test
set(Headers
    NQueens.hpp
)
set(Sources
    NQueens.cpp
)

# Libraray means that it will be 
# linked with other things to run programs
add_library(${This} STATIC ${Sources} ${Headers})

# Put our tests in a subdirectory called test
# This is to keep it seperate from our code
add_subdirectory(test)