#include "../include/hanoi_t.hpp"

hanoi_t::hanoi_t(int numero_discos):
  palos_(NUMERO_PALOS, palo_t(numero_discos)),
  numero_movimientos_(0)
  {
    palos_[0].set_cima(numero_discos - 1);
    for(int i = 0; i < numero_discos; i++)
      palos_[0].set_disco(i, numero_discos - i);
  }

hanoi_t::~hanoi_t(void)
{}

movimientos_t hanoi_t::get_numero_movimientos(void) const
{
  return(numero_movimientos_);
}

void hanoi_t::reset_numero_movimientos(void)
{
  numero_movimientos_ = 0;
}
    
bool hanoi_t::movimiento_valido(const int palo_inicial, const int palo_destino) const
{
  if(palo_inicial < 0 || palo_inicial >= NUMERO_PALOS)
    return(0);
  if(palo_destino < 0 || palo_destino >= NUMERO_PALOS)
    return(0);
  if(palos_[palo_destino].get_disco_cima() < 0)
    return(1);
  if(palos_[palo_inicial].get_disco_cima() < 0)
    return(0);
  if(palos_[palo_inicial].get_disco_cima() >= palos_[palo_destino].get_disco_cima())
    return(0);
  return(1);
}

void hanoi_t::mover(const int palo_inicial, const int palo_destino)
{
  numero_movimientos_++;
  palos_[palo_destino].poner_cima(palos_[palo_inicial].quitar_cima());
}

void hanoi_t::resolver(bool debug)
{
  resolver_recursivo(palos_[0].get_numero_discos(), 0, 2, 1, debug);
}

void hanoi_t::resolver_recursivo(int size, int palo_inicial, int palo_destino, int palo_auxiliar, bool debug)
{
  if(size == 1)
    {
      mover(palo_inicial, palo_destino);
      if(debug)
        std::cout << *this << std::endl;
    }
    else
    {
        resolver_recursivo(size - 1, palo_inicial, palo_auxiliar, palo_destino, debug);
        
        mover(palo_inicial, palo_destino);

        if(debug)
          std::cout << *this << std::endl;
        resolver_recursivo(size - 1, palo_auxiliar, palo_destino, palo_inicial, debug);
    }
}

std::ostream& hanoi_t::mostrar(std::ostream &os) const
{
  
  os << "Movimiento numero: " << numero_movimientos_ << std::endl << std::endl;
  for(int j = palos_[0].get_numero_discos() - 1;  j >= 0; j--)
  {
    for(unsigned int i = 0; i < palos_.size(); i++)
      if(palos_[i].get_cima() >= j)
        os << std::setw(10) << palos_[i].get_disco(j) << " ";
      else
        os << "           ";
    os << std::endl;
  }
  for(unsigned int i = 0; i < palos_.size(); i++)
    os << std::setw(10) << "   Palo " << (i + 1) << " ";
  os << std::endl;
  return(os);
}

std::ostream& operator <<(std::ostream &os, const hanoi_t &hanoi)
{
  return(hanoi.mostrar(os));
}