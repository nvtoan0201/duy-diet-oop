#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

bool isPrime(int number);
void generateRandom(std::vector<int> &nums);
void analyzeNumbers(const std::vector<int> &nums);

int main(){
    srand(time(0));
    
    int size = rand() % 10 + 10;
    std::cout << "Number of elements: " << size << "\n";
    
    std::vector<int> nums(size);
    generateRandom(nums);
    
    analyzeNumbers(nums);
    
    return 0;
}

bool isPrime(int number){
    if(number < 2) return false;
    for(int i = 2; i * i <= number; i++){
        if(number % i == 0) return false;
    }
    return true;
}

void generateRandom(std::vector<int> &nums){
    for(int i = 0; i < nums.size(); ++i){
        nums[i] = rand() % 100 + 1;
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";
}

void analyzeNumbers(const std::vector<int> &nums) {
    int even = 0;
    std::cout << "Prime numbers: ";
    for (int num : nums) {
        if (num % 2 == 0) even++;

        if (isPrime(num)) std::cout << num << " ";
    }
    std::cout << "\n";
    std::cout << "Number of odd: " << nums.size() - even << "\n";
    std::cout << "Number of even: " << even << "\n";
}