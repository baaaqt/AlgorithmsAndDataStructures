#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include "Lib.h"

/*template<typename _Type>
std::vector<_Type> createFibonacciHighPowerSequence(const int _size, const int _power) {
	if (_size <= 0)
		return std::vector<_Type>();
	if (_power > _size || _power <= 0)
		return std::vector<_Type>(_size);
	
	std::vector<_Type> sequence(_size);
	for (int i = 0; i < _power - 1; i++)
		sequence[i] = 0;
	sequence[_power - 1] = 1;
	
	for (int i = _power; i < _size; i++)
	{
		_Type sum = 0;
		for (int j = 0; j <= _power; j++)
			sum += sequence[i - j];
		sequence[i] = sum;
	}
	return sequence;
}
*/

bool createFileWithRandomNumbers(const std::string& _fileName, const int _numbersCount,
	const int _minNumber = 0, const int _maxNumber = 100, const int _filesCount = 3)
{
	if (_numbersCount < 0) {
		throw "Invalid argument: _numbersCount must be greater or equal 0.";
	}
	std::ofstream out(_fileName);
	if (!out.is_open())
		throw "Error opening file";


	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());  // to seed mersenne twister.
	std::uniform_int_distribution<> dist(_minNumber, _maxNumber);
	for (int i = 0; i < _numbersCount; i++)
		out << dist(gen) << ' ';
	out.close();
	return true;
}


int createAndSortFile(const std::string& _fileName, const int _numbersCount,
	const int _minNumber = 0, const int _maxNumber = 100, const int _filesCount = 3)
{
	if (_numbersCount < 0) {
		throw "Invalid argument: _numbersCount must be greater or equal 0.";
	}

	if (!createFileWithRandomNumbers(_fileName, _numbersCount, _minNumber, _maxNumber))
		return -1;

	multiphaseSorting(_fileName, _filesCount);

	if (!isSortedArrayInFile(_fileName))
		return -2;

	return 1;
}


int main() {
	return 0;
}