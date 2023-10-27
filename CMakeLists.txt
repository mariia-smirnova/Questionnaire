cmake_minimum_required(VERSION 3.5)

project(Questionnaire VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


qt_add_executable(Questionnaire
main.cpp
login.h login.cpp login.ui
roomforlist.h roomforlist.cpp roomforlist.ui
constructor.h constructor.cpp constructor.ui
)


target_link_libraries(Questionnaire PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
