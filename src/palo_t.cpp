#include "../include/palo_t.hpp"

palo_t::palo_t(int numero_discos):
  discos_(numero_discos),
  cima_(-1)
  {}

palo_t::palo_t(const palo_t &otro_palo)
{
  discos_.resize(otro_palo.get_numero_discos());
  for(unsigned int i = 0; i < discos_.size(); i++)
    set_disco(i, otro_palo.get_disco(i));
  set_cima(otro_palo.get_cima());
}

palo_t::~palo_t(void)
{}

int palo_t::quitar_cima(void)
{
  if(cima_ <= -1 || cima_ >= get_numero_discos())
  {
    std::cerr << "Error quitando cima con indice: " << cima_ << std::endl;
    exit (EXIT_FAILURE);
  }
  return(discos_[cima_--]);
}

void palo_t::poner_cima(int disco)
{
  if(cima_ < -1 || cima_ -1 >= get_numero_discos())
  {
    std::cerr << "Error poniendo cima con indice: " << cima_ << std::endl;
    exit (EXIT_FAILURE);
  }
  discos_[++cima_] = disco;
}

int palo_t::get_cima(void) const
{
  return(cima_);
}

void palo_t::set_cima(int cima)
{
  cima_ = cima;
}

int palo_t::get_numero_discos(void) const
{
  return(discos_.size());
}

int palo_t::get_disco(const int posicion) const
{
  if(posicion < 0 || posicion >= get_numero_discos())
  {
    std::cerr << "Error en get_disco con indice: " << cima_ << std::endl;
    exit (EXIT_FAILURE);
  }
  return(discos_[posicion]);
}

void palo_t::set_disco(int posicion, int disco)
{
  if(posicion < 0 || posicion >= get_numero_discos())
  {
    std::cerr << "Error en set_disco con indice: " << cima_ << std::endl;
    exit (EXIT_FAILURE);
  }
  discos_[posicion] = disco;
}

int palo_t::get_disco_cima(void) const
{
  if(get_cima() >= get_numero_discos())
  {
    std::cerr << "Error en get_disco_cima con cima: " << cima_ << std::endl;
    exit (EXIT_FAILURE);
  }
  if(get_cima() == -1)
    return(-1);
  if(get_cima() < -1)
  {
    std::cerr << "Error en get_disco_cima con cima: " << cima_ << std::endl;
    exit (EXIT_FAILURE);
  }
  return(discos_[get_cima()]);
}