#include <iostream>
#include <string>
#include <set>
#include <cmath>

//функция для подсчета количества нулей в конце числа
int countTrailingZeros(const std::string& n) {
    int count = 0;
    for (int i = n.length() - 1; i >= 0; i--) {
        if (n[i] == '0') {
            count++;
        } else {
            break;
        }
    }
    return count;
}

int main() {
    std::set<int> unique_powers;
    
    //перебираем числа до 10^5 для проверки
    for (int i = 2; i < 100000; i++) {
        std::string num = std::to_string(i);
        int k = countTrailingZeros(num);
        unique_powers.insert(k);
    }
    
    
    std::cout << "\nTotal number of unique values: " << unique_powers.size() << std::endl;
    
    return 0;
}
