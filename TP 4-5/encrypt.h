#include <string>

class encrypt {

public:
  encrypt();
  std::string getplain();
  std::string getcypher();
  virtual void encode() = 0;
  virtual void decode() = 0;
  void read();
  void write();

protected:
  std::string _plain;
  std::string _cipher;

private:
};
