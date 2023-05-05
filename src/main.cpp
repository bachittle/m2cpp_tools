// simple test example for the library

#include <iostream>
#include <cstring>
#include "m2cpp/utils.hpp"

int main(int argc, char ** argv) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <option> <input file> <output file : optional>" << std::endl;
        return 1;
    }
    char * option = argv[1];
    char * filename = argv[2];
    char * output_filename = "output";
    if (argc >= 4) {
        output_filename = argv[3];
    } 

    std::cout << "Loading file: " << filename << "..." << std::endl;

    if (std::strcmp(option, "mat_b2t") == 0) {
        auto mat = m2cpp::load_binary_mat<Eigen::MatrixXf, float>(filename);
        std::cout << "Loaded matrix: " << std::endl;
        std::cout << "rows: " << mat.rows() << std::endl;
        std::cout << "cols: " << mat.cols() << std::endl;
        
        m2cpp::save_text_mat(output_filename, mat);
    } else if (std::strcmp(option, "mat_t2b") == 0) {
        auto mat = m2cpp::load_text_mat<Eigen::MatrixXf>(filename);
        std::cout << "Loaded matrix: " << std::endl;
        std::cout << "rows: " << mat.rows() << std::endl;
        std::cout << "cols: " << mat.cols() << std::endl;
        
        m2cpp::save_binary_mat<float>(output_filename, mat);

    } else if (std::strcmp(option, "vec_b2t") == 0) {
        auto vec = m2cpp::load_binary_vec<Eigen::VectorXf, float>(filename);
        std::cout << "Loaded vector: " << std::endl;
        std::cout << "size: " << vec.size() << std::endl;
        
        m2cpp::save_text_vec(output_filename, vec);
    
    } else if (std::strcmp(option, "vec_t2b") == 0) {
        auto vec = m2cpp::load_text_vec<Eigen::VectorXf>(filename);
        std::cout << "Loaded vector: " << std::endl;
        std::cout << "size: " << vec.size() << std::endl;
        
        m2cpp::save_binary_vec<float>(output_filename, vec);
    
    }

    return 0;
}