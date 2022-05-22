#pragma once
#include "C:\C++\eigen-3.4.0\Eigen\Dense"
#include "C:\C++\eigen-3.4.0\Eigen\Geometry"
class DensityChar {
public:
    DensityChar()=delete;
    DensityChar(char character);
    
    void print();
    char getChar();
private:
    const char character;
    const double width;
    const double height;
};


class AsciH {
public:
    AsciH();
    ~AsciH();
    void printBlock(int width, int height);
    void printMatrix(Eigen::MatrixXd matrix, int columnsTerminal=20);
    
private:
    const double densityMax = 9.99;
    DensityChar* densityArr[10];
    double numberOfCharsInALinPerNumberOfRows;
    void printTerminalMatrix(Eigen::MatrixXd matrix);
};
