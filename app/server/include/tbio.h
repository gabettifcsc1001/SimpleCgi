#ifndef TBIO_H
#define TBIO_H

class TBTESTIO
{
public:
  TBTESTIO(const int id, const char buf);
  void Set();
  void SetField();
  void GetField();

protected:
  const int m_id;
  const char m_buf;
  const char table = "tb_test";
};

#endif // TBIO_H
