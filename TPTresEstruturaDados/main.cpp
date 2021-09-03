#include <iostream>
#include "ArvoreBinaria.h"
#include "TipoItemArvore.h"
#include <string>
#include <sstream>

using namespace std;

/// <summary>
/// Faz a leitura dos arquivos e executa as operacoes solicitadas.
/// </summary>
/// <param name="arquivo">Arquivo a ser lido</param>
/// <param name="arvore">Arvore com os dados a serem tratados</param>
void RealizarComandos(FILE* arquivo, ArvoreBinaria* arvore)
{
	char* result;
	char Linha[100];

	while (!feof(arquivo))
	{
		result = fgets(Linha, 100, arquivo);
		if (result == NULL)break;
		string s = result;
		s = s.erase(s.length() - 1);
		TipoNo* no = arvore->Pesquisa(s);
		int number = 0;
		Fila* fila = no->GetDados();
		while (fila->GetTamanho() != 0) {
			number += stoi(fila->Desenfilera().GetDados(), 0, 2);
		}
		std::cout << no->GetNome() << " " << number << std::endl;
		arvore->Remove(s);
	}
}

TipoItemArvore* getTipoItemArvore(string rawInput) {
	TipoItemArvore* item = new TipoItemArvore();

	std::stringstream rawInputStream(rawInput);
	std::string buffer;
	char commandSeparator = ' ';

	getline(rawInputStream, buffer, commandSeparator);
	item->SetNome(buffer);
	getline(rawInputStream, buffer, commandSeparator);
	item->SetDados(buffer);
	item->SetDadosInt(stoi(buffer));

	return item;
}

/// <summary>
/// Faz a leitura do arquivo e realiza as operacoes na arvore.
/// </summary>
/// <param name="caminho">Caminho do arquivo</param>
/// <param name="arvore">Arvore a ser tratada.</param>
void PreencheVetor(const char caminho[], ArvoreBinaria* arvore)
{
	string result;
	char Linha[100];
	FILE* arquivo = fopen(caminho, "rt");
	int aux = 0;
	result = fgets(Linha, 100, arquivo);
	int tamanho = stoi(result);
	while (!feof(arquivo) && aux < tamanho)
	{
		result = fgets(Linha, 100, arquivo);
		if (result.size() == 0)break;
		string s = result;
		TipoItemArvore* tipoItem = getTipoItemArvore(result);
		arvore->Insere(*tipoItem);
		aux++;
	}

	arvore->Imprime();
	std::cout << std::endl;
	RealizarComandos(arquivo, arvore);
	arvore->Imprime();
	fclose(arquivo);
}

int main(int argc, const char* argv[])
{
	ArvoreBinaria* arvore = new ArvoreBinaria();
	PreencheVetor(argv[1], arvore);
	delete arvore;
}
