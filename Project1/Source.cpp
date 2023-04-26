#include <fstream>
#include "DataStruct.h"

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        return -1;
    }

    std::vector<DataStruct> vec;
    DataStruct data;

    while (inputFile >> data) {
        vec.push_back(data);
    }

    inputFile.close();
    std::sort(vec.begin(), vec.end());
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<DataStruct>(std::cout, "\n"));

    return 0;
}