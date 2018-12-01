# Ternary Huffman Encoder


## Overview 
Program takes a string of text as input, counts the frequency of characters in that string, and generates a frequency list. 

It then constructs a ternary huffman tree, and saves the generated codes to a codebook. 


#### CodeBook structure

Implemented as a linked list
``` c 
struct codeSet {
    char character;
    int *code;
    int length;
    CodeSet *next;
}
```

## Example

#### Sample Input
``` "Lorem ipsum dolor sit amet, vim affert alterum " ```

#### Resulting frequencies and codes

| Character | Frequency | Non-canonical Code |
|-----------|-----------|--------------------|
| ,         | 1         | 000                |
| L         | 1         | 001                |
| d         | 1         | 002                |
| p         | 1         | 110                |
| v         | 1         | 111                |
| f         | 2         | 112                |
| l         | 2         | 200                |
| s         | 2         | 201                |
| u         | 2         | 202                |
| a         | 3         | 220                |
| i         | 3         | 221                |
| o         | 3         | 222                |
| e         | 4         | 01                 |
| r         | 4         | 02                 |
| t         | 4         | 10                 |
| m         | 5         | 12                 |
|           | 8         | 21                 |


##### Right side of tree
![Alt Text](https://github.com/deak-s/TernaryHuffmanEncoder_c/blob/master/public/tree_example2.png)

## To Do/fix
* iterateThroughEncodings() has leak & is inefficient
* file I/O option
