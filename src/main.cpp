#include "../include/hanoi_ciclico_t.hpp"
#include <ctime>
void usage(void)
{
  std::cout << "usage: ./bin/hanoi_tower num_discos debug [cyclic]" << std::endl;
  
}

int main(int argc, char *argv[])
{
  bool ciclico = 0;
  unsigned tiempo_inicial, tiempo_final;
  double tiempo_ejecucion;
  hanoi_t* hanoi;
  if(argc < 3)
  {
    usage();
    return(1);
  }
  if(argc == 4 && argv[3][0] == '1')
      ciclico = 1;
  if(ciclico)
    hanoi = new hanoi_ciclico_t(atoi(argv[1]));
  else
    hanoi = new hanoi_t(atoi(argv[1]));
  
  std::cout << *hanoi <<std::endl;
  
  tiempo_inicial = clock();
  hanoi->resolver(argv[2][0] == '1');
  tiempo_final = clock();
  
  tiempo_ejecucion = (double (tiempo_final - tiempo_inicial) / CLOCKS_PER_SEC);
  
  std::cout << "Movimientos necesarios: " << hanoi->get_numero_movimientos() <<std::endl;
  std::cout << "Tiempo de ejecución: " << tiempo_ejecucion << std::endl;
}