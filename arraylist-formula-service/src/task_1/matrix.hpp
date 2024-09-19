/*
 * DO NOT CHANGE CODE UNLESS SPECIFIED (such as TODOs)
 */
#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>
#include <iomanip>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows, cols;

public:
    /*
     * constructors
     */
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<T>(cols, 0));
    }

    Matrix() : rows(0), cols(0) {}

    Matrix(const std::vector<std::vector<T>> &data) {
        if (data.empty() || data[0].empty()) {
            throw std::invalid_argument("Matrix dimensions cannot be zero");
        }
        this->rows = data.size();
        this->cols = data[0].size();
        this->data = data;
    }

    Matrix(const Matrix<T> &other) : data(other.data), rows(other.rows), cols(other.cols) {}

    /*
     * operators
     */

    // element at (i, j)
    T &operator()(size_t i, size_t j) {
        if (i >= rows || j >= cols) {
            throw std::out_of_range("Index out of range");
        }
        return data[i][j];
    }

    // element at (i, j)
    // I Used the following for reference: https://www.geeksforgeeks.org/const-member-functions-c/. The difference between this operator and the one above is this operator's return parameter is const reference and this operator cannot change the data members that are passed in unless they are mutable due to const.
    const T &operator()(size_t i, size_t j) const {
        if (i >= rows || j >= cols) {
            throw std::out_of_range("Index out of range");
        }
        return data[i][j];
    }

    // A==B
    bool operator==(const Matrix<T> &other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions must match for addition");
        }

        T tolerance;
        if constexpr (std::is_same_v<T, float>) {
            tolerance = static_cast<T>(1e-5);
        } else if constexpr (std::is_same_v<T, double>) {
            tolerance = static_cast<T>(1e-9);
        } else {    // assuming int
            tolerance = 0;
        }

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                if (std::abs(data[i][j] - other.data[i][j]) > tolerance) {
                    return false;
                }
            }
        }
        return true;
    }

    // A + B
    Matrix<T> operator+(const Matrix<T> &other_matrix) const {
        if (rows != other_matrix.rows || cols != other_matrix.cols) {
            throw std::invalid_argument("matrix dimensions do not match");
        }

        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] + other_matrix(i, j);
            }
        }
        return result;
    }

    // A * B
    Matrix<T> operator*(const Matrix<T> &other_matrix) const {
        if (cols != other_matrix.rows) {
            throw std::invalid_argument("matrix dimensions do not match");
        }

        Matrix<T> AXB(rows, other_matrix.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other_matrix.cols; ++j) {
                AXB(i,j) = 0;// I originally only had two loops, looked up matrix multiplication and used the following to help write the rest of this: https://stackoverflow.com/questions/56855917/matrix-multiplication-four-loops-vs-three-loops. I also checked with GPT and got a similar answer.
                for(int k = 0; k < cols; ++k) {
                    AXB(i, j) += data[i][k] * other_matrix(k, j);
                }
            }
        }
        return AXB;
    }

    size_t get_rows() const {
        return rows;
    }

    size_t get_cols() const {
        return cols;
    }

    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << std::fixed <<
                                        std::setprecision(4) << data[i][j]
                                        << " ";   // 4 is the number of decimal to print
            }
            std::cout << std::endl;
        }
    }
};
