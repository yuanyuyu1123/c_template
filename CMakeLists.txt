cmake_minimum_required(VERSION 3.30.5)

project(myRing C)

set(CMAKE_C_STANDARD 23)          # C23 标准
set(CMAKE_C_STANDARD_REQUIRED ON) # 必须支持
set(CMAKE_C_EXTENSIONS ON)        # 启用 GNU 扩展

include_directories(include)
add_compile_options(-g -Wall -Wextra -O0)

# 启用测试支持
enable_testing()

# 包含测试目录
add_subdirectory(tests)

add_executable(ring
        src/main.c
        src/log.c
        src/lwrb/lwrb.c)

find_library(ZLOG_LIB zlog HINTS /usr/local/lib)
target_link_libraries(ring PRIVATE ${ZLOG_LIB})