cmake_minimum_required(VERSION 3.10)
project(EnigmaticEnclave)

set(SFML_INCLUDE_DIR "/opt/homebrew/Cellar/sfml/2.6.0/include")
set(SFML_LIBRARY_DIR "/opt/homebrew/Cellar/sfml/2.6.0/lib")
set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.0/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)

include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.6 COMPONENTS graphics audio window system REQUIRED)

add_executable(EnigmaticEnclave src/main.cpp src/game.cpp src/terminal.cpp)

target_link_libraries(EnigmaticEnclave sfml-graphics sfml-audio sfml-window sfml-system)
