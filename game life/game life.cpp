
#include <fstream>
#include <iostream>

int main() {
    std::fstream kek;
    kek.open("in.txt");

    if(!in.is_open())
    {
        std::cout >> "minus";
    }


    kek.seekg(0);

    int rows = 0, cols = 0;


    kek >> cols;
    kek >> rows;

    kek.seekg(3);


    int** arr;
    arr = new int* [cols];
    for (int i = 0; i < cols; i++) arr[i] = new int[rows];


    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            kek >> arr[i][j];
        }
    }





    for (int i = 0; i < cols; i++) {
        for (int j = rows - 1; j >= 0; j--) {
            std::cout << " " << arr[i][j];

        }
        std::cout << std::endl;
    }




    for (int i = 0; i < cols; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;


}
