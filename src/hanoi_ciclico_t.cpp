#include "../include/hanoi_ciclico_t.hpp"

hanoi_ciclico_t::hanoi_ciclico_t(int numero_discos):
  hanoi_t(numero_discos)
  {}
  
hanoi_ciclico_t::~hanoi_ciclico_t(void)
{}

void hanoi_ciclico_t::resolver_recursivo(int size, int palo_inicial, int palo_destino, int palo_auxiliar, bool debug)
{
  mover_discos_sentido_horario(size, palo_inicial, palo_destino, palo_auxiliar, debug);
}

void hanoi_ciclico_t::movimiento(int palo)
{
  if(movimiento_valido_sentido_horario(palo))
    mover_sentido_horario(palo);
  else
    if(movimiento_valido_sentido_antihorario(palo))
      mover_sentido_antihorario(palo);
    else
    {
      std::cout<<"error movimiento"<<std::endl;
      exit(EXIT_FAILURE);
    }
}

void hanoi_ciclico_t::mover_discos_sentido_horario(int size, int palo_inicial, int palo_destino, int palo_auxiliar, bool debug)
{
  if(size > 0)
  {
    mover_discos_sentido_antihorario(size - 1, palo_inicial, palo_auxiliar, palo_destino, debug);
    movimiento(palo_inicial);
    if(debug)
      std::cout << *this << std::endl;
    mover_discos_sentido_antihorario(size - 1, palo_auxiliar, palo_destino, palo_inicial, debug);
  }
}

void hanoi_ciclico_t::mover_discos_sentido_antihorario(int size, int palo_inicial, int palo_destino, int palo_auxiliar, bool debug)
{
  if(size > 0)
  {
    mover_discos_sentido_antihorario(size - 1, palo_inicial, palo_destino, palo_auxiliar, debug);
    movimiento(palo_inicial);
    if(debug)
      std::cout << *this << std::endl;
    mover_discos_sentido_horario(size - 1, palo_destino, palo_inicial, palo_auxiliar, debug);
    movimiento(palo_auxiliar);
    if(debug)
      std::cout << *this << std::endl;
    mover_discos_sentido_antihorario(size - 1, palo_inicial, palo_destino, palo_auxiliar, debug);
  }
}

void hanoi_ciclico_t::mover_sentido_horario(int palo)
{
  mover(palo, (palos_.size() + palo - 1) % palos_.size()); 
}

bool hanoi_ciclico_t::movimiento_valido_sentido_horario(int palo) const
{
  return(movimiento_valido(palo, (palos_.size() + palo - 1) % palos_.size()));
}

void hanoi_ciclico_t::mover_sentido_antihorario(int palo)
{
  mover(palo, (palo + 1) % palos_.size());
}

bool hanoi_ciclico_t::movimiento_valido_sentido_antihorario(int palo) const
{
  return(movimiento_valido(palo, (palo + 1) % palos_.size()));
}