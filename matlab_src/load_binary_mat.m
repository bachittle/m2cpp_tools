function output = load_binary_mat(filename)
    fid = fopen(filename, 'rb');
    dims = fread(fid, 2, 'int32');
    output = fread(fid, prod(dims), 'float32');
    fclose(fid);
    output = reshape(output, dims(1), dims(2));  
end