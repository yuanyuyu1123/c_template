#include "log.h"
#include <lwrb.h>
#include <pthread.h>
#include <unistd.h>

// 定义环形缓冲区
#define BUFFER_SIZE 128
static uint8_t buffer_mem[BUFFER_SIZE];
static lwrb_t rb;
static pthread_mutex_t rb_mutex = PTHREAD_MUTEX_INITIALIZER;

// 生产者线程：模拟数据写入
[[noreturn]]
void *producer_thread(void *arg) {
  (void)arg;
  const char *data = "Hello, ring in Linux!\n";
  size_t len = strlen(data);

  while (1) {
    pthread_mutex_lock(&rb_mutex); // 加锁
    size_t written = lwrb_write(&rb, (uint8_t *)data, len);
    pthread_mutex_unlock(&rb_mutex);

    if (written != len) {
      zlog_error(c, "Buffer full, failed to write all data\n");
    }

    usleep(100000); // 100ms 生产一次
  }
}

// 消费者线程：读取并打印数据
[[noreturn]]
void *consumer_thread(void *arg) {
  (void)arg;
  uint8_t read_buf[64];

  while (1) {
    pthread_mutex_lock(&rb_mutex); // 加锁
    size_t read_len = lwrb_read(&rb, read_buf, sizeof(read_buf));
    pthread_mutex_unlock(&rb_mutex);

    if (read_len > 0) {
      zlog_debug(c, "Received: %.*s", (int)read_len, read_buf);
    }

    usleep(50000); // 50ms 消费一次
  }
}

int main() {

  // 初始化环形缓冲区
  lwrb_init(&rb, buffer_mem, BUFFER_SIZE);

  // 创建生产者和消费者线程
  pthread_t producer, consumer;
  pthread_create(&producer, nullptr, producer_thread, nullptr);
  pthread_create(&consumer, nullptr, consumer_thread, nullptr);

  // 主线程等待（按 Ctrl+C 退出）
  pthread_join(producer, nullptr);
  pthread_join(consumer, nullptr);

  return 0;
}