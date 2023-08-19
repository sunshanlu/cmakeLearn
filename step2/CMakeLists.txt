cmake_minimum_required(VERSION 3.11)
project(step2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 使用add_subdirectory()函数来添加子目录
add_subdirectory(MathFunctions/)

add_executable(${PROJECT_NAME} tutorial.cxx)

# 使用target_link_libraries()函数来添加库文件
target_link_libraries(${PROJECT_NAME} 
    PUBLIC MathFunctions
)

# 使用target_include_directories()函数引入头文件目录
# 其中PROJECT_SOURCE_DIR变量存储的是项目的根目录，即第一个CMakeLists.txt文件所在的目录
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/MathFunctions/
)