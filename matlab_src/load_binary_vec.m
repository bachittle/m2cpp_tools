function output = load_binary_vec(filename)
    fid = fopen(filename, 'rb');
    dims = fread(fid, 1, 'int32');
    output = fread(fid, dims, 'float32');
    fclose(fid);
end