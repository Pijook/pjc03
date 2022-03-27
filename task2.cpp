#include <iostream>
#include <cmath>

const double* aver(const double* arr, size_t size, double& average);

int main(){
    double arr[] = {1, 2, -1.5 , 3.25, 5.5, 7.75, -0.25, 5.75};
    size_t size = std::size(arr);

    double average = 0;
    const double* p = aver(arr, size, average);
    std::cout << *p << " " << average << std::endl;

}

const double* aver(const double* arr, size_t size, double& average){
    for(size_t i = 0; i < size; i++){
        average += arr[i];
    }

    average = average / size;
    const double* element;
    double difference = 0;
    for(size_t i = 0; i < size; i++){
        if(i == 0){
            element = &arr[i];
            difference = std::abs(arr[i] - average);
        }
        else{
            if(std::abs(arr[i] - average) < difference){
                element = &arr[i];
                difference = std::abs(arr[i] - average);
            }
        }
    }

    return element;
}
