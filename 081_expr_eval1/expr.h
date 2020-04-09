#include <sstream>
class Expression{
 public:
  virtual std::string toString() const=0;
  virtual ~Expression(){};
};

class NumExpression : public Expression{
 private:
  long num;
 public:
 NumExpression(long w):num(w){}
  virtual std::string toString() const{
    std::string temp;
    std::stringstream ss;
    ss<<num;
    temp=ss.str();
    return temp;
  }
  virtual ~NumExpression(){};
};

class PlusExpression :public Expression{
 private:
  std::string exp1;
  std::string exp2;
 public:
 PlusExpression(Expression *lhs, Expression *rhs):exp1(lhs->toString()),exp2(rhs->toString()){
    delete lhs;
    delete rhs;
  }
  virtual std::string toString() const{
    std::string temp;
    std::stringstream ss;
    ss<<'('<<exp1<<'+'<<exp2<<')';
    temp=ss.str();
    return temp;
  }
  virtual ~PlusExpression(){};
  
};
