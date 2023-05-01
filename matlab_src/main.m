# load binary files
test_mat = load_binary_mat('../testdata/test_mat.bin')
test_vec = load_binary_vec('../testdata/test_vec.bin')

# save all
save_binary('../testdata/test_mat2.bin', test_mat);
save_binary('../testdata/test_vec2.bin', test_vec);