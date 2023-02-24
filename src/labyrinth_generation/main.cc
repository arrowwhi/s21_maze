#include "lab_gen.h"

using namespace s21;

int main() {
  Labyrinth l(10, 10);
  // std::cout << l.GetCols() << " " << l.GetRows() << std::endl;
  l.Generate();
  // int err = l.FromFile("test.txt");
  // std::cout << err << std::endl;
  l.PrintLab();
  int check = l.LabyrinthSolve(std::make_pair(0,0), std::make_pair(6,6));
  if (check==-1) {
  std::cout << "ТЫ НЕ ПРОЙДЕШЬ" << std::endl;
  } else {
    l.PrintSolve();
  }
  return 0;
}