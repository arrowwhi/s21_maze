#ifndef MAZE_SRC_LAB_GEN_H
#define MAZE_SRC_LAB_GEN_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace s21 {

class Labyrinth {
 private:
  int rows_;
  int cols_;
  bool** horisontal_matrix_;
  bool** vertical_matrix_;
  std::vector<int> sideLine_;
  int counter_ = 0;
  unsigned rand_ = time(nullptr);

 public:
  Labyrinth() = delete;
  Labyrinth(int rows, int cols);
  ~Labyrinth();

  int GetRows() const noexcept;
  int GetCols() const noexcept;
  void SetRowsCols(int rows, int cols);

  void Generate();
  int FromFile(std::string path);
  void PrintLab();

 private:
  void fillEmptyValue();
  void assignUniqueSet();
  void addingVerticalWalls(int row);
  void mergeSet(int index, int element);
  void addingHorizontalWalls(int row);
  int calculateUniqueSet(int element);
  void checkedHorizontalWalls(int row);
  int calculateHorizontalWalls(int element, int row);
  void preparatingNewLine(int row);
  void addingEndLine();
  void checkedEndLine();
  bool RandomNumber();

  void CreateMatrix(bool*** matrix);
  void DeleteMatrix(bool*** matrix) noexcept;
};

}  // namespace s21

#endif  //   MAZE_SRC_LAB_GEN_H
