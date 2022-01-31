#!/usr/bin/env bash

make -s -C ../

function compress_test {
    for ORIGINAL_FILE in "$@"
    do
        printf "\nLet's compress $ORIGINAL_FILE\n"
        ../antman/antman $ORIGINAL_FILE 1 > temp.txt
        ../giantman/giantman ./temp.txt 1 > g_temp.txt

        ORIGINAL_SIZE=$(stat -c%s $ORIGINAL_FILE)
        COMPRESSED_SIZE=$(stat -c%s ./temp.txt)
        UNCOMPRESSED_SIZE=$(stat -c%s ./g_temp.txt)
        COMPRECED_PERCENT=$((100 * $COMPRESSED_SIZE / $ORIGINAL_SIZE))

        if cmp -s "temp" "g_temp"; then
            printf "File $ORIGINAL_FILE was probably not compressed\n"
        else
            printf "The file is now compressed at $((100 -$COMPRECED_PERCENT))"
            printf " percent of his original size\n"
        fi

        if (($ORIGINAL_SIZE != $UNCOMPRESSED_SIZE)); then
            printf "File Invalid decompression: $ORIGINAL_SIZE is now $UNCOMPRESSED_SIZE\n"
        else
            printf "File compressed and uncompressed successfully\n"
        fi

        rm -f ./temp.txt
        rm -f ./g_temp.txt
    done
}

compress_test $(find ./comp_test/TA/*.lyr -type f -follow -print)

make -s -C../ fclean
