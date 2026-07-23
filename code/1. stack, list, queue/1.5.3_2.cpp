#include <iostream>
#include <string>
#include <forward_list>
#include <algorithm>

struct Student{
    std::string name;
    int score;
};

std::ostream &operator<<(std::ostream& os, const Student &s) {
    return (os << "[" << s.name << "," << s.score << "]");
}

int main() {
    std::forward_list<Student> students = {
        {"Kim", 95}, {"Lee", 72}, {"Park", 58}, {"Choi", 81}, {"Jung", 66}
    };

    std::cout << "전체 학생:\n";
    for (const auto& person : students) {
        std::cout << person << " ";
    }
    std::cout << "\n";

    auto passed = students;

    passed.remove_if([](const Student &s){return (s.score < 60);});

    std::cout << "합격한 학생:\n";
    for (const auto& person : passed) {
        std::cout << person << " ";
    }
    std::cout << "\n";

    auto excellent = students;

    excellent.remove_if([](const Student &s){return (s.score < 90);});

    std::cout << "우수 학생:\n";
    for (const auto& person : excellent) {
        std::cout << person << " ";
    }
    std::cout <<"\n";

    std::cout << "원본:\n";
    for (const auto& person : students) {
        std::cout << person << " ";
    }
    std::cout << "\n";

    auto it = std::find_if(students.begin(), students.end(), [](const Student &s) {return (s.score >= 80);});
    if (it != students.end()) {
        std::cout << "우수 학생 발견: " << *it << "\n";
    }

    auto that = std::find_if(students.begin(), students.end(), [](const Student &s) {return (s.name == "Park");});
    if (that != students.end()) {
        that->score = 100;
    }
    
    std::cout << "Park 학생의 점수를 100점으로 수정\n";
    for (const auto& person : students) {
        std::cout << person << " ";
    }
    std::cout << "\n";
   
}
