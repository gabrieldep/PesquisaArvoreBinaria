#include <iostream>
#include "ArvoreBinaria.h"
#include "TipoItemArvore.h"

using namespace std;

void PreencheVetor(const char caminho[], ArvoreBinaria* arvore) {
	char* result;
	char Linha[100];
	FILE* arquivo = fopen(caminho, "rt");
	int aux = 0;
	int tamanho = *fgets(Linha, 100, arquivo) - 48;
	while (!feof(arquivo) && aux < tamanho)
	{
		result = fgets(Linha, 100, arquivo);
		if (result == NULL)break;
		string s = result;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				TipoItemArvore* tipoItem = new TipoItemArvore();
				tipoItem->SetNome(s.substr(0, i));
				tipoItem->SetDados(s.substr(i + 1, s.size()));
				tipoItem->SetDadosInt(stoi(s.substr(i + 1, s.size())));
				arvore->Insere(*tipoItem);
				break;
			}
		}
		aux++;
	}
	fclose(arquivo);
}

int main(int argc, const char* argv[])
{
	ArvoreBinaria* arvore = new ArvoreBinaria();
	PreencheVetor(argv[1], arvore);

	arvore->Imprime();
}
