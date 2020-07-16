cmake_minimum_required(VERSION 3.16)
project(PhoneticSearch)

set(CMAKE_CXX_STANDARD 20)

add_executable(PhoneticFinder.hpp PhoneticFinder.cpp Test.cpp Test1.cpp Test2.cpp Test_ofek.cpp Test_snir.cpp TestRunner.cpp)
#add_executable(PhoneticFinder.hpp PhoneticFinder.cpp Demo.cpp)


