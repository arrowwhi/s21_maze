#include "lab_gen.h"

using namespace s21;

Labyrinth::Labyrinth(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ <= 0 || cols_ <= 0)
    throw std::out_of_range(
        "Incorrect input, rows and cols size should be positive");
  CreateMatrix(&horisontal_matrix_);
  CreateMatrix(&vertical_matrix_);
}

Labyrinth::~Labyrinth() {
  if (horisontal_matrix_) DeleteMatrix(&horisontal_matrix_);
  if (vertical_matrix_) DeleteMatrix(&vertical_matrix_);
}

void Labyrinth::CreateMatrix(bool ***matrix) {
  *matrix = new bool *[rows_]();
  for (int i = 0; i < rows_; i++) {
    try {
      (*matrix)[i] = new bool[cols_]();
      for (int j = 0; j < cols_; j++) {
        (*matrix)[i][j] = false;
      }
    } catch (...) {
      for (int j = 0; j < i; j++) delete[] matrix[j];
      delete[] matrix;
      throw;
    }
  }
}

void Labyrinth::DeleteMatrix(bool ***matrix) noexcept {
  for (int i = 0; i < rows_; i++) {
    delete[] (*matrix)[i];
  }
  delete[] * matrix;
}

int Labyrinth::GetRows() const noexcept { return rows_; }

int Labyrinth::GetCols() const noexcept { return cols_; }

void Labyrinth::SetRowsCols(int rows, int cols) {
  if (rows <= 0 || cols <= 0)
    throw std::out_of_range("Incorrect input, size should be positive");
  if (rows != rows_ || cols != cols_) {
    DeleteMatrix(&horisontal_matrix_);
    DeleteMatrix(&vertical_matrix_);
    rows_ = rows;
    cols_ = cols;
    CreateMatrix(&horisontal_matrix_);
    CreateMatrix(&vertical_matrix_);
  }
}

void Labyrinth::PrintLab() {
  for (int i = 0; i < cols_; i++) std::cout << "__";
  std::cout << std::endl;
  for (int i = 0; i < rows_; i++) {
    std::cout << "|";
    for (int j = 0; j < cols_; j++) {
      if (horisontal_matrix_[i][j]) {
        std::cout << "_";
      } else {
        std::cout << " ";
      }
      if (vertical_matrix_[i][j]) {
        std::cout << "|";
      } else {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
}

void Labyrinth::Generate() {
  fillEmptyValue();
  for (int j = 0; j < rows_ - 1; j++) {
    assignUniqueSet();
    addingVerticalWalls(j);
    addingHorizontalWalls(j);
    checkedHorizontalWalls(j);
    preparatingNewLine(j);
  }
  addingEndLine();
}

void Labyrinth::fillEmptyValue() {
  for (int i = 0; i < cols_; i++) {
    sideLine_.push_back(0);
  }
}

void Labyrinth::assignUniqueSet() {
  for (int i = 0; i < cols_; i++) {
    if (sideLine_[i] == 0) {
      sideLine_[i] = counter_;
      counter_++;
    }
  }
}

void Labyrinth::addingVerticalWalls(int row) {
  for (int i = 0; i < cols_ - 1; i++) {
    bool choise = RandomNumber();
    if (!choise || sideLine_[i] == sideLine_[i + 1]) {
      vertical_matrix_[row][i] = true;
    } else {
      mergeSet(i, sideLine_[i]);
    }
  }
  vertical_matrix_[row][cols_ - 1] = true;
}

void Labyrinth::mergeSet(int index, int element) {
  int mutableSet = sideLine_[index + 1];
  for (int j = 0; j < cols_; j++) {
    if (sideLine_[j] == mutableSet) {
      sideLine_[j] = element;
    }
  }
}

void Labyrinth::addingHorizontalWalls(int row) {
  for (int i = 0; i < cols_; i++) {
    bool choise = RandomNumber();
    if (calculateUniqueSet(sideLine_[i]) != 1 && !choise) {
      horisontal_matrix_[row][i] = true;
    }
  }
}

int Labyrinth::calculateUniqueSet(int element) {
  int countUniqSet = 0;
  for (int i = 0; i < cols_; i++) {
    if (sideLine_[i] == element) {
      countUniqSet++;
    }
  }
  return countUniqSet;
}

void Labyrinth::checkedHorizontalWalls(int row) {
  for (int i = 0; i < cols_; i++) {
    if (calculateHorizontalWalls(sideLine_[i], row) == 0) {
      horisontal_matrix_[row][i] = true;
    }
  }
}

int Labyrinth::calculateHorizontalWalls(int element, int row) {
  int countHorizontalWalls = 0;
  for (int i = 0; i < cols_; i++) {
    if (sideLine_[i] == element && horisontal_matrix_[row][i] == false) {
      countHorizontalWalls++;
    }
  }
  return countHorizontalWalls;
}

void Labyrinth::preparatingNewLine(int row) {
  for (int i = 0; i < cols_; i++) {
    if (horisontal_matrix_[row][i] == true) {
      sideLine_[i] = 0;
    }
  }
}

void Labyrinth::addingEndLine() {
  assignUniqueSet();
  addingVerticalWalls(rows_ - 1);
  checkedEndLine();
}

void Labyrinth::checkedEndLine() {
  for (int i = 0; i < cols_ - 1; i++) {
    if (sideLine_[i] != sideLine_[i + 1]) {
      vertical_matrix_[rows_ - 1][i] = false;
      mergeSet(i, sideLine_[i]);
    }
    horisontal_matrix_[rows_ - 1][i] = true;
  }
  horisontal_matrix_[rows_ - 1][cols_ - 1] = true;
}

bool Labyrinth::RandomNumber() {
  srand((unsigned)rand_);
  rand_ = rand();
  return rand_ % 3;
}

int Labyrinth::FromFile(std::string path) {
  int n = 20, num = -1;
  char *buff = new char[20];
  std::ifstream file_in(path);
  if (!file_in.is_open()) return -1;
  if (file_in.eof()) return -1;
  file_in.getline(buff, 20, ' ');
  int rows = atoi(buff);

  if (file_in.eof()) return -1;
  file_in.getline(buff, 20, '\n');
  int cols = atoi(buff);
  SetRowsCols(rows, cols);
  std::cout << rows_ << cols_ << std::endl;

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_ - 1; j++) {
      if (file_in.eof()) return -1;
      file_in.getline(buff, 25, ' ');

      std::cout << buff << std::endl;
      num = atoi(buff);
      if (num != 1 && num != 0) return -1;
      vertical_matrix_[i][j] = num;
      num = -1;
    }
    file_in.getline(buff, 25, '\n');
    std::cout << buff << std::endl;
    num = atoi(buff);
    if (num != 1 && num != 0) return -1;
    vertical_matrix_[i][cols_ - 1] = num;
    num = -1;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_ - 1; j++) {
      if (file_in.eof()) return -1;
      file_in.getline(buff, 8, ' ');
      num = atoi(buff);
      if (num != 1 && num != 0) return -1;
      horisontal_matrix_[i][j] = num;
    }

    file_in.getline(buff, 25, '\n');
    std::cout << buff << std::endl;
    num = atoi(buff);
    if (num != 1 && num != 0) return -1;
    horisontal_matrix_[i][cols_ - 1] = num;
    num = -1;
  }

  return 0;
}