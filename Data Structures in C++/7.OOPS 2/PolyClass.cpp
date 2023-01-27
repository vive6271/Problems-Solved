class Polynomial{
    public:

    int *degCoeff;
    int capacity;

    Polynomial(){
        degCoeff = new int[10];
        capacity = 10;
        for(int i = 0; i < capacity; i++){
            degCoeff[i] = 0;
        }
    }

    Polynomial(Polynomial const &p){
        degCoeff = new int[p.capacity];
        capacity = p.capacity;
        for(int i = 0; i < capacity; i++){
            degCoeff[i] = p.degCoeff[i];
        }
    }

    void operator=(Polynomial const &p){
        delete [] degCoeff;
        degCoeff = new int[p.capacity];
        capacity = p.capacity;
        for(int i = 0; i < capacity; i++){
            degCoeff[i] = p.degCoeff[i];
        }
    }

    Polynomial operator+(Polynomial const &p){
        Polynomial pNew;
        int i = 0, j = 0;
        while(i < capacity && j < p.capacity){
            int deg = i;
            int coef = degCoeff[i] + p.degCoeff[j];
            pNew.setCoefficient(deg, coef);
            i++;
            j++;
        }
        while(i < capacity){
            pNew.setCoefficient(i, degCoeff[i]);
            i++;
        }
        while(j < p.capacity){
            pNew.setCoefficient(j, p.degCoeff[j]);
            j++;
        }
        return pNew;
    }

    Polynomial operator-(Polynomial const &p){
        Polynomial pNew;
        int i = 0, j = 0;
        while(i < capacity && j < p.capacity){
            int deg = i;
            int coef = degCoeff[i] - p.degCoeff[j];
            pNew.setCoefficient(deg, coef);
            i++;
            j++;
        }
        while(i < capacity){
            pNew.setCoefficient(i, degCoeff[i]);
            i++;
        }
        while(j < p.capacity){
            pNew.setCoefficient(j, (0 - p.degCoeff[j]));
            j++;
        }
        return pNew;

    }

    Polynomial operator*(Polynomial const &p){
        Polynomial pNew;
        for(int i = 0; i < capacity; i++){
            for(int j = 0; j < p.capacity; j++){
                int deg = (i+j);
                int coef = pNew.getCoefficient(deg) + (degCoeff[i] * p.degCoeff[j]);
                pNew.setCoefficient(deg, coef);
            }
        }
        return pNew;
    }

    void setCoefficient(int de, int co){
        if(de >= capacity){
            int size = 2 * capacity;
            while(size <= de){
                size *= 2;
            }
            int *newDegCoeff = new int[size];
            for(int i = 0; i < size; i++){
                if(i < capacity){
                    newDegCoeff[i] = degCoeff[i]; 
                }else{
                    newDegCoeff[i] = 0;
                }
            }
            delete [] degCoeff;
            degCoeff = newDegCoeff;
            capacity = size;
        }
        degCoeff[de] = co;
    }

    int getCoefficient(int deg){
        if(deg < capacity){
            return degCoeff[deg];
        }
        return 0;
    }

    void print(){
        for(int i = 0; i < capacity; i++){
            if(degCoeff[i] != 0){
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
};