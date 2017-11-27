#ifndef TEST_H
#define TEST_H

class TEST
{
public:
  TEST(const char *name);

  void print();

protected:
  char mName[1028];
  
};

#endif // TEST_H
