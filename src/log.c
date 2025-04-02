#include "log.h"

zlog_category_t *c;

[[gnu::constructor(200)]]
void init(void) {
  int rc;

  // 初始化日志系统
  rc = zlog_init("../config/zlog.conf");
  if (rc) {
    printf("zlog初始化失败: %d\n", rc);
    exit(-1);
  }

  // 获取分类（对应配置文件中的 [rules]）
  c = zlog_get_category("my_cat");
  if (!c) {
    printf("获取分类失败\n");
    zlog_fini();
    exit(-2);
  }
}

[[gnu::destructor(210)]]
void release(void) {
  // 清理资源
  zlog_fini();
}
