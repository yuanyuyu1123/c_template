include_directories(${CMAKE_SOURCE_DIR}/include)  # 引用主项目的头文件

# 添加测试可执行文件
add_executable(test_hello test_hello.c)

# 链接主项目库和 Check 库
target_link_libraries(test_hello
        PRIVATE
        -lcheck         # Check 库
)

# 注册测试到 CTest
add_test(NAME test_hello COMMAND test_hello)