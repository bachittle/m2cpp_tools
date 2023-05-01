// simple test example for the library

#include <iostream>
#include "m2cpp/utils.hpp"

#define MAT_BIN_TO_TXT 1
// #define MAT_TXT_TO_BIN 1

// #define VEC_BIN_TO_TXT 1
// #define VEC_TXT_TO_BIN 1

int main(int argc, char ** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <input file> <output file : optional>" << std::endl;
        return 1;
    }
    char * filename = argv[1];
    char * output_filename = "output";
    if (argc >= 3) {
        output_filename = argv[2];
    } 

    std::cout << "Loading file: " << filename << "..." << std::endl;

    #ifdef MAT_BIN_TO_TXT
    auto mat = m2cpp::load_binary_mat<Eigen::MatrixXf, float>(filename);
    std::cout << "Loaded matrix: " << std::endl;
    std::cout << "rows: " << mat.rows() << std::endl;
    std::cout << "cols: " << mat.cols() << std::endl;
    
    m2cpp::save_text_mat(output_filename, mat);
    #endif

    #ifdef MAT_TXT_TO_BIN
    auto mat = m2cpp::load_text_mat<Eigen::MatrixXf>(filename);
    std::cout << "Loaded matrix: " << std::endl;
    std::cout << "rows: " << mat.rows() << std::endl;
    std::cout << "cols: " << mat.cols() << std::endl;
    
    m2cpp::save_binary_mat<float>(output_filename, mat);
    #endif

    #ifdef VEC_TXT_TO_BIN
    auto vec = m2cpp::load_text_vec<Eigen::VectorXf>(filename);
    std::cout << "Loaded vector: " << std::endl;
    std::cout << "size: " << vec.size() << std::endl;
    
    m2cpp::save_binary_vec<float>(output_filename, vec);
    #endif
    
    #ifdef VEC_BIN_TO_TXT
    auto vec = m2cpp::load_binary_vec<Eigen::VectorXf, float>(filename);
    std::cout << "Loaded vector: " << std::endl;
    std::cout << "size: " << vec.size() << std::endl;
    
    m2cpp::save_text_vec(output_filename, vec);
    #endif
    
    return 0;
}