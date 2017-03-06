#include "../include/hanoi_ciclico_t.hpp"

void usage(void)
{
  std::cout << "usage: ./bin/hanoi_tower num_discos debug [cyclic]" << std::endl;
  
}

int main(int argc, char *argv[])
{
  bool ciclico = 0;
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
  hanoi->resolver(argv[2][0] == '1');
  std::cout << "Movimientos necesarios: " << hanoi->get_numero_movimientos() <<std::endl;
}