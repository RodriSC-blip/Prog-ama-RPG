#include "Monstro.h"
#include "Combatente.h"  // <--- ISSO VAI RESOLVER O ERRO DE DECLARAÇÃO
#include <iostream>      // <--- ISSO VAI RESOLVER O ERRO DO COUT

Monstro::Monstro() : Combatente() {}

Monstro::Monstro(std::string nome, int hp, int ataque, int defesa, int velocidade)
    : Combatente(nome, hp, ataque, defesa, velocidade) {}

void Monstro::atacar(Combatente &alvo) {
    std::cout << "[MONSTRO] " << this->nome << " avanca ferozmente contra " << alvo.getNome() << "!\n";
    alvo.receberDano(this->ataque);
}

void Monstro::exibirStatus() const {
    Combatente::exibirStatus();
    std::cout << " [Agressivo]\n";
}