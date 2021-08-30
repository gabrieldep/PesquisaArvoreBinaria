#include "StringServices.h"

StringServices::StringServices()
{
}

bool StringServices::VemAntes(std::string primeira, std::string segunda)
{
	if (primeira == segunda) {
		return false;
	}
	int tamanho = primeira.size() > segunda.size() ?
		segunda.size() : primeira.size();

	for (int i = 0; i < tamanho; i++) {
		if (primeira[i] != segunda[i]) {
			return primeira[i] < segunda[i];
		}
	}
	return primeira.size() < segunda.size();
}
