class Polynomial{
public:
  int *degCoeff;
  int capacity;

  Polynomial(){
    this -> degCoeff = new int[10];
    for(int i = 0; i < 10; i++){
      this -> degCoeff[i] = 0;
    }
    this -> capacity = 10;
  }

  Polynomial(Polynomial const &p){
    this -> degCoeff = new int[p.capacity];
    for(int i = 0; i < p.capacity; i++){
      this -> degCoeff[i] = p.degCoeff[i];
    }
    this -> capacity = p.capacity;
  }

  void operator=(Polynomial const &p){
    delete [] degCoeff;
    this -> degCoeff = new int[p.capacity];
    for(int i = 0; i < p.capacity; i++){
      this -> degCoeff[i] = p.degCoeff[i];
    }
    this -> capacity = p.capacity;
  }

  Polynomial operator+(Polynomial const &p){
    Polynomial pNew;
    int i = 0, j = 0;
    while(i < this -> capacity && j < p.capacity){
      int deg = i;
      int coff = this -> degCoeff[i] + p.degCoeff[j];
      pNew.setCoefficient(deg,coff);
      i++;
      j++;
    }
    while(i < this -> capacity){
      pNew.setCoefficient(i,this-> degCoeff[i]);
      i++;
    }
    while(j < p.capacity){
      pNew.setCoefficient(j,p.degCoeff[j]);
      j++;
    }
    return pNew;
  }

  Polynomial operator-(Polynomial const &p){
    Polynomial pNew;
    int i = 0, j = 0;
    while(i < this -> capacity && j < p.capacity){
      int deg = i;
      int coff = this -> degCoeff[i] - p.degCoeff[j];
      pNew.setCoefficient(deg,coff);
      i++;
      j++;
    }
    while(i < this -> capacity){
      pNew.setCoefficient(i,this-> degCoeff[i]);
      i++;
    }
    while(j < p.capacity){
      pNew.setCoefficient(j, -1*p.degCoeff[j]);
      j++;
    }
    return pNew;
  }

  Polynomial operator*(Polynomial const &p){
    Polynomial pNew;
    for(int i = 0; i < this -> capacity; i++){
      for(int j = 0; j < p.capacity; j++){
        int deg = i+j;
        int coff = pNew.getCoefficient(deg) + (this -> degCoeff[i] * p.degCoeff[j]);
        pNew.setCoefficient(deg,coff);
      }
    }
    return pNew;
  }

  int getCoefficient(int degree){
    if(degree >= capacity){
      return 0;
    }
    return degCoeff[degree];
  }

  void setCoefficient(int deg, int coff){
    if(deg >= this -> capacity){
      int size = 2 * this -> capacity;
      while(size <= deg){
        size *= 2;
      }
      int *newData = new int[size];
      for(int i = 0; i < size; i++){
        newData[i] = 0;
      }
      for(int i = 0; i < this -> capacity; i++){
        newData[i] = this -> degCoeff[i];
      }
      delete [] degCoeff;
      this -> degCoeff = newData;
      this -> capacity = size;
    }
    this -> degCoeff[deg] = coff;
  }


  void print(){
    for(int i = 0; i < this -> capacity; i++){
      if(this -> degCoeff[i] != 0){
        cout << this -> degCoeff[i] << "x" << i << " ";
      }
    }
    cout << endl;
  }
};
