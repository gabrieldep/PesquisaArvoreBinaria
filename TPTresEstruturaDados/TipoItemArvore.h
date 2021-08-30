#pragma once
#include <string>
class TipoItemArvore
{
	public:
		TipoItemArvore();
		TipoItemArvore(std::string dados, std::string nome);
		void SetDados(std::string valor);
		void SetDadosInt(int valor);
		void SetNome(std::string valor);
		std::string GetDados();
		int GetDadosInt();
		std::string GetNome();
		void Imprime();
	private:
		std::string dados;
		std::string nome;
		int dadosInt;

		friend class Fila;
		friend class TipoCelula;
};

