
# Huffman Coding Project

This project implements a **Huffman Coding** compression algorithm in C++. Huffman coding is a widely used technique for lossless data compression, which uses variable-length codes to represent characters based on their frequencies. This program compresses a text file using Huffman coding, saves the compressed data to a binary file, and supports decompression to recover the original text.

## Features

-   **Frequency Calculation**: Calculates character frequencies in the input text.
-   **Huffman Tree Construction**: Builds a binary tree to represent Huffman codes for each character.
-   **Compression**: Encodes the text into a compressed form.
-   **Decompression**: Decodes the compressed data back to its original form.
-   **File Operations**: Handles reading, writing, and binary data storage for compressed files.

## Project Structure

-   `main.cpp`: The main driver file that runs the compression and decompression processes.
-   `Huffman.hpp` and `huffman.cpp`: Implement the `Huffman` class responsible for encoding and decoding operations.
-   `Node.hpp` and `node.cpp`: Define the `Node` class for constructing the Huffman tree.
-   `compressed_input.txt`: Output file containing the compressed data.
-   `decompressed_input.txt`: Output file with decompressed data to verify accuracy.

## How It Works

1.  **Frequency Calculation**: The program reads the text file, calculates the frequency of each character, and stores it in a map.
2.  **Huffman Tree Generation**: Using a priority queue, it builds a binary tree where each character is represented by a unique binary code.
3.  **Compression**: The text is encoded based on the Huffman codes of each character, resulting in a binary string.
4.  **Binary File Storage**: Converts the binary string into bytes, adds padding for alignment, and saves it in `compressed_input.txt`.
5.  **Decompression**: Reads the binary file, decodes it using the Huffman tree, and writes the output to `decompressed_input.txt`.

## How to Run

1.  Clone or download the repository.
2. Open PowerShell in the project src directory.Compile the program
    ```
    g++ *.cpp -o my_program
	``` 
3. Run the compiled program:
	```
	.\my_program.exe
	``` 
4.  Check the `compressed_input.txt` and `decompressed_input.txt` files for compressed and decompressed data, respectively.


## Example Files

-   **Input File (`input.txt`)**: Contains the text to be compressed.
-   **Compressed File (`compressed_input.txt`)**: Contains the compressed data.
-   **Decompressed File (`decompressed_input.txt`)**: Contains the decompressed data, matching `input.txt`.
