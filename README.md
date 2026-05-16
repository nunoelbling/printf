*This project was developed as part of the 42 curriculum by nuelblin*

# ft_printf

## Description

**ft_printf** is a custom re-implementation of the standard C `printf` function, built from scratch without relying on it. The goal is to understand how variadic functions work in C and to reproduce the core formatting behaviour of `printf` using only low-level write operations.

The function parses a format string character by character and, whenever it encounters a `%` conversion specifier, retrieves the corresponding argument from the variadic list and prints it in the appropriate format. The total number of characters written is accumulated and returned, mirroring the real `printf`.

**Supported conversion specifiers:**

| Specifier | Output |
| :--- | :--- |
| `%c` | Single character |
| `%s` | String (`(null)` if pointer is NULL) |
| `%d` | Signed decimal integer |
| `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal (lowercase) |
| `%X` | Unsigned hexadecimal (uppercase) |
| `%p` | Pointer address (`(nil)` if NULL) |
| `%%` | Literal `%` character |

## Instructions

### Compilation

Clone the repository and run `make` to compile the library:

## Resources

Youtube.

### AI Usage

AI was used during this project for the following purposes:

- **Concept clarification:** understanding edge case behaviour such as `%p` with a NULL pointer, the 64-bit truncation issue with pointer addresses, and the exact return value semantics of `printf`.

AI was used to explain the struct and why the printf returns the lenght, it was also used to format the README file.

---