#pragma once
#include "TipoNo.h"
#include "TipoItemArvore.h"
class ArvoreBinaria
{
	public:
		ArvoreBinaria();
		~ArvoreBinaria();

		void Insere(TipoItemArvore tipoItem);
		TipoNo Pesquisa(std::string nome);
		void Remove(std::string nome);
		void Imprime();
		void Limpa();

	private:
		void InsereRecursivo(TipoNo* &p, TipoItemArvore item);
		TipoNo PesquisaRecursiva(TipoNo* &p, std::string chave);
		void RemoveRecursiva(TipoNo* &p, std::string chave);
		void ApagaRecursivo(TipoNo* p);
		void InOrdem(TipoNo* p);
		void Antecessor(TipoNo* q, TipoNo*& r);

		TipoNo* raiz;
};

