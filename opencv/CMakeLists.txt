cmake_minimum_required(VERSION 3.10)
project(YourOpenCVProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 可选：在Windows上设置运行时库为MD（多线程DLL）
if(WIN32)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

# 1. 查找OpenCV包，指定您编译的安装路径
find_package(OpenCV REQUIRED PATHS "D:/opencv/build/x64/cctest/install" NO_DEFAULT_PATH)

# 检查是否找到
if(OpenCV_FOUND)
    message(STATUS "OpenCV library status:")
    message(STATUS "    version: ${OpenCV_VERSION}")
    message(STATUS "    libraries: ${OpenCV_LIBS}")
    message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
else()
    message(FATAL_ERROR "OpenCV not found. Please check the path.")
endif()

# 2. 添加可执行文件
add_executable(${PROJECT_NAME} main.cpp)

# 3. 包含OpenCV头文件目录
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})

# 4. 链接OpenCV库
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})

# 5. 在Windows上，确保运行时能找到DLL
if(WIN32)
    # 将OpenCV的bin目录添加到运行时路径
    get_filename_component(OpenCV_BIN_DIR "${OpenCV_DIR}/../bin" ABSOLUTE)
    # 将DLL复制到可执行文件目录
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${OpenCV_BIN_DIR}/opencv_world4120.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()