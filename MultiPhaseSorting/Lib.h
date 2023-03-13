#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

bool isFileEmpty(const std::string& _fileName);

bool isSortedArrayInFile(const std::string& _fileName);

void printFile(const std::string& _fileName);

void multiphaseSorting(const std::string& _fileName, const int _filesCount = 3, const bool _showWorkFiles=false);

int findBorder(const std::string& _fileName);

int deleteElement(const std::string& _fileName, const int _element);

void calculateIdealPartition(int* _idealPartition, int _size);

void fillIdealPartitionAndNullSlices(int* _idealPartition, int* _nullSlicesCount, const int _size);