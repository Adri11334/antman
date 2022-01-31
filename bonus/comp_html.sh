#!/usr/bin/env bash

make -s -C ../

function compress_test {
    for ORIGINAL_FILE in "$@"
    do
        printf "\nLet's compress $ORIGINAL_FILE\n"
        ../antman/antman $ORIGINAL_FILE 2 > temp.txt
        ../giantman/giantman ./temp 2 > g_temp.txt

        ORIGINAL_SIZE=$(stat -c%s $ORIGINAL_FILE)
        COMPRESSED_SIZE=$(stat -c%s ./temp.txt)
        COMPRECED_PERCENT=$((100 * $COMPRESSED_SIZE / $ORIGINAL_SIZE))

        if cmp -s "temp" "g_temp"; then
            printf "File $ORIGINAL_FILE was probably not compressed\n"
        else
            printf "The file is now compressed at $((100 -$COMPRECED_PERCENT))"
            printf " percent of his original size\n"
        fi

        rm -f ./temp.txt
        rm -f ./g_temp.txt
    done
}

compress_test $(find ./TA/*.html -type f -follow -print)

make -s -C../ fclean
