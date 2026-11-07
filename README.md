# C Command Prompt Calculator

A fast, lightweight, and interactive command-line calculator written in C.

## Features

* Basic arithmetic operations: Addition (`+`), Subtraction (`-`), Multiplication (`*`), and Division (`/`)
* Support for floating-point calculations
* Clean command-line interface with input validation
* Error handling (e.g., division by zero prevention)

## Prerequisites

You need a C compiler installed on your system:
* **Windows:** MinGW, GCC, or Visual Studio Developer Command Prompt
* **Linux / macOS:** GCC or Clang

## Getting Started

### 1. Clone the repository
```bash
git clone https://github.com
cd c-calculator
```

### 2. Compile the code
Run the following command in your terminal or command prompt:

```bash
gcc -o calculator main.c
```

*(Note: Replace `main.c` with the name of your source code file if it is named differently).*

### 3. Run the program

* **Linux / macOS:**
  ```bash
  ./calculator
  ```
* **Windows (Command Prompt):**
  ```cmd
  calculator.exe
  ```

## Usage Example

```text
=== Simple C Calculator ===
Enter calculation (e.g., 5 + 3 or 10 / 2): 12 * 4
Result: 48.00
```

## Project Structure

```text
├── main.c          # Core calculator logic and CLI loop
├── README.md       # Project documentation
└── Makefile        # (Optional) Build automation script
```

## Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the [issues page](https://github.com).

## License

This project is open-source and available under the [MIT License](LICENSE).
