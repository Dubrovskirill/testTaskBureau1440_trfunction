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

// Функция для генерации следующего числа
std::string nextNumber(const std::string& current) {
    std::string result = current;
    int i = result.length() - 1;
    
    while (i >= 0) {
        if (result[i] < '9') {
            result[i]++;
            return result;
        }
        result[i] = '0';
        i--;
    }
    
    return "1" + std::string(result.length(), '0');
}

int main() {
    std::set<int> unique_powers;
    std::string current = "2";  
    
    // Перебираем числа до 10^30
    while (current.length() <= 30) {
        int k = countTrailingZeros(current);
        unique_powers.insert(k);
        current = nextNumber(current);
    }
    
    std::cout << "Total number of unique values: " << unique_powers.size() << std::endl;
    
    return 0;
}
