#pragma once
#define NUMERO_PALOS 3
#include <iomanip> 
#include "palo_t.hpp"
typedef double movimientos_t;

class hanoi_t
{
  protected:
    std::vector<palo_t> palos_;       //vector que contiene los diferentes palos
    movimientos_t numero_movimientos_; // contador de movimientos
  public:
    hanoi_t(int numero_discos); //constructor que inicializa 3 palos al número de discos indicado
    ~hanoi_t(void);
    
    // función que retorna el número de movimientos actual
    movimientos_t get_numero_movimientos(void) const;
    // función que pone a cero el contador de movimientos
    void reset_numero_movimientos(void);
    
    // función que resuelve el problema de las torres de hanoi
    // en caso de que la variable debug este a 1 se mostrará la evolución paso a paso
    void resolver(bool debug);
    // función que formatea por un flujo de salida el estado actual
    // de las torres de hanoi
    std::ostream& mostrar(std::ostream &os) const;
    // sobrecarga del operador << que vuelca sobre el flujo el formateo
    // del estado actual de las torres de hanoi
    friend std::ostream& operator <<(std::ostream &os, const hanoi_t &hanoi);
    
    protected:
      // función recursiva que resuelve el problema
      // mueve "size" discos desde el palo_inicial hasta el palo_destino
      // en caso de que el debug sea true mostrará la traza
      virtual void resolver_recursivo(int size, int palo_inicial, int palo_destino, int palo_auxiliar, bool debug);
      // función que comprueba si se puede mover la cima del palo_inicial al palo_destino
      bool movimiento_valido(const int palo_inicial, const int palo_destino) const;
      // función que mueve la cima del palo_inicial al palo_destino
      void mover(const int palo_inicial, const int palo_destino);
};