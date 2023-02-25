#include "lab_gen.h"

using namespace s21;

using solve_stack = std::stack<std::pair<int, int>>;

Labyrinth::Labyrinth() : rows_(0), cols_(0) {}

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
      for (int j = 0; j < i; j++)
          delete[] matrix[j];
      delete[] matrix;
        throw;
    }

  }
}

void Labyrinth::CreateMatrix(int ***matrix) {
  *matrix = new int *[rows_]();
  for (int i = 0; i < rows_; i++) {
    try {
      (*matrix)[i] = new int[cols_]();
      for (int j = 0; j < cols_; j++) {
        (*matrix)[i][j] = 0;
      }
    } catch (...) {
      for (int j = 0; j < i;j++) {
          delete[] matrix[j];
      }
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
    if (horisontal_matrix_){
      DeleteMatrix(&horisontal_matrix_);
    }
    if (vertical_matrix_) {
      DeleteMatrix(&vertical_matrix_);
    }
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
  FillEmptyValue();
  counter_=1;
  for (int j = 0; j < rows_ - 1; j++) {
    AssignUniqueSet();
    AddingVerticalWalls(j);
    AddingHorizontalWalls(j);
    CheckedHorizontalWalls(j);
    PreparatingNewLine(j);
  }
  AddingEndLine();
}

void Labyrinth::FillEmptyValue() {
  for (int i = 0; i < cols_; i++) {
    side_line_.push_back(0);
  }
}


void Labyrinth::AssignUniqueSet() {
  for (int i = 0; i < cols_; i++) {
    if (side_line_[i] == 0) {
      side_line_[i] = counter_;
      counter_++;
    }
  }
}

void Labyrinth::AddingVerticalWalls(int row) {
  for (int i = 0; i < cols_ - 1; i++) {
    bool choise = RandomNumber();
    if (!choise || side_line_[i] == side_line_[i + 1]) {
      vertical_matrix_[row][i] = true;
    } else {
      MergeSet(i, side_line_[i]);
    }
  }
  vertical_matrix_[row][cols_ - 1] = true;
}

void Labyrinth::MergeSet(int index, int element) {
  int mutableSet = side_line_[index + 1];
  for (int j = index; j < cols_; j++) {
    if (side_line_[j] == mutableSet) {
      side_line_[j] = element;
    }
  }
}

void Labyrinth::PreparatingNewLine(int row) {
  for (int i = 0; i < cols_; i++) {
    if (horisontal_matrix_[row][i]) {
      side_line_[i] = 0;
    }
  }
}

void Labyrinth::AddingEndLine() {
  AssignUniqueSet();
  AddingVerticalWalls(rows_ - 1);
  CheckedEndLine();
}

void Labyrinth::CheckedEndLine() {
  for (int i = 0; i < cols_ - 1; i++) {
    if (side_line_[i] != side_line_[i + 1]) {
      vertical_matrix_[rows_ - 1][i] = false;
      MergeSet(i, side_line_[i]);
    }
    horisontal_matrix_[rows_ - 1][i] = true;
  }
  horisontal_matrix_[rows_ - 1][cols_ - 1] = true;
}


void Labyrinth::AddingHorizontalWalls(int row) {
  for (int i = 0; i < cols_; i++) {
    bool choise = RandomNumber();
    if (CalculateUniqueSet(side_line_[i]) > 1 && !choise) {
      horisontal_matrix_[row][i] = true;
    }
  }
}

int Labyrinth::CalculateUniqueSet(int element) const {
  int countUniqSet = 0;
  for (int i = 0; i < cols_; i++) {
    if (side_line_[i] == element) {
      countUniqSet++;
    }
  }
  return countUniqSet;
}

void Labyrinth::CheckedHorizontalWalls(int row) {
  for (int i = 0; i < cols_; i++) {
    if (CalculateHorizontalWalls(side_line_[i], row) == 0) {
      horisontal_matrix_[row][i] = false;
    }
  }
}

int Labyrinth::CalculateHorizontalWalls(int element, int row) const {
  int countHorizontalWalls = 0;
  for (int i = 0; i < cols_; i++) {
    if (side_line_[i] == element && !horisontal_matrix_[row][i]) {
      countHorizontalWalls++;
    }
  }
  return countHorizontalWalls;
}



bool Labyrinth::RandomNumber() {
  srand((unsigned)rand_);
  rand_ = rand();
  return rand_ % 3;
}

int Labyrinth::FromFile(std::string path) {
  int num;
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

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_ - 1; j++) {
      if (file_in.eof()) return -1;
      file_in.getline(buff, 25, ' ');

      num = atoi(buff);
      if (num != 1 && num != 0) return -1;
      vertical_matrix_[i][j] = num;
      num = -1;
    }
    file_in.getline(buff, 25, '\n');
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
    num = atoi(buff);
    if (num != 1 && num != 0) return -1;
    horisontal_matrix_[i][cols_ - 1] = num;
    num = -1;
  }

  return 0;
}

