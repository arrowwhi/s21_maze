#ifndef MAZE_SRC_LAB_GEN_H
#define MAZE_SRC_LAB_GEN_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

namespace s21 {

class Maze {

  using solve_stack = std::stack<std::pair<int, int>>;
 private:
  int rows_;
  int cols_;
  bool** horisontal_matrix_{};
  bool** vertical_matrix_{};
  int** solve_way_{};
  solve_stack solve_line_;
  std::vector<int> side_line_;
  int counter_ = 0;
  unsigned rand_ = time(nullptr);
  bool exit_ = true;
  

 public:
  Maze();
  Maze(int rows, int cols);
  ~Maze();

  /**
   * @brief Геттер строк
   * @return 
   */
  int GetRows() const noexcept;

  /**
   * @brief Геттер столбцов
   *
   */
  int GetCols() const noexcept;

  /**
   * @brief Возвращает стек из решенного лабиринта
   *
   */
  const solve_stack &GetSolve() const noexcept;

  /**
   * @brief Изменяет размер лабиринта, вместе с этим перерисовывает его
   * 
   * @param rows количество строк
   * @param cols количество столбцов
   */
  void SetRowsCols(int rows, int cols);

  /**
   * @brief Генерирует случайный лабиринт с выставленными размерами
   *
   */
  void Generate();

  /**
   * @brief Загружает лабиринт из файла
   * 
   * @param path путь до файла
   * @return int 0 - успешно
   *
   */
  int FromFile(const std::string& path);

  /**
   * @brief выводит лабиринт в консоль
   */
  void PrintLab();

  /**
   * @brief выводит решение лабиринта в консоль
   */
  void PrintSolve();

  /**
   * @brief Находит решение лабиринта
   * @return int 0 - успешно, иначе нет
   *
   */
  int MazeSolve(std::pair<int,int> start, std::pair<int,int> end);
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

  void CreateMatrix(bool*** matrix) const;
  void CreateMatrix(int*** matrix) const;
  void DeleteMatrix(bool*** matrix) const noexcept;
};

}  // namespace s21

#endif  //   MAZE_SRC_LAB_GEN_H