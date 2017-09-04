#include <iostream>
#define ARRAY_SIZE 5

/*alignArray template from slides*/
template < typename T >
void alignArray(T* array, int size, T barrier) {
    for (int i = 0; i < size; i++) {
        if (array[i] < barrier)
            array[i] += 2;
        else if (array[i] > barrier)
            array[i] -= 2;
    }
}

/*My own type*/
class MyType {
    int value;

public:
    MyType(): value (0) {}

    /*Override of '>' operator
     * true if this value more than comparable value*/
    bool operator > (MyType& myType){
        return value > myType.value;
    }

    /*Override of '<' operator
     * true if this value less than comparable value*/
    bool operator < (MyType& myType){
        return value < myType.value;
    }

    /*Override of '+=' operator*/
    int operator += (const int& a){
        return value += a;
    }

    /*Override of '-=' operator*/
    int operator -= (const int& a){
        return value -= a;
    }

    /*Value setter*/
    void setValue(int value){
        this->value = value;
    }

    /*Printing value*/
    void printValue(){
        std::cout << value;
    }
};


int main() {
    /*Some random array*/
    int array[] = {1, 2, 3, 4, 5};

    std::cout << "Integer array: " << std::endl;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    alignArray(array, ARRAY_SIZE, 2);

    /*Printing array' values*/
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;


    /*My type array part*/
    std::cout << "My Type array: " << std::endl;

    /*Implementing new array MyType*/
    MyType* mtarray = new MyType[ARRAY_SIZE];

    /*Setting some values to that array*/
    for (int i = 0; i < ARRAY_SIZE; i++){
        mtarray[i].setValue(i);
        mtarray[i].printValue();
        std::cout << " ";
    }
    std::cout << std::endl;

    /*Some value for barrier*/
    MyType barrier;
    barrier.setValue(2);

    alignArray(mtarray, ARRAY_SIZE, barrier);

    /*Printing new array*/
    for (int i = 0; i < ARRAY_SIZE; i++) {
        mtarray[i].printValue();
        std::cout << " ";
    }

    std::cout << std::endl;

    return 0;
}