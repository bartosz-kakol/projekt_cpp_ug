[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/ZlJyXC1z)

# Projekt Świat
Bartosz Kąkol

## Zmiany względem starego kodu
Lista nie uwzględnia nowych funkcjonalności.
- **Ogólnie**
  - `CMakeLists.txt` do ułatwienia kompilacji. 
  - Dodano `const` **tam gdzie to możliwe**.
  - Przeniesiono **implementacje konstruktorów** z plików `.h` do plików `.cpp`.
  - Poprawiono **skrótową składnię** `for` i `if` **niewykorzystującą klamer** - jest nieczytelna, szczególnie przy nestowaniu.
  - **Cast'y w stylu C** zostały zmienione na `static_cast` lub inny nowoczesny zamiennik.
  - W wielu miejscach używane jest `std::unique_ptr` aby zapewnić **większe bezpieczeństwo pamięciowe**.
  - Klasy `Organism`, `Animal` i `Plant` są teraz **częściowo lub całkowicie abstrakcyjne**.
- `World`
  - Zmiana `push_back` na `emplace_back` w celu **optymalizacji dodawania obiektów do wektora**.
  - `makeTurn` używa biblioteki `random` do **generowania liczb losowych**, zamiast przestarzałego `srand`/`rand`.
- `Organism`
  - `species` zostało **usunięte** na rzecz `sign`.
  - Każdy organizm **posiada swoje numeryczne ID** w polu `id` dla łatwiejszej identyfikacji.
