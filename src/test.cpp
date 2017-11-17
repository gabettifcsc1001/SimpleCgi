#include <stdio.h>
#include <string.h>
#include "test.h"

TEST::TEST(const char *name) {
  strcpy(mName, name);
}

void TEST::print() {
  printf("%s \n", mName);
}
