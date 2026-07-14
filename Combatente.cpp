#include "Combatente.h"
#include <iostream>

Combatente::Combatente() : nome("Desconhecido"), hp(1), ataque(1), defesa(1), velocidade(1) {}

Combatente::Combatente(std::string nome, int hp, int ataque, int defesa, int velocidade)
    : nome(nome), hp(hp), ataque(ataque), defesa(defesa), velocidade(velocidade) {
    if (this->hp < 0) this->hp = 0;
}

Combatente::~Combatente() {}

std::string Combatente::getNome() const { return this->nome; }
int Combatente::getHp() const { return this->hp; }
int Combatente::getAtaque() const { return this->ataque; }
int Combatente::getDefesa() const { return this->defesa; }
int Combatente::getVelocidade() const { return this->velocidade; }

void Combatente::setHp(int hp) {
    this->hp = (hp < 0) ? 0 : hp; // Validação estrita
}

void Combatente::receberDano(int danoInimigo) {
    int danoReal = danoInimigo - this->defesa;
    if (danoReal < 0) danoReal = 0;
    this->setHp(this->hp - danoReal);
}

void Combatente::exibirStatus() const {
    std::cout << this->nome << " | HP: " << this->hp 
              << " | ATK: " << this->ataque 
              << " | DEF: " << this->defesa 
              << " | VEL: " << this->velocidade;
}