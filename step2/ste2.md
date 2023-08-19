# step2 添加一个库

## 一、添加一个库
```cmake
# MathFunctions/CMakeLists.txt
add_library(MathFunctions MathFunctions.cxx mySqrt.cxx)
```

```cmake
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
```
- `add_subdirectory()`函数用来声明一个项目的子文件夹，即项目子文件夹里面还存在一个CMakeLists.txt文件，函数接受的参数为一个文件目录
- `target_link_libraries()`函数用来引入库文件，在本实例中，target引入的是子文件夹中生成的库文件
- `PROJECT_SOURCE_DIR`变量是存储项目根目录地址的地方。
- `add_library()`函数用来创建一个库文件，其接受参数如下
  - 库文件的名称
  - 库文件所对应的源文件列表


## 二、为库文件生成添加选项
