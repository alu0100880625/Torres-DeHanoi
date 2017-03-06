#pragma once
#include "hanoi_t.hpp"

class hanoi_ciclico_t : public hanoi_t
{
  public:
    hanoi_ciclico_t(int numero_discos);
    ~hanoi_ciclico_t(void);
    private:
      // función heredada que inicializa la recursividad
      void resolver_recursivo(int size, int palo_inicial, int palo_destino, int palo_auxiliar, bool debug);
      // función recursiva que mueve "size" discos desde el palo_inicial hasta el palo_destino 
      // en sentido horario en caso de que el debug sea true mostrará la traza
      void mover_discos_sentido_horario(int size, int palo_inicial, int palo_destino, int palo_auxiliar, bool debug);
      // función recursiva que mueve "size" discos desde el palo_inicial hasta el palo_destino 
      // en sentido antihorario en caso de que el debug sea true mostrará la traza
      void mover_discos_sentido_antihorario(int size, int palo_inicial, int palo_destino, int palo_auxiliar, bool debug);
      
      // función que mueve en el sentido que sea posible
      // (intenta mover en sentido horario y antihorario)
      void movimiento(int palo);
      
      // función que mueve la cima del palo indicado
      // una vez en sentido horario
      void mover_sentido_horario(int palo);
      // función comprueba si se puede mover la cima del palo indicado
      // en sentido horario
      bool movimiento_valido_sentido_horario(int palo) const;
    
      // función que mueve la cima del palo indicado
      // una vez en sentido antihorario
      void mover_sentido_antihorario(int palo);
      // función comprueba si se puede mover la cima del palo indicado
      // en sentido antihorario
      bool movimiento_valido_sentido_antihorario(int palo) const;
};