# 58---Huffman-Compression-Tool--Kitetu-Veronica-Kavata-FEE3-2883-2025
Huffman Compression Tool implemented in C++ using Code: Blocks. Project submitted by Kitetu Veronica Kavata FEE3 - 2883 -2025

Description - This is a C++ program that implements Huffman coding - a lossless data compression algorithm.
            - It reduces text or image without losing the actual data.
            - It is based on the fact that some data is used more frequently than the others. The more frequently a                        character is used, the shorter the Huffman code.
            - This program takes input text, compresses it using Huffman coding, and outputs the encoded data.
            - Works by creating a Huffman tree that needs to be stored alongside the compressed data.

Features - Builds a Huffman tree from the input characters; Generates Huffman codes for each character; Compresses input data efficiently; Displays the Huffman codes for reference.

How to Run -

1.Compile the code using g++ (or any C++ compiler): e.g
g++ Huffman.cpp -o Huffman

2.Run the program: e.g
./Huffman

3.Follow the prompts to enter your text for compression

Sample Input/Output

Input:

huffman

Output:

Character codes: 
h: 100 
u: 101 
f: 01 
m: 110 
a: 111 
n: 00

Encoded text/string: 1001010111011100

Compression Ratio - Compression ratio shows how much the Huffman algorithm reduces the size of the data. It is calculated as:

   Compression Ratio = (Size of compressed data)/ (Size of original data) 
                                        Example: 
  -In the orignal text: huffman, there are 7 characters. Each character has 8 bits, thus the total number of bits for the 7 characters = 7 x 8 = 56 bits. 
  - When the text is Huffman coded, it will have 16 bits.
  - - Thus, the number of bits saved by compression is 56 bits-16 bits = 40 bits (this is one of the advantages of Huffman coding over fixed-length coding)
      
Other advantages of using Huffman Compression Tool: 
      1. It is a lossless compression thus data can always be perfectly reconstructed from the compressed file. 
      2. Huffman coding produces the most efficient prefix code for a given set of symbol frequencies. It guarantees the minimum total bits required for encoding the data.
      3. The codes are customised for the input data, therefore, it works efficiently for any text or symbols, not just standatd files. 
      4. The algorithm is straightforward to implement the use of binary trees making it popular in educational projects and practical applications. 5. No code is a prefix of another code, which ensures unambiguous decoding.

Author:
VERONICA KAVATA KITETU - FEE3/2883/2025
