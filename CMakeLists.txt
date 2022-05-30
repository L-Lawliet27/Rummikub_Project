cmake_minimum_required(VERSION 3.21)
project(Rummikub_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rummikub_Project main.cpp Sources/Colors.cpp Headers/Colors.h Sources/Tiles.cpp Headers/Tiles.h Sources/Bag.cpp Headers/Bag.h Sources/Rack.cpp Headers/Rack.h Sources/Racks.cpp Headers/Racks.h Sources/Sets.cpp Headers/Sets.h Sources/Board.cpp Headers/Board.h)
