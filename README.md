# Advanced String Library

A lightweight C library for dynamic string manipulation, providing a robust set of functions to create, modify, and manage strings efficiently.

## Features

- **Dynamic String Structure:** Manage strings with dynamic sizing.
- **Comprehensive Functions:** Create, destroy, compare, search, trim, convert case, concatenate, replace, reverse, slice, copy, and split strings.
- **Ease of Integration:** Easily integrate into your projects by copying files or adding as a submodule.

## Installation

The Advanced String Library consists of two essential files located in the root directory:

- `ads_string.h`
- `ads_string.c`

You have two options to include the library in your project:

### 1. Copy the Files

Simply copy `ads_string.h` and `ads_string.c` into your project's directory and include them in your build process.

### 2. Add as a Submodule

Alternatively, you can add the Advanced String Library repository to your project as a git submodule.

```
git submodule add https://github.com/beyluta/advanced_string_library
```

## Example Usage

For documentation please refer to the `ads_string.h` header file. All functions, parameters, and expected outputs have been documented.

```c
#include "ads_string.h"

int main()
{
    // Creating the string
    ads_string *str = ads_create("Hello World");

    // Checking if the string contains the word "Hello"
    ads_string *check = ads_create("Hello");
    if (ads_includes(str, check) == 0)
    {
        printf("String contains the word %s\n", check->buffer);
    }

    // Freeing up memory
    ads_destroy(check)
    ads_destroy(str);
    return 0;
}
```

### Functions

#### `ads_string *ads_create(const char *const src)`

- Creates a new `ads_string`.
- **Parameters**:
  - `src`: C-Style char array (must be zero-terminated).
- **Returns**: Memory-allocated `ads_string` struct.
- **Notes**: Ensure `src` is zero-terminated.

#### `void ads_destroy(ads_string *src)`

- Destroys a previously created `ads_string` and frees memory.
- **Parameters**:
  - `src`: Source `ads_string` to be freed.

#### `char ads_char_at(ads_string *src, size_t pos)`

- Searches for a char at a given position.
- **Parameters**:
  - `src`: Source string.
  - `pos`: Position to look for the char.
- **Returns**: A single char at the specified location.

#### `int ads_char_code_at(ads_string *src, size_t pos)`

- Searches for a char code at a given position.
- **Parameters**:
  - `src`: Source string.
  - `pos`: Position to look for the char code.
- **Returns**: A single char code at the specified location.

#### `int ads_is_equal(ads_string *src, ads_string *target)`

- Compares two strings for equality.
- **Parameters**:
  - `src`: Source string.
  - `target`: Target string.
- **Returns**: `0` if equal, `1` otherwise.

#### `int ads_ends_with(ads_string *src, ads_string *target)`

- Checks whether a string ends with another string.
- **Parameters**:
  - `src`: Source string.
  - `target`: Target string.
- **Returns**: `0` if it ends with the target, `1` otherwise.

#### `int ads_includes(ads_string *src, ads_string *target)`

- Checks whether a string contains a substring.
- **Parameters**:
  - `src`: Source string.
  - `target`: Substring to search for.
- **Returns**: `0` if the substring is found, `1` otherwise.

#### `int ads_index_of(ads_string *src, ads_string *target)`

- Searches for the starting index of a substring.
- **Parameters**:
  - `src`: Source string.
  - `target`: Substring to find.
- **Returns**: Starting index on success, `-1` on failure.

#### `ads_string *ads_concat(ads_string *src, ads_string *target)`

- Concatenates two strings.
- **Parameters**:
  - `src`: Left string.
  - `target`: Right string.
- **Returns**: A concatenated `ads_string`.
- **Notes**: Free memory of `src` and `target` separately.

#### `ads_string *ads_trim_start(ads_string *src)`

- Removes leading whitespace from a string.
- **Parameters**:
  - `src`: String to trim.
- **Returns**: A trimmed `ads_string`.

#### `ads_string *ads_trim_end(ads_string *src)`

- Removes trailing whitespace from a string.
- **Parameters**:
  - `src`: String to trim.
- **Returns**: A trimmed `ads_string`.

#### `ads_string *ads_trim(ads_string *src)`

- Removes leading and trailing whitespace from a string.
- **Parameters**:
  - `src`: String to trim.
- **Returns**: A trimmed `ads_string`.

#### `ads_string *ads_to_lowercase(ads_string *src)`

- Converts a string to lowercase.
- **Parameters**:
  - `src`: String to convert.
- **Returns**: A lowercase `ads_string`.

#### `ads_string *ads_to_uppercase(ads_string *src)`

- Converts a string to uppercase.
- **Parameters**:
  - `src`: String to convert.
- **Returns**: An uppercase `ads_string`.

#### `ads_string *ads_replace(ads_string *src, ads_string *query, ads_string *target)`

- Replaces the first occurrence of a substring.
- **Parameters**:
  - `src`: Source string.
  - `query`: Substring to replace.
  - `target`: Replacement substring.
- **Returns**: A new `ads_string` with replacements.

#### `ads_string *ads_reverse(ads_string *src)`

- Reverses a string.
- **Parameters**:
  - `src`: String to reverse.
- **Returns**: A reversed `ads_string`.

#### `ads_string *ads_slice(ads_string *src, const size_t start, const size_t end)`

- Removes content between `start` and `end` indexes.
- **Parameters**:
  - `src`: Source string.
  - `start`: Start index.
  - `end`: End index.
- **Returns**: A new `ads_string` with the specified content removed.

#### `ads_string *ads_copy(ads_string *src, const size_t start, const size_t end)`

- Copies content between `start` and `end` indexes to a new string.
- **Parameters**:
  - `src`: Source string.
  - `start`: Start index.
  - `end`: End index.
- **Returns**: A copied `ads_string`.

#### `ads_string **ads_split(ads_string *src, const char target, size_t *len)`

- Splits a string into an array of strings by a delimiter.
- **Parameters**:
  - `src`: Source string.
  - `target`: Delimiter.
  - `len`: Size of the resulting array.
- **Returns**: An array of `ads_string` structs.
