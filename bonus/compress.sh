#!/usr/bin/env bash

make -s -C ../ re

ORIGINAL_FILE="$1"
FILE_TYPE="$2"

printf "\nLet's compress $ORIGINAL_FILE\n"
../antman/antman $ORIGINAL_FILE $FILE_TYPE > ./temp.txt
../giantman/giantman ./temp.txt $FILE_TYPE > ./g_temp.ppm

ORIGINAL_SIZE=$(stat -c%s $ORIGINAL_FILE)
COMPRESSED_SIZE=$(stat -c%s ./temp)
UNCOMPRESSED_SIZE=$(stat -c%s ./g_temp.ppm)
COMPRECED_PERCENT=$((100 * $COMPRESSED_SIZE / $ORIGINAL_SIZE))

if cmp -s "temp" "g_temp"; then
    printf "File $ORIGINAL_FILE was probably not compressed\n"
else
    printf "The file is now compressed at $((100 - $COMPRECED_PERCENT))"
    printf " percent of his original size\n"
fi

if (($ORIGINAL_SIZE != $UNCOMPRESSED_SIZE)); then
    printf "File Invalid decompression: $ORIGINAL_SIZE is now $UNCOMPRESSED_SIZE\n"
else
    printf "File compressed and uncompressed successfully\n"
fi

make -s -C ../ fclean
