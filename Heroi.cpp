#include "Heroi.h"
#include "Combatente.h"
#include <iostream>

Heroi::Heroi() : Combatente(), itemEquipado() {}

Heroi::Heroi(std::string nome, int hp, int ataque, int defesa, int velocidade, Item item)
    : Combatente(nome, hp, ataque, defesa, velocidade), itemEquipado(item) {}

void Heroi::atacar(Combatente &alvo) {
    int danoTotal = this->ataque + itemEquipado.getBonusAtaque();
    std::cout << "[HEROI] " << this->nome << " brande sua arma e ataca " << alvo.getNome() << "!\n";
    alvo.receberDano(danoTotal);
}

void Heroi::exibirStatus() const {
    Combatente::exibirStatus();
    std::cout << " | Item: " << itemEquipado.getNome() << " (+" << itemEquipado.getBonusAtaque() << " ATK)\n";
}