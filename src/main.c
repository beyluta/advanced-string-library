#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../ads_string.h"

int main()
{
    ads_string *string = ads_create("Hello World");
    assert(strcmp(string->buffer, "Hello World") == 0);
    printf("assert ads_create passed ✔\n");

    assert(ads_char_at(string, 0) == 'H');
    printf("assert ads_char_at passed ✔\n");

    assert(ads_char_code_at(string, 0) == 24);
    printf("assert ads_char_code_at passed ✔\n");

    {
        ads_string *temp = ads_create("Hello World");
        assert(ads_is_equal(string, temp) == 0);
        ads_destroy(temp);
        printf("assert ads_is_equal passed ✔\n");
    }

    {
        ads_string *temp = ads_create("World");
        assert(ads_ends_with(string, temp) == 0);
        ads_destroy(temp);
        printf("assert ads_ends_with passed ✔\n");
    }

    {
        ads_string *temp = ads_create("Hello");
        assert(ads_includes(string, temp) == 0);
        ads_destroy(temp);
        printf("assert ads_includes passed ✔\n");
    }

    {
        ads_string *temp = ads_create("World");
        assert(ads_index_of(string, temp) == 6);
        ads_destroy(temp);
        printf("assert ads_index_of passed ✔\n");
    }

    {
        ads_string *temp = ads_create("!");
        ads_string *concat = ads_concat(string, temp);
        assert(strcmp(concat->buffer, "Hello World!") == 0);
        ads_destroy(temp);
        ads_destroy(concat);
        printf("assert ads_concat passed ✔\n");
    }

    {
        ads_string *temp = ads_create("       Hello World");
        ads_string *trim = ads_trim_start(temp);
        assert(strcmp(trim->buffer, "Hello World") == 0);
        ads_destroy(temp);
        ads_destroy(trim);
        printf("assert ads_trim_start passed ✔\n");
    }

    {
        ads_string *temp = ads_create("Hello World     ");
        ads_string *trim = ads_trim_end(temp);
        assert(strcmp(trim->buffer, "Hello World") == 0);
        ads_destroy(temp);
        ads_destroy(trim);
        printf("assert ads_trim_end passed ✔\n");
    }

    {
        ads_string *temp = ads_create("     Hello World     ");
        ads_string *trim = ads_trim(temp);
        assert(strcmp(trim->buffer, "Hello World") == 0);
        ads_destroy(temp);
        ads_destroy(trim);
        printf("assert ads_trim passed ✔\n");
    }

    {
        ads_string *lowercase = ads_to_lowercase(string);
        assert(strcmp(lowercase->buffer, "hello world") == 0);
        ads_destroy(lowercase);
        printf("assert ads_to_lowercase passed ✔\n");
    }

    {
        ads_string *uppercase = ads_to_uppercase(string);
        assert(strcmp(uppercase->buffer, "HELLO WORLD") == 0);
        ads_destroy(uppercase);
        printf("assert ads_to_uppercase passed ✔\n");
    }

    {
        ads_string *query = ads_create("World");
        ads_string *target = ads_create("Programmer");
        ads_string *replaced = ads_replace(string, query, target);
        assert(strcmp(replaced->buffer, "Hello Programmer") == 0);
        ads_destroy(replaced);
        ads_destroy(target);
        ads_destroy(query);
        printf("assert ads_replace passed ✔\n");
    }

    {
        ads_string *reverse = ads_reverse(string);
        assert(strcmp(reverse->buffer, "dlroW olleH") == 0);
        ads_destroy(reverse);
        printf("assert ads_reverse passed ✔\n");
    }

    {
        ads_string *slice = ads_slice(string, 5, 10);
        assert(strcmp(slice->buffer, "Hello") == 0);
        ads_destroy(slice);
        printf("assert ads_slice passed ✔\n");
    }

    {
        ads_string *copy = ads_copy(string, 6, 10);
        assert(strcmp(copy->buffer, "World") == 0);
        ads_destroy(copy);
        printf("assert ads_copy passed ✔\n");
    }

    {
        ads_string *text = ads_create("Hello, World");
        size_t size;
        ads_string **texts = ads_split(text, ',', &size);
        const char *arr[] = {"Hello", " World"};
        for (size_t i = 0; i < size; i++)
        {
            assert(strcmp(texts[i]->buffer, arr[i]) == 0);
            ads_destroy(texts[i]);
        }
        ads_destroy(text);
        free(texts);
        printf("assert ads_split passed ✔\n");
    }

    ads_destroy(string);
    return 0;
}