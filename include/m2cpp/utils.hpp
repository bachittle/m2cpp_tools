#ifndef M2CPP_H
#define M2CPP_H

#include <Eigen/Dense>
#include <Eigen/Core>
#include <fstream>

namespace m2cpp {


template <typename T, typename U>
inline auto load_binary(const char * filename) -> T {
    std::ifstream file(filename, std::ios::binary | std::ios::in); 
    
    if (!file.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return T();
    }

    int rows, cols;
    file.read(reinterpret_cast<char*>(&rows), sizeof(int));
    file.read(reinterpret_cast<char*>(&cols), sizeof(int));
    
    
    T result(rows, cols);
    file.read(reinterpret_cast<char*>(result.data()), rows * cols * sizeof(U));

    return result;
}

template <typename T>
inline auto load_text_vec(const char * filename) {
    std::ifstream file(filename, std::ios::in);
    if (!file.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return T();
    }

    int size;
    file >> size;
    T result(size);
    for (int i = 0; i < size; ++i) {
        file >> result(i);
    }
    return result;
}

template <typename T>
inline auto load_text_mat(const char * filename) {
    std::ifstream file(filename, std::ios::in);
    if (!file.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return T();
    }

    int rows, cols;
    file >> rows >> cols;

    T result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0 ; j < cols; ++j) {
            file >> result(i,j);
        }
    }
    return result;
}

template <typename T>
inline void save_text(const char * filename, Eigen::MatrixBase<T>& matrix) {
    auto rows = matrix.rows();
    auto cols = matrix.cols();
    
    std::ofstream file(filename, std::ios::out);
    if (!file.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return;
    }
    
    file << rows << " " << cols << std::endl;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0 ; j < cols; ++j) {
            file << matrix(i,j) << " ";
        }
        file << std::endl;
    }
}

template <typename T, typename U>
inline void save_binary(const char * filename, U& matrix) {
    int rows = matrix.rows();
    int cols = matrix.cols();

    std::ofstream file(filename, std::ios::binary | std::ios::out);
    if (!file.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return;
    }
    
    file.write(reinterpret_cast<char*>(&rows), sizeof(rows));
    file.write(reinterpret_cast<char*>(&cols), sizeof(cols));
    file.write(reinterpret_cast<char*>(matrix.data()), matrix.size() * sizeof(T));
}

} // namespace m2cpp

#endif