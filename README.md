# 🧮 Custom Vector and Set Templates in C++

This project demonstrates the manual implementation of two essential data structures using C++ templates:

- **Vector<T>** – a dynamic array class (similar to `std::vector`)
- **Set<T>** – a mathematical set class (similar to `std::set`) that avoids duplicates and supports set operations

No STL containers are used in the core logic — everything is built from scratch to help understand the inner workings of such data structures.

---

## 🚀 Features

### ✅ `Vector<T>`
- Dynamic resizing with manual memory management
- Supports:
  - `push_back`, `pop_back`, `insert`, `erase`
  - `at()`, `[]` operator with bounds checking
  - `size()`, `empty()`, and iterators (`begin()`, `end()`)
- Custom `==` and `<<` operator overloads

### ✅ `Set<T>`
- Built on top of `Vector<T>`
- Ensures uniqueness of elements
- Supports:
  - `insert()`, `erase()`, `find()`, `size()`, `empty()`
  - Operator overloading for:
    - `+` → Union
    - `-` → Difference
    - `*` → Intersection
    - `^` → Symmetric Difference
    - `==`, `+=`, `<<`

---

## 📁 File Structure
.
├── main.cpp           # Test file demonstrating usage of Vector and Set
├── Vector.h           # Template definition of the custom Vector<T> class
├── Set.h              # Template definition of the custom Set<T> class using Vector<T>
├── README.md          # Project documentation (this file)

