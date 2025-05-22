[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/ZlJyXC1z)

# Projekt Świat
Bartosz Kąkol

## Zmiany
- **Ogólnie**
  - `CMakeLists.txt` do ułatwienia kompilacji. 
  - Dodano `const` tam gdzie to możliwe.
  - Przeniesiono implementacje konstruktorów z plików `.h` do plików `.cpp`.
  - Poprawiono skrótową składnię `for` i `if` niewykorzystującą klamer - jest nieczytelna, szczególnie przy nestowaniu.
- `World`
  - Zmiana `push_back` na `emplace_back` w celu optymalizacji dodawania obiektów do wektora.
  - `makeTurn` używa biblioteki `random` do generowania liczb losowych, zamiast przestarzałego `srand`/`rand`.
- `Organism`
  - `species` zostało usunięte na rzecz `sign`.
