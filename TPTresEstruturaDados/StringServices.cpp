#include "StringServices.h"

/// <summary>
/// Verifica se a primeira string vem antes da segunda na ordem alfabetica
/// </summary>
/// <param name="primeira">Primeira string</param>
/// <param name="segunda">Segunda string</param>
/// <returns>True caso a primeira venha antes e False caso a segunda venha antes</returns>
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
