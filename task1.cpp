#include <iostream>

void minMaxRep(const int a[], size_t size, int& mn, size_t& in, int& mx, size_t& ix);


int main() {
    int a[]{2,3,4,2,7,4,7,2};
    size_t size = std::size(a);

    int mn, mx;
    size_t in,ix;
    minMaxRep(a, size, mn, in, mx, ix);

    std::cout << "Array: [ ";
    for(size_t i = 0; i < size; ++i){
        std::cout << a[i] << " ";
    }
    std::cout << "]\n";
    std::cout << "Min = " << mn << " " << in << " times\n";
    std::cout << "Max = " << mx << " " << ix << " times\n";
}

void minMaxRep(const int a[], size_t size, int& mn, size_t& in, int& mx, size_t& ix){
    int tempMin = 0;
    int tempMax = 0;

    int maxAmount = 0;
    int minAmount = 0;

    //Finding min and max
    for(int i = 0; i < size; i++){
        if(i == 0){
            tempMin = a[i];
            tempMax = a[i];
        }
        else{
            if(a[i] < tempMin){
                tempMin = a[i];
            }
            else if(a[i] > tempMax){
                tempMax = a[i];
            }
        }
    }

    //Counting min and max
    for(int i = 0; i < size; i++){
        if(a[i] == tempMin){
            minAmount++;
        }
        else if(a[i] == tempMax){
            maxAmount++;
        }
    }

    mn = tempMin;
    in = minAmount;
    mx = tempMax;
    ix = maxAmount;
}


