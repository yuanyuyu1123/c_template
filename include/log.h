#pragma once

#include <stdlib.h>
#include <zlog.h>

extern zlog_category_t *c;

void init(void);

void release(void);
