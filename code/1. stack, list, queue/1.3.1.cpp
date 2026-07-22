    //학교에서 학생 정보를 관리하는 프로그램
    //한 반의 학생 수와 학생 정보는 프로그램 실행 시 입력으로 받는다
    //학생 데이터를 관리하기 위해 배열과 유사한 자료구조를 사용하고 이 배열은 다양한 크기를 지원해야 한다.
    //여러 반을 하나로 합치는 기능도 지원해야 한다.


    #include <iostream>
    #include <algorithm>
    #include <sstream>



    template <typename T>
    class Classroom{
        private:
            T* data;
            std::size_t number;

        public:
            Classroom() : data(nullptr), number(0) {}
            ~Classroom() {
                delete[] data;
                data = nullptr;
                number = 0;
            }
            Classroom(int num) {
                this->number = num;
                data = new T[number];
            }
            Classroom(const Classroom<T>& other) {
                number = other.number;
                data = new T[number];
                for (std::size_t i = 0; i < number; i++) {
                    data[i] = other.data[i];
                }
            
            }
            Classroom& operator=(const Classroom<T>& other) {
                if (this != &other) {
                    delete[] data;
                    number = other.number;

                    data = new T[number];

                    for (std::size_t i = 0; i< number; i++) {
                        data[i] = other.data[i];
                    }


                }
                return *this;
            }

            T& operator[](int index) {
                return data[index];
            }
            const T& operator[](int index) const{
                return data[index];
            }
            
            T& at(int index) {
                if (index >= 0 && index < number) {
                    return data[index];
                }

                throw std::out_of_range("OUT_OF_RANGE\n");
            }

            std::size_t size() const noexcept {
                return number;
            }

            T* begin() {
                return data;
            }
            const T* begin() const{
                return data;
            }

            T* end() {
                return data + number;
            }

            const T* end() const {
                return data + number;
            }


            friend Classroom<T> operator+(const Classroom<T>&other1, const Classroom<T>&other2) {
                Classroom<T> result(other1.size() + other2.size());
                std::copy(other1.begin(), other1.end(), result.begin());
                std::copy(other2.begin(), other2.end(), result.begin() + other1.size());

                return result;
            }
            
            std::string print_class(const std::string& sep = ", ") {
                if (number == 0) {
                    return "";
                }
                std::ostringstream os;
                os<<data[0];
                for (std::size_t i = 1; i < number; i++) {
                    os << sep << data[i]; //data[i]의 타입이 Student라서 Student의 << 연산자를 받는다
                }

                return os.str();
            }
            

            
    };

    struct Student{
        std::string name;
        int standard;
        Student() = default;
        Student(std::string n, int s) : name(n), standard(s) {} 
    };

    std::ostream& operator<<(std::ostream& os, const Student& s) {
        return (os << "[" << s.name << ", " << s.standard << "]");
    }


    int main() {

        int n;
        std::cout << "1반 학생 수 입력 : ";
        std::cin >> n;
        
        Classroom<Student> class1(n);

        for (std::size_t i = 0; i < n; i++) {
            std::string name;
            int standard;
            std::cout << i+1 << "번째 학생 이름과 나이 : ";
            std::cin >> name >> standard;
            class1[i] = Student(name, standard);
        }

        try {
            class1.at(n) = Student("John", 18); //예외 발생
        }
        catch (...){
            std::cout << "예외 발생\n"; 
        }

        auto class2 = class1;
        std::cout << "1반을 복사하여 2반 생성 : " << class2.print_class() << "\n";
        
        auto class3 = class1 + class2;
        std::cout << "1반과 2반을 합쳐서 3반 생성 : " << class3.print_class() << "\n";
    }

