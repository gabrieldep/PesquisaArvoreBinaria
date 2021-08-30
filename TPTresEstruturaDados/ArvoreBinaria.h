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
		void Caminha(int tipo);
		void Imprime();
		void Limpa();

	private:
		void InsereRecursivo(TipoNo* &p, TipoItemArvore item);
		TipoNo PesquisaRecursiva(TipoNo* &p, std::string chave);
		void RemoveRecursiva(TipoNo* &p, std::string chave);
		void ApagaRecursivo(TipoNo* p);
		void PorNivel();
		void PreOrdem(TipoNo* p);
		void InOrdem(TipoNo* p);
		void PosOrdem(TipoNo* p);

		TipoNo* raiz;
};

