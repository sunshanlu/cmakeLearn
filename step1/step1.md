# step1：简单的开始

## 一、建立一个基础的项目
```cmake
cmake_minimum_required(VERSION 3.11)
project(cmakeLearn)
add_executable(${PROJECT_NAME} turtorial.cxx)
```
- `cmake_minimum_required()`用来指定cmake程序的版本，值得注意的是不可直接写版本号，前面有关键字`VERSION`
- `project()`用来指定项目名称，括号内可以直接写项目名，这段代码应该紧跟着`cmake_minimum_required()`，用来声明与项目相关的内容，执行完该代码后，变量`PROJECT_NAME`被创建
- `add_executable()`用来指定某一个可执行程序所对应的源文件是哪几个，该函数的第一个参数为可执行程序的名称，其余紧跟着为可执行程序对应的源文件路径

## 二、指定C++标准
```cmake
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
```
- `CMAKE_CXX_STANDARD` 是cmake程序中内置的变量，可以通过设置该变量对C++的标准进行声明
- `CMAKE_CXX_STANDARD_REQUIRED`的作用是当cmake的使用者没有对`CMAKE_CXX_STANDARD`进行声明的话，cmake程序报错
- `CMAKE_CXX_STANDARD`不仅可以使用`True`，还可以使用`ON`

## 三、添加版本信息
```cmake
#cmake file
cmake_minimum_required(VERSION 3.11)
project(cmakeLearn VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
configure_file(Version.h.in Version.h)

add_executable(${PROJECT_NAME} turtorial.cxx)
target_include_directories(${PROJECT_NAME} 
    PUBLIC ${PROJECT_BINARY_DIR})
```


```c++
// Version.h.in
#define VERSION_MAJOR @cmakeLearn_VERSION_MAJOR@
#define VERSION_MINOR @cmakeLearn_VERSION_MINOR@
```

```C++
// ${CMAKE_BINARY_DIR}/Version.h
#define VERSION_MAJOR 1
#define VERSION_MINOR 0
```

- `project()`函数不仅仅可以对项目名称进行定义，还可以定义项目的版本号，该函数运行完成后，cmake 的部分变量被创建
  - `PROJECT_NAME`：项目名称
  - `${PROJECT_NAME}_VERSION_MAJOR`：项目的大版本号
  - `${PROJECT_NAME}_VERSION_MINOR`：项目的小版本号
- `configure_file()`函数会将某一个配置文件和头文件联系起来
  - 配置文件中，定义的宏应该是CMakeLists.txt文件中存在的变量名，其中宏定义处被替换成为`@CMAKE_VARIABLE@`
  - 除此之外，值得注意的是Version.h.in 是人为创建的文件，而Version.h 是cmake程序创建的文件，它将cmake中定义的变量与程序联系了起来
  - 因此当项目进行版本迭代维护的时候，只需要修改cmake文件中的版本号即可
- `target_include_directories()`函数声明target包含的头文件，target由`add_executable()`或`add_library()`函数产生。
  - 接受参数一：target
  - 接受参数二：权限关键字 引入文件的目录
  - 由于接受的参数是target，因此，其在target产生后调用