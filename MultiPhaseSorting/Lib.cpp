#include "Lib.h"

template<class _fstreamClass>
void checkFileOpening(const _fstreamClass& _file, const std::string& _fileName = "") {
	if(!_file.is_open())
		throw std::string("Error opening file. File: ") + _fileName;
}

bool isFileEmpty(const std::string& _fileName)
{
	std::ifstream in(_fileName);
	checkFileOpening(in,_fileName);

	int a;
	if (!(in >> a)) {
		in.close();
		return true;
	}
	in.close();
	return false;
}

bool isSortedArrayInFile(const std::string& _fileName) {
	if (isFileEmpty(_fileName))
		return false;

	std::ifstream in(_fileName);
	checkFileOpening(in, _fileName);

	int a, b;
	in >> a;
	while (in >> b) {
		if (b < a)
		{
			in.close();
			return false;
		}
		a = b;
	}
	in.close();
	return true;
}

void printFile(const std::string& _fileName)
{
	std::ifstream file(_fileName);
	checkFileOpening(file, _fileName);

	while (!file.eof()) {
		int num;
		file >> num;
		std::cout << num << ' ';
	}
	file.close();
}

void multiphaseSorting(const std::string& _fileName, const int _filesCount = 3, const bool _showWorkFiles = false) {
	unsigned int filesCount = _filesCount < 3 ? 3 : _filesCount;
	int border = findBorder(_fileName);
	int borderCount = deleteElement(_fileName, border);
}

int partition(const std::string& _fileName, const int _filesCount) {

}

void calculateIdealPartition(int * _idealPartition, int _size) {
	int temp = _idealPartition[0];
	for (int i = 0; i < _size - 1; i++)
		_idealPartition[i] = _idealPartition[i + 1] + temp;
}

void fillIdealPartitionAndNullSlices(int * _idealPartition, int * _nullSlicesCount, const int _size) {
	_idealPartition[_size - 1] = _nullSlicesCount[_size - 1] = 0;
	for (int i = 0; i < _size - 1; i++)
		_idealPartition[i] = _nullSlicesCount[i] = 0;
}

int findBorder(const std::string & _fileName) {
	// border element is maximum number in file
	std::ifstream file(_fileName);
	checkFileOpening(file, _fileName);
	
	int maximum = ~0, count = 0;
	int temp;
	while (file >> temp) {
		if (maximum < temp)
			maximum = temp;
	}
	file.close();

	return maximum;
}

int deleteElement(const std::string& _fileName, const int _element) {
	std::ifstream mainFile(_fileName);
	checkFileOpening(mainFile, _fileName);

	std::ofstream tempFile("temp.txt");
	checkFileOpening(tempFile, "temp.txt");

	int temp;
	int count = 0;
	while (mainFile >> temp) {
		if (temp != _element)
			tempFile << temp;
		else
			count++;
	}
	tempFile.close();
	mainFile.close();
	
	remove(_fileName.c_str());
	rename("temp.txt", _fileName.c_str());
	return count;
}