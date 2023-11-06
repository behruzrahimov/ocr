cmake_minimum_required(VERSION 3.26)
project(ocr)

set(CMAKE_CXX_STANDARD 17)


find_package(Tesseract CONFIG REQUIRED)
include_directories(${Tesseract_INCLUDE_DIRS})
add_executable(ocr main.cpp)
target_link_libraries(ocr PRIVATE Tesseract::libtesseract)
