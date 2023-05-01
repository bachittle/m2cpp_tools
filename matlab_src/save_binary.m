function save_binary(filename, data)
    fid = fopen(filename, 'wb');
    if isvector(data)
        fwrite(fid, length(data), 'int32');
    else
        fwrite(fid, size(data), 'int32');
    end
    fwrite(fid, data, 'float32');
    fclose(fid);
end