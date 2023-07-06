/*https://aceptaelreto.com/problem/statement.php?id=137*/
#include <iostream> 
#define MAX_SIZE 128

int table[128][128];
int sizes[128];

int get_table(int i, int j, int table_size) {
  if (i < 0 || i >= table_size) return 0; 
  if (j < 0 || j >= table_size) return 0; 
  return table[i][j];
}

int delete_boat(int i, int j, int table_size) {
  int size = 1;
  if (!get_table(i + 1, j, table_size) && !get_table(i, j + 1, table_size)) {
    return !(get_table(i + 1, j + 1, table_size) || get_table(i - 1, j + 1, table_size) || get_table(i + 1, j - 1, table_size) || get_table(i - 1, j - 1, table_size)); 
  }
  if (get_table(i + 1, j, table_size) && get_table(i, j + 1, table_size)) return 0;
  if (get_table(i + 1, j, table_size)) { // down 
    if (get_table(i - 1, j + 1, table_size) || get_table(i - 1, j - 1, table_size)) return 0;
    while (get_table(++i, j, table_size)) {
      table[i - 1][j] = 0;
      if (get_table(i, j - 1, table_size)) return 0;
      if (get_table(i, j + 1, table_size)) return 0;
      ++size;
    }
    table[i - 1][j] = 0;
    if (get_table(i, j + 1, table_size) || get_table(i, j - 1, table_size)) return 0;
  } else if (get_table(i, j + 1, table_size)) { // right 
    if (get_table(i - 1, j - 1, table_size) || get_table(i + 1, j - 1, table_size)) return 0;
    while (get_table(i, ++j, table_size)) {
      table[i][j - 1] = 0;
      if (get_table(i - 1, j, table_size)) return 0;
      if (get_table(i + 1, j, table_size)) return 0;
      ++size;
    }
    table[i][j - 1] = 0;
    if (get_table(i + 1, j, table_size) || get_table(i - 1, j, table_size)) return 0;
  }
  return size;
}

bool ev_table(int barcos, int table_size) {
  for (int i = 0; i < table_size; ++i) {
    for (int j = 0; j < table_size; ++j) {
      if (table[i][j] == 1) {
        int size_boat = delete_boat(i, j, table_size);
        if (size_boat != 0 && sizes[size_boat - 1] > 0) {
          sizes[size_boat - 1]--;
        } else return false;
      }
    }
  }

  for (int i = 0; i < MAX_SIZE; ++i) {
    if (sizes[i] > 0) return false;
  }
  
  return true; 
}

int main() {
  std::cin.tie(NULL);
  std::ios_base::sync_with_stdio(false);
  int barcos, table_size; 
  std::cin >> barcos; 
  while (barcos > 0) {
    for (int i = 0; i < MAX_SIZE; i++) sizes[i] = 0;
    for (int i = 0; i < barcos; ++i) {
      int size_now; 
      std::cin >> size_now; 
      sizes[size_now - 1]++;
    }
    
    std::cin >> table_size; 
    
    for (int i = 0; i < table_size; ++i) {
      for (int j = 0; j < table_size; ++j) {
        int agua_o_barco; 
        std::cin >> agua_o_barco; 
        table[i][j] = agua_o_barco;
      }
    }
    
    if (ev_table(barcos, table_size)) std::cout << "SI\n";
    else std::cout << "NO\n"; 
    std::cin >> barcos;
  }
  
  return 0;
}