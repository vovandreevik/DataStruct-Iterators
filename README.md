# DataStruct and Sorting Using Iterators
This C++ program demonstrates how to read, process, and sort data using the DataStruct structure and custom sorting criteria. 

The program reads data from an input file, parses it into DataStruct objects, sorts the objects, and then prints the sorted data. 

To achieve this, the program heavily relies on iterators for data processing and sorting.

## DataStruct is a C++ struct that represents data with three components:

key1: An unsigned long long integer (ull) extracted from the input as "key1."

key2: An unsigned long long integer (ull) extracted from the input as "key2," with values given in binary form ("0b").

key3: A string extracted from the input as "key3" enclosed in double quotes.

The program reads data in the format (:key1 ...:key2 ...:key3 ...:) from the input file, parses it, and constructs DataStruct objects.

## Sorting DataStruct Objects with Iterators
The program uses iterators to process and sort DataStruct objects:

- It uses an input iterator to read data from the input file and populate DataStruct objects.
- It employs custom comparison functions along with iterators to sort the objects based on the specified criteria.
- Output iterators are used to print the sorted DataStruct objects to the console.

## Input Data Example
The input.txt file should contain data in the following format for parsing:

```
(:key1 89ull:key2 0b1000101:key3 "Data":)
(:key2 0B001001:key1 89ULL:key3 "Data":)
(:key3 "Data":key2 0B001001:key1 10ull:)
(:key3 "Another":key1 100ull:key2 0b1110001:)
(:key1 50ull:key2 0b1010101:key3 "Some":)
(:key1 50000:key2 0b1010101:key3 "Some":)
(:key3 "Another":key1 100:key2 1110001:)
(:key3 "Another":key1 gdfgll:key2 0b1110001:)
```
## Examples
The main.cpp file contains example code that demonstrates how to read, parse, and sort DataStruct objects using iterators. 