int Labyrinth::LabyrinthSolve(std::pair<int,int> start, std::pair<int,int> end) {
  counter_ = 1;
  exit_ = true;
  CreateMatrix(&solve_way_);
  solve_way_[start.first][start.second] = counter_;
  while (!solve_way_[end.first][end.second] && exit_) {
    exit_=false;
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (solve_way_[i][j] == counter_) {
          exit_=true;
          NextTurn(i,j);
        }
      }
    }
    ++counter_;
  }
  if (!exit_) {
    return -1;
  } else {
    GetWay(end.first, end.second);
    return 0;
  }
}

void Labyrinth::NextTurn(int i, int j) {
  if (j>0 && !vertical_matrix_[i][j-1] && !solve_way_[i][j-1]) {
    solve_way_[i][j-1] = counter_+1;
    exit_ = true;
  }
  if (j<rows_-1 && !vertical_matrix_[i][j] && !solve_way_[i][j+1]) {
    solve_way_[i][j+1] = counter_+1;
    exit_ = true;
  }
  if (i>0 && !horisontal_matrix_[i-1][j] && !solve_way_[i-1][j]) {
    solve_way_[i-1][j] = counter_+1;
    exit_ = true;
  }
  if (i< cols_-1 && !horisontal_matrix_[i][j] && !solve_way_[i+1][j]) {
    solve_way_[i+1][j] = counter_+1;
    exit_ = true;
  }
}



void Labyrinth::PrintSolve() {
  for(int i = 0; i < rows_; i++) {
    for(int j = 0; j < cols_; j++) {
      std::cout << "\t" << solve_way_[i][j];
    }
    std::cout << std::endl;
  }
}

int Labyrinth::GetWay(int x, int y) {
  int cou = 1;
  ++counter_;
  if (!solve_way_[x][y]) return -1;
  solve_way_[x][y]+=1;
  solve_line_ = solve_stack();
  while (cou != counter_) {
    solve_line_.push(std::make_pair(x,y));
    solve_way_[x][y] = -1;
    if (x < rows_-1 && solve_way_[x+1][y]+cou==counter_) {
      x = x+1;
    } else if (x>0 && solve_way_[x-1][y]+cou==counter_) {
      x = x-1;
    } else if (y < cols_-1 && solve_way_[x][y+1]+cou == counter_) {
      y = y+1;
    } else if (y > 0 && solve_way_[x][y-1]+cou == counter_) {
      y = y-1;
    }
    solve_way_[x][y]+=cou;
    solve_line_.push(std::make_pair(x,y));
    cou++;
  }
  return 0;
}

const solve_stack &Labyrinth::GetSolve() const noexcept {
  return solve_line_;
}

std::pair<bool, bool> Labyrinth::GetCell(int i, int j) const noexcept {
  return std::make_pair(horisontal_matrix_[i][j], vertical_matrix_[i][j]);
}
