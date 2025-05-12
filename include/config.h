#pragma once
/* C 标准库 */
#include <arpa/inet.h>    // 网络地址转换（如 inet_ntop）
#include <assert.h>       // 断言宏 assert()
#include <ctype.h>        // 字符分类和转换（如 isdigit）
#include <dirent.h>       // 目录操作（如 opendir, readdir）
#include <endian.h>       // 字节序转换宏（如 htobe32）
#include <errno.h>        // 错误码（如 errno）
#include <fcntl.h>        // 文件控制（如 open, O_RDWR）
#include <fenv.h>         // 浮点数环境（如 fegetround）
#include <float.h>        // 浮点数特性宏（如 FLT_MAX）
#include <fnmatch.h>      // 文件名模式匹配（如 fnmatch）
#include <glob.h>         // 路径名模式扩展（如 glob）
#include <iconv.h>        // 字符编码转换
#include <inttypes.h>     // 跨平台整数类型（如 int64_t, PRIu64）
#include <langinfo.h>     // 本地化信息（如 nl_langinfo）
#include <limits.h>       // 整数范围宏（如 INT_MAX）
#include <locale.h>       // 本地化设置（如 setlocale）
#include <math.h>         // 数学函数（如 sqrt, sin）
#include <monetary.h>     // 货币格式（如 strfmon）
#include <net/if.h>       // 网络接口（如 if_nametoindex）
#include <netdb.h>        // 网络数据库操作（如 getaddrinfo）
#include <netinet/in.h>   // IPv4/IPv6 地址族（如 sockaddr_in）
#include <poll.h>         // I/O 多路复用（如 poll）
#include <pthread.h>      // POSIX 线程（如 pthread_create）
#include <sched.h>        // 线程调度（如 sched_yield）
#include <search.h>       // 搜索和排序（如 hcreate, tsearch）
#include <signal.h>       // 信号处理（如 signal, sigaction）
#include <spawn.h>        // 进程生成（如 posix_spawn）
#include <stdalign.h>     // 对齐控制（如 alignas）
#include <stdarg.h>       // 可变参数（如 va_start）
#include <stddef.h>       // 基础类型和宏（如 size_t, NULL）
#include <stdint.h>       // 固定宽度整数类型（如 uint32_t）
#include <stdio.h>        // 标准 I/O（如 printf, fopen）
#include <stdlib.h>       // 通用工具（如 malloc, exit）
#include <string.h>       // 字符串操作（如 strcpy, memcpy）
#include <strings.h>      // 字符串处理扩展（如 strcasecmp）
#include <sys/msg.h>      // System V 消息队列
#include <sys/resource.h> // 资源控制（如 getrlimit）
#include <sys/select.h>   // I/O 多路复用（select）
#include <sys/sem.h>      // System V 信号量
#include <sys/shm.h>      // System V 共享内存
#include <sys/socket.h>   // 套接字接口（如 socket, bind）
#include <sys/stat.h>     // 文件状态（如 stat, S_ISDIR）
#include <sys/time.h>     // 时间操作（如 gettimeofday）
#include <sys/times.h>    // 进程时间（如 times）
#include <sys/types.h>    // 基本系统数据类型（如 pid_t）
#include <sys/uio.h>      // 向量 I/O（如 readv）
#include <sys/un.h>       // UNIX 域套接字（如 sockaddr_un）
#include <sys/utsname.h>  // 系统信息（如 uname）
#include <sys/wait.h>     // 进程控制（如 waitpid）
#include <termios.h>      // 终端 I/O（如 tcgetattr）
#include <time.h>         // 时间处理（如 time, strftime）
#include <uchar.h>        // Unicode 字符类型（如 char16_t）
#include <unistd.h>       // POSIX API（如 fork, getpid）
#include <utime.h>        // 文件时间修改（如 utime）
#include <wchar.h>        // 宽字符处理（如 wprintf）
#include <wctype.h>       // 宽字符分类（如 iswalpha）

/*-------------------------*/
/* 动态内存与低级操作       */
/*-------------------------*/
#include <alloca.h>   // 栈动态内存分配（如 alloca），注意：非标准且可能不安全
#include <byteswap.h> // 字节序转换宏（如 bswap_16/bswap_32/bswap_64），Linux 特有

/*-------------------------*/
/* 系统工具与错误处理       */
/*-------------------------*/
#include <sysexits.h> // 标准化进程退出状态码（如 EX_USAGE, EX_OSERR）

/*-------------------------*/
/* 命令行与文件系统操作     */
/*-------------------------*/
#include <getopt.h>   // 命令行参数解析（如 getopt_long），需定义 _GNU_SOURCE
#include <mntent.h>   // 文件系统挂载信息（如 setmntent/getmntent），Linux 特有
#include <sys/file.h> // 文件锁定（如 flock）

/*-------------------------*/
/* 系统控制与设备 I/O       */
/*-------------------------*/
#include <sys/ioctl.h>  // 设备控制（如终端大小获取 TIOCGWINSZ）
#include <sys/random.h> // 安全随机数（如 getrandom），Linux 3.17+ 特有
