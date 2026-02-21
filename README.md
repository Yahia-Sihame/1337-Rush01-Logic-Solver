# 1337 Rush01 - Logic Solver

## 📌 Project Overview
This project is a logic-based solver designed to crack a 4x4 grid puzzle, similar to Sudoku but with a "skyscraper" twist. Given specific visibility constraints from four different points of view (Top, Bottom, Left, and Right), the program places boxes of heights 1 to 4 in each cell.

## ⚙️ Rules & Logic
- **Grid Size:** 4x4 grid.
- **Constraints:** Every row and column must contain each number from 1 to 4 exactly once.
- **Visibility:** The numbers outside the grid represent how many "skyscrapers" are visible from that direction.A taller building hides a shorter one behind it.
- **Algorithm:** Developed using a **Backtracking** approach to explore possible solutions efficiently.

## 🚀 How to Run
[cite_start]The program is written in **C** and complies with the following flags: `-Wall -Wextra -Werror`.

1. **Compile:**
   ```bash
   cc -Wall -Wextra -Werror -o rush01 *.c
2. Execute:
Provide 16 numbers (1-4) as a single string argument representing the views:
  ./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

🛠️ Technical Constraints
Only write, malloc, and free are used.

Error handling: Displays "Error" for invalid inputs or if no solution is found.

Disclaimer: This repository is for educational purposes only. If you are a student at 42 Network, please respect the peer-learning rules and avoid copying code.
<img width="279" height="603" alt="image" src="https://github.com/user-attachments/assets/e9367daf-2a22-4ac4-968f-fae282890dc2" />
