#pragma once
#include <vector>
#include <stdlib.h>
#include <iostream>

class palo_t
{
  private:
    std::vector<int> discos_; // vector que contiene los discos
    int cima_;                // atributo que marca el ultimo elemento del palo
  public:
    // constructor que recibe el número de discos e inicializa la cima a -1
    palo_t(int numero_discos);
    //constructor de copia
    palo_t(const palo_t &otro_palo);

    ~palo_t(void);
    
    // función que retorna el elemento de la cima y la decrementa
    int quitar_cima(void);
    // función que inserta un elemento indicado en la cima y la incrementa
    void poner_cima(int disco);
    
    // función que retorna 
    int get_cima(void) const;
    // función que modifica el valor del atributo cima
    void set_cima(int cima);
    
    // función que retorna el número de discos almacenables
    int get_numero_discos(void) const;
    
    // función que retorna el disco indicado por parámetro
    int get_disco(const int posicion) const;
    
    // función que modifica el disco indicado por parámetro por el valor indicado
    void set_disco(int posicion, int disco);
    // función que retorna el valor del elemento situado en la cima
    int get_disco_cima(void) const;
};