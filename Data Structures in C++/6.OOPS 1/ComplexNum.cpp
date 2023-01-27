class ComplexNumbers {
  private :
  int real;
  int imaginary;

  public :

  ComplexNumbers(int real, int imaginary){
    this -> real = real;
    this -> imaginary = imaginary;
  }
  void print(){
    cout << real << " + i" << imaginary << endl;
  }
  void plus(ComplexNumbers const c2){
    real += c2.real;
    imaginary += c2.imaginary;
  }

  void multiply(ComplexNumbers const c2){
    int real1 = 0 - (c2.imaginary * imaginary);
    int real2 = c2.real * real;
    int imaginary1 = c2.imaginary * real;
    int imaginary2 = c2.real * imaginary;

    real = real1 + real2;
    imaginary = imaginary1 + imaginary2;
  }
};
