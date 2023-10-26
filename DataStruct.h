#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

struct DataStruct {
    unsigned long long key1;
    unsigned long long key2;
    std::string key3;
};

bool isValidBin(const std::string& value) {
    for (const char& temp : value) {
        if (!isdigit(temp)) {
            return false;
        }
    }
    return true;
}

bool isValidUll(const std::string& value) {
    for (const char& temp : value) {
        if (!isdigit(temp)) {
            return false;
        }
    }
    return true;
}

std::istream& operator>>(std::istream& is, DataStruct& data) {
    std::string str;

    while (std::getline(is, str)) {
        if (str.front() != '(' or str.back() != ')') {
            continue;
        }

        std::stringstream ss(str.substr(1, str.size() - 2));
        std::string token;
        int validFields = 0;
        DataStruct temp;

        while (std::getline(ss, token, ':')) {
            std::stringstream inner(token);
            std::string key, value;

            inner >> key >> value;

            if (key == "key1") {
                std::string check = value.substr(value.size() - 3, value.size());
                std::string numStr = value.substr(0, value.size() - 3);
                if (isValidUll(numStr) and (check == "ull" or check == "ULL")) {
                    try {
                        temp.key1 = std::stoull(numStr);
                        validFields++;
                    }
                    catch (const std::exception&) {
                    }
                }
            }
            else if (key == "key2") {
                std::string check = value.substr(0, 2);
                std::string numStr = value.substr(2, value.size());
                if (isValidBin(numStr) and (check == "0b" or check == "0B")) {
                    try {
                        temp.key2 = std::stoull(numStr);
                        validFields++;
                    }
                    catch (const std::exception&) {
                    }
                }
            }
            else if (key == "key3") {
                temp.key3 = value.substr(1, value.size() - 2);
                validFields++;
            }
        }

        if (validFields == 3) {
            data = temp;
            return is;
        }
    }

    is.setstate(std::ios::failbit);
    return is;
}

std::ostream& operator<<(std::ostream& out, const DataStruct& data) {
    out << "(:key1 " << data.key1 << "ull:key2 0b" << data.key2 << ":key3 \"" << data.key3 << "\":)";
    return out;
}

bool operator<(const DataStruct& left, const DataStruct& right) {
    if (left.key1 != right.key1) {
        return left.key1 < right.key1;
    }
    else if (left.key2 != right.key2) {
        return left.key2 < right.key2;
    }
    else {
        return left.key3.size() < right.key3.size();
    }
}

#endif // DATA_STRUCT_H
