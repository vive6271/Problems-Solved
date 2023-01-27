class Fraction{
  private :
  int numerator;
  int denominator;

public:

  Fraction(int numerator, int denominator) {
     this -> numerator = numerator;
     this -> denominator = denominator;
  }

  void print() const{
    cout << this -> numerator << " / " << denominator << endl;
  }

  void simplify() {
    int gcd = 1;
    int j = min(this -> numerator, this -> denominator);
    for(int i = 1;  i <= j; i++){
       if(this -> numerator % i  == 0 && this -> denominator % i == 0){
          gcd = i;
       }
    }
    this -> numerator /= gcd;
    this -> denominator /= gcd;
  }

  Fraction& operator++(){
    numerator += denominator;
    simplify();
    return *this;
  }
};
