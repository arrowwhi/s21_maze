#ifndef MAZE_SRC_LAB_GEN_H
#define MAZE_SRC_LAB_GEN_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

namespace s21 {

class Labyrinth {

  using solve_stack = std::stack<std::pair<int, int>>;
 private:
  int rows_;
  int cols_;
  bool** horisontal_matrix_;
  bool** vertical_matrix_;
  int** solve_way_;
  solve_stack solve_line_;
  std::vector<int> side_line_;
  int counter_ = 0;
  unsigned rand_ = time(nullptr);
  bool exit_ = true;
  

 public:
  Labyrinth();
  Labyrinth(int rows, int cols);
  ~Labyrinth();

  int GetRows() const noexcept;
  int GetCols() const noexcept;
  solve_stack GetSolve() const noexcept;
  void SetRowsCols(int rows, int cols);

  void Generate();
  int FromFile(std::string path);
  void PrintLab();
  void PrintSolve();
  int LabyrinthSolve(std::pair<int,int> start, std::pair<int,int> end);
  std::pair<bool, bool> GetCell(int i, int j) const noexcept;
  
 private:
  void FillEmptyValue();
  bool RandomNumber();
  void AssignUniqueSet();
  void AddingVerticalWalls(int row);
  void MergeSet(int index, int element);
  void AddingHorizontalWalls(int row);
  int CalculateUniqueSet(int element) const;
  void CheckedHorizontalWalls(int row);
  int CalculateHorizontalWalls(int element, int row) const;
  void PreparatingNewLine(int row);
  void AddingEndLine();
  void CheckedEndLine();

  void NextTurn(int i, int j);
  int GetWay(int x, int y);

  void CreateMatrix(bool*** matrix);
  void CreateMatrix(int*** matrix);
  void DeleteMatrix(bool*** matrix) noexcept;
};

}  // namespace s21

#endif  //   MAZE_SRC_LAB_GEN_H
