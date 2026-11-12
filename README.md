# CPP05-09

Advanced C++ exercises from École 42's cursus, covering core language features and the Standard Template Library.

## Overview

This project contains five C++ modules exploring essential C++ concepts:

- **CPP05**: Exception handling, custom exceptions, and class design patterns (Bureaucrat, Form)
- **CPP06**: Type casting, casting operators, and runtime type information
- **CPP07**: Generic programming with templates (function templates, class templates)
- **CPP08**: Containers and algorithms from the Standard Template Library (STL)
- **CPP09**: STL containers, algorithms, and practical implementations

## Language

- **C++98** – Compatible with the C++98 standard
- Strict École 42 norm compliance (no external libraries except STL)

## Building

Each exercise can be built independently:

```bash
cd Cpp0X/exYY
make
./programName
```

Clean all builds:

```bash
make clean      # Remove object files
make fclean     # Remove executables
make re         # Rebuild
```

## Key Concepts

- **Exception handling**: Custom exception classes, try-catch mechanisms
- **Operator overloading**: << (stream insertion), comparison operators
- **Templates**: Function and class templates, template specialization
- **STL**: Vectors, lists, deques, iterators, algorithms (find, sort, etc.)
- **Object-oriented design**: Inheritance, polymorphism, abstract classes

## Notes

All code follows École 42 guidelines:
- No C++11 or later features
- Memory management without std::unique_ptr or std::shared_ptr
- No external dependencies
