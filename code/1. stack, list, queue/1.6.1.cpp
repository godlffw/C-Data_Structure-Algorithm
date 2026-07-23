#include <iostream>
#include <forward_list>
#include <vector>

int main() {
    std::vector<std::string> vec = {
        "Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg", "Sebastian Vettel", "Lewis Hamilton", 
        "Sebastian Vettel", "Sebastian Vettel", "Sebastian Vettel", "Fernado Alonso"
    };

    auto it = vec.begin();
    std::cout << "가장 최근 우승자: " << *it << "\n";

    it += 8;
    std::cout << "8년 전 우승자: " << *it << "\n";

    advance(it, -3);
    std::cout << "그후 3년 뒤 우승자: " <<*it << "\n";

    std::forward_list<std::string> fwd(vec.begin(), vec.end());

    auto it1 = vec.begin();
    std::cout << "가장 최근 우승자: " << *it1 << "\n";

    it1 += 8;
    std::cout << "8년 전 우승자: " << *it1 << "\n";

    // advance(it1, -3);
    // std::cout << "그후 3년 뒤 우승자: " <<*it1 << "\n";
    //에러 발생
    //std::forward_list는 순방향으로만 이동가능하므로 에러가 발생한다.

    
}
