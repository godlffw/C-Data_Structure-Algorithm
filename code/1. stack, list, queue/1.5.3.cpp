#include <iostream>
#include <forward_list>
#include <string>


struct citizen{
    std::string name;
    int age;
};


std::ostream &operator<<(std::ostream &os, const citizen& c) {
    return (os << "[" << c.name << "," << c.age <<"]");
}

int main() {
    std::forward_list<citizen> citizens ={
        {"Kim", 22}, {"Lee", 25} , {"Park", 18}, {"Jin", 16}
    };
    auto citizens_copy = citizens;
    std::cout << "전체 시민들: ";
    for (const auto &kv : citizens) {
        std::cout << kv << " ";
    }
    std::cout <<"\n";
    
    citizens.remove_if([](const citizen& c){return (c.age < 19);});

    std::cout << "투표권이 있는 시민들: " ;
    for (const auto& kv: citizens) {
        std::cout << kv << " ";
    }
    std::cout << "\n";

    
    citizens_copy.remove_if([](const citizen &c){return (c.age != 18);});
    std::cout << "내년에 투표권이 생기는 시민들: ";
    for (const auto& kv : citizens_copy) {
        std::cout << kv << " ";
    }
    std::cout << "\n";
    
    return 0;
    
}
