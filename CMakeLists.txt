cmake_minimum_required(VERSION 3.22)

# 项目信息
project(CTP2MiniFuture)

# 设置C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(${PROJECT_SOURCE_DIR}/api/include)

# 设置库文件目录
link_directories(${PROJECT_SOURCE_DIR}/api/so)

# 源文件列表
set(SOURCES
    src/main.cpp
    src/MarketData.cpp
)

# 可执行文件
add_executable(CTP2MiniFuture ${SOURCES})

# 链接库
target_link_libraries(CTP2MiniFuture thostmduserapi thosttraderapi)

# 复制库文件到构建目录
file(COPY ${PROJECT_SOURCE_DIR}/api/so/libthostmduserapi.so DESTINATION ${PROJECT_SOURCE_DIR}/build)
file(COPY ${PROJECT_SOURCE_DIR}/api/so/libthosttraderapi.so DESTINATION ${PROJECT_SOURCE_DIR}/build)
