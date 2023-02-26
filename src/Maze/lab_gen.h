#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

#include "../Helpers/Helpers.h"

namespace s21 {

/*!
	\brief Класс, создающий и обрабатывающий лабиринты.
*/
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

  /**
   * @brief Геттер строк
   * @return количество строк
   */
  int GetRows() const noexcept;

  /**
   * @brief Геттер столбцов
   * @return int количество столбцов
   */
  int GetCols() const noexcept;

  /**
   * @brief Геттер решения
   * @return solve_stack стек из решенного лабиринта
   */
  const solve_stack &GetSolve() const noexcept;

  /**
   * @brief Изменяет размер лабиринта, вместе с этим перерисовывает его
   * 
   * @param[in] rows количество строк
   * @param[in] cols количество столбцов
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
   * @return int 0 - успешно,
   * @return остальные ответы - ошибка
   *
   */
  int FromFile(std::string path);

  /**
   * @brief выводит лабиринт в консоль
   */
  void PrintLab();

  /**
   * @brief выводит решение лабиринта в консоль
   */
  void PrintSolve();

  /**
   * @brief выводит решение лабиринта в консоль
   * @return int 0 - успешно,
   * @return остальные ответы - ошибка
   */
  int LabyrinthSolve(std::pair<int,int> start, std::pair<int,int> end);

  /**
   * @brief Получает вертикальную и горизонтальную стену у ячейки
   * @param[in] i строка ячейки
   * @param[in] j столбец ячейки
   * @return пара<граница снизу, граница справа>
   */
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