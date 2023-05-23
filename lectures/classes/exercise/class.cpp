#include <iostream>
#include <cassert>
#include <vector>

struct Dexter {
    Dexter() = default;
    Dexter(int age);
    Dexter(int age, int height);
    Dexter(int age, int height, int weight);
    
    int age = 0;
    int height = 0;
    int weight = 0;

    double magnitude() const;

    Dexter& operator+(Dexter const & rhs) {
        age -= rhs.age;
        return *this;
    }
};

Dexter::Dexter(int age) : age(age) {
}

Dexter::Dexter(int age, int height, int weight) : age(age), \
               height(height), weight(weight) {
}

double Dexter::magnitude() const {
    return age * height * weight;
}

class Dexter2 {
    std:: string name;
public:
    void say_hello() const {
        std::cout << "Hello, world! " << name << std::endl;
    }
};

void scaleVector(double scale, std::vector<double> & v) {
    for (auto & element : v) {
        element *= scale;
    }
}

int main() {
    auto small = Dexter{12, 1, 1};
    std::cout << small.magnitude() << std::endl;

    assert(small.age == 12);
    assert(small.height == 1);
    assert(small.weight == 1);

    auto test = Dexter{1};
    // the plus sign is a trap
    test = small + test;
    std::cout << test.age << std::endl;

    assert(test.age == 11);

    // not a static function, which means it can be 
    // called on an instance of the class
    Dexter2 dexter2;
    dexter2.say_hello();

    return 0;
}