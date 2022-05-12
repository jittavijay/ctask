cmake_minimum_required (VERSION 2.8.11)
project (ctask  LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "-fexceptions -g -O2 -pthread -Wall -pedantic ")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(ctask )
target_sources(
  ctask
  PRIVATE
  Ctask.cpp Player.cpp Initiator.cpp Channel.cpp UDPChannel.cpp
  )

