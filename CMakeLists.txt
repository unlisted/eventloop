cmake_minimum_required(VERSION 3.2.1 FATAL_ERROR)

project(event_loop)
set (CMAKE_CXX_STANDARD 14)

# update these to suite your needs
list(APPEND CMAKE_MODULE_PATH "~/work/cmake-findgmock")
set(GTEST_ROOT "/opt/external")
set(GMOCK_ROOT "/opt/external")

enable_testing()
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})

#ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
#FIND_PACKAGE(Boost 1.58 COMPONENTS log REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -lboost_log")

add_executable(event scheduler.cpp processor.cpp event.cpp main.cpp)
#TARGET_LINK_LIBRARIES(event ${Boost_LOG_LIBRARY})
#target_link_libraries(event ${GTEST_BOTH_LIBRARIES})

