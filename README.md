# Data-Compression

This is a data compression program I developed by implementing a hash table data structure from scratch and using object-oriented programming principles.
The hash table is used to map each word from the original text file to a unique code.
This program outputs two files: a compressed file (Compressed_file.txt) and a decoder mapping file (decoderMappingFile.txt).
The decoderMappingFile contains a unique code for each word from the file and each word's frequency.
The Compressed_file contains a unique numerical code for each word from the original file. This allows the Compressed_file to be greatly compressed, yet still retain the same data.

How to run this program:
1. Download all project files on a local folder in your computer.
2. Open Command Prompt (on Windows) or Terminal (on Mac) and change directory to the folder that contains this project's files.
3. Compile the program with this compile command: "g++ TokenObject.cpp HashTable.cpp main.cpp -Wall -Wuninitialized -o a.out"
4. Run the executable by entering "a.out" command, and enter the name of the file you want compressed (make sure to include .txt at the end of the file name for text file). I've included the file "sample_file_wikipedia.txt" you can use to compress.
5. There should be two output files in the folder: Compressed_file.txt and decoderMappingFile.txt
