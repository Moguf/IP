set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_definitions(-Wall -O3)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(../includes/)

add_executable(run.exe main.cpp image.cpp threshold.cpp histgram.cpp histimage.cpp histprint.cpp histsmooth.cpp thresh_mode.cpp threshold_discrim.cpp threshold_dynamic.cpp)

target_link_libraries(run.exe ${OpenCV_LIBS})
