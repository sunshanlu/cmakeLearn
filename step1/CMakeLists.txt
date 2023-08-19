# 每个项目的最顶层必须首先制定CMake的最低版本
cmake_minimum_required(VERSION 3.11)

# 要启动一个项目需要指定项目的名称，每个项目都需要调用的，紧跟在cmake_minimum_required()后面
project(cmakeLearn VERSION 1.0)

# 添加c++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_DEFINE_FUCK 100)

# 配置xxx.h.in文件，通过@something@进行替换
configure_file(TurtorialConfig.h.in TurtorialConfig.h)


# 最后通过指定可执行文件名称和
add_executable(
    ${PROJECT_NAME}
    tutorial.cxx
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${PROJECT_BINARY_DIR}
)

