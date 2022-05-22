#include "header.h"
#include <iostream>
#include "C:\C++\eigen-3.4.0\Eigen\Dense"
#include "C:\C++\eigen-3.4.0\Eigen\Geometry"
using namespace Eigen;
DensityChar::DensityChar(char character)
        :character(character), width(7), height(10)
    {

    }
void DensityChar::print() {
    std::cout << character;
}char DensityChar::getChar() {
    return character;
}

AsciH::AsciH() :numberOfCharsInALinPerNumberOfRows(2.1) {

    densityArr[0] = new DensityChar(' ');
    densityArr[1] = new DensityChar(',');
    densityArr[2] = new DensityChar('-');
    densityArr[3] = new DensityChar('+');
    densityArr[4] = new DensityChar('1');
    densityArr[5] = new DensityChar('T');
    densityArr[6] = new DensityChar('D');
    densityArr[7] = new DensityChar('W');
    densityArr[8] = new DensityChar('$');
    densityArr[9] = new DensityChar('@');
    
}
AsciH::~AsciH() {
    for (int i = 0; i < 10; i++) {
        delete densityArr[i];
    }
}
void AsciH::printBlock(int width, int height) {
    for (int i = 0; i < height; i++) {
        std::cout << "\n";
        for (int j = 0; j < width; j++) {
            double f = (double)rand() / RAND_MAX;
            if (f > 0.5) {
                (*densityArr[2]).print();

            }
            else {
                (*densityArr[5]).print();

            }
        }
    }
}void AsciH::printTerminalMatrix(MatrixXd terminalMat) {
    std::string imgString = "";
    for (int i = 0; i < terminalMat.rows(); i++) {
        imgString.append("\n");
        for (int j = 0; j < terminalMat.cols(); j++) {
            
            int densityInt = int(terminalMat(i, j)* densityMax);
            //std::cout << densityInt<<std::endl;
            char newChar=(*densityArr[densityInt]).getChar();
            imgString.append(1,newChar);
        }
    }
    imgString.append("\n");
    std::cout << imgString;
}
void AsciH::printMatrix(MatrixXd img,int columnsTerminal) {
    int heightMat = img.rows();
    int widthMat = img.cols();
    int charactersPerRowTerminal = int(numberOfCharsInALinPerNumberOfRows * columnsTerminal);
    int heightTerminalMat = columnsTerminal;
    int widthTerminalMat = charactersPerRowTerminal;
    MatrixXd terminalMat;
    terminalMat.resize(heightTerminalMat, widthTerminalMat);
    terminalMat = MatrixXd::Zero(heightTerminalMat, widthTerminalMat);
    for (int i = 0; i < heightTerminalMat; i++) {
        for (int j  = 0; j < widthTerminalMat; j++) {
            int iImg = int(double(i) / heightTerminalMat * heightMat); // linear Scaling/resampling -- maybe implement mean filter
            int jImg = int(double(j) / widthTerminalMat * widthMat);
            terminalMat(i, j) = img(iImg, jImg);
        }

    }
    printTerminalMatrix(terminalMat);

}
