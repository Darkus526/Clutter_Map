cmake_minimum_required(VERSION 3.8)
project(Clutter_Map)

set(CMAKE_CXX_STANDARD 17)

# включаем поиск библиотек с использованием find_package()
# через REQUIRED указываем, что библиотеки обязательны
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(Clutter_Map ${SOURCE_FILES})

# указываем, какие библиотеки необходимо подключить
target_link_libraries(${PROJECT_NAME} Qt5::Core)
