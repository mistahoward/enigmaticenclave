cmake_minimum_required(VERSION 3.10)
project(EnigmaticEnclave)

if (APPLE)
    set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.0/lib/cmake/SFML")
elseif (WIN32)
    set(SFML_DIR "C:/cpp/sfml/lib/cmake/SFML")
endif()

find_package(SFML 2.6 COMPONENTS graphics audio window system REQUIRED)

add_executable(EnigmaticEnclave src/main.cpp src/game.cpp)

target_link_libraries(EnigmaticEnclave sfml-graphics sfml-audio sfml-window sfml-system)
