#ifndef ADS_STRING_H
#define ADS_STRING_H

#include <string.h>

#define EXIT_OOB -1
#define WHITESPACE_CHAR ' '

/**
 * @struct ads_string
 * @brief String structure representing a dynamic string
 *
 */
typedef struct ads_string
{
    int size;     /** @brief Size of chars in the buffer */
    char *buffer; /** @brief Buffer containing chars that make up the string */
} ads_string;

/**
 * @brief Creates a news ads_string
 * @param src C-Style char array (must be zero-termined)
 * @return Memory allocated ads_string struct
 * @note Ensure that the `src` parameter is zero-terminal
 */
ads_string *ads_create(const char *const src);

/**
 * @brief Destroys a previously created ads_string and frees up memory
 * @param src Source `ads_string` to be freed
 */
void ads_destroy(ads_string *src);

/**
 * @brief Searches for a char at `pos`
 * @param src Source string being searched
 * @param pos Position to look for the char
 * @return A single char at the specified location
 */
char ads_char_at(ads_string *src, size_t pos);

/**
 * @brief Searches for a char code at `pos`
 * @param src Source string being searched
 * @param pos Position to look for the char code
 * @return A single char code at the specified location
 */
int ads_char_code_at(ads_string *src, size_t pos);

/**
 * @brief Compares whether the `src` and `target` are equal
 * @param src Source string to be compared
 * @param target Target string to be compared
 * @return
 *  - On success: `0`
 *  - On failure: `1`
 */
int ads_is_equal(ads_string *src, ads_string *target);

/**
 * @brief Checks whether a string ends with another
 * @param src Source string to be checked against
 * @param target Target string being searched at the end of `src`
 * @return
 *  - On success: `0`
 *  - On failure: `1`
 */
int ads_ends_with(ads_string *src, ads_string *target);

/**
 * @brief Checks whether a string contains a substring
 * @param src Source string to be checked against
 * @param target Target string being searched inside of `src`
 * @return
 *  - On success: `0`
 *  - On failure: `1`
 */
int ads_includes(ads_string *src, ads_string *target);

/**
 * @brief Searches for the starting index of a substring
 * @param src Source string
 * @param target Target string
 * @return
 *  - On success: The starting index of the `target` substring
 *  - On failure: `-1`
 */
int ads_index_of(ads_string *src, ads_string *target);

/**
 * @brief Joins two ads_string structs together
 * @param src Left ads_string struct
 * @param target Right ads_string struct
 * @return A single concatenated ads_string struct
 * @note Memory of `src` and `target` must be freed separately. Use `ads_destroy(...)`
 */
ads_string *ads_concat(ads_string *src, ads_string *target);

/**
 * @brief Trims the start of a string (removes whitespaces)
 * @param src The string to removed the whitespaces from
 * @return The same content as `src` but without the whitespaces
 * @note Memory of `src` must be freed separately. Use `ads_destroy(...)`
 */
ads_string *ads_trim_start(ads_string *src);

/**
 * @brief Trims the end of a string (removes whitespaces)
 * @param src The string to removed the whitespaces from
 * @return The same content as `src` but without the whitespaces
 * @note Memory of `src` must be freed separately. Use `ads_destroy(...)`
 */
ads_string *ads_trim_end(ads_string *src);

/**
 * @brief Trims the start and end of a string (removes whitespaces)
 * @param src The string to removed the whitespaces from
 * @return The same content as `src` but without the whitespaces
 * @note Memory of `src` must be freed separately. Use `ads_destroy(...)`
 */
ads_string *ads_trim(ads_string *src);

/**
 * @brief Transforms the entire content of the string to lowercase
 * @param src The string to be transformed to lowercase
 * @return A new ads_string struct containing a lowercase string
 * @note Memory of `src` must be freed separately. Use `ads_destroy(...)`
 */
ads_string *ads_to_lowercase(ads_string *src);

/**
 * @brief Transforms the entire content of the string to uppercase
 * @param src The string to be transformed to uppercase
 * @return A new ads_string struct containing a uppercase string
 * @note Memory of `src` must be freed separately. Use `ads_destroy(...)`
 */
ads_string *ads_to_uppercase(ads_string *src);

/**
 * @brief Replaces the first occurence of a substring by another substring
 * @param src Source string to be queried against
 * @param query Substring to be replaced
 * @param target Substring to be taking the place of the old one
 * @return A new ads_string struct containing the replaced results
 * @note Memory of `src`, `query`, and `target` must be freed separately. Use `ads_destroy(...)`
 */
ads_string *ads_replace(ads_string *src, ads_string *query, ads_string *target);

/**
 * @brief Reverses a string
 * @param src The string to be reversed
 * @return A new ads_string struct containing a reversed string
 * @note Memory of `src` must be freed separately. Use `ads_destroy(...)`
 */
ads_string *ads_reverse(ads_string *src);

/**
 * @brief Removes content from a string by `start` and `end` index
 * @param src The string that will be searched and being removed from
 * @param start Start index of the removal
 * @param end End index of the removal
 * @return A new ads_string struct containing everything in `src->buffer` but the content between the indexes
 * @note Memory of `src` must be freed separately. Use `ads_destroy(...)`
 */
ads_string *ads_slice(ads_string *src, const size_t start, const size_t end);

/**
 * @brief Copies the content between `start` and `end` to a new ads_string struct
 * @param src String that will be copied from
 * @param start Starting index of the copy operation
 * @param end End index of the copy operation
 * @return A new ads_string struct containing only the chars betweeb `start` and `end`
 * @note Memory of `src` must be freed separately. Use `ads_destroy(...)`
 */
ads_string *ads_copy(ads_string *src, const size_t start, const size_t end);

/**
 * @brief Split the string into an array of strings by a delimiter
 * @param src String that will be split
 * @param target Delimiter that will be used to split the string
 * @param len Size of the new array of ads_string structs
 * @return An array of ads_string structs containing the split results
 * @note Memory of `src` must be freed separately. Use `ads_destroy(...)`
 */
ads_string **ads_split(ads_string *src, const char target, size_t *len);

#endif